///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
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
///   File: sha256.hpp
///
/// Author: $author$
///   Date: 3/12/2022, 6/20/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_HASH_OPENSSL_SHA256_HPP
#define XOS_CRYPTO_HASH_OPENSSL_SHA256_HPP

#include "xos/crypto/hash/sha256.hpp"

namespace xos {
namespace crypto {
namespace hash {
namespace openssl {

/// class sha256
class exported sha256: virtual public hash::sha256::implements, public hash::sha256 {
public:
    typedef hash::sha256::implements implements;
    typedef hash::sha256 extends;
    typedef sha256 derives;

    /// constructor / destructor
    sha256(void* out, size_t outsize, const void* in, size_t inlen, const void* key, size_t keylen) {
        if (0 > (this->operator()(out, outsize, in, inlen, key, keylen))) {
            throw crypto::exception(error_failed);
        }
    }
    sha256(void* out, size_t outsize, const void* in, size_t inlen) {
        if (0 > (this->operator()(out, outsize, in, inlen))) {
            throw crypto::exception(error_failed);
        }
    }
    sha256(const sha256& copy): extends(copy) {
    }
    sha256() {
    }
    virtual ~sha256() {
    }

protected:
    /// initial / final / transform / update
    virtual void initial();
    virtual void final();
    virtual void transform();
    virtual void update(const uint8_t* in, size_t inlen);

protected:
    static uint32_t m_K[KONSTSIZE];
}; /// class sha256

} /// namespace openssl
} /// namespace hash
} /// namespace crypto
} /// namespace xos

#endif /// ndef XOS_CRYPTO_HASH_OPENSSL_SHA256_HPP
