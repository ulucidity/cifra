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
///   File: key.hpp
///
/// Author: $author$
///   Date: 7/6/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_ECC_CURVE25519_KEY_HPP
#define XOS_CRYPTO_ECC_CURVE25519_KEY_HPP

#include "xos/crypto/ecc/curve25519/array.hpp"

namespace xos {
namespace crypto {
namespace ecc {
namespace curve25519 {

/// class keyt
template 
<class TArray = curve25519::array, 
 class TExtends = TArray, class TImplements = typename TExtends::implements>

class exported keyt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef keyt derives; 
    
    typedef typename extends::key_size_t size_of_t;
    enum { size_of = extends::key_size };
    
    /// constructors / destructor
    keyt(const byte_t* elements, size_t length): extends(elements, length) {
    }
    keyt(const keyt& copy): extends(copy) {
    }
    keyt() {
    }
    virtual ~keyt() {
    }
}; /// class keyt
typedef keyt<> key;

} /// namespace curve25519
} /// namespace ecc
} /// namespace crypto
} /// namespace xos

#endif /// ndef XOS_CRYPTO_ECC_CURVE25519_KEY_HPP
