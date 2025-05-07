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
///   File: public_key.hpp
///
/// Author: $author$
///   Date: 4/16/2022
///
/// Tatu Ylonen's RSA public key implementation modified to be a C++
/// class that uses Eric Young's big number library instead of gmp used
/// in the original C version.
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RSA_BN_PUBLIC_KEY_HPP
#define XOS_CRYPTO_RSA_BN_PUBLIC_KEY_HPP

#include "xos/crypto/rsa/bn/license.hpp"
#include "xos/crypto/rsa/bn/key.hpp"
#include "xos/crypto/rsa/public_key/extend.hpp"

namespace xos {
namespace crypto {
namespace rsa {
namespace bn {

/// class public_keyt
template 
<class TExtends = crypto::rsa::bn::keyt
 <crypto::rsa::public_key::extend>, class TImplements = typename TExtends::implements>

class exported public_keyt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements, implements;
    typedef TExtends Extends, extends;
    typedef public_keyt Derives, derives; 
    
    /// constructors / destructor
    public_keyt
    (const byte_t* modulus, size_t modbytes,
     const byte_t* exponent, size_t expbytes): m_modulus(0), m_exponent(0) {
        if (!(this->create_msb(modulus, modbytes, exponent, expbytes))) {
            LOGGER_LOG_ERROR("...failed on create() throwing creator_exception failed_to_create...");
            throw (create_exception(create_failed));
        }
    }
    public_keyt
    (const mpint_t* modulus, size_t modbytes,
     const mpint_t* exponent, size_t expbytes): m_modulus(0), m_exponent(0) {
        if (!(this->create(modulus, modbytes, exponent, expbytes))) {
            LOGGER_LOG_ERROR("...failed on create() throwing creator_exception failed_to_create...");
            throw (create_exception(create_failed));
        }
    }
    public_keyt(size_t modbytes, size_t expbytes): m_modulus(0), m_exponent(0) {
        if (!(this->create(modbytes, expbytes))) {
            LOGGER_LOG_ERROR("...failed on create() throwing creator_exception failed_to_create...");
            throw (create_exception(create_failed));
        }
    }
    public_keyt(const public_keyt& copy): m_modulus(0), m_exponent(0) {
        if (!(this->create(copy.m_modulus, copy.m_modbytes, copy.m_exponent, copy.m_expbytes))) {
            LOGGER_LOG_ERROR("...failed on create() throwing creator_exception failed_to_create...");
            throw (create_exception(create_failed));
        }
    }
    public_keyt(): m_modulus(0), m_exponent(0) {
    }
    virtual ~public_keyt() {
        if (!(this->destroyed())) {
            LOGGER_LOG_ERROR("...failed on destroyed() throwing creator_exception failed_to_destroy...");
            throw (create_exception(destroy_failed));
        }
    }

    /// create / destroy
    virtual bool create
    (const mpint_t* modulus, size_t modbytes, const mpint_t* exponent, size_t expbytes) {
        if ((modulus) && (modbytes) && (exponent) && (expbytes)) {
            if ((this->create(modbytes, expbytes))) {
                if ((this->set(modulus, exponent))) {
                    return true;
                }
                this->destroy();
            }
        }
        return false;
    }
    virtual bool create(size_t modbytes, size_t expbytes) {
        if ((this->destroyed())) {
            if ((Extends::create(modbytes, expbytes))) {

                LOGGER_LOG_DEBUG("m_modulus = BN_new()...");
                if ((m_modulus = BN_new())) {

                    LOGGER_LOG_DEBUG("m_exponent = BN_new()...");
                    if ((m_exponent = BN_new())) {
                        return true;

                        LOGGER_LOG_DEBUG("BN_free(m_exponent)...");
                        this->BN_free(m_exponent);
                    }
                    LOGGER_LOG_DEBUG("BN_free(m_modulus)...");
                    this->BN_free(m_modulus);
                }
                Extends::destroy();
            }
        }
        return false;
    }
    virtual bool destroy() {
        if ((this->is_created())) {
            bool success = true;

            LOGGER_LOG_DEBUG("BN_free(m_exponent)...");
            if (!(this->BN_free(m_exponent))) {
                success = false;
            }

            LOGGER_LOG_DEBUG("BN_free(m_modulus)...");
            if (!(this->BN_free(m_modulus))) {
                success = false;
            }
            if (!(Extends::destroy())) {
                success = false;
            }
            return success;
        }
        return false;
    }

