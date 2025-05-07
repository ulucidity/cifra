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
///   Date: 4/24/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_ARRAY_HPP
#define XOS_CRYPTO_ARRAY_HPP

#include "xos/base/array.hpp"

namespace xos {
namespace crypto {

/// class arrayt
template 
<typename TUnsignedValue = uint64_t,
 class TExtends = xos::byte_array, class TImplements = typename TExtends::implements>

class exported arrayt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements, implements;
    typedef TExtends Extends, extends;
    typedef arrayt Derives, derives; 
    
    typedef TUnsignedValue unsigned_value_t;
    
    /// constructors / destructor
    arrayt(const arrayt& copy): extends(copy) {
    }
    arrayt(const unsigned_value_t& value, size_t size, size_t length): extends(size) {
        this->set_length(0);
        this->append(value, size, length);
    }
    arrayt(const unsigned_value_t& value, size_t size): extends(size) {
        this->set_length(0);
        this->append(value, size, 1);
    }
    arrayt(size_t size): extends(size) {
    }
    arrayt() {
    }
    virtual ~arrayt() {
    }

    /// append...
    using Extends::append;
    virtual size_t append(const unsigned_value_t& value, size_t size, size_t length) {
        size_t count = 0;
        for (size_t amount = 0; length; --length, count += amount) {
            amount = append_msb(value, size);
        }
        return count;
    }
    virtual size_t append_msb(const unsigned_value_t& value, size_t size) {
        unsigned_value_t msb = value, lsb = 0;
        size_t i = 0;
        byte_t b = 0;
        for (i = 0; i < size; ++i, msb >>= 8) {
            (lsb <<= 8) |= (msb & 255);
        }
        return append_lsb(lsb, size);
    }
    virtual size_t append_lsb(const unsigned_value_t& value, size_t size) {
        unsigned_value_t lsb = value;
        size_t i = 0;
        byte_t b = 0;
        for (i = 0; i < size; ++i, lsb >>= 8) {
            b = (lsb & 255);
            this->append(&b, 1);
        }
        return size;
    }

}; /// class arrayt
typedef arrayt<> array;

} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_ARRAY_HPP
