//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2024 $organization$
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
///   File: to_main_output.hpp
///
/// Author: $author$
///   Date: 6/6/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_CODE_BASE_TO_MAIN_OUTPUT_HPP
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_TO_MAIN_OUTPUT_HPP

#include "xos/app/console/crypto/code/base/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace code {
namespace base {

/// class to_main_output
class exported to_main_output {
public:
    typedef main_opt to_t;
    
    /// constructors / destructor
    to_main_output(const to_main_output& copy): to_(copy.to_) {
    }
    to_main_output(to_t& to): to_(to) {
    }
    virtual ~to_main_output() {
    }

    /// reset / flush / put
    virtual ssize_t flush() {
        to_t &to = to_;
        return to.out_flush();
    }
    virtual ssize_t put(const byte_t& byte) {
        to_t &to = to_;
        return to.out((const char_t*)(&byte), 1);
    }
    virtual ssize_t put(const char_t& c) {
        to_t &to = to_;
        return to.out((const char_t*)(&c), 1);
    }

protected:
    to_t& to_;
}; /// class to_main_output

} /// namespace base 
} /// namespace code 
} /// namespace crypto 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_CODE_BASE_TO_MAIN_OUTPUT_HPP

