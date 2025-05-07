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
#ifndef XOS_CRYPTO_RSA_MP_KEY_HPP
#define XOS_CRYPTO_RSA_MP_KEY_HPP

#include "xos/crypto/rsa/mp/license.hpp"
#include "xos/crypto/rsa/key/extend.hpp"
#include "mpz_msb.h"

namespace xos {
namespace crypto {
namespace rsa {
namespace mp {

typedef MP_INT mpint_t;
typedef MP_INT BIGPRIME;
typedef MP_INT BIGINT;

/// class keyt
template 
<class TExtends = crypto::rsa::key::extend, class TImplements = typename TExtends::implements>

class exported keyt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements, implements;
    typedef TExtends Extends, extends;
    typedef keyt Derives, derives; 
    
    /// constructors / destructor
    keyt() {
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

                LOGGER_LOG_DEBUG("mpz_init_set_ui(&m_temp,0)...");
                mpz_init_set_ui(&m_temp,0);
                return true;
                Extends::destroy();
            }
        }
        return false;
    }
    virtual bool create(size_t pbytes) {
        if ((this->destroyed())) {
            if ((Extends::create(pbytes))) {

                LOGGER_LOG_DEBUG("mpz_init_set_ui(&m_temp,0)...");
                mpz_init_set_ui(&m_temp,0);
                return true;
                Extends::destroy();
            }
        }
        return false;
    }
    virtual bool destroy() {
        if ((this->is_created())) {
            bool success = true;

            LOGGER_LOG_DEBUG("mpz_clear(&m_temp)...");
            mpz_clear(&m_temp);
            if (!(Extends::destroy())) {
                success = false;
            }
            return success;
        }
        return false;
    }

protected:
    MP_INT m_temp;
}; /// class keyt
typedef keyt<> key;

} /// namespace mp
} /// namespace rsa
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RSA_MP_KEY_HPP
