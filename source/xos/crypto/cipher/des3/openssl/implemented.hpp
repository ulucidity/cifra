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
///   File: implemented.hpp
///
/// Author: $author$
///   Date: 2/2/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_CIPHER_DES3_OPENSSL_IMPLEMENTED_HPP
#define XOS_CRYPTO_CIPHER_DES3_OPENSSL_IMPLEMENTED_HPP

#include "xos/crypto/cipher/des/openssl/implemented.hpp"
#include "xos/crypto/cipher/des3/extend.hpp"

namespace xos {
namespace crypto {
namespace cipher {
namespace des3 {
namespace openssl {

typedef des3::implement implements;
typedef des3::extendt<des::openssl::implemented, openssl::implements> extends;

/// class implemented
class exported implemented: virtual public openssl::implements, public openssl::extends {
public:
    typedef openssl::implements implements;
    typedef openssl::extends extends;
    typedef implemented derives; 
    
    /// constructors / destructor
    implemented
    (const void* key, size_t keylen, const void* iv, size_t ivlen, const void* padd = 0, size_t paddlen = 0) {
        if (0 > (initialize(key, keylen, iv, ivlen, padd, paddlen))) {
            LOGGER_LOG_ERROR("...failed on initialize(key, keylen, iv, ivlen, padd, paddlen) throw (error_failed)...");
            throw (error_failed);
        }
    }
    implemented(const void* key, const void* iv, const void* padd = 0) {
        if (0 > (initialize(key, iv, padd))) {
            LOGGER_LOG_ERROR("...failed on initialize(key, iv, padd) throw (error_failed)...");
            throw (error_failed);
        }
    }
    implemented() {
    }
    virtual ~implemented() {
    }
private:
    implemented(const implemented& copy) {
    }
public:

    using implements::initialize;
    virtual ssize_t initialize
    (const void* key, size_t keylen, const void* iv, size_t ivlen, const void* padd = 0, size_t paddlen = 0);

    virtual void EncryptBlock(tBlock out, const tBlock in);
    virtual void DecryptBlock(tBlock out, const tBlock in);

}; /// class implemented

} /// namespace openssl
} /// namespace des3
} /// namespace cipher
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_CIPHER_DES3_OPENSSL_IMPLEMENTED_HPP
