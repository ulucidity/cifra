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
///   Date: 2/1/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_CIPHER_DES_OPENSSL_IMPLEMENTED_HPP
#define XOS_CRYPTO_CIPHER_DES_OPENSSL_IMPLEMENTED_HPP

#include "xos/crypto/cipher/des/extend.hpp"

namespace xos {
namespace crypto {
namespace cipher {
namespace des {
namespace openssl {

/// class implemented
class exported implemented: virtual public des::extend::implements, public des::extend {
public:
    typedef des::extend::implements implements;
    typedef des::extend extends;
    typedef implemented derives; 
    
    /// constructors / destructor
    implemented
    (const void* key, size_t keylen, const void* iv, size_t ivlen, const void* padd = 0, size_t paddlen = 0) {
        clear();
        if (0 > (initialize(key, keylen, iv, ivlen, padd, paddlen))) {
            LOGGER_LOG_ERROR("...failed on initialize(key, keylen, iv, ivlen, padd, paddlen) throw (error_failed)...");
            throw (error_failed);
        }
    }
    implemented(const void* key, const void* iv, const void* padd = 0) {
        clear();
        if (0 > (initialize(key, iv, padd))) {
            LOGGER_LOG_ERROR("...failed on initialize(key, iv, padd) throw (error_failed)...");
            throw (error_failed);
        }
    }
    implemented() {
        clear();
    }
    virtual ~implemented() {
        clear();
    }
private:
    implemented(const implemented& copy) {
    }
public:

    using implements::initialize;
    virtual ssize_t initialize
    (const void* key, size_t keylen, const void* iv, size_t ivlen, const void* padd = 0, size_t paddlen = 0);
    virtual void clear();

    virtual ssize_t encrypt(void* out, size_t outsize, const void* in, size_t inlen);
    virtual ssize_t decrypt(void* out, size_t outsize, const void* in, size_t inlen);

protected:
    typedef uint8_t tBlock[BLOCKSIZE];
    typedef uint8_t tKey[BLOCKSIZE*3];
    typedef uint32_t tSchedule[32];

    void InitSchedule(tSchedule schedule, const tBlock key);

    void Encode(uint32_t data[2], tSchedule schedule);
    void Decode(uint32_t data[2], tSchedule schedule);

    virtual void EncryptBlock(tBlock out, const tBlock in);
    virtual void DecryptBlock(tBlock out, const tBlock in);

protected:
    static const uint32_t m_setkey[8][64];
    static const uint32_t m_encrypt[8][64];

    tKey m_key;
    tBlock m_iv;
    tBlock m_padd;
    tSchedule m_schedule[3];
}; /// class implemented

} /// namespace openssl
} /// namespace des
} /// namespace cipher
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_CIPHER_DES_OPENSSL_IMPLEMENTED_HPP
