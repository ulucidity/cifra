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
///   File: algorithm.hpp
///
/// Author: $author$
///   Date: 5/2/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_HASH_ALGORITHM_HPP
#define XOS_CRYPTO_HASH_ALGORITHM_HPP

#include "xos/crypto/base/implement.hpp"

namespace xos {
namespace crypto {
namespace hash {

/// enun PAD
typedef uint8_t PAD;
enum {
    IPAD = 0x36,
    OPAD = 0x5c
}; /// enun PAD

/// class algorithmt
template <class TImplements = crypto::implement>
class exported algorithmt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef algorithmt derives;

    /// initialize / finalize
    virtual ssize_t initialize(const void* key, size_t keylen) {
        return -error_not_implemented;
    }
    virtual ssize_t initialize(const void* key) {
        if ((key)) {
            size_t keylen = 0;
            if ((keylen = bytes_t::count((const byte_t*)key))) {
                return this->initialize(key, keylen);
            }
        }
        return -error_failed;
    }
    virtual ssize_t initialize() {
        return this->initialize(0, 0);
    }
    virtual ssize_t finalize(void* out, size_t outsize) {
        return -error_not_implemented;
    }

    /// hash
    virtual ssize_t hash(const void* in, size_t inlen) {
        return -error_not_implemented;
    }
    virtual ssize_t hash(const void* in) {
        if ((in)) {
            size_t inlen = 0;
            if ((inlen = bytes_t::count((const byte_t*)in))) {
                return this->hash(in, inlen);
            }
        }
        return -error_failed;
    }
    virtual ssize_t hash() {
        return this->hash(0, 0);
    }
    virtual ssize_t hash_size() const {
        return -error_not_implemented;
    }

    /// merkel
    virtual ssize_t merkel(void* out, size_t outsize, const void* key, size_t keylen) {
        ssize_t size = 0;
        if ((0 < (size = hash_size())) && (out) && (size <= (outsize))) {
            ssize_t count = 0;
            if ((size == (count = finalize(out, outsize)))) {
                ssize_t amount = 0;
                if ((0 <= (amount = initialize(key, keylen)))) {
                    if ((0 <= (amount = hash(out, size)))) {
                        return finalize(out, outsize);
                    }
                }
            }
        }
        return -error_failed;
    }
    virtual ssize_t merkel(void* out, size_t outsize, const void* key) {
        ssize_t size = 0;
        if ((0 < (size = hash_size())) && (out) && (size <= (outsize))) {
            ssize_t count = 0;
            if ((size == (count = finalize(out, outsize)))) {
                ssize_t amount = 0;
                if ((0 <= (amount = initialize(key)))) {
                    if ((0 <= (amount = hash(out, size)))) {
                        return finalize(out, outsize);
                    }
                }
            }
        }
        return -error_failed;
    }
    virtual ssize_t merkel(void* out, size_t outsize) {
        ssize_t size = 0;
        if ((0 < (size = hash_size())) && (out) && (size <= (outsize))) {
            ssize_t count = 0;
            if ((size == (count = finalize(out, outsize)))) {
                ssize_t amount = 0;
                if ((0 <= (amount = initialize()))) {
                    if ((0 <= (amount = hash(out, size)))) {
                        return finalize(out, outsize);
                    }
                }
            }
        }
        return -error_failed;
    }

    /// operator(...key...)
    virtual ssize_t operator()(void* out, size_t outsize, const void* in, size_t inlen, const void* key, size_t keylen) {
        ssize_t count = 0;
        if (0 <= (count = initialize(key, keylen))) {
            if (0 <= (count = hash(in, inlen))) {
                count = finalize(out, outsize);
            }
        }
        return count;
    }
    virtual ssize_t operator()(void* out, size_t outsize, const void* in, size_t inlen, const void* key) {
        ssize_t count = 0;
        if (0 <= (count = initialize(key))) {
            if (0 <= (count = hash(in, inlen))) {
                count = finalize(out, outsize);
            }
        }
        return count;
    }
    virtual ssize_t operator()(void* out, size_t outsize, const void* in, const void* key) {
        ssize_t count = 0;
        if (0 <= (count = initialize(key))) {
            if (0 <= (count = hash(in))) {
                count = finalize(out, outsize);
            }
        }
        return count;
    }

    /// operator()
    virtual ssize_t operator()(void* out, size_t outsize, const void* in, size_t inlen) {
        ssize_t count = 0;
        if (0 <= (count = initialize())) {
            if (0 <= (count = hash(in, inlen))) {
                count = finalize(out, outsize);
            }
        }
        return count;
    }
    virtual ssize_t operator()(void* out, size_t outsize, const void* in) {
        ssize_t count = 0;
        if (0 <= (count = initialize())) {
            if (0 <= (count = hash(in))) {
                count = finalize(out, outsize);
            }
        }
        return count;
    }
    virtual ssize_t operator()(void* out, size_t outsize) {
        ssize_t count = 0;
        if (0 <= (count = initialize())) {
            if (0 <= (count = hash())) {
                count = finalize(out, outsize);
            }
        }
        return count;
    }

    /// ...size / ...min / ...max
    virtual ssize_t blocksize() const {
        return -error_not_implemented;
    }
    virtual ssize_t hashsize() const {
        return -error_not_implemented;
    }
    virtual ssize_t keysize() const {
        return -error_not_implemented;
    }
    virtual ssize_t keymin() const {
        return -error_not_implemented;
    }
    virtual ssize_t keymxn() const {
        return -error_not_implemented;
    }
}; /// class algorithmt
typedef algorithmt<> algorithm;

} /// namespace hash
} /// namespace crypto
} /// namespace xos

#endif /// ndef XOS_CRYPTO_HASH_ALGORITHM_HPP 
