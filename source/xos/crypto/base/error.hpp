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
///   File: error.hpp
///
/// Author: $author$
///   Date: 4/30/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_BASE_ERROR_HPP
#define XOS_CRYPTO_BASE_ERROR_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace crypto {

/// enum error
typedef int error;
enum {
    error_none = 0,

    error_failed,
    error_unexpected,
    error_not_implemented,
    error_invalid_parameter,
    error_invalid_parameter_size,

    next_error,
    first_error = error_none,
    last_error = (next_error - 1)
}; /// enum error

/// function error_to_chars
inline const char* error_to_chars(crypto::error error) {
    switch(error) {
    case error_none: return "error_none";
    case error_failed: return "error_failed";
    case error_unexpected: return "error_unexpected";
    case error_not_implemented: return "error_not_implemented";
    case error_invalid_parameter: return "error_invalid_parameter";
    case error_invalid_parameter_size: return "error_invalid_parameter_size";
    }
    return "unknown";
}

} /// namespace crypto
} /// namespace xos

#endif /// ndef XOS_CRYPTO_BASE_ERROR_HPP 
