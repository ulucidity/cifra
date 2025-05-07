///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
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
///   Date: 2/1/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_CIPHER_DES3_IMPLEMENT_HPP
#define XOS_CRYPTO_CIPHER_DES3_IMPLEMENT_HPP

#include "xos/crypto/cipher/des/implement.hpp"

#define XOS_CRYPTO_CIPHER_DES3_NAME "des3"

namespace xos {
namespace crypto {
namespace cipher {
namespace des3 {

enum {
    BLOCKSIZE = des::BLOCKSIZE,

    KEYMIN    = des::KEYMIN*3,
    KEYMAX    = des::KEYMAX*3,
    KEYINC    = des::KEYINC*3,
    KEYSIZE   = des::KEYSIZE*3,

    IVMIN     = des::IVMIN,
    IVMAX     = des::IVMAX,
    IVINC     = des::IVINC,
    IVSIZE    = des::IVSIZE
};

/// class implementt
template <class TImplements = des::implement>
class exported implementt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef implementt derives; 
    
    /// key_size...
    virtual ssize_t key_size_min() const {
        return KEYMIN;
    }
    virtual ssize_t key_size_max() const {
        return KEYMAX;
    }
    virtual ssize_t key_size_inc() const {
        return KEYINC;
    }
    virtual ssize_t key_size() const {
        return KEYSIZE;
    }

    /// iv_size...
    virtual ssize_t iv_size_min() const {
        return IVMIN;
    }
    virtual ssize_t iv_size_max() const {
        return IVMAX;
    }
    virtual ssize_t iv_size_inc() const {
        return IVINC;
    }
    virtual ssize_t iv_size() const {
        return IVSIZE;
    }

    /// ...block...
    virtual ssize_t block_size() const {
        return BLOCKSIZE;
    }

    /// name
    virtual const char* name() const {
        return XOS_CRYPTO_CIPHER_DES3_NAME;
    }
}; /// class implementt
typedef implementt<> implement;

} /// namespace des3
} /// namespace cipher
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_CIPHER_DES3_IMPLEMENT_HPP
