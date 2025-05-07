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
///   Date: 4/22/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RANDOM_NUMBER_READER_HPP
#define XOS_CRYPTO_RANDOM_NUMBER_READER_HPP

#include "xos/crypto/random/reader.hpp"

namespace xos {
namespace crypto {
namespace random {
namespace number {

/// class readert
template 
<class TReaderImplements = xos::crypto::implement, class TReaderObserver = TReaderImplements, 
 class TRandomReader = xos::crypto::random::reader, class TImplements = TReaderImplements>

class exported readert: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef readert derives; 
    
    typedef TRandomReader random_reader_t;
    typedef TReaderObserver reader_observer_t;

    /// constructors / destructor
    virtual ~readert() {
    }

    /// read...
    virtual ssize_t read(byte_t* bytes, size_t size, random_reader_t& random) {
        byte_t byte = 0;
        if ((bytes) && (size)) {
            for (size_t i=0; i<size; ++i) {
                if (0 >= (this->get(byte, random))) {
                    return 0;
                }
                bytes[i] = byte;
            }
        }
        return size;
    }

    /// get
    virtual ssize_t get(byte_t& byte, random_reader_t& random) {
        ssize_t count = 0;
        if ((no_remove_zeros())) {
            count = random.read(&byte, 1);
        } else {
            do {
                if (0 >= (count = random.read(&byte, 1))) {
                    return count;
                }
            } while (!(byte & 0xF) || !(byte & 0xF0));
        }
        return count;
    }
    
    /// Get
    virtual ssize_t Get(BYTE& byte, random_reader_t& random) {
        return this->get(byte, random);
    }

    /// no_remove_zeros
    virtual bool no_remove_zeros() const {
        return false;
    }
}; /// class readert
typedef readert<> reader;

} /// namespace number
} /// namespace random
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RANDOM_NUMBER_READER_HPP
