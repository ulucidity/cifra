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
///   File: base_point.hpp
///
/// Author: $author$
///   Date: 7/6/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_ECC_CURVE25519_BASE_POINT_HPP
#define XOS_CRYPTO_ECC_CURVE25519_BASE_POINT_HPP

#include "xos/crypto/ecc/curve25519/key.hpp"

#define XOS_CRYPTO_ECC_CURVE25519_BASE_POINT_VALUE 9

namespace xos {
namespace crypto {
namespace ecc {
namespace curve25519 {

/// enum base_point_value_t
typedef byte_t base_point_value_t;
enum {
    base_point_value = XOS_CRYPTO_ECC_CURVE25519_BASE_POINT_VALUE
}; /// enum base_point_value_t

/// class base_pointt
template 
<typename TValue = curve25519::base_point_value_t, TValue VValue = curve25519::base_point_value,
 class TKey = curve25519::key, class TExtends = TKey, class TImplements = typename TExtends::implements>

class exported base_pointt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef base_pointt derives; 
    
    typedef TValue value_t;
    enum { value = VValue };
    
    /// constructors / destructor
    base_pointt(const base_pointt& copy): extends(copy) {
    }
    base_pointt() {
        construct();
    }
    virtual ~base_pointt() {
    }
private:
    void construct() {
        byte_t& b = this->operator[](0);
        b = value;
    }

}; /// class base_pointt
typedef base_pointt<> base_point;

} /// namespace curve25519
} /// namespace ecc
} /// namespace crypto
} /// namespace xos

#endif /// ndef XOS_CRYPTO_ECC_CURVE25519_BASE_POINT_HPP
