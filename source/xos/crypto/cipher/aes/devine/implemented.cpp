///////////////////////////////////////////////////////////////////////
/// FIPS-197 compliant AES implementation
///
/// Copyright (C) 2006-2007  Christophe Devine
///
/// This program is free software; you can redistribute it and/or modify
/// it under the terms of the GNU General Public License as published by
/// the Free Software Foundation; either version 2 of the License, or
/// (at your option) any later version.
///
/// This program is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
/// GNU General Public License for more details.
///
/// You should have received a copy of the GNU General Public License along
/// with this program; if not, write to the Free Software Foundation, Inc.,
/// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
///
/// The AES block cipher was designed by Vincent Rijmen and Joan Daemen.
///
/// http://csrc.nist.gov/encryption/aes/rijndael/Rijndael.pdf
/// http://csrc.nist.gov/publications/fips/fips197/fips-197.pdf
///
///   File: implemented.cpp
///
/// Author: $author$
///   Date: 1/27/2021
///
/// Christophe Devine's implementation of AES modified to be a C++ class
/// implementation.
///////////////////////////////////////////////////////////////////////
#include "xos/crypto/cipher/aes/devine/implemented.hpp"
#include "xos/crypto/cipher/aes/devine/extend.cpp"

namespace xos {
namespace crypto {
namespace cipher {
namespace aes {
namespace devine {

///  Class: implemented

ssize_t implemented::initialize
(const void* key, size_t keylen, const void* iv, size_t ivlen, const void* padd, size_t paddlen) {
    ssize_t length = IVMAX;
    const uint8_t* keyBytes;
    const uint8_t* ivBytes;
    const uint8_t* paddBytes;

    if (!(keyBytes = ((const uint8_t*)key)))
        return 0;

    if (0 > keylen)
        keylen = strlen((const char*)key);

    if (KEYMIN > keylen)
        return -ERROR_KEY_SIZE_UNDER;

    if (KEYMAX < keylen)
        return -ERROR_KEY_SIZE_OVER;

    CopyRepeat(m_key, KEYMAX, keyBytes, keylen);

    m_keysize = KEYMIN;

    while (m_keysize < ((unsigned)keylen))
        m_keysize += KEYINC;

    length += m_keysize;

    if ((ivBytes = ((const uint8_t*)iv))) {
        if (0 > ivlen)
            ivlen = strlen((const char*)ivBytes);

        if (IVMIN > ivlen)
            return -ERROR_IV_SIZE_UNDER;

        if (IVMAX < ivlen)
            return -ERROR_IV_SIZE_OVER;

        CopyRepeat(m_iv, IVMAX, ivBytes, ivlen);
    } else {
        if (IVMAX < keylen)
            keylen = IVMAX;

        CopyRepeat(m_iv, IVMAX, keyBytes, keylen);
    }

    memset(m_padd, 0, BLOCKSIZE);

    if ((paddBytes = ((const uint8_t*)padd))) {
        if (0 > paddlen) {
            if (BLOCKSIZE < (paddlen = strlen((const char*)paddBytes)))
                paddlen = BLOCKSIZE;
        }
        if (0 < paddlen)
            CopyRepeat(m_padd, BLOCKSIZE, paddBytes, paddlen);
    }
    return length;
}

ssize_t implemented::encrypt(void* out, size_t outsize, const void* in, size_t inlen) {
    tBlock block;
    ssize_t outlen, size;
    uint8_t* outBytes;
    const uint8_t* inBytes;

    if (!(outBytes = ((uint8_t*)out))
        || !(inBytes = ((const uint8_t*)in))
        || !(inlen))
        return 0;

    outlen = ((inlen+BLOCKSIZE-1)/BLOCKSIZE)*BLOCKSIZE;

    if (outsize < outlen)
        return -ERROR_OUT_SIZE_UNDER;

    if (0 > (size = InitEncryptKeySchedule(m_key, m_keysize)))
        return size;

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
    size_t outlen, size;
    uint8_t* outBytes;
    const uint8_t* inBytes;

    if (!(outBytes = ((uint8_t*)out))
        || !(inBytes = ((const uint8_t*)in))
        || !(inlen))
        return 0;

    outlen = ((inlen+BLOCKSIZE-1)/BLOCKSIZE)*BLOCKSIZE;

    if (outsize < outlen)
        return -ERROR_OUT_SIZE_UNDER;

    if (0 > (size = InitDecryptKeySchedule(m_key, m_keysize)))
        return size;

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

void implemented::ClearKey() {
    m_keysize = 0;
    memset(m_key, 0, sizeof(m_key));
    memset(m_iv, 0, sizeof(m_iv));
    memset(m_padd, 0, sizeof(m_padd));
}
ssize_t implemented::InitDecryptKeySchedule(const uint8_t* key, unsigned keysize) {
    unsigned i, j;
    ssize_t size;
    uint32_t *RK;
    uint32_t *SK;
    extend aes;

    if (0 > (size = aes.InitEncryptKeySchedule(key, keysize)))
        return size;

    RK = (rk = buf);
    SK = aes.rk + (nr = aes.nr)*4;

    *RK++ = *SK++;
    *RK++ = *SK++;
    *RK++ = *SK++;
    *RK++ = *SK++;

    for( i = nr, SK -= 8; i > 1; i--, SK -= 8 ) {
        for( j = 0; j < 4; j++, SK++ ) {
            *RK++ = RT0[ FSb[ ( *SK       ) & 0xFF ] ] ^
                    RT1[ FSb[ ( *SK >>  8 ) & 0xFF ] ] ^
                    RT2[ FSb[ ( *SK >> 16 ) & 0xFF ] ] ^
                    RT3[ FSb[ ( *SK >> 24 ) & 0xFF ] ];
        }
    }

    *RK++ = *SK++;
    *RK++ = *SK++;
    *RK++ = *SK++;
    *RK++ = *SK++;

    return keysize;
}

void implemented::EncryptBlock(tBlock output, const tBlock input) {
    unsigned i;

    for( i = 0; i < 16; i++ )
        output[i] = ( input[i] ^ m_iv[i] );

    EncodeBlock(output, output);

    Copy8(m_iv, output);
    Copy8(m_iv+8, output+8);
}
void implemented::DecryptBlock(tBlock output, const tBlock input) {
    unsigned i;
    tBlock temp;

    Copy8(temp, input);
    Copy8(temp+8, input+8);

    DecodeBlock(output, input);

    for( i = 0; i < 16; i++ )
        output[i] = ( output[i] ^ m_iv[i] );

    Copy8(m_iv, temp);
    Copy8(m_iv+8, temp+8);
}

void implemented::EncodeBlock(tBlock output, const tBlock input) {
    unsigned i;
    uint32_t *RK, X0, X1, X2, X3, Y0, Y1, Y2, Y3;

    RK = rk;

    X0 = LSBToU32(input)^(*RK++);
    X1 = LSBToU32(input+4)^(*RK++);
    X2 = LSBToU32(input+8)^(*RK++);
    X3 = LSBToU32(input+12)^(*RK++);

    for( i = (nr >> 1); i > 1; i-- ) {
        AES_FROUND( Y0, Y1, Y2, Y3, X0, X1, X2, X3 );
        AES_FROUND( X0, X1, X2, X3, Y0, Y1, Y2, Y3 );
    }

    AES_FROUND( Y0, Y1, Y2, Y3, X0, X1, X2, X3 );

    X0 = *RK++ ^ ( FSb[ ( Y0       ) & 0xFF ]       ) ^
                 ( FSb[ ( Y1 >>  8 ) & 0xFF ] <<  8 ) ^
                 ( FSb[ ( Y2 >> 16 ) & 0xFF ] << 16 ) ^
                 ( FSb[ ( Y3 >> 24 ) & 0xFF ] << 24 );

    X1 = *RK++ ^ ( FSb[ ( Y1       ) & 0xFF ]       ) ^
                 ( FSb[ ( Y2 >>  8 ) & 0xFF ] <<  8 ) ^
                 ( FSb[ ( Y3 >> 16 ) & 0xFF ] << 16 ) ^
                 ( FSb[ ( Y0 >> 24 ) & 0xFF ] << 24 );

    X2 = *RK++ ^ ( FSb[ ( Y2       ) & 0xFF ]       ) ^
                 ( FSb[ ( Y3 >>  8 ) & 0xFF ] <<  8 ) ^
                 ( FSb[ ( Y0 >> 16 ) & 0xFF ] << 16 ) ^
                 ( FSb[ ( Y1 >> 24 ) & 0xFF ] << 24 );

    X3 = *RK++ ^ ( FSb[ ( Y3       ) & 0xFF ]       ) ^
                 ( FSb[ ( Y0 >>  8 ) & 0xFF ] <<  8 ) ^
                 ( FSb[ ( Y1 >> 16 ) & 0xFF ] << 16 ) ^
                 ( FSb[ ( Y2 >> 24 ) & 0xFF ] << 24 );

    U32ToLSB(output, X0);
    U32ToLSB(output+4, X1);
    U32ToLSB(output+8, X2);
    U32ToLSB(output+12, X3);
}
void implemented::DecodeBlock(tBlock output, const tBlock input) {
    unsigned i;
    uint32_t *RK, X0, X1, X2, X3, Y0, Y1, Y2, Y3;

    RK = rk;

    X0 = LSBToU32(input)^(*RK++);
    X1 = LSBToU32(input+4)^(*RK++);
    X2 = LSBToU32(input+8)^(*RK++);
    X3 = LSBToU32(input+12)^(*RK++);

    for( i = (nr >> 1); i > 1; i-- ) {
        AES_RROUND( Y0, Y1, Y2, Y3, X0, X1, X2, X3 );
        AES_RROUND( X0, X1, X2, X3, Y0, Y1, Y2, Y3 );
    }

    AES_RROUND( Y0, Y1, Y2, Y3, X0, X1, X2, X3 );

    X0 = *RK++ ^ ( RSb[ ( Y0       ) & 0xFF ]       ) ^
                 ( RSb[ ( Y3 >>  8 ) & 0xFF ] <<  8 ) ^
                 ( RSb[ ( Y2 >> 16 ) & 0xFF ] << 16 ) ^
                 ( RSb[ ( Y1 >> 24 ) & 0xFF ] << 24 );

    X1 = *RK++ ^ ( RSb[ ( Y1       ) & 0xFF ]       ) ^
                 ( RSb[ ( Y0 >>  8 ) & 0xFF ] <<  8 ) ^
                 ( RSb[ ( Y3 >> 16 ) & 0xFF ] << 16 ) ^
                 ( RSb[ ( Y2 >> 24 ) & 0xFF ] << 24 );

    X2 = *RK++ ^ ( RSb[ ( Y2       ) & 0xFF ]       ) ^
                 ( RSb[ ( Y1 >>  8 ) & 0xFF ] <<  8 ) ^
                 ( RSb[ ( Y0 >> 16 ) & 0xFF ] << 16 ) ^
                 ( RSb[ ( Y3 >> 24 ) & 0xFF ] << 24 );

    X3 = *RK++ ^ ( RSb[ ( Y3       ) & 0xFF ]       ) ^
                 ( RSb[ ( Y2 >>  8 ) & 0xFF ] <<  8 ) ^
                 ( RSb[ ( Y1 >> 16 ) & 0xFF ] << 16 ) ^
                 ( RSb[ ( Y0 >> 24 ) & 0xFF ] << 24 );

    U32ToLSB(output, X0);
    U32ToLSB(output+4, X1);
    U32ToLSB(output+8, X2);
    U32ToLSB(output+12, X3);
}

} /// namespace devine
} /// namespace aes
} /// namespace cipher
} /// namespace crypto
} /// namespace xos
