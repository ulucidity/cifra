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
///   Date: 1/27/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_CIPHER_AES_DEVINE_IMPLEMENTED_HPP
#define XOS_CRYPTO_CIPHER_AES_DEVINE_IMPLEMENTED_HPP

#include "xos/crypto/cipher/aes/devine/extend.hpp"

namespace xos {
namespace crypto {
namespace cipher {
namespace aes {
namespace devine {

/// class implemented
class exported implemented: virtual public devine::extend::implements, public devine::extend {
public:
    typedef devine::extend::implements implements;
    typedef devine::extend extends;
    typedef implemented derives; 
    
    /// constructors / destructor
    implemented
    (const void* key, size_t keylen, const void* iv, size_t ivlen, const void* padd = 0, size_t paddlen = 0) {
        ClearKey();
        if (0 > (initialize(key, keylen, iv, ivlen, padd, paddlen))) {
            LOGGER_LOG_ERROR("...failed on initialize(key, keylen, iv, ivlen, padd, paddlen) throw (error_failed)...");
            throw (error_failed);
        }
    }
    implemented(const void* key, const void* iv, const void* padd = 0) {
        ClearKey();
        if (0 > (initialize(key, iv, padd))) {
            LOGGER_LOG_ERROR("...failed on initialize(key, iv, padd) throw (error_failed)...");
            throw (error_failed);
        }
    }
    implemented() {
        ClearKey();
    }
    virtual ~implemented() {
        ClearKey();
    }
private:
    implemented(const implemented& copy) {
    }
public:

    /// initialize
    using extends::initialize;
    virtual ssize_t initialize
    (const void* key, size_t keylen, const void* iv, size_t ivlen, const void* padd = 0, size_t paddlen = 0);

    /// encrypt / decrypt
    virtual ssize_t encrypt(void* out, size_t outsize, const void* in, size_t inlen);
    virtual ssize_t decrypt(void* out, size_t outsize, const void* in, size_t inlen);

    /// clear
    virtual void clear() {
        ClearKey();
        ClearKeySchedule();
    }

protected:
    /// class extend
    class exported extend: virtual public devine::extend::implements, public devine::extend {
    friend class implemented;
    public:
        typedef devine::extend::implements implements;
        typedef devine::extend extends;
        typedef extend derives;         
        /// constructors / destructor
        extend() {
        }
        virtual ~extend() {
        }
    private:
        extend(const extend& copy) {
        }
    }; /// class extend
    typedef uint8_t tBlock[BLOCKSIZE];
    typedef uint8_t tKey[KEYMAX];

    /// ...Key...
    virtual void ClearKey();
    virtual ssize_t InitDecryptKeySchedule(const uint8_t* key, unsigned keysize);

    /// Encrypt... / Decrypt...
    virtual void EncryptBlock(tBlock output, const tBlock input);
    virtual void DecryptBlock(tBlock output, const tBlock input);

    /// Encode... / Decode...
    virtual void EncodeBlock(tBlock output, const tBlock input);
    virtual void DecodeBlock(tBlock output, const tBlock input);

protected:
    unsigned m_keysize;
    tKey m_key;
    tBlock m_iv;
    tBlock m_padd;
}; /// class implemented

} /// namespace devine
} /// namespace aes
} /// namespace cipher
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_CIPHER_AES_DEVINE_IMPLEMENTED_HPP
