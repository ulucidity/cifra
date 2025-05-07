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
///   File: sha256.cpp
///
/// Author: $author$
///   Date: 3/12/2022, 6/20/2022
///////////////////////////////////////////////////////////////////////
#include "xos/crypto/hash/sha256.hpp"

#if !defined(XOS_CRYPTO_HASH_SHA256_INSTANCE)
///#define XOS_CRYPTO_HASH_SHA256_INSTANCE
#endif /// !defined(XOS_CRYPTO_HASH_SHA256_INSTANCE)

namespace xos {
namespace crypto {
namespace hash {

///  Class: sha256t
#if defined(XOS_CRYPTO_HASH_SHA256_INSTANCE)
static sha256 the_sha256;
#endif /// defined(XOS_CRYPTO_HASH_SHA256_INSTANCE)

} /// namespace hash
} /// namespace crypto
} /// namespace xos
