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
///   File: private_key.hpp
///
/// Author: $author$
///   Date: 4/16/2022
///
/// Tatu Ylonen's RSA private key implementation modified to be a C++
/// class that uses Eric Young's big number library instead of gmp used
/// in the original C version.
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RSA_BN_PRIVATE_KEY_HPP
#define XOS_CRYPTO_RSA_BN_PRIVATE_KEY_HPP

#include "xos/crypto/rsa/bn/license.hpp"
#include "xos/crypto/rsa/bn/key.hpp"
#include "xos/crypto/rsa/private_key/extend.hpp"

namespace xos {
namespace crypto {
namespace rsa {
namespace bn {

/// class private_keyt
template 
<class TExtends = crypto::rsa::bn::keyt
 <crypto::rsa::private_key::extend>, class TImplements = typename TExtends::implements>

class exported private_keyt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements, implements;
    typedef TExtends Extends, extends;
    typedef private_keyt Derives, derives; 
    
    /// constructors / destructor
    private_keyt
    (const byte_t *p, const byte_t *q,
     const byte_t *dmp1, const byte_t *dmq1,
     const byte_t *iqmp, size_t pbytes)
    : m_p(0), m_q(0), m_dmp1(0), m_dmq1(0), m_iqmp(0), m_ptemp(0), m_qtemp(0) {
        if (!(this->create_msb(p, q, dmp1, dmq1, iqmp, pbytes))) {
            LOGGER_LOG_ERROR("...failed on create() throwing creator_exception failed_to_create...");
            throw (create_exception(create_failed));
        }
    }
    private_keyt
    (const mpint_t *p, const mpint_t *q,
     const mpint_t *dmp1, const mpint_t *dmq1,
     const mpint_t *iqmp, size_t pbytes)
    : m_p(0), m_q(0), m_dmp1(0), m_dmq1(0), m_iqmp(0), m_ptemp(0), m_qtemp(0) {
        if (!(this->create(p, q, dmp1, dmq1, iqmp, pbytes))) {
            LOGGER_LOG_ERROR("...failed on create() throwing creator_exception failed_to_create...");
            throw (create_exception(create_failed));
        }
    }
    private_keyt(size_t pbytes)
    : m_p(0), m_q(0), m_dmp1(0), m_dmq1(0), m_iqmp(0), m_ptemp(0), m_qtemp(0) {
        if (!(this->create(pbytes))) {
            LOGGER_LOG_ERROR("...failed on create() throwing creator_exception failed_to_create...");
            throw (create_exception(create_failed));
        }
    }
    private_keyt(const private_keyt& copy)
    : m_p(0), m_q(0), m_dmp1(0), m_dmq1(0), m_iqmp(0), m_ptemp(0), m_qtemp(0) {
        if (!(this->create(copy.m_p, copy.m_q, copy.m_dmp1, copy.m_dmq1, copy.m_iqmp, copy.m_pbytes))) {
            LOGGER_LOG_ERROR("...failed on create() throwing creator_exception failed_to_create...");
            throw (create_exception(create_failed));
        }
    }
    private_keyt()
    : m_p(0), m_q(0), m_dmp1(0), m_dmq1(0), m_iqmp(0), m_ptemp(0), m_qtemp(0) {
    }
    virtual ~private_keyt() {
        if (!(this->destroyed())) {
            LOGGER_LOG_ERROR("...failed on destroyed() throwing creator_exception failed_to_destroy...");
            throw (create_exception(destroy_failed));
        }
    }

