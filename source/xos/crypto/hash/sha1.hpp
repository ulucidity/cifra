///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
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
///   File: sha1.hpp
///
/// Author: $author$
///   Date: 5/1/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_HASH_SHA1_HPP
#define XOS_CRYPTO_HASH_SHA1_HPP

#include "xos/crypto/hash/extend.hpp"

namespace xos {
namespace crypto {
namespace hash {

/// class sha1t
template <class TExtends = hash::extend, class TImplements = typename TExtends::implements>
class exported sha1t: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef sha1t derives;

    enum {
        HASHSIZE  = 20,
        BLOCKSIZE = 64,
        KEYMIN    = 1,
        KEYMAX    = BLOCKSIZE,
        KEYSIZE   = BLOCKSIZE
    };
    enum {
        HASH_SIZE = HASHSIZE,
        KEY_MIN = KEYMIN,
        KEY_MAX = KEYMAX,
        KEY_SIZE = KEYSIZE
    };

    /// constructor / destructor
    sha1t(void* out, size_t outsize, const void* in, size_t inlen): extends(HASHSIZE, BLOCKSIZE, KEYMIN, KEYMAX, m_key, m_mac, m_hash) {
        this->operator~();
        if (0 > (this->operator()(out, outsize, in, inlen))) {
            throw crypto::exception(error_failed);
        }
    }
    sha1t(const sha1t& copy): extends(HASHSIZE, BLOCKSIZE, KEYMIN, KEYMAX, m_key, m_mac, m_hash) {
        this->operator=(copy);
    }
    sha1t(): extends(HASHSIZE, BLOCKSIZE, KEYMIN, KEYMAX, m_key, m_mac, m_hash) {
        this->operator~();
    }
    virtual ~sha1t() {
        this->operator~();
    }

    /// operator = / operator ~
    virtual sha1t& operator = (const sha1t& copy) {
        m_A = copy.m_A; m_B = copy.m_B;
        m_C = copy.m_C; m_D = copy.m_D; m_E = copy.m_E;
        m_L = copy.m_L; m_H = copy.m_H;
        memcpy(m_in, copy.m_in, sizeof(m_in));
        memcpy(m_key, copy.m_key, sizeof(m_key));
        memcpy(m_mac, copy.m_mac, sizeof(m_mac));
        memcpy(m_hash, copy.m_hash, sizeof(m_hash));
        return *this;
    }
    virtual sha1t& operator ~ () {
        m_A = 0; m_B = 0;
        m_C = 0; m_D = 0; m_E = 0;
        m_L = 0; m_H = 0;
        memset(m_in, 0, sizeof(m_in));
        memset(m_key, 0, sizeof(m_key));
        memset(m_mac, 0, sizeof(m_mac));
        memset(m_hash, 0, sizeof(m_hash));
        return *this;
    }

    /// ...size / ...min / ...max
    virtual ssize_t blocksize() const {
        return BLOCKSIZE;
    }
    virtual ssize_t hashsize() const {
        return HASHSIZE;
    }
    virtual ssize_t keysize() const {
        return KEYSIZE;
    }
    virtual ssize_t keymin() const {
        return KEYMIN;
    }
    virtual ssize_t keymxn() const {
        return KEYMAX;
    }

protected:
    /// initial / final / transform / update
    virtual void initial() {}
    virtual void final() {}
    virtual void transform() {}
    virtual void update(const uint8_t* in, size_t inlen) {}

protected:
    uint32_t m_A, m_B, m_C, m_D, m_E, m_L, m_H;
    uint8_t m_hash[HASHSIZE], m_in[BLOCKSIZE], m_key[BLOCKSIZE], m_mac[HASHSIZE];
}; /// class sha1t
typedef sha1t<> sha1;

} /// namespace hash
} /// namespace crypto
} /// namespace xos

#endif /// ndef XOS_CRYPTO_HASH_SHA1_HPP 
