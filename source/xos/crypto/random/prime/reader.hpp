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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 4/21/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RANDOM_PRIME_READER_HPP
#define XOS_CRYPTO_RANDOM_PRIME_READER_HPP

#include "xos/crypto/random/number/reader.hpp"

namespace xos {
namespace crypto {
namespace random {
namespace prime {

/// class readert
template 
<typename TBIGPRIME, 
 class TReaderImplements = xos::crypto::random::number::reader, 
 class TReaderObserver = typename TReaderImplements::reader_observer_t, 
 class TRandomReader = xos::crypto::random::reader, class TImplements = TReaderImplements>

class exported readert: virtual public TImplements {
public:
    typedef TImplements Implements, implements;
    typedef readert Derives, derives; 
    
    typedef TBIGPRIME BIGPRIME;
    typedef TReaderObserver reader_observer_t;
    typedef TRandomReader random_reader_t;

    /// class observer
    class exported observer: virtual public reader_observer_t {
    public:
        typedef reader_observer_t Implements, implements;
        typedef observer Derives, derives; 
        
        /// constructors / destructor
        virtual ~observer() {
        }

        /// ...read / ...delegated
        virtual ssize_t on_read(BIGPRIME* n, size_t bytes) {
            observer* delegated = observer_delegated(n);
            if ((delegated)) {
                return delegated->on_read(n, bytes);
            }
            return bytes;
        }
        virtual observer* observer_delegated(BIGPRIME* n) const {
            return 0;
        }

        /// ...Read / ...Delegated
        virtual ssize_t OnRead(BIGPRIME* n, size_t bytes) {
            observer* delegated = ObserverDelegated(n);
            if ((delegated)) {
                return delegated->OnRead(n, bytes);
            }
            bytes = this->on_read(n, bytes);
            return bytes;
        }
        virtual observer* ObserverDelegated(BIGPRIME* n) const {
            return 0;
        }
    }; /// class observer

    /// constructors / destructor
    virtual ~readert() {
    }

    /// read...
    virtual ssize_t read_msb(BIGPRIME* n, size_t bytes, random_reader_t& random) {
        return 0;
    }
    virtual ssize_t ReadMSB(BIGPRIME* n, size_t bytes, random_reader_t& random) {
        return this->read_msb(n, bytes, random);
    }

}; /// class readert

} /// namespace prime
} /// namespace random
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RANDOM_PRIME_READER_HPP
