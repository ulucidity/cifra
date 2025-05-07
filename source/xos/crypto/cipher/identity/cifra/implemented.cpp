//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2024 $organization$
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
///   Date: 9/11/2024
//////////////////////////////////////////////////////////////////////////
#include "xos/crypto/cipher/identity/cifra/implemented.hpp"

#if defined(ERROR_INVALID_PARAMETER)
#define XOS_CRYPTO_CIPHER_IDENTITY_ETIRIS_ERROR_INVALID_PARAMETER ERROR_INVALID_PARAMETER
#undef ERROR_INVALID_PARAMETER
#endif /// defined(ERROR_INVALID_PARAMETER)

namespace xos {
namespace crypto {
namespace cipher {
namespace identity {
namespace cifra {

/// enum ERROR
enum {
    ERROR_INVALID_PARAMETER = error_invalid_parameter,

    ERROR_KEY_SIZE = error_invalid_parameter_size,
    ERROR_KEY_SIZE_UNDER = error_invalid_parameter_size,
    ERROR_KEY_SIZE_OVER = error_invalid_parameter_size,

    ERROR_IV_SIZE = error_invalid_parameter_size,
    ERROR_IV_SIZE_UNDER = error_invalid_parameter_size,
    ERROR_IV_SIZE_OVER = error_invalid_parameter_size,

    ERROR_OUT_SIZE = error_invalid_parameter_size,
    ERROR_OUT_SIZE_UNDER = error_invalid_parameter_size,
    ERROR_OUT_SIZE_OVER = error_invalid_parameter_size
}; /// enum ERROR

#if defined(XOS_CRYPTO_CIPHER_IDENTITY_ETIRIS_IMPLEMENTED_INSTANCE)
static implemented the_implemented;
#endif /// defined(XOS_CRYPTO_CIPHER_IDENTITY_ETIRIS_IMPLEMENTED_INSTANCE)

///  Class: implemented

/// initialize / clear
ssize_t implemented::initialize
(const void* key, size_t keylen, const void* iv, size_t ivlen, const void* padd, size_t paddlen) {
    return keylen;
}
void implemented::clear() {
}

/// ..crypt...
ssize_t implemented::encrypt(void* out, size_t outsize, const void* in, size_t inlen) {
    size_t outlen = 0;
    if ((out) && (outsize) && (in)) {
        if (0 >= inlen) {
            inlen = strlen((const char*)in);
        }
        if ((outlen = inlen) > outsize) {
            outlen = outsize;
        }
        ::memset(out, 0, outsize);
        ::memcpy(out, in, outlen);
    }
    return outlen;
}
ssize_t implemented::decrypt(void* out, size_t outsize, const void* in, size_t inlen) {
    ssize_t outlen = encrypt(out, outsize, in, inlen);
    return outlen;
}

} /// namespace cifra 
} /// namespace identity 
} /// namespace cipher 
} /// namespace crypto 
} /// namespace xos 

#if defined(XOS_CRYPTO_CIPHER_IDENTITY_ETIRIS_ERROR_INVALID_PARAMETER)
#define ERROR_INVALID_PARAMETER XOS_CRYPTO_CIPHER_IDENTITY_ETIRIS_ERROR_INVALID_PARAMETER
#undef XOS_CRYPTO_CIPHER_IDENTITY_ETIRIS_ERROR_INVALID_PARAMETER
#endif /// defined(XOS_CRYPTO_CIPHER_IDENTITY_ETIRIS_ERROR_INVALID_PARAMETER)
