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
///   File: extend.hpp
///
/// Author: $author$
///   Date: 4/13/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RSA_PUBLIC_KEY_EXTEND_HPP
#define XOS_CRYPTO_RSA_PUBLIC_KEY_EXTEND_HPP

#include "xos/crypto/rsa/key/extend.hpp"

namespace xos {
namespace crypto {
namespace rsa {
namespace public_key {

/// class extendt
template 
<class TExtends = crypto::rsa::key::extend, class TImplements = typename TExtends::implements>

class exported extendt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef extendt derives; 
    
    /// constructors / destructor
    extendt
    (const byte_t* modulus, size_t modbytes, 
     const byte_t* exponent, size_t expbytes) {
        if (!(this->create_msb(modulus, modbytes, exponent, expbytes))) {
            throw (create_exception(create_failed));
        }
    }
    extendt(size_t modbytes, size_t expbytes) {
        if (!(this->create(modbytes, expbytes))) {
            throw (create_exception(create_failed));
        }
    }
    extendt() {
    }
    virtual ~extendt() {
        if (!(this->destroyed())) {
            throw (create_exception(destroy_failed));
        }
    }
private:
    extendt(const extendt& copy) {
        throw exception(exception_unexpected);
    }
public:

}; /// class extendt
typedef extendt<> extend;

} /// namespace public_key
} /// namespace rsa
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RSA_PUBLIC_KEY_EXTEND_HPP
