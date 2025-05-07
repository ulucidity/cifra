///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: implemented.cpp
///
/// Author: $author$
///   Date: 2/1/2021
///////////////////////////////////////////////////////////////////////
#include "xos/crypto/cipher/des/openssl/constants.cpp"

#if !defined(XOS_CRYPTO_CIPHER_DES_OPENSSL_IMPLEMENTED_INSTANCE)
//#define XOS_CRYPTO_CIPHER_DES_OPENSSL_IMPLEMENTED_INSTANCE
#endif /// !defined(XOS_CRYPTO_CIPHER_DES_OPENSSL_IMPLEMENTED_INSTANCE)

namespace xos {
namespace crypto {
namespace cipher {
namespace des {
namespace openssl {

///  Class: implemented

/// initialize / clear
ssize_t implemented::initialize
(const void* key, size_t keylen, const void* iv, size_t ivlen, const void* padd, size_t paddlen) {
    ssize_t length = KEYMAX+IVMAX;
    const uint8_t* keyBytes;
    const uint8_t* ivBytes;
    const uint8_t* paddBytes;

    if (!(keyBytes = ((const uint8_t*)key)))
        return 0;

    if (KEYMIN > keylen)
        return 0;

    if (KEYMAX < keylen)
        return 0;

    CopyRepeat(m_key, KEYMAX, keyBytes, keylen);

    if ((ivBytes = ((const uint8_t*)iv))) {
        if (IVMIN > ivlen)
            return 0;

        if (IVMAX < ivlen)
            return 0;

        CopyRepeat(m_iv, IVMAX, ivBytes, ivlen);
    } else {
        if (IVMAX < keylen)
            keylen = IVMAX;

        CopyRepeat(m_iv, IVMAX, keyBytes, keylen);
    }

    memset(m_padd, 0, BLOCKSIZE);

    if ((paddBytes = ((const uint8_t*)padd))) {
        if (BLOCKSIZE < paddlen)
            paddlen = BLOCKSIZE;

        if (0 < paddlen)
            CopyRepeat(m_padd, BLOCKSIZE, paddBytes, paddlen);
    }

    InitSchedule(m_schedule[0], m_key);
    return length;
}
void implemented::clear() {
    memset(m_key, 0, sizeof(m_key));
    memset(m_iv, 0, sizeof(m_iv));
    memset(m_padd, 0, sizeof(m_padd));
    memset(m_schedule, 0, sizeof(m_schedule));
}

/// ..crypt...
ssize_t implemented::encrypt(void* out, size_t outsize, const void* in, size_t inlen) {
    tBlock block;
    ssize_t outlen,size;
    uint8_t* outBytes;
    const uint8_t* inBytes;

    if (!(outBytes = ((uint8_t*)out))
        || !(inBytes = ((const uint8_t*)in)))
        return 0;

    outlen = ((inlen+BLOCKSIZE-1)/BLOCKSIZE)*BLOCKSIZE;

    if (outsize < outlen)
        return 0;

    for (outlen=0; inlen>0; inlen-=size, outlen+=BLOCKSIZE) {
        if ((size=inlen) >= BLOCKSIZE) {
            size=BLOCKSIZE;
            EncryptBlock(outBytes+outlen, inBytes+outlen);
        } else {
            memcpy(block, inBytes+outlen, size);
            memcpy(block+size, m_padd, BLOCKSIZE-size);
            EncryptBlock(outBytes+outlen, block);
        }
    }
    return outlen;
}
ssize_t implemented::decrypt(void* out, size_t outsize, const void* in, size_t inlen) {
    tBlock block;
    ssize_t outlen,size;
    uint8_t* outBytes;
    const uint8_t* inBytes;

    if (!(outBytes = ((uint8_t*)out))
        || !(inBytes = ((const uint8_t*)in)))
        return 0;

    outlen = ((inlen+BLOCKSIZE-1)/BLOCKSIZE)*BLOCKSIZE;

    if (outsize < outlen)
        return 0;

    for (outlen=0; inlen>0; inlen-=size, outlen+=BLOCKSIZE) {
        if ((size=inlen) >= BLOCKSIZE) {
            size=BLOCKSIZE;
            DecryptBlock(outBytes+outlen, inBytes+outlen);
        } else {
            memcpy(block, inBytes+outlen, size);
            memcpy(block+size, m_padd, BLOCKSIZE-size);
            DecryptBlock(outBytes+outlen, block);
        }
    }
    return outlen;
}

/// ...Schedule
void implemented::InitSchedule(tSchedule schedule, const tBlock key) {
    uint32_t c,d,t,s,t2,*sch;
    unsigned i,shift;

    c = LSBToU32(key);
    d = LSBToU32(key+4);

    /* I now do it in 47 simple operations :-)
     * Thanks to John Fletcher (john_fletcher@lccmail.ocf.llnl.gov)
     * for the inspiration. :-)
     */
    PERM_OP (d,c,t,4,0x0f0f0f0fL);
    HPERM_OP(c,t,-2,0xcccc0000L);
    HPERM_OP(d,t,-2,0xcccc0000L);
    PERM_OP (d,c,t,1,0x55555555L);
    PERM_OP (c,d,t,8,0x00ff00ffL);
    PERM_OP (d,c,t,1,0x55555555L);
    d=    (((d&0x000000ffL)<<16L)| (d&0x0000ff00L)     |
         ((d&0x00ff0000L)>>16L)|((c&0xf0000000L)>>4L));
    c&=0x0fffffffL;

    sch=schedule;
    shift=0x7efc;
    for (i=0; i<16; i++) {
        if (shift & 1) {
            c=((c>>2L)|(c<<26L));
            d=((d>>2L)|(d<<26L));
        } else {
            c=((c>>1L)|(c<<27L));
            d=((d>>1L)|(d<<27L));
        }
        c&=0x0fffffffL;
        d&=0x0fffffffL;
        /* could be a few less shifts but I am to lazy at this
         * point in time to investigate
         */
        s=  m_setkey[0][(c)&0x3f]|
            m_setkey[1][((c>> 6)&0x03)|((c>> 7L)&0x3c)]|
            m_setkey[2][((c>>13)&0x0f)|((c>>14L)&0x30)]|
            m_setkey[3][((c>>20)&0x01)|((c>>21L)&0x06)|((c>>22L)&0x38)];

        t=  m_setkey[4][(d)&0x3f]|
            m_setkey[5][((d>>7L)&0x03)|((d>> 8L)&0x3c)]|
            m_setkey[6][(d>>15L)&0x3f]|
            m_setkey[7][((d>>21L)&0x0f)|((d>>22L)&0x30)];

        /* table contained 0213 4657
         */
        t2=((t<<16L)|(s&0x0000ffffL))&0xffffffffL;
        *(sch++)=ROTATE(t2,30)&0xffffffffL;

        t2=((s>>16L)|(t&0xffff0000L));
        *(sch++)=ROTATE(t2,26)&0xffffffffL;

        shift>>=1;
    }
}

/// ...code
void implemented::Encode(uint32_t data[2], tSchedule schedule) {
    uint32_t l,r,t,u,*s;

    r=data[0];
    l=data[1];
    s=(uint32_t*)schedule;

    /* Things have been modified so that the initial rotate is
     * done outside the loop.  This required the
     * des_SPtrans values in sp.h to be rotated 1 bit to the right.
     * One perl script later and things have a 5% speed up on a sparc2.
     * Thanks to Richard Outerbridge <71755.204@CompuServe.COM>
     * for pointing this out.
     */
    /* clear the top bits on machines with 8byte longs
     * shift left by 2
     */
    r=ROTATE(r,29)&0xffffffffL;
    l=ROTATE(l,29)&0xffffffffL;

    /* I don't know if it is worth the effort of loop unrolling the
     * inner loop.
     */
#if defined(DES_NO_UNROLL)
    for (int i=0; i<32; i+=8) {
        D_ENCRYPT(l,r,i+0 ,u,t,s); /*  1 */
        D_ENCRYPT(r,l,i+2 ,u,t,s); /*  2 */
        D_ENCRYPT(l,r,i+4 ,u,t,s); /*  3 */
        D_ENCRYPT(r,l,i+6 ,u,t,s); /*  4 */
    }
#else /* defined(DES_NO_UNROLL) */
    /* but...
     */
    D_ENCRYPT(l,r, 0, u,t,s); /*  1 */
    D_ENCRYPT(r,l, 2, u,t,s); /*  2 */
    D_ENCRYPT(l,r, 4, u,t,s); /*  3 */
    D_ENCRYPT(r,l, 6, u,t,s); /*  4 */
    D_ENCRYPT(l,r, 8, u,t,s); /*  5 */
    D_ENCRYPT(r,l,10, u,t,s); /*  6 */
    D_ENCRYPT(l,r,12, u,t,s); /*  7 */
    D_ENCRYPT(r,l,14, u,t,s); /*  8 */
    D_ENCRYPT(l,r,16, u,t,s); /*  9 */
    D_ENCRYPT(r,l,18, u,t,s); /*  10 */
    D_ENCRYPT(l,r,20, u,t,s); /*  11 */
    D_ENCRYPT(r,l,22, u,t,s); /*  12 */
    D_ENCRYPT(l,r,24, u,t,s); /*  13 */
    D_ENCRYPT(r,l,26, u,t,s); /*  14 */
    D_ENCRYPT(l,r,28, u,t,s); /*  15 */
    D_ENCRYPT(r,l,30, u,t,s); /*  16 */
#endif /* defined(DES_NO_UNROLL) */

    /* rotate and clear the top bits on machines with 8byte longs
     */
    l=ROTATE(l,3)&0xffffffffL;
    r=ROTATE(r,3)&0xffffffffL;

    data[0]=l;
    data[1]=r;
    l=r=t=u=0;
}
void implemented::Decode(uint32_t data[2], tSchedule schedule) {
    uint32_t l,r,t,u,*s;

    r=data[0];
    l=data[1];
    s=(uint32_t*)schedule;

    /* Things have been modified so that the initial rotate is
     * done outside the loop.  This required the
     * des_SPtrans values in sp.h to be rotated 1 bit to the right.
     * One perl script later and things have a 5% speed up on a sparc2.
     * Thanks to Richard Outerbridge <71755.204@CompuServe.COM>
     * for pointing this out.
     */
    /* clear the top bits on machines with 8byte longs
     * shift left by 2
     */
    r=ROTATE(r,29)&0xffffffffL;
    l=ROTATE(l,29)&0xffffffffL;

    /* I don't know if it is worth the effort of loop unrolling the
     * inner loop.
     */
#if defined(DES_NO_UNROLL)
    for (int i=30; i>0; i-=8) {
        D_ENCRYPT(l,r,i-0 ,u,t,s); /* 16 */
        D_ENCRYPT(r,l,i-2 ,u,t,s); /* 15 */
        D_ENCRYPT(l,r,i-4 ,u,t,s); /* 14 */
        D_ENCRYPT(r,l,i-6 ,u,t,s); /* 13 */
    }
#else /* defined(DES_NO_UNROLL) */
    /* but...
     */
    D_ENCRYPT(l,r,30 ,u,t,s); /* 16 */
    D_ENCRYPT(r,l,28 ,u,t,s); /* 15 */
    D_ENCRYPT(l,r,26 ,u,t,s); /* 14 */
    D_ENCRYPT(r,l,24 ,u,t,s); /* 13 */
    D_ENCRYPT(l,r,22 ,u,t,s); /* 12 */
    D_ENCRYPT(r,l,20 ,u,t,s); /* 11 */
    D_ENCRYPT(l,r,18 ,u,t,s); /* 10 */
    D_ENCRYPT(r,l,16 ,u,t,s); /*  9 */
    D_ENCRYPT(l,r,14 ,u,t,s); /*  8 */
    D_ENCRYPT(r,l,12 ,u,t,s); /*  7 */
    D_ENCRYPT(l,r,10 ,u,t,s); /*  6 */
    D_ENCRYPT(r,l, 8 ,u,t,s); /*  5 */
    D_ENCRYPT(l,r, 6 ,u,t,s); /*  4 */
    D_ENCRYPT(r,l, 4 ,u,t,s); /*  3 */
    D_ENCRYPT(l,r, 2 ,u,t,s); /*  2 */
    D_ENCRYPT(r,l, 0 ,u,t,s); /*  1 */
#endif /* defined(DES_NO_UNROLL) */

    /* rotate and clear the top bits on machines with 8byte longs
     */
    l=ROTATE(l,3)&0xffffffffL;
    r=ROTATE(r,3)&0xffffffffL;

    data[0]=l;
    data[1]=r;
    l=r=t=u=0;
}

/// ..crypt...
void implemented::EncryptBlock(tBlock out, const tBlock in) {
    uint32_t l,r,t,u,data[2];

    r = LSBToU32(in);
    l = LSBToU32(in+4);
    t = LSBToU32(m_iv);
    u = LSBToU32(m_iv+4);
    r^=t;
    l^=u;
    IP(r,l,t);
    data[0]=r;
    data[1]=l;
    Encode(data,m_schedule[0]);
    l=data[0];
    r=data[1];
    FP(r,l,t);
    U32ToLSB(m_iv,l);
    U32ToLSB(m_iv+4,r);
    U32ToLSB(out,l);
    U32ToLSB(out+4,r);
    l=r=t=u=0;
}
void implemented::DecryptBlock(tBlock out, const tBlock in) {
    uint32_t l,r,t,u,data[2];

    r = LSBToU32(in);
    l = LSBToU32(in+4);
    IP(r,l,t);
    data[0]=r;
    data[1]=l;
    Decode(data,m_schedule[0]);
    l=data[0];
    r=data[1];
    FP(r,l,t);
    t = LSBToU32(m_iv);
    u = LSBToU32(m_iv+4);
    l^=t;
    r^=u;
    Copy8(m_iv,in);
    U32ToLSB(out,l);
    U32ToLSB(out+4,r);
    l=r=t=u=0;
}

#if defined(XOS_CRYPTO_CIPHER_DES_OPENSSL_IMPLEMENTED_INSTANCE)
static implemented the_implemented;
#endif /// defined(XOS_CRYPTO_CIPHER_DES_OPENSSL_IMPLEMENTED_INSTANCE)

} /// namespace openssl
} /// namespace des
} /// namespace cipher
} /// namespace crypto
} /// namespace xos
