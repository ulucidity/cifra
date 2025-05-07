///////////////////////////////////////////////////////////////////////
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
///   File: number.hpp
///
/// Author: $author$
///   Date: 4/22/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RANDOM_PRIME_BN_NUMBER_HPP
#define XOS_CRYPTO_RANDOM_PRIME_BN_NUMBER_HPP

#include "xos/crypto/random/prime/bn/license.hpp"
#include "xos/crypto/base.hpp"
#include "xos/base/created.hpp"
#include "xos/base/attached.hpp"
#include "bn_msb.h"

namespace xos {
namespace crypto {
namespace random {
namespace prime {
namespace bn {

typedef BIGNUM BIGPRIME;
typedef BIGNUM* BIGINT;

typedef BIGNUM* number_attached_t;
typedef int number_unattached_t;
enum { number_unattached = 0 };

/// class number_implementt
template <class TImplements = xos::crypto::implement>
class exported number_implementt: virtual public TImplements {
public:
    typedef TImplements Implements, implements;
    typedef number_implementt Derives, derives; 
    
    /// constructors / destructor
    virtual ~number_implementt() {
    }

    /// BN...free
    virtual bool BN_CTX_free(BN_CTX*& a) {
        if ((a)) {
            ::BN_CTX_free(a);
            a = 0;
            return true;
        }
        return false;
    }
    virtual bool BN_free(BIGNUM*& a) {
        if ((a)) {
            ::BN_free(a);
            a = 0;
            return true;
        }
        return false;
    }
}; /// class number_implementt
typedef number_implementt<> number_implement;

/// class number_extendt
template 
<class TExtends = xos::crypto::extend, 
 class TImplements = xos::crypto::random::prime::bn::number_implement>

class exported number_extendt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements, implements;
    typedef TExtends Extends, extends;
    typedef number_extendt Derives, derives; 
    
    /// constructors / destructor
    number_extendt(const number_extendt& copy) {
    }
    number_extendt() {
    }
    virtual ~number_extendt() {
    }

}; /// class number_extendt
typedef number_extendt<> number_extend;

/// class numbert
template 
<class TNumberImplement = xos::crypto::random::prime::bn::number_implement, 
 class TNumberExtend = xos::crypto::random::prime::bn::number_extend,
 class TImplements = xos::creatort<TNumberImplement>, 
 class TExtends = xos::createdt
 <number_attached_t, number_unattached_t, number_unattached, TImplements, TNumberExtend> >

class exported numbert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements, implements;
    typedef TExtends Extends, extends;
    typedef numbert Derives, derives; 
    
    typedef TNumberImplement number_implement_t;
    typedef TNumberExtend number_extend_t;
    
    /// constructors / destructor
    numbert(const unsigned& value) {
        if (!(this->create(value))) {
            LOGGER_LOG_ERROR("...failed on create() throwing create_exception create_failed...");
            throw (create_exception(create_failed));
        }
    }
    numbert() {
        if (!(this->create(0))) {
            LOGGER_LOG_ERROR("...failed on create() throwing create_exception create_failed...");
            throw (create_exception(create_failed));
        }
    }
    virtual ~numbert() {
        if (!(this->destroyed())) {
            LOGGER_LOG_ERROR("...failed on destroyed() throwing create_exception destroy_failed...");
            throw (create_exception(destroy_failed));
        }
    }
private:
    numbert(const numbert& copy) {
        LOGGER_LOG_ERROR("...unexpected throwing exception exception_unexpected...");
        throw exception(exception_unexpected);
    }
public:

    /// ...msb
    virtual ssize_t from_msb(const byte_t* from, unsigned bytes) {
        ssize_t size = 0;
        if ((from) && (bytes)) {
            BIGNUM* detached = 0;
            if ((detached = this->attached_to())) {
                LOGGER_LOG_TRACE("BN_set_msb(detached, from, bytes = " << unsigned_to_string(bytes) << ")...");
                BN_set_msb(detached, from, bytes);
                size = bytes;
            }
        }
        return size;
    }
    virtual ssize_t to_msb(byte_t* to, unsigned bytes) const {
        ssize_t size = 0;
        if ((to) && (bytes)) {
            BIGNUM* detached = 0;
            if ((detached = this->attached_to())) {
                LOGGER_LOG_TRACE("BN_get_msb(detached, from, bytes = " << unsigned_to_string(bytes) << ")...");
                BN_get_msb(detached, to, bytes);
                size = bytes;
            }
        }
        return size;
    }
    
    /// ...MSB
    virtual ssize_t FromMSB(const byte_t* from, unsigned bytes) {
        ssize_t size = this->from_msb(from, bytes);
        return size;
    }
    virtual ssize_t ToMSB(byte_t* to, unsigned bytes) const {
        ssize_t size = this->to_msb(to, bytes);
        return size;
    }

    /// operator BIGNUM*
    virtual operator BIGNUM* () const {
        return this->attached_to();
    }

protected:
    /// create / destroy
    virtual bool create(unsigned value) {
        BIGNUM* detached = 0;
        if ((detached = BN_new())) {
            this->attach_created(detached);
            BN_set_word(detached, value);
            return true;
        }
        return false;
    }
    virtual bool destroy() {
        BIGNUM* detached = 0;
        if ((detached = this->detach())) {
            BN_free(detached);
            return true;
        }
        return false;
    }
}; /// class numbert
typedef numbert<> number;

} /// namespace bn
} /// namespace prime
} /// namespace random
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RANDOM_PRIME_BN_NUMBER_HPP
