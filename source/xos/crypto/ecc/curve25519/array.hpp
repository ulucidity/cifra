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
///   File: array.hpp
///
/// Author: $author$
///   Date: 7/6/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_ECC_CURVE25519_ARRAY_HPP
#define XOS_CRYPTO_ECC_CURVE25519_ARRAY_HPP

#include "xos/crypto/base/extend.hpp"
#include "xos/base/array.hpp"

#define XOS_CRYPTO_ECC_CURVE25519_KEY_SIZE 32

namespace xos {
namespace crypto {
namespace ecc {
namespace curve25519 {

/// enum key_size_t
typedef byte_t key_size_t;
enum {
    key_size = XOS_CRYPTO_ECC_CURVE25519_KEY_SIZE
}; /// enum key_size_t

/// class arrayt
template 
<typename TKeySize = curve25519::key_size_t, TKeySize VKeySize = curve25519::key_size,
 class TCryptoImplement = xos::crypto::implementt<xos::logged>,
 class TCryptoExtend = xos::crypto::extendt<TCryptoImplement, xos::extended::logged>,
 class TArray = xos::arrayt<byte_t, VKeySize, TCryptoExtend, TCryptoImplement>, 
 class TExtends = TArray, class TImplements = typename TExtends::implements>

class exported arrayt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef arrayt derives; 
    
    typedef TKeySize key_size_t;
    enum { key_size = VKeySize };
    
    /// constructors / destructor
    arrayt(const byte_t* elements, size_t length) {
        construct(elements, length);
    }
    arrayt(const arrayt& copy): extends(copy) {
    }
    arrayt() {
        construct();
    }
    virtual ~arrayt() {
        destruct();
    }
private:
    void construct(const byte_t* elements, size_t length) {
        this->set_length(key_size);
        this->zero();
        if ((elements) && (key_size == length)) {
            byte_t* bytes = 0;
            if ((bytes = this->elements(length)) && (key_size == length)) {
                memcpy(bytes, elements, key_size);
            }
        }
    }
    void construct() {
        this->set_length(key_size);
        this->zero();
    }
    void destruct() {
        this->zero();
    }

public:
    /// zero
    virtual derives& zero() {
        byte_t& b = this->operator[](0);
        ::memset(&b, 0, key_size);
        return *this;
    }

    /// operator[]
    virtual byte_t& operator[](size_t index) const {
        byte_t* b = 0;
        if ((key_size != (this->size())) || (key_size != (this->length())) || (!(b = this->elements()))) {
            LOGGER_IS_LOGGED_ERROR("...unexpected condition throw (error_failed)...");
            throw (error_failed);
        } else {
            if (index >= key_size) {
                LOGGER_IS_LOGGED_ERROR("...index [" << index << "] out of range throw (error_failed)...");
                throw (error_failed);
            }
        }
        return b[index];
    }
    
}; /// class arrayt
typedef arrayt<> array;

} /// namespace curve25519
} /// namespace ecc
} /// namespace crypto
} /// namespace xos

#endif /// ndef XOS_CRYPTO_ECC_CURVE25519_ARRAY_HPP