    /// create / destroy
    virtual bool create
    (const mpint_t *p, const mpint_t *q,
     const mpint_t *dmp1, const mpint_t *dmq1,
     const mpint_t *iqmp, size_t pbytes) {
        if ((this->create(pbytes))) {
            if ((this->set(p,q,dmp1,dmq1,iqmp,pbytes))) {
                return true;
            }
            this->destroy();
        }
        return false;
    }
    virtual bool create(size_t pbytes) {
        if ((this->destroyed())) {
            if ((Extends::create(pbytes))) {
                
            LOGGER_LOG_DEBUG("m_p=BN_new()...");
            if ((m_p=BN_new())) {
                
            LOGGER_LOG_DEBUG("m_q=BN_new()...");
            if ((m_q=BN_new())) {
                
            LOGGER_LOG_DEBUG("m_dmp1=BN_new()...");
            if ((m_dmp1=BN_new())) {
                
            LOGGER_LOG_DEBUG("m_dmq1=BN_new()...");
            if ((m_dmq1=BN_new())) {
                
            LOGGER_LOG_DEBUG("m_iqmp=BN_new()...");
            if ((m_iqmp=BN_new())) {
                
            LOGGER_LOG_DEBUG("m_ptemp=BN_new()...");
            if ((m_ptemp=BN_new())) {
                
            LOGGER_LOG_DEBUG("m_qtemp=BN_new()...");
            if ((m_qtemp=BN_new())) {
                return true;
                
            LOGGER_LOG_DEBUG("BN_free(m_qtemp)...");
            this->BN_free(m_qtemp); }

            LOGGER_LOG_DEBUG("BN_free(m_ptemp)...");
            this->BN_free(m_ptemp); }

            LOGGER_LOG_DEBUG("BN_free(m_iqmp)...");
            this->BN_free(m_iqmp); }

            LOGGER_LOG_DEBUG("BN_free(m_dmq1)...");
            this->BN_free(m_dmq1); }

            LOGGER_LOG_DEBUG("BN_free(m_dmp1)...");
            this->BN_free(m_dmp1); }

            LOGGER_LOG_DEBUG("BN_free(m_q)...");
            this->BN_free(m_q); }

            LOGGER_LOG_DEBUG("BN_free(m_p)...");
            this->BN_free(m_p); }
            Extends::destroy(); }
        }
        return false;
    }
    virtual bool destroy() {
        if ((this->is_created())) {
            bool success = true;

            LOGGER_LOG_DEBUG("BN_free(m_p)...");
            if (!(this->BN_free(m_p))) {
                success = false; }

            LOGGER_LOG_DEBUG("BN_free(m_q)...");
            if (!(this->BN_free(m_q))) {
                success = false; }

            LOGGER_LOG_DEBUG("BN_free(m_dmp1)...");
            if (!(this->BN_free(m_dmp1))) {
                success = false; }

            LOGGER_LOG_DEBUG("BN_free(m_dmq1)...");
            if (!(this->BN_free(m_dmq1))) {
                success = false; }

            LOGGER_LOG_DEBUG("BN_free(m_iqmp)...");
            if (!(this->BN_free(m_iqmp))) {
                success = false; }

            LOGGER_LOG_DEBUG("BN_free(m_ptemp)...");
            if (!(this->BN_free(m_ptemp))) {
                success = false; }

            LOGGER_LOG_DEBUG("BN_free(m_qtemp)...");
            if (!(this->BN_free(m_qtemp))) {
                success = false; }
            if (!(Extends::destroy())) {
                success = false; }
            return success;
        }
        return false;
    }

