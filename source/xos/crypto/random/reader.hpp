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
#ifndef XOS_CRYPTO_RANDOM_READER_HPP
#define XOS_CRYPTO_RANDOM_READER_HPP

#include "xos/crypto/base.hpp"

namespace xos {
namespace crypto {
namespace random {

/// class readert
template <class TImplements = xos::crypto::implement>
class exported readert: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef readert derives; 
    
    /// class observer
    class exported observer: virtual public xos::implement {
    public:
        typedef xos::implement implements;
        typedef observer derives; 
        
        /// constructors / destructor
        virtual ~observer() {
        }

        /// on_read
        virtual ssize_t on_read(byte_t* bytes, size_t size) {
            observer* delegated = observer_delegated();
            if ((delegated)) {
                return delegated->on_read(bytes, size);
            }
            return 0;
        }
        virtual observer* observer_delegated() const {
            return 0;
        }

        /// OnRead
        virtual ssize_t OnRead(BYTE* bytes, size_t size) {
            observer* delegated = ObserverDelegated();
            if ((delegated)) {
                return delegated->OnRead(bytes, size);
            }
            return this->on_read(bytes, size);
        }
        virtual observer* ObserverDelegated() const {
            return 0;
        }
    }; /// class observer

    /// constructors / destructor
    virtual ~readert() {
    }

    /// read
    virtual ssize_t read(byte_t* bytes, size_t size) {
        return 0;
    }
    
    /// Read
    virtual ssize_t Read(BYTE* bytes, size_t size) {
        return this->read(bytes, size);
    }

}; /// class readert
typedef readert<> reader;

} /// namespace random
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RANDOM_READER_HPP
