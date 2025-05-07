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
///   File: generator.hpp
///
/// Author: $author$
///   Date: 4/21/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RANDOM_NUMBER_GENERATOR_HPP
#define XOS_CRYPTO_RANDOM_NUMBER_GENERATOR_HPP

#include "xos/crypto/random/reader.hpp"

namespace xos {
namespace crypto {
namespace random {
namespace number {

/// class generatort
template <class TImplements = xos::crypto::random::reader>
class exported generatort: virtual public TImplements {
public:
    typedef TImplements Implements, implements;
    typedef generatort Derives, derives; 
    
    /// constructors / destructor
    virtual ~generatort() {
    }

    /// generate / read
    virtual ssize_t generate(void* out, size_t size) {
        return 0;
    }
    virtual ssize_t read(byte_t* bytes, size_t size) {
        return this->generate(bytes, size);
    }

}; /// class generatort
typedef generatort<> generator;

} /// namespace number
} /// namespace random
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RANDOM_NUMBER_GENERATOR_HPP