    /// set...msb / get...msb
    virtual bool set_msb
    (const byte_t* modulus, size_t modbytes, const byte_t* exponent, size_t expbytes) {
        if ((modulus) && (modbytes) && (exponent) && (expbytes)) {
            if ((m_modulus) && (m_exponent)) {

                LOGGER_LOG_DEBUG("BN_set_msb(m_modulus, modulus, m_modbytes = modbytes)...");
                BN_set_msb(m_modulus, modulus, this->m_modbytes = modbytes);

                LOGGER_LOG_DEBUG("BN_set_msb(m_exponent, exponent, m_expbytes = expbytes)...");
                BN_set_msb(m_exponent, exponent, this->m_expbytes = expbytes);
                return true;
            }
        }
        return false;
    }
    virtual bool get_msb
    (size_t& modlen, size_t& explen, 
     byte_t* modulus, size_t modbytes, byte_t* exponent, size_t expbytes) const {
        if ((modulus) && (modbytes) && (exponent) && (expbytes)) {
            if ((m_modulus) && (modbytes >= this->m_modbytes)
                && (m_exponent) && (expbytes >= this->m_expbytes)) {

                LOGGER_LOG_DEBUG("BN_get_msb(m_modulus, modulus, m_modbytes)...");
                BN_get_msb(m_modulus, modulus, this->m_modbytes);

                LOGGER_LOG_DEBUG("BN_get_msb(m_exponent, exponent, m_expbytes)...");
                BN_get_msb(m_exponent, exponent, this->m_expbytes);
                explen = this->m_expbytes;
                modlen = this->m_modbytes;
                return true;
            }
        }
        return false;
    }
    virtual ssize_t get_modulus_msb(byte_t* modulus, size_t modbytes) const {
        if ((modulus) && (modbytes)) {
            if ((m_modulus) && (modbytes >= this->m_modbytes)) {

                LOGGER_LOG_DEBUG("BN_get_msb(m_modulus, modulus, m_modbytes)...");
                BN_get_msb(m_modulus, modulus, this->m_modbytes);
                return this->m_modbytes;
            }
        }
        return 0;
    }
    virtual ssize_t get_exponent_msb(byte_t* exponent, size_t expbytes) const {
        if ((exponent) && (expbytes)) {
            if ((m_exponent) && (expbytes >= this->m_expbytes)) {

                LOGGER_LOG_DEBUG("BN_get_msb(m_exponent, exponent, m_expbytes)...");
                BN_get_msb(m_exponent, exponent, this->m_expbytes);
                return this->m_expbytes;
            }
        }
        return 0;
    }

    /// set / get
    virtual bool set(const mpint_t* modulus, const mpint_t* exponent) {
        if ((modulus) && (exponent)) {
            if ((m_modulus) && (m_exponent)) {

                LOGGER_LOG_DEBUG("BN_copy(m_modulus, (BIGNUM*)(modulus))...");
                BN_copy(m_modulus, (BIGNUM*)(modulus));

                LOGGER_LOG_DEBUG("BN_copy(m_exponent, (BIGNUM*)(exponent))...");
                BN_copy(m_exponent, (BIGNUM*)(exponent));
                return true;
            }
        }
        return false;
    }
    virtual bool get(size_t& modlen, size_t& explen, mpint_t*& modulus, mpint_t*& exponent) const {
        if ((modulus) && (exponent)) {
            if ((m_modulus) && (m_exponent)) {

                LOGGER_LOG_DEBUG("BN_copy(modulus, m_modulus)...");
                BN_copy(modulus, m_modulus);

                LOGGER_LOG_DEBUG("BN_copy(exponent, m_exponent)...");
                BN_copy(exponent, m_exponent);
                explen = this->m_expbytes;
                modlen = this->m_modbytes;
                return true;
            }
        }
        return false;
    }

    /// operator()
    virtual ssize_t operator()(void* out, size_t outsize, const void* in, size_t inlen) {
        if ((m_modulus) && (this->m_modbytes)
            && (m_exponent) && (this->m_expbytes) && (this->m_temp) && (this->m_ctx)) {
            const byte_t* inb;
            byte_t* outb;

            if ((inb = ((const byte_t*)in)) && (inlen == this->m_modbytes)
                && (outb = ((byte_t*)out)) && (outsize >= this->m_modbytes)) {

                LOGGER_LOG_DEBUG("BN_set_msb(m_temp, inb, inlen)...");
                BN_set_msb(this->m_temp, inb, inlen);

                LOGGER_LOG_DEBUG("BN_mod_exp(m_temp, m_temp, m_exponent, m_modulus, m_ctx)...");
                BN_mod_exp(this->m_temp, this->m_temp, m_exponent, m_modulus, this->m_ctx);

                LOGGER_LOG_DEBUG("BN_get_msb(m_temp, outb, m_modbytes)...");
                BN_get_msb(this->m_temp, outb, this->m_modbytes);
                return this->m_modbytes;
            }
        }
        return 0;
    }

    /// ...
    virtual BIGNUM* modulus(size_t& modlen) const {
        if ((m_modulus) && (this->m_modbytes)) {
            modlen = this->m_modbytes;
            return m_modulus;
        }
        return 0;
    }
    virtual BIGNUM* exponent(size_t& explen) const {
        if ((m_exponent) && (this->m_expbytes)) {
            explen = this->m_expbytes;
            return m_exponent;
        }
        return 0;
    }
    virtual BIGINT& modulus() const {
        return (BIGINT&)m_modulus;
    }
    virtual BIGINT& exponent() const {
        return (BIGINT&)m_exponent;
    }

protected:
    BIGNUM *m_modulus, *m_exponent;
}; /// class public_keyt
typedef public_keyt<> public_key;

} /// namespace bn
} /// namespace rsa
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RSA_BN_PUBLIC_KEY_HPP
