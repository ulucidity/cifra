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
///   File: exception.hpp
///
/// Author: $author$
///   Date: 4/30/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_BASE_EXCEPTION_HPP
#define XOS_CRYPTO_BASE_EXCEPTION_HPP

#include "xos/crypto/base/error.hpp"
#include "xos/base/exception.hpp"

namespace xos {
namespace crypto {

typedef crypto::error exception_status;

/// function exception_status_to_chars
inline const char* exception_status_to_chars(exception_status status) {
    return error_to_chars(status);
}

/// class exceptiont
template <class TExtends = xos::exceptiont<exception_status>, class TImplements = typename TExtends::implements>
class exported exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef exceptiont derives;

    typedef typename extends::status_t status_t;

    /// constructor / destructor
    exceptiont(status_t status): extends(status) {
    }
    exceptiont(const exceptiont& copy): extends(copy) {
    }
    exceptiont() {
    }
    virtual ~exceptiont() {
    }

    /// status_to_chars
    virtual const char* status_to_chars() const {
        return exception_status_to_chars(this->status());
    }
}; /// class exceptiont
typedef exceptiont<> exception;

} /// namespace crypto
} /// namespace xos

#endif /// ndef XOS_CRYPTO_BASE_EXCEPTION_HPP 
