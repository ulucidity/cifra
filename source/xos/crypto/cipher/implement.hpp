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
///   File: implement.hpp
///
/// Author: $author$
///   Date: 1/25/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_CIPHER_IMPLEMENT_HPP
#define XOS_CRYPTO_CIPHER_IMPLEMENT_HPP

#include "xos/crypto/cipher/base.hpp"

namespace xos {
namespace crypto {
namespace cipher {

/// class implementt
template <class TImplements = crypto::implement>
class exported implementt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef implementt derives;
    
    /// initialize
    virtual ssize_t initialize
    (const void* key, size_t keylen, const void* iv, size_t ivlen, const void* padd, size_t paddlen) {
        return -error_not_implemented;
    }
    virtual ssize_t initialize
    (const void* key, const void* iv, const void* padd) {
        if ((key)) {
            size_t keylen = 0;
            if ((keylen = bytes_t::count((const byte_t*)key))) {
                if ((iv)) {
                    size_t ivlen = 0;
                    if ((ivlen = bytes_t::count((const byte_t*)iv))) {
                        if ((padd)) {
                            size_t paddlen = 0;
                            if ((paddlen = bytes_t::count((const byte_t*)padd))) {
                                return this->initialize(key, keylen, iv, ivlen, padd, paddlen);
                            }
                        } else {
                            return this->initialize(key, keylen, iv, ivlen, 0, 0);
                        }
                    }
                }
            }
        }
        return -error_failed;
    }

    /// encrypt / decrypt
    virtual ssize_t encrypt(void* out, size_t outsize, const void* in, size_t inlen) {
        return -error_not_implemented;
    }
    virtual ssize_t encrypt(void* out, size_t outsize, const void* in) {
        if ((in)) {
            size_t inlen = 0;
            if ((inlen = bytes_t::count((const byte_t*)in))) {
                return this->encrypt(out, outsize, in, inlen);
            }
        }
        return -error_failed;
    }
    virtual ssize_t decrypt(void* out, size_t outsize, const void* in, size_t inlen) {
        return -error_not_implemented;
    }
    virtual ssize_t decrypt(void* out, size_t outsize, const void* in) {
        if ((in)) {
            size_t inlen = 0;
            if ((inlen = bytes_t::count((const byte_t*)in))) {
                return this->decrypt(out, outsize, in, inlen);
            }
        }
        return -error_failed;
    }

    /// key_size...
    virtual ssize_t key_size_min() const {
        return 0;
    }
    virtual ssize_t key_size_max() const {
        return 0;
    }
    virtual ssize_t key_size_inc() const {
        return 0;
    }
    virtual ssize_t key_size() const {
        return 0;
    }

    /// iv_size...
    virtual ssize_t iv_size_min() const {
        return 0;
    }
    virtual ssize_t iv_size_max() const {
        return 0;
    }
    virtual ssize_t iv_size_inc() const {
        return 0;
    }
    virtual ssize_t iv_size() const {
        return 0;
    }

    /// ...block...
    virtual ssize_t block_size() const {
        return 0;
    }
    virtual bool is_block() const {
        return (1 > block_size());
    }
    virtual bool is_stream() const {
        return (1 == block_size());
    }

}; /// class implementt
typedef implementt<> implement;

} /// namespace cipher
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_CIPHER_IMPLEMENT_HPP
