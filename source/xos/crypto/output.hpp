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
///   File: output.hpp
///
/// Author: $author$
///   Date: 4/14/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_OUTPUT_HPP
#define XOS_CRYPTO_OUTPUT_HPP

#include "xos/console/output.hpp"
#include "xos/base/array.hpp"

namespace xos {
namespace crypto {

/// class outputt
template 
<class TExtendsOutput = xos::extended::output, 
 class TExtends = TExtendsOutput, class TImplements = typename TExtends::implements>

class exported outputt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef outputt derives; 
    
    typedef xos::byte_array byte_array_t;
    typedef typename extends::output_t output_t;
    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };

    typedef char_t what_t;
    typedef char_t sized_t;

    /// constructors / destructor
    outputt(const outputt& copy): output_hex_(0), output_hex_x_(0) {
    }
    outputt(): output_hex_(0), output_hex_x_(0) {
    }
    virtual ~outputt() {
    }

    /// ...output_hex
    virtual ssize_t output_hex(const byte_array_t &array) {
        ssize_t count = 0;
        size_t length = 0;
        const byte_t *bytes = 0;
        
        if ((bytes = array.elements(length))) {
            count = this->output_hex(bytes, length);
        }
        return count;
    }
    ssize_t (derives::*output_hex_)(const void* out, size_t len);
    virtual ssize_t output_hex(const void* out, size_t len) {
        ssize_t count = 0;
        if (output_hex_) {
            count = (this->*output_hex_)(out, len);
        } else {
            count = default_output_hex(out, len);
        }
        return count;
    }
protected:
    virtual ssize_t default_output_hex(const void* out, size_t len) {
        ssize_t count = 0;
        const byte_t *bytes = 0;

        if ((bytes = ((const byte_t*)out)) && (len)) {
            size_t cols = 32, col = 0;
            ssize_t amount = 0;
            const char_t& nextln = this->nextln();

            for (col = 0; len; --len, ++bytes, ++col) {
                if (cols <= (col)) {
                    if (0 < (amount = this->outln(&nextln, 1))) {
                        count += amount;
                    }
                    col = 0;
                }
                if (0 < (amount = this->output_hex_x(bytes, 1))) {
                    count += amount;
                }
            }
            if (0 < (amount = this->outln())) {
                count += amount;
            }
        }
        return count;
    }
public:

protected:
    /// ...output_hex_x
    ssize_t (derives::*output_hex_x_)(const void* out, size_t len);
    virtual ssize_t output_hex_x(const void* out, size_t len) {
        ssize_t count = 0;
        if (output_hex_x_) {
            count = (this->*output_hex_x_)(out, len);
        } else {
            count = lower_output_hex_x(out, len);
        }
        return count;
    }
    virtual ssize_t lower_output_hex_x(const void* out, size_t len) {
        ssize_t count = this->outx(out, len);
        return count;
    }
    virtual ssize_t upper_output_hex_x(const void* out, size_t len) {
        ssize_t count = this->outX(out, len);
        return count;
    }
public:

protected:
    /// nextln
    virtual const char_t& nextln() const {
        static const char_t nextln = (char_t)'\\';
        return nextln;
    }

protected:
}; /// class outputt
typedef outputt<> output;

namespace console {
typedef outputt<xos::console::output> output;
} /// namespace console

} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_OUTPUT_HPP
