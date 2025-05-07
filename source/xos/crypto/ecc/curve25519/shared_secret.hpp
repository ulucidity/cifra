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
///   File: shared_secret.hpp
///
/// Author: $author$
///   Date: 7/6/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_ECC_CURVE25519_SHARED_SECRET_HPP
#define XOS_CRYPTO_ECC_CURVE25519_SHARED_SECRET_HPP

#include "xos/crypto/ecc/curve25519/public_key.hpp"
#include "xos/crypto/ecc/curve25519/private_key.hpp"

namespace xos {
namespace crypto {
namespace ecc {
namespace curve25519 {

/// class shared_secrett
template 
<class TPublicKey = curve25519::public_key, class TExtends = TPublicKey, class TImplements = typename TExtends::implements>

class exported shared_secrett: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef shared_secrett derives; 
    
    /// constructors / destructor
    shared_secrett(const private_key& from_private, const public_key& from_public) {
        construct(from_private, from_public);
    }
    shared_secrett(const shared_secrett& copy): extends(copy) {
    }
    shared_secrett() {
    }
    virtual ~shared_secrett() {
    }
private:
    void construct(const private_key& from_private, const public_key& from_public) {
        if (!(generate(from_private, from_public))) {
            LOGGER_IS_LOGGED_ERROR("...failed on generate(from_private, from_public) throw exception(exception_failed)...");
            throw exception(exception_failed);
        }
    }

public:
    /// generate
    virtual bool generate(const private_key& from_private, const public_key& from_public) {
        return from_public.generate(*this, from_private, from_public);
    }

}; /// class shared_secrett
typedef shared_secrett<> shared_secret;

} /// namespace curve25519
} /// namespace ecc
} /// namespace crypto
} /// namespace xos

#endif /// ndef XOS_CRYPTO_ECC_CURVE25519_SHARED_SECRET_HPP