    /// set_msb / get...msb
    virtual bool set_msb
    (const byte_t *p, const byte_t *q,
     const byte_t *dmp1, const byte_t *dmq1,
     const byte_t *iqmp, size_t pbytes) {
        if ((p) && (q) && (dmp1) && (dmq1) && (iqmp)) {
            if ((m_p) && (m_q) && (m_dmp1) && (m_dmq1) && (m_iqmp)) {

                LOGGER_LOG_DEBUG("BN_set_msb(m_p,p,pbytes)...");
                BN_set_msb(m_p,p,pbytes);

                LOGGER_LOG_DEBUG("BN_set_msb(m_q,q,pbytes)...");
                BN_set_msb(m_q,q,pbytes);

                LOGGER_LOG_DEBUG("N_set_msb(m_dmp1,dmp1,pbytes)...");
                BN_set_msb(m_dmp1,dmp1,pbytes);

                LOGGER_LOG_DEBUG("BN_set_msb(m_dmq1,dmq1,pbytes)...");
                BN_set_msb(m_dmq1,dmq1,pbytes);

                LOGGER_LOG_DEBUG("BN_set_msb(m_iqmp,iqmp,pbytes)...");
                BN_set_msb(m_iqmp,iqmp,pbytes);
                this->m_expbytes = (this->m_modbytes = ((this->m_pbytes = pbytes) << 1));
                return true;
            }
        }
        return false;
    }
    virtual bool get_msb
    (size_t& plen, byte_t *p, byte_t *q,
     byte_t *dmp1, byte_t *dmq1,
     byte_t *iqmp, size_t pbytes) {
        if ((p) && (q) && (dmp1) && (dmq1) && (iqmp) && (pbytes >= this->m_pbytes)) {
            if ((m_p) && (m_q) && (m_dmp1) && (m_dmq1) && (m_iqmp)) {

                LOGGER_LOG_DEBUG("BN_get_msb(m_p,p,pbytes)...");
                BN_get_msb(m_p,p,pbytes);

                LOGGER_LOG_DEBUG("BN_get_msb(m_q,q,pbytes)...");
                BN_get_msb(m_q,q,pbytes);

                LOGGER_LOG_DEBUG("BN_get_msb(m_dmp1,dmp1,pbytes)...");
                BN_get_msb(m_dmp1,dmp1,pbytes);

                LOGGER_LOG_DEBUG("BN_get_msb(m_dmq1,dmq1,pbytes)...");
                BN_get_msb(m_dmq1,dmq1,pbytes);

                LOGGER_LOG_DEBUG("BN_get_msb(m_iqmp,iqmp,pbytes)...");
                BN_get_msb(m_iqmp,iqmp,pbytes);
                plen = this->m_pbytes;
                return true;
            }
        }
        return false;
    }
    virtual ssize_t get_p_msb
    (byte_t* p, size_t pbytes) const {
        if ((m_p) && (p) && (pbytes >= this->m_pbytes)) {

            LOGGER_LOG_DEBUG("BN_get_msb(m_p,p,pbytes)...");
            BN_get_msb(m_p,p,pbytes);
            return this->m_pbytes;
        }
        return 0;
    }
    virtual ssize_t get_q_msb
    (byte_t* p, size_t pbytes) const {
        if ((m_q) && (p) && (pbytes >= this->m_pbytes)) {

            LOGGER_LOG_DEBUG("BN_get_msb(m_q,p,pbytes)...");
            BN_get_msb(m_q,p,pbytes);
            return this->m_pbytes;
        }
        return 0;
    }
    virtual ssize_t get_dmp1_msb
    (byte_t* p, size_t pbytes) const {
        if ((m_dmp1) && (p) && (pbytes >= this->m_pbytes)) {

            LOGGER_LOG_DEBUG("BN_get_msb(m_dmp1,p,pbytes)...");
            BN_get_msb(m_dmp1,p,pbytes);
            return this->m_pbytes;
        }
        return 0;
    }
    virtual ssize_t get_dmq1_msb
    (byte_t* p, size_t pbytes) const {
        if ((m_dmq1) && (p) && (pbytes >= this->m_pbytes)) {

            LOGGER_LOG_DEBUG("BN_get_msb(m_dmq1,p,pbytes)...");
            BN_get_msb(m_dmq1,p,pbytes);
            return this->m_pbytes;
        }
        return 0;
    }
    virtual ssize_t get_iqmp_msb
    (byte_t* p, size_t pbytes) const {
        if ((m_iqmp) && (p) && (pbytes >= this->m_pbytes)) {

            LOGGER_LOG_DEBUG("BN_get_msb(m_iqmp,p,pbytes)...");
            BN_get_msb(m_iqmp,p,pbytes);
            return this->m_pbytes;
        }
        return 0;
    }

