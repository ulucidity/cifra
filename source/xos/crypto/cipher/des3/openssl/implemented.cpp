///////////////////////////////////////////////////////////////////////
/// Copyright (C) 1995-1997 Eric Young (eay@cryptsoft.com)
/// All rights reserved.
///
/// This package is an SSL implementation written
/// by Eric Young (eay@cryptsoft.com).
/// The implementation was written so as to conform with Netscapes SSL.
///
/// This library is free for commercial and non-commercial use as long as
/// the following conditions are aheared to.  The following conditions
/// apply to all code found in this distribution, be it the RC4, RSA,
/// lhash, DES, etc., code; not just the SSL code.  The SSL documentation
/// included with this distribution is covered by the same copyright terms
/// except that the holder is Tim Hudson (tjh@cryptsoft.com).
///
/// Copyright remains Eric Young's, and as such any Copyright notices in
/// the code are not to be removed.
/// If this package is used in a product, Eric Young should be given attribution
/// as the author of the parts of the library used.
/// This can be in the form of a textual message at program startup or
/// in documentation (online or textual) provided with the package.
///
/// Redistribution and use in source and binary forms, with or without
/// modification, are permitted provided that the following conditions
/// are met:
/// 1. Redistributions of source code must retain the copyright
///    notice, this list of conditions and the following disclaimer.
/// 2. Redistributions in binary form must reproduce the above copyright
///    notice, this list of conditions and the following disclaimer in the
///    documentation and/or other materials provided with the distribution.
/// 3. All advertising materials mentioning features or use of this software
///    must display the following acknowledgement:
///    "This product includes cryptographic software written by
///     Eric Young (eay@cryptsoft.com)"
///    The word 'cryptographic' can be left out if the rouines from the library
///    being used are not cryptographic related :-).
/// 4. If you include any Windows specific code (or a derivative thereof) from
///    the apps directory (application code) you must include an acknowledgement:
///    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"
///
/// THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND
/// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
/// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
/// ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
/// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
/// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
/// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
/// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
/// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
/// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
/// SUCH DAMAGE.
///
/// The licence and distribution terms for any publically available version or
/// derivative of this code cannot be changed.  i.e. this code cannot simply be
/// copied and put under another distribution licence
/// [including the GNU Public Licence.]
///
///   File: implemented.cpp
///
/// Author: $author$
///   Date: 2/2/2021
///
/// Eric Young's implementation of DES and 3DES modified to be C++ class
/// implementations.
///////////////////////////////////////////////////////////////////////
#include "xos/crypto/cipher/des3/openssl/implemented.hpp"
#include "xos/crypto/cipher/des/openssl/implemented.cpp"

#if !defined(XOS_CRYPTO_CIPHER_DES3_OPENSSL_IMPLEMENTED_INSTANCE)
//#define XOS_CRYPTO_CIPHER_DES3_OPENSSL_IMPLEMENTED_INSTANCE
#endif /// !defined(XOS_CRYPTO_CIPHER_DES3_OPENSSL_IMPLEMENTED_INSTANCE)

namespace xos {
namespace crypto {
namespace cipher {
namespace des3 {
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
    InitSchedule(m_schedule[1], m_key+8);
    InitSchedule(m_schedule[2], m_key+16);
    return length;
}

/// ..crypt...
void implemented::EncryptBlock(tBlock out, const tBlock in) {
    uint32_t l,r,t,u,data[2];

    l = LSBToU32(in);
    r = LSBToU32(in+4);
    t = LSBToU32(m_iv);
    u = LSBToU32(m_iv+4);
    l^=t;
    r^=u;
    IP(l,r,t);
    data[0]=l;
    data[1]=r;
    Encode(data,m_schedule[0]);
    Decode(data,m_schedule[1]);
    Encode(data,m_schedule[2]);
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

    l = LSBToU32(in);
    r = LSBToU32(in+4);
    IP(l,r,t);
    data[0]=l;
    data[1]=r;
    Decode(data,m_schedule[2]);
    Encode(data,m_schedule[1]);
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

#if defined(XOS_CRYPTO_CIPHER_DES3_OPENSSL_IMPLEMENTED_INSTANCE)
static implemented the_implemented;
#endif /// defined(XOS_CRYPTO_CIPHER_DES3_OPENSSL_IMPLEMENTED_INSTANCE)

} /// namespace openssl
} /// namespace des3
} /// namespace cipher
} /// namespace crypto
} /// namespace xos
