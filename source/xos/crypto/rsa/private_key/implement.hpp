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
///   File: implement.hpp
///
/// Author: $author$
///   Date: 4/13/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RSA_PRIVATE_KEY_IMPLEMENT_HPP
#define XOS_CRYPTO_RSA_PRIVATE_KEY_IMPLEMENT_HPP

#include "xos/crypto/rsa/key/implement.hpp"

namespace xos {
namespace crypto {
namespace rsa {
namespace private_key {

/// class implementt
template <class TImplements = crypto::rsa::key::implement>
class exported implementt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef implementt derives; 
    
    /// constructors / destructor
    virtual ~implementt() {
    }
}; /// class implementt
typedef implementt<> implement;

} /// namespace private_key
} /// namespace rsa
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RSA_PRIVATE_KEY_IMPLEMENT_HPP
