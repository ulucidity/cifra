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
///   File: extend.hpp
///
/// Author: $author$
///   Date: 4/13/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RSA_KEY_EXTEND_HPP
#define XOS_CRYPTO_RSA_KEY_EXTEND_HPP

#include "xos/crypto/rsa/key/implement.hpp"
#include "xos/crypto/base/extend.hpp"

namespace xos {
namespace crypto {
namespace rsa {
namespace key {

/// class extendt
template 
<class TExtends = crypto::extendt<xos::crypto::rsa::key::implement>, 
 class TImplements = typename TExtends::implements>

class exported extendt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef extendt derives; 
    
    /// constructors / destructor
    extendt
    (const byte_t* modulus, size_t modbytes, 
     const byte_t* exponent, size_t expbytes): m_modbytes(0), m_expbytes(0), m_pbytes(0) {
        if (!(this->create_msb(modulus, modbytes, exponent, expbytes))) {
            throw (create_exception(create_failed));
        }
    }
    extendt
    (const byte_t *p, const byte_t *q,
     const byte_t *dmp1, const byte_t *dmq1,
     const byte_t *iqmp, size_t pbytes): m_modbytes(0), m_expbytes(0), m_pbytes(0) {
        if (!(this->create_msb(p, q, dmp1, dmq1, iqmp, pbytes))) {
            throw (create_exception(create_failed));
        }
    }
    extendt(size_t modbytes, size_t expbytes): m_modbytes(0), m_expbytes(0), m_pbytes(0) {
        if (!(this->create(modbytes, expbytes))) {
            throw (create_exception(create_failed));
        }
    }
    extendt(): m_modbytes(0), m_expbytes(0), m_pbytes(0) {
    }
    virtual ~extendt() {
        if (!(this->destroyed())) {
            throw (create_exception(destroy_failed));
        }
    }
private:
    extendt(const extendt& copy): m_modbytes(0), m_expbytes(0), m_pbytes(0) {
        throw exception(exception_unexpected);
    }
public:

    /// create / destroy
    virtual bool create(size_t modbytes, size_t expbytes) {
        if ((this->destroyed())) {
            if ((modbytes) && (!(modbytes & 1)) && (expbytes)) {
                this->m_pbytes = (modbytes >> 1);
                this->m_modbytes = modbytes;
                this->m_expbytes = expbytes;
                this->set_is_created();
                return true;
            }
        }
        return false;
    }
    virtual bool create(size_t pbytes) {
        if ((this->destroyed())) {
            if ((pbytes)) {
                this->m_pbytes = pbytes;
                this->m_modbytes = (pbytes << 1);
                this->m_expbytes = this->m_modbytes;
                this->set_is_created();
                return true;
            }
        }
        return false;
    }
    virtual bool destroy() {
        if ((this->is_created())) {
            this->set_is_created(false);
            this->m_modbytes = (this->m_expbytes = (this->m_pbytes = 0));
            return true;
        }
        return false;
    }

    /// ...modulus...
    virtual size_t set_modbytes(size_t to) {
        m_modbytes = to;
        return m_modbytes;
    }
    virtual size_t modbytes() const {
        return m_modbytes;
    }

    /// ...exponent...
    virtual size_t set_expbytes(size_t to) {
        m_expbytes = to;
        return m_expbytes;
    }
    virtual size_t expbytes() const {
        return m_expbytes;
    }

    /// ...p...
    virtual size_t set_pbytes(size_t to) {
        m_pbytes = to;
        return m_pbytes;
    }
    virtual size_t pbytes() const {
        return m_pbytes;
    }

protected:
    size_t m_modbytes, m_expbytes, m_pbytes;
}; /// class extendt
typedef extendt<> extend;

} /// namespace key
} /// namespace rsa
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RSA_KEY_EXTEND_HPP
