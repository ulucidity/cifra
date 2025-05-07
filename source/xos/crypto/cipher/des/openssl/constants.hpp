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
///   File: constants.hpp
///
/// Author: $author$
///   Date: 2/1/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_CIPHER_DES_OPENSSL_CONSTANTS_HPP
#define XOS_CRYPTO_CIPHER_DES_OPENSSL_CONSTANTS_HPP

#include "xos/crypto/cipher/des/openssl/implemented.hpp"

namespace xos {
namespace crypto {
namespace cipher {
namespace des {
namespace openssl {

/// enum ERROR
enum {
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

/// class bytes
class bytes {
public:
    static inline size_t Set(void* b, byte_t to, size_t length) {
        if ((b) && (length)) {
            memset(b, to, length);
            return length;
        }
        return 0;
    }
    static inline size_t Copy(void* to, const void* from, size_t length) {
        if ((to) && (from) && (length)) {
            memcpy(to, from, length);
            return length;
        }
        return 0;
    }
    static inline size_t Count(const void* b) {
        const char* chars = 0;
        if ((b) && (chars = ((const char*)b))) {
            size_t length = strlen(chars);
            return length;
        }
        return 0;
    }
}; /// class bytes

} /// namespace openssl
} /// namespace des
} /// namespace cipher
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_CIPHER_DES_OPENSSL_CONSTANTS_HPP
