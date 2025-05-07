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
#ifndef XOS_CRYPTO_HASH_OPENSSL_SHA1_HPP
#define XOS_CRYPTO_HASH_OPENSSL_SHA1_HPP

#include "xos/crypto/hash/sha1.hpp"

namespace xos {
namespace crypto {
namespace hash {
namespace openssl {

/// class sha1
class exported sha1: virtual public hash::sha1::implements, public hash::sha1 {
public:
    typedef hash::sha1::implements implements;
    typedef hash::sha1 extends;
    typedef sha1 derives;

    /// constructor / destructor
    sha1(void* out, size_t outsize, const void* in, size_t inlen) {
        if (0 > (this->operator()(out, outsize, in, inlen))) {
            throw crypto::exception(error_failed);
        }
    }
    sha1(const sha1& copy): extends(copy) {
    }
    sha1() {
    }
    virtual ~sha1() {
    }

protected:
    /// initial / final / transform / update
    virtual void initial();
    virtual void final();
    virtual void transform();
    virtual void update(const uint8_t* in, size_t inlen);
}; /// class sha1

} /// namespace openssl
} /// namespace hash
} /// namespace crypto
} /// namespace xos

#endif /// ndef XOS_CRYPTO_HASH_OPENSSL_SHA1_HPP 
