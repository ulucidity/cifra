///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
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
///   Date: 5/3/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RANDOM_GENERATOR_HPP
#define XOS_CRYPTO_RANDOM_GENERATOR_HPP

#include "xos/io/reader.hpp"

namespace xos {
namespace crypto {
namespace random {

/// class generatort
template <class TImplements = io::byte_reader>
class exported generatort: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef generatort derives;

    typedef typename implements::what_t what_t;
    typedef typename implements::sized_t sized_t;
    typedef typename implements::endof_t endof_t;
    static const endof_t endof = implements::endof;

    virtual ssize_t read(what_t* what, size_t size) {
        sized_t* sized = 0; size_t length = 0;

        if ((sized = (sized_t*)what) && (0 < (length = size))) {
            ssize_t count = 0;

            size *= sizeof(sized_t);
            if ((size == (count = generate(what, size)))) {
                return length;
            } else {
                if (0 > count) {
                    return count;
                }
            }
        }
        return 0;
    }
    virtual ssize_t generate(void* out, size_t size) {
        return 0;
    }
}; /// class generatort
typedef generatort<> generator;

} /// namespace random
} /// namespace crypto
} /// namespace xos

#endif /// ndef XOS_CRYPTO_RANDOM_GENERATOR_HPP 
