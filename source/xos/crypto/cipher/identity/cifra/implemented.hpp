//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2024 $organization$
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
///   File: implemented.hpp
///
/// Author: $author$
///   Date: 9/11/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_CIPHER_IDENTITY_CIFRA_IMPLEMENTED_HPP
#define XOS_CRYPTO_CIPHER_IDENTITY_CIFRA_IMPLEMENTED_HPP

#include "xos/crypto/cipher/identity/extend.hpp"

namespace xos {
namespace crypto {
namespace cipher {
namespace identity {
namespace cifra {

//////////////////////////////////////////////////////////////////////////
/// class implemented
class exported implemented: virtual public ::xos::crypto::cipher::identity::extend::implements, public ::xos::crypto::cipher::identity::extend {
public:
    typedef ::xos::crypto::cipher::identity::extend::implements implements;
    typedef ::xos::crypto::cipher::identity::extend extends;
    typedef implemented derives; 
    
    //////////////////////////////////////////////////////////////////////////
    /// constructors / destructor
    implemented() {
        clear();
        if (0 > (initialize())) {
            LOGGER_LOG_ERROR("...failed on initialize() throw (error_failed)...");
            throw (error_failed);
        }
    }
    virtual ~implemented() {
        clear();
    }
private:
    implemented(const implemented& copy) {
    }
public:

    //////////////////////////////////////////////////////////////////////////
    using implements::initialize;
    virtual ssize_t initialize
    (const void* key = 0, size_t keylen = 0, 
     const void* iv = 0, size_t ivlen = 0, const void* padd = 0, size_t paddlen = 0);
    virtual void clear();

    //////////////////////////////////////////////////////////////////////////
    virtual ssize_t encrypt(void* out, size_t outsize, const void* in, size_t inlen);
    virtual ssize_t decrypt(void* out, size_t outsize, const void* in, size_t inlen);

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class implemented

} /// namespace cifra 
} /// namespace identity 
} /// namespace cipher 
} /// namespace crypto 
} /// namespace xos 

#endif /// ndef XOS_CRYPTO_CIPHER_IDENTITY_CIFRA_IMPLEMENTED_HPP
