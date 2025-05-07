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
///   File: implement.hpp
///
/// Author: $author$
///   Date: 4/13/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RSA_KEY_IMPLEMENT_HPP
#define XOS_CRYPTO_RSA_KEY_IMPLEMENT_HPP

#include "xos/crypto/base/implement.hpp"

namespace xos {
namespace crypto {
namespace rsa {
namespace key {

/// class implementt
template <class TImplements = xos::creatort<xos::crypto::implement> >
class exported implementt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef implementt derives; 
    
    /// constructors / destructor
    virtual ~implementt() {
    }

    /// create...
    virtual bool create_msb
    (const byte_t* modulus, size_t modbytes,
     const byte_t* exponent, size_t expbytes) {
        if ((modulus) && (modbytes) && (exponent) && (expbytes)) {
            if ((this->create(modbytes, expbytes))) {
                if ((this->set_msb(modulus, modbytes, exponent, expbytes))) {
                    return true;
                }
                this->destroy();
            }
        }
        return false;
    }
    virtual bool create_msb
    (const byte_t *p, const byte_t *q,
     const byte_t *dmp1, const byte_t *dmq1,
     const byte_t *iqmp, size_t pbytes) {
        if ((p) && (p) && (dmp1) && (dmq1) && (iqmp) && (pbytes)) {
            if ((this->create(pbytes))) {
                if ((this->set_msb(p, q, dmp1, dmq1, iqmp, pbytes))) {
                    return true;
                }
                this->destroy();
            }
        }
        return false;
    }
    virtual bool create(size_t modbytes, size_t expbytes) {
        return false;
    }
    virtual bool create(size_t pbytes) {
        return false;
    }

    /// operate / operator()
    virtual ssize_t operate(void* out, size_t outsize, const void* in, size_t inlen) {
        return 0;
    }
    virtual ssize_t operator()(void* out, size_t outsize, const void* in, size_t inlen) {
        return this->operate(out, outsize, in, inlen);
    }

    /// set... / get...
    virtual bool set_msb
    (const byte_t* modulus, size_t modbytes,
     const byte_t* exponent, size_t expbytes) {
        return false;
    }
    virtual bool get_msb
    (size_t& modlen, size_t& explen,
     byte_t* modulus, size_t modbytes,
     byte_t* exponent, size_t expbytes) const {
        return false;
    }
    virtual bool set_msb
    (const byte_t *p, const byte_t *q,
     const byte_t *dmp1, const byte_t *dmq1,
     const byte_t *iqmp, size_t pbytes) {
        return false;
    }
    virtual bool get_msb
    (size_t& plen, byte_t *p, byte_t *q,
     byte_t *dmp1, byte_t *dmq1,
     byte_t *iqmp, size_t pbytes) const {
        return false;
    }

    /// ...modulus...
    virtual ssize_t set_modulus_msb(const byte_t* modulus, size_t modbytes) {
        return 0;
    }
    virtual ssize_t get_modulus_msb(byte_t* modulus, size_t modbytes) const {
        return 0;
    }
    virtual size_t set_modbytes(size_t to) {
        return 0;
    }
    virtual size_t modbytes() const {
        return 0;
    }

    /// ...exponent...
    virtual ssize_t set_exponent_msb(const byte_t* exponent, size_t expbytes) {
        return 0;
    }
    virtual ssize_t get_exponent_msb(byte_t* exponent, size_t expbytes) const {
        return 0;
    }
    virtual size_t set_expbytes(size_t to) {
        return 0;
    }
    virtual size_t expbytes() const {
        return 0;
    }

    /// ...p...
    virtual ssize_t get_p_msb(byte_t* p, size_t pbytes) const {
        return 0;
    }
    virtual ssize_t get_q_msb(byte_t* p, size_t pbytes) const {
        return 0;
    }
    virtual ssize_t get_dmp1_msb(byte_t* p, size_t pbytes) const {
        return 0;
    }
    virtual ssize_t get_dmq1_msb(byte_t* p, size_t pbytes) const {
        return 0;
    }
    virtual ssize_t get_iqmp_msb(byte_t* p, size_t pbytes) const {
        return 0;
    }
    virtual size_t set_pbytes(size_t to) {
        return 0;
    }
    virtual size_t pbytes() const {
        return 0;
    }

    /// legacy
    /// ...

    /// Create...
    virtual bool CreateMSB
    (const BYTE* modulus, size_t modbytes,
     const BYTE* exponent, size_t expbytes) {
        return create_msb(modulus, modbytes, exponent, expbytes);
    }
    virtual bool CreateMSB
    (const BYTE *p, const BYTE *q,
     const BYTE *dmp1, const BYTE *dmq1,
     const BYTE *iqmp, size_t pbytes) {
        return create_msb(p,q, dmp1,dmq1, iqmp, pbytes);
    }
    virtual bool Create(size_t modbytes, size_t expbytes) {
        return create(modbytes, expbytes);
    }
    virtual bool Create(size_t pbytes) {
        return create(pbytes);
    }

    /// Set... / Get...
    virtual bool SetMSB
    (const BYTE* modulus, size_t modbytes,
     const BYTE* exponent, size_t expbytes) {
        return set_msb(modulus, modbytes, exponent, expbytes);
    }
    virtual bool GetMSB
    (size_t& modlen, size_t& explen,
     BYTE* modulus, size_t modbytes,
     BYTE* exponent, size_t expbytes) const {
        return get_msb(modlen, explen, modulus, modbytes, exponent, expbytes);
    }
    virtual bool SetMSB
    (const BYTE *p, const BYTE *q,
     const BYTE *dmp1, const BYTE *dmq1,
     const BYTE *iqmp, size_t pbytes) {
        return set_msb(p,q, dmp1,dmq1, iqmp, pbytes);
    }
    virtual bool GetMSB
    (size_t& plen, BYTE *p, BYTE *q,
     BYTE *dmp1, BYTE *dmq1,
     BYTE *iqmp, size_t pbytes) const {
        return get_msb(plen, p,q, dmp1,dmq1, iqmp, pbytes);
    }

    /// ...Modulus...
    virtual size_t SetModBytes(size_t to) {
        return set_modbytes(to);
    }
    virtual size_t ModBytes() const {
        return modbytes();
    }
    
    /// ...Exponent...
    virtual size_t SetExpBytes(size_t to) {
        return set_expbytes(to);
    }
    virtual size_t ExpBytes() const {
        return expbytes();
    }

    /// ...P...
    virtual size_t SetPBytes(size_t to) {
        return set_pbytes(to);
    }
    virtual size_t PBytes() const {
        return pbytes();
    }
    /// ...
    /// legacy
}; /// class implementt
typedef implementt<> implement;

} /// namespace key
} /// namespace rsa
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RSA_KEY_IMPLEMENT_HPP
