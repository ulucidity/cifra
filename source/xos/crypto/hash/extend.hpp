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
///   File: extend.hpp
///
/// Author: $author$
///   Date: 5/1/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_HASH_EXTEND_HPP
#define XOS_CRYPTO_HASH_EXTEND_HPP

#include "xos/crypto/hash/implement.hpp"
#include "xos/crypto/base/extend.hpp"

namespace xos {
namespace crypto {
namespace hash {

/// class extendt
template <class TImplements = hash::implement, class TExtends = crypto::extend>
class exported extendt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef extendt derives;

    /// constructor / destructor
    extendt(const extendt& copy)
    : m_hashsize(copy.m_hashsize), m_blocksize(copy.m_blocksize), 
      m_keymin(copy.m_keymin), m_keymax(copy.m_keymax), m_keylen(0), m_keysize(0),
      m_keybuff(copy.m_keybuff), m_macbuff(copy.m_macbuff), m_hashbuff(copy.m_hashbuff) {
    }
    extendt
    (size_t hashsize, size_t blocksize, size_t keymin, size_t keymax,
     uint8_t* keybuff, uint8_t* macbuff, uint8_t* hashbuff)
    : m_hashsize(hashsize), m_blocksize(blocksize), 
      m_keymin(keymin), m_keymax(keymax), m_keylen(0), m_keysize(0),
      m_keybuff(keybuff), m_macbuff(macbuff), m_hashbuff(hashbuff) {
    }
    virtual ~extendt() {
    }

    /// initialize / finalize
    using implements::initialize;
    virtual ssize_t initialize(const void* key, size_t keylen) {
        const uint8_t* keybytes = 0;
        size_t i = 0;

        if ((keybytes = ((const uint8_t*)key)) && (keylen)) {
            if (keylen < m_keymin) {
                return -error_invalid_parameter_size;
            }

            if (keylen > m_keymax) {
                return -error_invalid_parameter_size;
            }

            m_keylen = keylen;
            m_keysize = m_keymax;
            memcpy(m_keybuff, keybytes, keylen);
            memset(m_keybuff+keylen, 0, m_keymax-keylen);

            ///
            /// HMAC
            ///
            for (i=0; i<m_keymax; i++)
                m_keybuff[i] ^= OPAD;
        } else {
            m_keysize = m_keylen = keylen = 0;
        }

        initial();

        if (m_keysize) {
            ///
            /// HMAC
            ///
            for (i=0; i<m_keysize; i++) {
                m_keybuff[i] = (m_keybuff[i]^OPAD)^IPAD;
            }

            update(m_keybuff, m_keysize);

            ///
            /// HMAC
            //
            for (i=0; i<m_keysize; i++) {
                m_keybuff[i] = (m_keybuff[i]^IPAD)^OPAD;
            }
        }
        return keylen;
    }
    virtual ssize_t finalize(void* out, size_t outsize) {
        size_t outlen = outsize;

        if (outlen > m_hashsize) {
            outlen = m_hashsize;
        }

        final();

        if (m_keysize) {
            ///
            /// HMAC
            ///
            memcpy(m_macbuff, m_hashbuff, m_hashsize);
            initial();
            update(m_keybuff, m_keysize);
            update(m_macbuff, m_hashsize);
            final();
        }

        memcpy(out, m_hashbuff, outlen);
        return outlen;
    }

    /// hash
    using implements::hash;
    virtual ssize_t hash(const void* in, size_t inlen) {
        const uint8_t* inbytes = 0;
        if ((inbytes = ((const uint8_t*)in)) && (inlen)) {
            update(inbytes, inlen);
            return inlen;
        }
        return 0;
    }
    virtual ssize_t hash_size() const {
        return m_hashsize;
    }

protected:
    /// initial / final / transform / update
    virtual void initial() = 0;
    virtual void final() = 0;
    virtual void transform() = 0;
    virtual void update(const uint8_t* in, size_t inlen) = 0;

protected:
    size_t m_hashsize, m_blocksize, m_keymin, m_keymax, m_keysize, m_keylen;
    uint8_t *m_keybuff, *m_macbuff, *m_hashbuff;
}; /// class extendt
typedef extendt<> extend;

} /// namespace hash
} /// namespace crypto
} /// namespace xos

#endif /// ndef XOS_CRYPTO_HASH_EXTEND_HPP 
