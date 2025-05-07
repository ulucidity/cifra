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
///   File: sha512.hpp
///
/// Author: $author$
///   Date: 5/1/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_HASH_SHA512_HPP
#define XOS_CRYPTO_HASH_SHA512_HPP

#include "xos/crypto/hash/extend.hpp"

namespace xos {
namespace crypto {
namespace hash {

/// class sha512t
template <class TExtends = hash::extend, class TImplements = typename TExtends::implements>
class exported sha512t: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef sha512t derives;

    enum {
        WORDSIZE    = 8,
        LENGTHSIZE  = 16
    };
    enum {
        HASHSIZE  = 64,
        KONSTSIZE = 80,
        BLOCKSIZE = 128,
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
    sha512t(void* out, size_t outsize, const void* in, size_t inlen)
    : extends(HASHSIZE, BLOCKSIZE, KEYMIN, KEYMAX, m_key, m_mac, m_hash) {
        this->operator~();
        if (0 > (this->operator()(out, outsize, in, inlen))) {
            throw crypto::exception(error_failed);
        }
    }
    sha512t(const sha512t& copy): extends(HASHSIZE, BLOCKSIZE, KEYMIN, KEYMAX, m_key, m_mac, m_hash) {
        this->operator=(copy);
    }
    sha512t(): extends(HASHSIZE, BLOCKSIZE, KEYMIN, KEYMAX, m_key, m_mac, m_hash) {
        this->operator~();
    }
    virtual ~sha512t() {
        this->operator~();
    }

    /// operator = / operator ~
    virtual sha512t& operator = (const sha512t& copy) {
        m_A = copy.m_A; m_B = copy.m_B;
        m_C = copy.m_C; m_D = copy.m_D;
        m_E = copy.m_E; m_F = copy.m_F;
        m_G = copy.m_G; m_H = copy.m_H;
        m_l = copy.m_l; m_h = copy.m_h;
        memcpy(m_in, copy.m_in, sizeof(m_in));
        memcpy(m_key, copy.m_key, sizeof(m_key));
        memcpy(m_mac, copy.m_mac, sizeof(m_mac));
        memcpy(m_hash, copy.m_hash, sizeof(m_hash));
        return *this;
    }
    virtual sha512t& operator ~ () {
        m_A = 0; m_B = 0;
        m_C = 0; m_D = 0;
        m_E = 0; m_F = 0;
        m_G = 0; m_H = 0;
        m_l = 0; m_h = 0;
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
    uint64_t m_A, m_B, m_C, m_D, m_E, m_F, m_G, m_H, m_l, m_h;
    uint8_t m_hash[HASHSIZE], m_mac[HASHSIZE], m_in[BLOCKSIZE], m_key[BLOCKSIZE];
}; /// class sha512t
typedef sha512t<> sha512;

} /// namespace hash
} /// namespace crypto
} /// namespace xos

#endif /// ndef XOS_CRYPTO_HASH_SHA512_HPP 
