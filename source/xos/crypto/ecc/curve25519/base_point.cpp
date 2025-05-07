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
///   File: base_point.cpp
///
/// Author: $author$
///   Date: 7/6/2022
///////////////////////////////////////////////////////////////////////
#include "xos/crypto/ecc/curve25519/base_point.hpp"

#if !defined(XOS_CRYPTO_ECC_CURVE25519_BASE_POINT_INSTANCE)
///#define XOS_CRYPTO_ECC_CURVE25519_BASE_POINT_INSTANCE
#endif /// !defined(XOS_CRYPTO_ECC_CURVE25519_BASE_POINT_INSTANCE)

namespace xos {
namespace crypto {
namespace ecc {
namespace curve25519 {

///  Class: base_pointt
#if defined(XOS_CRYPTO_ECC_CURVE25519_BASE_POINT_INSTANCE)
static base_point the_base_point;
#endif /// defined(XOS_CRYPTO_ECC_CURVE25519_BASE_POINT_INSTANCE)


} /// namespace curve25519
} /// namespace ecc
} /// namespace crypto
} /// namespace xos