    /// set / get
    virtual bool set
    (const mpint_t *p, const mpint_t *q,
     const mpint_t *dmp1, const mpint_t *dmq1,
     const mpint_t *iqmp, size_t pbytes) {
        if ((p) && (q) && (dmp1) && (dmq1) && (iqmp) && (pbytes)) {
            if ((m_p) && (m_q) && (m_dmp1) && (m_dmq1) && (m_iqmp)) {

                LOGGER_LOG_DEBUG("BN_copy(m_p,(BIGNUM*)(p))...");
                BN_copy(m_p,(BIGNUM*)(p));

                LOGGER_LOG_DEBUG("BN_copy(m_q,(BIGNUM*)(q))...");
                BN_copy(m_q,(BIGNUM*)(q));

                LOGGER_LOG_DEBUG("BN_copy(m_dmp1,(BIGNUM*)(dmp1))...");
                BN_copy(m_dmp1,(BIGNUM*)(dmp1));

                LOGGER_LOG_DEBUG("BN_copy(m_dmq1,(BIGNUM*)(dmq1))...");
                BN_copy(m_dmq1,(BIGNUM*)(dmq1));

                LOGGER_LOG_DEBUG("BN_copy(m_iqmp,(BIGNUM*)(iqmp))...");
                BN_copy(m_iqmp,(BIGNUM*)(iqmp));
                this->m_expbytes = (this->m_modbytes = ((this->m_pbytes = pbytes) << 1));
                return true;
            }
        }
        return false;
    }
    virtual bool get
    (size_t& plen, mpint_t *p, mpint_t *q,
     mpint_t *dmp1, mpint_t *dmq1, mpint_t *iqmp) {
        if ((p) && (q) && (dmp1) && (dmq1) && (iqmp)) {
            if ((m_p) && (m_q) && (m_dmp1) && (m_dmq1) && (m_iqmp) && (this->m_pbytes)) {

                LOGGER_LOG_DEBUG("BN_copy(p,m_p)...");
                BN_copy(p,m_p);

                LOGGER_LOG_DEBUG("BN_copy(q,m_q)...");
                BN_copy(q,m_q);

                LOGGER_LOG_DEBUG("BN_copy(dmp1,m_dmp1)...");
                BN_copy(dmp1,m_dmp1);

                LOGGER_LOG_DEBUG("BN_copy(dmq1,m_dmq1)...");
                BN_copy(dmq1,m_dmq1);

                LOGGER_LOG_DEBUG("BN_copy(iqmp,m_iqmp)...");
                BN_copy(iqmp,m_iqmp);
                plen = this->m_pbytes;
                return true;
            }
        }
        return false;
    }

