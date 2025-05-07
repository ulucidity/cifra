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
/// class that uses the gmp used in the original C version.
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RSA_MP_PRIVATE_KEY_HPP
#define XOS_CRYPTO_RSA_MP_PRIVATE_KEY_HPP

#include "xos/crypto/rsa/mp/key.hpp"
#include "xos/crypto/rsa/private_key/extend.hpp"

namespace xos {
namespace crypto {
namespace rsa {
namespace mp {

/// class private_keyt
template 
<class TExtends = crypto::rsa::mp::keyt
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
     const byte_t *iqmp, size_t pbytes) {
        if (!(this->create_msb(p, q, dmp1, dmq1, iqmp, pbytes))) {
            LOGGER_LOG_ERROR("...failed on create() throwing creator_exception failed_to_create...");
            throw (create_exception(create_failed));
        }
    }
    private_keyt
    (const mpint_t *p, const mpint_t *q,
     const mpint_t *dmp1, const mpint_t *dmq1,
     const mpint_t *iqmp, size_t pbytes) {
        if (!(this->create(p, q, dmp1, dmq1, iqmp, pbytes))) {
            LOGGER_LOG_ERROR("...failed on create() throwing creator_exception failed_to_create...");
            throw (create_exception(create_failed));
        }
    }
    private_keyt(size_t pbytes) {
        if (!(this->create(pbytes))) {
            LOGGER_LOG_ERROR("...failed on create() throwing creator_exception failed_to_create...");
            throw (create_exception(create_failed));
        }
    }
    private_keyt(const private_keyt& copy) {
        if (!(this->create(&copy.m_p, &copy.m_q, &copy.m_dmp1, &copy.m_dmq1, &copy.m_iqmp, copy.m_pbytes))) {
            LOGGER_LOG_ERROR("...failed on create() throwing creator_exception failed_to_create...");
            throw (create_exception(create_failed));
        }
    }
    private_keyt() {
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
                LOGGER_LOG_DEBUG("mpz_init_set_ui(&m_p,0)...");
                mpz_init_set_ui(&m_p,0);

                LOGGER_LOG_DEBUG("mpz_init_set_ui(&m_q,0)...");
                mpz_init_set_ui(&m_q,0);

                LOGGER_LOG_DEBUG("mpz_init_set_ui(&m_dmp1,0)...");
                mpz_init_set_ui(&m_dmp1,0);

                LOGGER_LOG_DEBUG("mpz_init_set_ui(&m_dmq1,0)...");
                mpz_init_set_ui(&m_dmq1,0);

                LOGGER_LOG_DEBUG("mpz_init_set_ui(&m_iqmp,0)...");
                mpz_init_set_ui(&m_iqmp,0);

                LOGGER_LOG_DEBUG("mpz_init_set_ui(&m_ptemp,0)...");
                mpz_init_set_ui(&m_ptemp,0);

                LOGGER_LOG_DEBUG("mpz_init_set_ui(&m_qtemp,0)...");
                mpz_init_set_ui(&m_qtemp,0);
                return true;
            }
        }
        return false;
    }
    virtual bool destroy() {
        if ((this->is_created())) {
            bool success = true;

            LOGGER_LOG_DEBUG("mpz_clear(&m_p)...");
            mpz_clear(&m_p);

            LOGGER_LOG_DEBUG("mpz_clear(&m_q)...");
            mpz_clear(&m_q);

            LOGGER_LOG_DEBUG("mpz_clear(&m_dmp1)...");
            mpz_clear(&m_dmp1);

            LOGGER_LOG_DEBUG("mpz_clear(&m_dmq1)...");
            mpz_clear(&m_dmq1);

            LOGGER_LOG_DEBUG("mpz_clear(&m_iqmp)...");
            mpz_clear(&m_iqmp);

            LOGGER_LOG_DEBUG("mpz_clear(&m_ptemp)...");
            mpz_clear(&m_ptemp);

            LOGGER_LOG_DEBUG("mpz_clear(&m_qtemp)...");
            mpz_clear(&m_qtemp);
            if (!(Extends::destroy())) {
                success = false; 
            }
            return success;
        }
        return false;
    }

