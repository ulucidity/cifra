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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 4/22/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RANDOM_PRIME_BN_READER_HPP
#define XOS_CRYPTO_RANDOM_PRIME_BN_READER_HPP

#include "xos/crypto/random/prime/bn/license.hpp"
#include "xos/crypto/random/prime/reader.hpp"
#include "xos/crypto/random/prime/bn/number.hpp"

namespace xos {
namespace crypto {
namespace random {
namespace prime {
namespace bn {

/// class readert
template 
<class TNumber = xos::crypto::random::prime::bn::number,
 class TReaderImplement = xos::crypto::random::prime::readert<BIGPRIME>, 
 class TReaderObserver = typename TReaderImplement::observer,
 class TRandomReader = xos::crypto::random::reader,
 class TExtends = xos::crypto::extend, class TImplements = TReaderImplement>

class exported readert: virtual public TReaderObserver, virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements, implements;
    typedef TExtends Extends, extends;
    typedef readert Derives, derives; 
    
    typedef TNumber number_t;
    typedef TReaderImplement reader_implement_t;
    typedef TReaderObserver reader_observer_t;
    typedef TRandomReader random_reader_t;

    /// constructors / destructor
    readert(reader_observer_t* observer): m_observer(observer) {
    }
    readert(): m_observer(0) {
    }
    virtual ~readert() {
    }
private:
    readert(const readert& copy): extends(copy) {
        LOGGER_LOG_ERROR("...unexpected throwing exception exception_unexpected...");
        throw exception(exception_unexpected);
    }
public:

    /// read_msb
    virtual ssize_t read_msb(number_t& n, size_t bytes, random_reader_t& random) {
        BIGPRIME* detached = 0;
        if ((detached = n.attached_to())) {
            LOGGER_LOG_TRACE("read_msb(detached, bytes = " << unsigned_to_string(bytes) << ", random)...");            
            return read_msb(detached, bytes, random);
        }
        return 0;
    }
    virtual ssize_t read_msb(BIGPRIME* n, size_t bytes, random_reader_t& random) {
        byte_t byte = 0;
        BN_set_word(n, 0);
        for (size_t i=0; i<bytes; i++) {
            if (0 >= (this->get(byte, random))) {
                return 0;
            }
            BN_lshift(n,n,8);
            BN_add_word(n,byte);
        }
        bytes = this->on_read(n, bytes);
        return bytes;
    }

    /// observer_delegated
    virtual reader_observer_t* observer_delegated(BIGPRIME* n) const {
        return m_observer;
    }

protected:
    reader_observer_t* m_observer;
}; /// class readert
typedef readert<> reader;

} /// namespace bn
} /// namespace prime
} /// namespace random
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RANDOM_PRIME_BN_READER_HPP
