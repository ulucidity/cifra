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
///   File: private_key.hpp
///
/// Author: $author$
///   Date: 7/6/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_ECC_CURVE25519_PRIVATE_KEY_HPP
#define XOS_CRYPTO_ECC_CURVE25519_PRIVATE_KEY_HPP

#include "xos/crypto/ecc/curve25519/key.hpp"
#include "xos/crypto/random/generator.hpp"

#define XOS_CRYPTO_ECC_CURVE25519_PRIVATE_KEY_MASK_BEGIN 248
#define XOS_CRYPTO_ECC_CURVE25519_PRIVATE_KEY_MASK_END 127
#define XOS_CRYPTO_ECC_CURVE25519_PRIVATE_KEY_BITS_END 64

namespace xos {
namespace crypto {
namespace ecc {
namespace curve25519 {

/// class private_keyt
template 
<class TRandomGenerator = crypto::random::generator,
 class TKey = curve25519::key, class TExtends = TKey, class TImplements = typename TExtends::implements>

class exported private_keyt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef private_keyt derives; 
    
    typedef TRandomGenerator random_generator_t;
    
    /// constructors / destructor
    private_keyt(const byte_t* elements, size_t length): extends(elements, length) {
    }
    private_keyt(random_generator_t &r) {
        construct(r);
    }
    private_keyt(const private_keyt& copy): extends(copy) {
    }
    private_keyt() {
    }
    virtual ~private_keyt() {
    }
private:
    void construct(random_generator_t &r) {
        byte_t* b = &(this->operator[](0));
        size_t size = this->size();
        if (size == (r.generate(b, size))) {
            b[0] &= XOS_CRYPTO_ECC_CURVE25519_PRIVATE_KEY_MASK_BEGIN;
            b[size-1] &= XOS_CRYPTO_ECC_CURVE25519_PRIVATE_KEY_MASK_END;
            b[size-1] |= XOS_CRYPTO_ECC_CURVE25519_PRIVATE_KEY_BITS_END;
        } else {
            LOGGER_IS_LOGGED_ERROR("(size != (r.generate(b, size))) throw exception(exception_unexpected)...");
            throw exception(exception_unexpected);
        }
    }
    
}; /// class private_keyt
typedef private_keyt<> private_key;

} /// namespace curve25519
} /// namespace ecc
} /// namespace crypto
} /// namespace xos

#endif /// ndef XOS_CRYPTO_ECC_CURVE25519_PRIVATE_KEY_HPP