    /// set...msb / get...msb
    virtual bool set_msb
    (const byte_t *p, const byte_t *q,
     const byte_t *dmp1, const byte_t *dmq1,
     const byte_t *iqmp, size_t pbytes) {
        if ((p) && (q) && (dmp1) && (dmq1) && (iqmp)) {
            if ((this->m_pbytes)) {

                LOGGER_LOG_DEBUG("mpz_set_msb(&m_p,p,pbytes)...");
                mpz_set_msb(&m_p,p,pbytes);

                LOGGER_LOG_DEBUG("mpz_set_msb(&m_q,q,pbytes)...");
                mpz_set_msb(&m_q,q,pbytes);

                LOGGER_LOG_DEBUG("mpz_set_msb(&m_dmp1,dmp1,pbytes)...");
                mpz_set_msb(&m_dmp1,dmp1,pbytes);

                LOGGER_LOG_DEBUG("mpz_set_msb(&m_dmq1,dmq1,pbytes)...");
                mpz_set_msb(&m_dmq1,dmq1,pbytes);

                LOGGER_LOG_DEBUG("mpz_set_msb(&m_iqmp,iqmp,pbytes)...");
                mpz_set_msb(&m_iqmp,iqmp,pbytes);
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
            if ((this->m_pbytes)) {

                LOGGER_LOG_DEBUG("mpz_get_msb(p,pbytes,&m_p)...");
                mpz_get_msb(p,pbytes,&m_p);

                LOGGER_LOG_DEBUG("mpz_get_msb(q,pbytes,&m_q)...");
                mpz_get_msb(q,pbytes,&m_q);

                LOGGER_LOG_DEBUG("mpz_get_msb(dmp1,pbytes,&m_dmp1)...");
                mpz_get_msb(dmp1,pbytes,&m_dmp1);

                LOGGER_LOG_DEBUG("mpz_get_msb(dmq1,pbytes,&m_dmq1)...");
                mpz_get_msb(dmq1,pbytes,&m_dmq1);

                LOGGER_LOG_DEBUG("mpz_get_msb(iqmp,pbytes,&m_iqmp)...");
                mpz_get_msb(iqmp,pbytes,&m_iqmp);
                plen = this->m_pbytes;
                return true;
            }
        }
        return false;
    }
    virtual ssize_t get_p_msb
    (byte_t* p, size_t pbytes) const {
        if ((p) && (pbytes >= this->m_pbytes) && (this->m_pbytes)) {

            LOGGER_LOG_DEBUG("mpz_get_msb(p,pbytes,&m_p)...");
            mpz_get_msb(p,pbytes,&m_p);
            return this->m_pbytes;
        }
        return 0;
    }
    virtual ssize_t get_q_msb
    (byte_t* p, size_t pbytes) const {
        if ((p) && (pbytes >= this->m_pbytes) && (this->m_pbytes)) {

            LOGGER_LOG_DEBUG("mpz_get_msb(p,pbytes,&m_q)...");
            mpz_get_msb(p,pbytes,&m_q);
            return this->m_pbytes;
        }
        return 0;
    }
    virtual ssize_t get_dmp1_msb
    (byte_t* p, size_t pbytes) const {
        if ((p) && (pbytes >= this->m_pbytes) && (this->m_pbytes)) {

            LOGGER_LOG_DEBUG("mpz_get_msb(p,pbytes,&m_dmp1)...");
            mpz_get_msb(p,pbytes,&m_dmp1);
            return this->m_pbytes;
        }
        return 0;
    }
    virtual ssize_t get_dmq1_msb
    (byte_t* p, size_t pbytes) const {
        if ((p) && (pbytes >= this->m_pbytes) && (this->m_pbytes)) {

            LOGGER_LOG_DEBUG("mpz_get_msb(p,pbytes,&m_dmq1)...");
            mpz_get_msb(p,pbytes,&m_dmq1);
            return this->m_pbytes;
        }
        return 0;
    }
    virtual ssize_t get_iqmp_msb
    (byte_t* p, size_t pbytes) const {
        if ((p) && (pbytes >= this->m_pbytes) && (this->m_pbytes)) {

            LOGGER_LOG_DEBUG("mpz_get_msb(p,pbytes,&m_iqmp)...");
            mpz_get_msb(p,pbytes,&m_iqmp);
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
            if ((this->m_pbytes)) {

                LOGGER_LOG_DEBUG("mpz_set(&m_p,p)...");
                mpz_set(&m_p,p);

                LOGGER_LOG_DEBUG("mpz_set(&m_q,q)...");
                mpz_set(&m_q,q);

                LOGGER_LOG_DEBUG("mpz_set(&m_dmp1,dmp1)...");
                mpz_set(&m_dmp1,dmp1);

                LOGGER_LOG_DEBUG("mpz_set(&m_dmq1,dmq1)...");
                mpz_set(&m_dmq1,dmq1);

                LOGGER_LOG_DEBUG("mpz_set(&m_iqmp,iqmp)...");
                mpz_set(&m_iqmp,iqmp);
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
            if ((this->m_pbytes)) {

                LOGGER_LOG_DEBUG("mpz_set(p,&m_p)...");
                mpz_set(p,&m_p);

                LOGGER_LOG_DEBUG("mpz_set(q,&m_q)...");
                mpz_set(q,&m_q);

                LOGGER_LOG_DEBUG("mpz_set(dmp1,&m_dmp1)...");
                mpz_set(dmp1,&m_dmp1);

                LOGGER_LOG_DEBUG("mpz_set(dmq1,&m_dmq1)...");
                mpz_set(dmq1,&m_dmq1);

                LOGGER_LOG_DEBUG("mpz_set(iqmp,&m_iqmp)...");
                mpz_set(iqmp,&m_iqmp);
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
        if ((this->m_modbytes)) {
            const byte_t* inb = 0;
            byte_t* outb = 0;

            if ((inb = ((const byte_t*)in)) && (inlen == this->m_modbytes)
                && (outb = ((byte_t*)out)) && (outsize >= this->m_modbytes)) {
                bool subp = 0;

                LOGGER_LOG_DEBUG("mpz_set_msb(&m_temp,inb,m_modbytes)...");
                mpz_set_msb(&this->m_temp,inb,this->m_modbytes);

                // Compute q2 = (value mod q) ^ dmq1 mod q.
                //
                LOGGER_LOG_DEBUG("mpz_mod(&m_qtemp,&m_temp,&m_q)...");
                mpz_mod(&m_qtemp,&this->m_temp,&m_q);

                LOGGER_LOG_DEBUG("mpz_powm(&m_qtemp,&m_qtemp,&m_dmq1,&m_q)...");
                mpz_powm(&m_qtemp,&m_qtemp,&m_dmq1,&m_q);

                // Compute p2 = (value mod p) ^ dmp1 mod p.
                //
                LOGGER_LOG_DEBUG("mpz_mod(&m_ptemp,&m_temp,&m_p)...");
                mpz_mod(&m_ptemp,&this->m_temp,&m_p);

                LOGGER_LOG_DEBUG("mpz_powm(&m_ptemp,&m_ptemp,&m_dmp1,&m_p)...");
                mpz_powm(&m_ptemp,&m_ptemp,&m_dmp1,&m_p);

                // if q2 > p then q2 = q2 - p
                //
                if ((subp=(mpz_cmp(&m_qtemp,&m_p)>0))!=0) {
                    LOGGER_LOG_DEBUG("mpz_sub(&m_qtemp,&m_qtemp,&m_p)...");
                    mpz_sub(&m_qtemp,&m_qtemp,&m_p);
                }
                // Compute k = (((p2 + p) - q2) mod p) * iqmp mod p.
                //
                LOGGER_LOG_DEBUG("mpz_add(&m_temp,&m_ptemp,&m_p)...");
                mpz_add(&this->m_temp,&m_ptemp,&m_p);

                LOGGER_LOG_DEBUG("mpz_sub(&m_temp,&m_temp,&m_qtemp)...");
                mpz_sub(&this->m_temp,&this->m_temp,&m_qtemp);

                LOGGER_LOG_DEBUG("mpz_mul(&m_ptemp,&m_temp,&m_iqmp)...");
                mpz_mul(&m_ptemp,&this->m_temp,&m_iqmp);

                LOGGER_LOG_DEBUG("mpz_mmod(&m_temp,&m_ptemp,&m_p)...");
                mpz_mmod(&this->m_temp,&m_ptemp,&m_p);

                // Compute value = q2 + q * k.
                //
                LOGGER_LOG_DEBUG("mpz_mul(&m_ptemp,&m_temp,&m_q)...");
                mpz_mul(&m_ptemp,&this->m_temp,&m_q);

                LOGGER_LOG_DEBUG("mpz_add(&m_temp,&m_ptemp,&m_qtemp)...");
                mpz_add(&this->m_temp,&m_ptemp,&m_qtemp);

                // if we subtracted p before then add it back here
                //
                if (subp) {
                    LOGGER_LOG_DEBUG("mpz_add(&m_temp,&m_temp,&m_p)...");
                    mpz_add(&this->m_temp,&this->m_temp,&m_p);
                }
                LOGGER_LOG_DEBUG("mpz_get_msb(outb,m_modbytes,&m_temp)...");
                mpz_get_msb(outb,this->m_modbytes,&this->m_temp);
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
    MP_INT m_p, m_q, m_dmp1, m_dmq1, m_iqmp, m_ptemp, m_qtemp;
}; /// class private_keyt
typedef private_keyt<> private_key;

} /// namespace mp
} /// namespace rsa
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RSA_MP_PRIVATE_KEY_HPP
