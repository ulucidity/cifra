///////////////////////////////////////////////////////////////////////
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
///   File: key.hpp
///
/// Author: $author$
///   Date: 4/16/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RSA_BN_KEY_HPP
#define XOS_CRYPTO_RSA_BN_KEY_HPP

#include "xos/crypto/rsa/bn/license.hpp"
#include "xos/crypto/rsa/key/extend.hpp"
#include "bn_msb.h"

namespace xos {
namespace crypto {
namespace rsa {
namespace bn {

typedef BIGNUM mpint_t;
typedef BIGNUM BIGPRIME;
typedef BIGNUM* BIGINT;

/// class keyt
template 
<class TExtends = crypto::rsa::key::extend, class TImplements = typename TExtends::implements>

class exported keyt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements, implements;
    typedef TExtends Extends, extends;
    typedef keyt Derives, derives; 
    
    /// constructors / destructor
    keyt(): m_temp(0), m_ctx(0) {
    }
    virtual ~keyt() {
        if (!(this->destroyed())) {
            throw (create_exception(destroy_failed));
        }
    }
private:
    keyt(const keyt& copy) {
        throw exception(exception_unexpected);
    }
public:

    /// create / destroy
    virtual bool create(size_t modbytes, size_t expbytes) {
        if ((this->destroyed())) {
            if ((Extends::create(modbytes, expbytes))) {
                LOGGER_LOG_DEBUG("m_temp = BN_new()...");
                if ((m_temp = BN_new())) {
                    LOGGER_LOG_DEBUG("m_ctx = BN_CTX_new()...");
                    if ((m_ctx = BN_CTX_new())) {
                        return true;
                        LOGGER_LOG_DEBUG("BN_CTX_free(m_ctx)...");
                        BN_CTX_free(m_ctx);
                    }
                    LOGGER_LOG_DEBUG("BN_free(m_temp)...");
                    BN_free(m_temp);
                }
                Extends::destroy();
            }
        }
        return false;
    }
    virtual bool create(size_t pbytes) {
        if ((this->destroyed())) {
            if ((Extends::create(pbytes))) {
                LOGGER_LOG_DEBUG("m_temp = BN_new()...");
                if ((m_temp = BN_new())) {
                    LOGGER_LOG_DEBUG("m_ctx = BN_CTX_new()...");
                    if ((m_ctx = BN_CTX_new())) {
                        return true;
                        LOGGER_LOG_DEBUG("BN_CTX_free(m_ctx)...");
                        BN_CTX_free(m_ctx);
                    }
                    LOGGER_LOG_DEBUG("BN_free(m_temp)...");
                    BN_free(m_temp);
                }
                Extends::destroy();
            }
        }
        return false;
    }
    virtual bool destroy() {
        if ((this->is_created())) {
            bool success = true;
            LOGGER_LOG_DEBUG("BN_CTX_free(m_ctx)...");
            if (!(BN_CTX_free(m_ctx))) {
                success = false;
            }
            LOGGER_LOG_DEBUG("BN_free(m_temp)...");
            if (!(BN_free(m_temp))) {
                success = false;
            }
            if (!(Extends::destroy())) {
                success = false;
            }
            return success;
        }
        return false;
    }

    /// ...
    virtual BN_CTX*& ctx() const {
        return (BN_CTX*&)m_ctx;
    }
    virtual BIGNUM*& temp() const {
        return (BIGNUM*&)m_temp;
    }

protected:
    /// ...free
    virtual bool BN_CTX_free(BN_CTX*& a) {
        if ((a)) {
            ///LOGGER_LOG_DEBUG("::BN_CTX_free(a)...");
            ::BN_CTX_free(a);
            a = 0;
            return true;
        }
        return false;
    }
    virtual bool BN_free(BIGNUM*& a) {
        if ((a)) {
            ///LOGGER_LOG_DEBUG("::BN_free(a)...");
            ::BN_free(a);
            a = 0;
            return true;
        }
        return false;
    }

protected:
    BIGNUM *m_temp;
    BN_CTX *m_ctx;
}; /// class keyt
typedef keyt<> key;

} /// namespace bn
} /// namespace rsa
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RSA_BN_KEY_HPP