    /// operator()
    virtual ssize_t operator()(void* out, size_t outsize, const void* in, size_t inlen) {
        ///
        /// Performs a private-key RSA operation (encrypt/decrypt). The computation
        /// is done using the Chinese Remainder Theorem, which is faster than
        /// direct modular exponentiation.
        /// 
        if ((m_p) && (m_q) && (m_dmp1) && (m_dmq1)
            && (m_iqmp) && (this->m_pbytes) && (this->m_temp) && (this->m_ctx) && (this->m_modbytes)) {
            const byte_t* inb = 0;
            byte_t* outb = 0;

            if ((inb = ((const byte_t*)in)) && (inlen == this->m_modbytes)
                && (outb = ((byte_t*)out)) && (outsize >= this->m_modbytes)) {
                bool subp = false;

                LOGGER_LOG_DEBUG("BN_set_msb(m_temp,inb,m_modbytes)...");
                BN_set_msb(this->m_temp,inb,this->m_modbytes);

                // Compute q2 = (value mod q) ^ dmq1 mod q.
                //
                LOGGER_LOG_DEBUG("BN_mod(m_qtemp,m_temp,m_q,m_ctx)...");
                BN_mod(m_qtemp,this->m_temp,m_q,this->m_ctx);

                LOGGER_LOG_DEBUG("BN_mod_exp(m_qtemp,m_qtemp,m_dmq1,m_q,m_ctx)...");
                BN_mod_exp(m_qtemp,m_qtemp,m_dmq1,m_q,this->m_ctx);

                // Compute p2 = (value mod p) ^ dmp1 mod p.
                //
                LOGGER_LOG_DEBUG("BN_mod(m_ptemp,m_temp,m_p,m_ctx)...");
                BN_mod(m_ptemp,this->m_temp,m_p,this->m_ctx);

                LOGGER_LOG_DEBUG("BN_mod_exp(m_ptemp,m_ptemp,m_dmp1,m_p,m_ctx)...");
                BN_mod_exp(m_ptemp,m_ptemp,m_dmp1,m_p,this->m_ctx);

                // if q2 > p then q2 = q2 - p
                //
                if ((subp=(BN_cmp(m_qtemp,m_p)>0))!=0) {
                    LOGGER_LOG_DEBUG("BN_sub(m_qtemp,m_qtemp,m_p)...");
                    BN_sub(m_qtemp,m_qtemp,m_p);
                }
                // Compute k = (((p2 + p) - q2) mod p) * iqmp mod p.
                //
                LOGGER_LOG_DEBUG("BN_add(m_temp,m_ptemp,m_p)...");
                BN_add(this->m_temp,m_ptemp,m_p);

                LOGGER_LOG_DEBUG("BN_sub(m_temp,m_temp,m_qtemp)...");
                BN_sub(this->m_temp,this->m_temp,m_qtemp);

                LOGGER_LOG_DEBUG("BN_mul(m_ptemp,m_temp,m_iqmp)...");
                BN_mul(m_ptemp,this->m_temp,m_iqmp);

                LOGGER_LOG_DEBUG("BN_mod(m_temp,m_ptemp,m_p,m_ctx)...");
                BN_mod(this->m_temp,m_ptemp,m_p,this->m_ctx);

                // Compute value = q2 + q * k.
                //
                LOGGER_LOG_DEBUG("BN_mul(m_ptemp,m_temp,m_q)...");
                BN_mul(m_ptemp,this->m_temp,m_q);

                LOGGER_LOG_DEBUG("BN_add(m_temp,m_ptemp,m_qtemp)...");
                BN_add(this->m_temp,m_ptemp,m_qtemp);

                // if we subtracted p before the add it back here
                //
                if (subp) {
                    LOGGER_LOG_DEBUG("BN_add(m_temp,m_temp,m_p)...");
                    BN_add(this->m_temp,this->m_temp,m_p);
                }
                LOGGER_LOG_DEBUG("BN_get_msb(m_temp,outb,m_modbytes)...");
                BN_get_msb(this->m_temp,outb,this->m_modbytes);
                return this->m_modbytes;
            }
        }
        return 0;
    }

    /// ...
    virtual BIGINT& p() const {
        return (BIGINT&)m_p;
    }
    virtual BIGINT& q() const {
        return (BIGINT&)m_q;
    }
    virtual BIGINT& dmp1() const {
        return (BIGINT&)m_dmp1;
    }
    virtual BIGINT& dmq1() const {
        return (BIGINT&)m_dmq1;
    }
    virtual BIGINT& iqmp() const {
        return (BIGINT&)m_iqmp;
    }

protected:
    BIGNUM *m_p, *m_q, *m_dmp1, *m_dmq1, *m_iqmp, *m_ptemp, *m_qtemp;
}; /// class private_keyt
typedef private_keyt<> private_key;

} /// namespace bn
} /// namespace rsa
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RSA_BN_PRIVATE_KEY_HPP
