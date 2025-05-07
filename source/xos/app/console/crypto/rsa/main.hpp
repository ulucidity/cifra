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
///   File: main.hpp
///
/// Author: $author$
///   Date: 11/6/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_HPP

#include "xos/app/console/crypto/rsa/main_opt.hpp"

#if defined(XOS_APP_CONSOLE_CRYPTO_RSA_CLIENT_MAIN_OPT_HPP)
#include "xos/app/console/crypto/rsa/client/key_pair.hpp"
#else /// defined(XOS_APP_CONSOLE_CRYPTO_RSA_CLIENT_MAIN_OPT_HPP)
#if defined(XOS_APP_CONSOLE_CRYPTO_RSA_SERVER_MAIN_OPT_HPP)
#include "xos/app/console/crypto/rsa/server/key_pair.hpp"
#else /// defined(XOS_APP_CONSOLE_CRYPTO_RSA_SERVER_MAIN_OPT_HPP)
#include "xos/app/console/crypto/rsa/key_pair.hpp"
#include "xos/app/console/crypto/rsa/public_key.hpp"
#include "xos/app/console/crypto/rsa/private_key.hpp"
#endif /// defined(XOS_APP_CONSOLE_CRYPTO_RSA_SERVER_MAIN_OPT_HPP)
#endif /// defined(XOS_APP_CONSOLE_CRYPTO_RSA_CLIENT_MAIN_OPT_HPP)

#include "xos/crypto/rsa/bn/public_key.hpp"
#include "xos/crypto/rsa/bn/private_key.hpp"

#include "xos/crypto/rsa/mp/public_key.hpp"
#include "xos/crypto/rsa/mp/private_key.hpp"

#include "xos/crypto/pseudo/random/number/generator.hpp"
#include "xos/crypto/random/number/reader.hpp"
#include "xos/crypto/random/prime/reader.hpp"

#include "xos/crypto/random/prime/bn/number.hpp"
#include "xos/crypto/random/prime/bn/reader.hpp"
#include "xos/crypto/random/prime/bn/miller_rabin.hpp"
#include "xos/crypto/random/prime/bn/generator.hpp"
#include "xos/crypto/rsa/bn/key_generator.hpp"

#include "xos/crypto/random/prime/mp/number.hpp"
#include "xos/crypto/random/prime/mp/reader.hpp"
#include "xos/crypto/random/prime/mp/miller_rabin.hpp"
#include "xos/crypto/random/prime/mp/generator.hpp"
#include "xos/crypto/rsa/mp/key_generator.hpp"

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace rsa {

/// class maint
template 
<class TExtends = xos::app::console::crypto::rsa::main_optt<>,  class TImplements = typename TExtends::implements>

class maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    typedef typename extends::sequence_char_t sequence_char_t;
    typedef typename extends::char_sequence_t char_sequence_t;
    typedef typename extends::char_seeker_t char_seeker_t;
    typedef typename extends::char_reader_t char_reader_t;
    typedef typename extends::char_writer_t char_writer_t;
    typedef typename extends::reader_string_t reader_string_t;
    typedef typename extends::string_reader_t string_reader_t;

    typedef typename extends::byte_array_t byte_array_t;
    typedef typename extends::crypto_array_t crypto_array_t;
    typedef typename extends::output_hex_verbage_sized_t output_hex_verbage_sized_t;

    /// constructor / destructor
    maint()
    : run_(0),
      exponent_value_(XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_EXPONENT_VALUE), 
      exponent_bits_(XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_EXPONENT_BITS),
      modulus_bits_(XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    //////////////////////////////////////////////////////////////////////////
    /// class bn_reader_observer_t
    class exported bn_reader_observer_t
    : virtual public xos::crypto::random::prime::bn::reader::reader_observer_t {
    friend class maint;
    public:
        bn_reader_observer_t(maint& main): main_(main), output_(0) {}
        virtual ~bn_reader_observer_t() {}
        virtual ssize_t on_read(BIGNUM* n, size_t bytes) {
            bool output = true;
            if ((output)) {
                main_.err(".");
                ++output_;
            }
            return bytes;
        }
        virtual size_t clear_output() {
            size_t output = output_;
            output_ = 0;
            if ((output)) {
                main_.errln();
            }
            return output;
        }
    protected:
        maint& main_;
        size_t output_;
    }; /// class bn_reader_observer_t

    //////////////////////////////////////////////////////////////////////////
    /// class mp_reader_observer_t
    class exported mp_reader_observer_t
    : virtual public xos::crypto::random::prime::mp::reader::reader_observer_t {
    friend class maint;
    public:
        mp_reader_observer_t(maint& main): main_(main), output_(0) {}
        virtual ~mp_reader_observer_t() {}
        virtual ssize_t on_read(MP_INT* n, size_t bytes) {
            bool output = true;
            if ((output)) {
                main_.err(".");
                ++output_;
            }
            return bytes;
        }
        virtual size_t clear_output() {
            size_t output = output_;
            output_ = 0;
            if ((output)) {
                main_.errln();
            }
            return output;
        }
    protected:
        maint& main_;
        size_t output_;
    }; /// class mp_reader_observer_t

protected:
    //////////////////////////////////////////////////////////////////////////
    /// run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            if (!(err = (this->*run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = extends::run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    /// ...bn_generate_key_pair_run
    virtual int bn_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t expbits = this->exponent_bits(), expbytes = ((expbits + 7) >> 3),
               modbits = this->modulus_bits(), modbytes = ((modbits + 7) >> 3),
               pbits = (modbits >> 1), pbytes = (modbytes >> 1);
        crypto_array_t exponent_array(exponent_value_, expbytes);
        byte_t* exponent = 0; size_t exponent_length = 0;
        
        if ((exponent = exponent_array.has_elements(exponent_length)) && (expbytes == exponent_length)) {
            xos::crypto::pseudo::random::number::generator random;
            xos::crypto::rsa::bn::public_key pub(modbytes, expbytes);
            xos::crypto::rsa::bn::private_key prv(pbytes);
            bn_reader_observer_t observer(*this);
            xos::crypto::rsa::bn::key_generator generator(&observer);
            
            observer.clear_output();
            if ((generator.generate(prv, pub, modbytes, exponent, expbytes, random))) {
                
                observer.clear_output();
                if (!(err = output_generated_key_pair_run(pub, prv, argc, argv, env))) {
                }
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...gmp_generate_key_pair_run
    virtual int gmp_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t expbits = this->exponent_bits(), expbytes = ((expbits + 7) >> 3),
               modbits = this->modulus_bits(), modbytes = ((modbits + 7) >> 3),
               pbits = (modbits >> 1), pbytes = (modbytes >> 1);
        crypto_array_t exponent_array(exponent_value_, expbytes);
        byte_t* exponent = 0; size_t exponent_length = 0;
        
        if ((exponent = exponent_array.has_elements(exponent_length)) && (expbytes == exponent_length)) {
            xos::crypto::pseudo::random::number::generator random;
            xos::crypto::rsa::mp::public_key pub(modbytes, expbytes);
            xos::crypto::rsa::mp::private_key prv(pbytes);
            mp_reader_observer_t observer(*this);
            xos::crypto::rsa::mp::key_generator generator(&observer);
            
            observer.clear_output();
            if ((generator.generate(prv, pub, modbytes, exponent, expbytes, random))) {
                
                observer.clear_output();
                if (!(err = output_generated_key_pair_run(pub, prv, argc, argv, env))) {
                }
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_generated_key_pair_run
    virtual int output_generated_key_pair_run
    (const xos::crypto::rsa::public_key::extend& pub, 
     const xos::crypto::rsa::private_key::extend& prv, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t expbytes = pub.expbytes(), 
               modbytes = pub.modbytes(), 
               pbytes = prv.pbytes();
        byte_array_t array(modbytes);
        byte_t *bytes = 0; size_t length = 0;
        
        if ((bytes = array.has_elements(length)) && (modbytes <= length)) {
            bool base64_output = this->base64_output();
            
            if ((base64_output)) {
                if (expbytes == (length = pub.get_exponent_msb(bytes, modbytes))) {
                    this->output_base64_verbage_sized("rsa_public_exponent", bytes, length);
    
                    if (modbytes == (length = pub.get_modulus_msb(bytes, modbytes))) {
                        this->output_base64_verbage_sized("rsa_public_modulus", bytes, length);
                        
                        if (pbytes == (length = prv.get_p_msb(bytes, pbytes))) {
                            this->output_base64_verbage_sized("rsa_private_p", bytes, length);
                            
                            if (pbytes == (length = prv.get_q_msb(bytes, pbytes))) {
                                this->output_base64_verbage_sized("rsa_private_q", bytes, length);
                                
                                if (pbytes == (length = prv.get_dmp1_msb(bytes, pbytes))) {
                                    this->output_base64_verbage_sized("rsa_private_dmp1", bytes, length);
                                    
                                    if (pbytes == (length = prv.get_dmq1_msb(bytes, pbytes))) {
                                        this->output_base64_verbage_sized("rsa_private_dmq1", bytes, length);
                                        
                                        if (pbytes == (length = prv.get_iqmp_msb(bytes, pbytes))) {
                                            this->output_base64_verbage_sized("rsa_private_iqmp", bytes, length);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                bool const_0x_output = this->const_0x_output();
                output_hex_verbage_sized_t output_hex_verbage_sized = 0;
    
                if ((const_0x_output)) {
                    output_hex_verbage_sized = this->set_output_const_0x_verbage_sized();
                    this->outlln("#ifndef ", this->key_pair_define_chars(), null);
                    this->outlln("#define ", this->key_pair_define_chars(), null);
                    this->outln("");
                }
                if (expbytes == (length = pub.get_exponent_msb(bytes, modbytes))) {
                    this->output_hex_verbage_sized("rsa_public_exponent", bytes, length);
    
                    if (modbytes == (length = pub.get_modulus_msb(bytes, modbytes))) {
                        this->output_hex_verbage_sized("rsa_public_modulus", bytes, length);
                        
                        if (pbytes == (length = prv.get_p_msb(bytes, pbytes))) {
                            this->output_hex_verbage_sized("rsa_private_p", bytes, length);
                            
                            if (pbytes == (length = prv.get_q_msb(bytes, pbytes))) {
                                this->output_hex_verbage_sized("rsa_private_q", bytes, length);
                                
                                if (pbytes == (length = prv.get_dmp1_msb(bytes, pbytes))) {
                                    this->output_hex_verbage_sized("rsa_private_dmp1", bytes, length);
                                    
                                    if (pbytes == (length = prv.get_dmq1_msb(bytes, pbytes))) {
                                        this->output_hex_verbage_sized("rsa_private_dmq1", bytes, length);
                                        
                                        if (pbytes == (length = prv.get_iqmp_msb(bytes, pbytes))) {
                                            this->output_hex_verbage_sized("rsa_private_iqmp", bytes, length);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if ((const_0x_output)) {
                    this->outln("");
                    this->outlln("#endif /// ndef ", this->key_pair_define_chars(), null);
                    this->unset_output_0x_verbage_sized(output_hex_verbage_sized);
                }
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...bn_test_key_pair_run
    virtual int bn_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_length = 0, exponent_length = 0;
        const byte_t *modulus = 0, *exponent = 0;

        if ((modulus = this->get_modulus(modulus_length)) && (modulus_length) 
            && (exponent = this->get_exponent(exponent_length)) && (exponent_length)) {
            size_t p_length = 0;
            const byte_t *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;
            
            xos::crypto::rsa::bn::public_key pub(modulus, modulus_length,exponent, exponent_length);
            if ((p = this->get_p(q, dmp1, dmq1, iqmp, p_length)) && (p_length)) {

                xos::crypto::rsa::bn::private_key prv(p, q, dmp1, dmq1, iqmp, p_length);
                err = test_key_pair_run(pub, prv, argc, argv, env);
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...gmp_test_key_pair_run
    virtual int gmp_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_length = 0, exponent_length = 0;
        const byte_t *modulus = 0, *exponent = 0;

        if ((modulus = this->get_modulus(modulus_length)) && (modulus_length) 
            && (exponent = this->get_exponent(exponent_length)) && (exponent_length)) {
            size_t p_length = 0;
            const byte_t *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;
            
            xos::crypto::rsa::mp::public_key pub(modulus, modulus_length,exponent, exponent_length);
            if ((p = this->get_p(q, dmp1, dmq1, iqmp, p_length)) && (p_length)) {

                xos::crypto::rsa::mp::private_key prv(p, q, dmp1, dmq1, iqmp, p_length);
                err = test_key_pair_run(pub, prv, argc, argv, env);
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// test_key_pair_run
    template <typename rsa_public_key_t, typename rsa_private_key_t>
    int test_key_pair_run(rsa_public_key_t& pub, rsa_private_key_t& prv, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t size = 0, modbytes = pub.modbytes();

        if ((modbytes >= modbytes_min) && (modbytes <= modbytes_max)) {
            size_t sizeof_plain = 0;
            byte_t *plain = &this->rsa_plain(sizeof_plain);
            
            if ((size = this->random_plain(plain, modbytes))) {
                size_t sizeof_cipher = 0;
                byte_t *cipher = &this->rsa_cipher(sizeof_cipher);

                this->out("plain = ");
                this->outx(plain, modbytes);
                this->outln();
                this->outln();

                if (modbytes == (size = pub(cipher, sizeof_cipher, plain, modbytes))) {
                    size_t sizeof_decipher = 0;
                    byte_t *decipher = &this->rsa_decipher(sizeof_decipher);
    
                    this->out("cipher = ");
                    this->outx(cipher, size);
                    this->outln();
                    this->outln();

                    if (modbytes == (size = prv(decipher, sizeof_decipher, cipher, size))) {
                        this->out("decipher = ");
                        this->outx(decipher, size);
                        this->outln();
                        this->outln();

                        this->out("public <--> private ");
                        if (!(::memcmp(plain, decipher, size))) {
                            this->outln("success");
                        } else {
                            this->outln("failure");
                        }
                        this->outln();
                    } else {
                    }
                } else {
                }
                if (modbytes == (size = prv(cipher, sizeof_cipher, plain, modbytes))) {
                    size_t sizeof_decipher = 0;
                    byte_t *decipher = &this->rsa_decipher(sizeof_decipher);
    
                    this->out("cipher = ");
                    this->outx(cipher, size);
                    this->outln();
                    this->outln();

                    if (modbytes == (size = pub(decipher, sizeof_decipher, cipher, size))) {
                        this->out("decipher = ");
                        this->outx(decipher, size);
                        this->outln();
                        this->outln();

                        this->out("private <--> public ");
                        if (!(::memcmp(plain, decipher, size))) {
                            this->outln("success");
                        } else {
                            this->outln("failure");
                        }
                        this->outln();
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...get_rsa_plain
    const byte_t* (derives::*get_rsa_plain_)(size_t &length);
    virtual const byte_t* get_rsa_plain(size_t &length) {
        const byte_t* bytes = 0;
        if (get_rsa_plain_) {
            bytes = (this->*get_rsa_plain_)(length);
        } else {
            bytes = get_test_rsa_plain(length);
        }
        return bytes;
    }
    virtual const byte_t* get_test_rsa_plain(size_t &length) {
        const byte_t *bytes = 0, *modulus = 0;
        size_t modbytes = 0;

        if ((modulus = this->get_modulus(modbytes)) && (modbytes)
            && (modbytes >= modbytes_min) && (modbytes <= modbytes_max)) {
            size_t size = 0, sizeof_plain = 0;
            byte_t *plain = &this->rsa_random(sizeof_plain);
            
            if (modbytes == (size = this->random_plain(plain, modbytes))) {
                length = size;
                bytes = plain;
            }
        }
        return bytes;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual const byte_t* get_literal_rsa_plain(size_t &length) {
        const byte_t* bytes = 0;
        length = rsa_plain_array_.length();
        bytes = rsa_plain_array_.elements();
        return bytes;
    }
    virtual int set_get_literal_rsa_plain(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_rsa_plain_ = &derives::get_literal_rsa_plain;
        return err;
    }
    virtual int get_literal_rsa_plain_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_get_literal_rsa_plain(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_rsa_plain_ = 0;
        return err;
    }
    virtual int get_literal_rsa_plain_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...get_rsa_cipher
    const byte_t* (derives::*get_rsa_cipher_)(size_t &length);
    virtual const byte_t* get_rsa_cipher(size_t &length) {
        const byte_t* bytes = 0;
        if (get_rsa_cipher_) {
            bytes = (this->*get_rsa_cipher_)(length);
        } else {
            bytes = get_test_rsa_cipher(length);
        }
        return bytes;
    }
    virtual const byte_t* get_test_rsa_cipher(size_t &length) {
        const byte_t *bytes = 0, *modulus = 0;
        size_t modbytes = 0;

        if ((modulus = this->get_modulus(modbytes)) && (modbytes)
            && (modbytes >= modbytes_min) && (modbytes <= modbytes_max)) {
            size_t size = 0, sizeof_cipher = 0;
            byte_t *cipher = &this->rsa_random(sizeof_cipher);
            
            if (modbytes == (size = this->random(cipher, modbytes))) {
                length = size;
                bytes = cipher;
            }
        }
        return bytes;;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual const byte_t* get_literal_rsa_cipher(size_t &length) {
        const byte_t* bytes = 0;
        length = rsa_cipher_array_.length();
        bytes = rsa_cipher_array_.elements();
        return bytes;;
    }
    virtual int set_get_literal_rsa_cipher(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_rsa_cipher_ = &derives::get_literal_rsa_cipher;
        return err;
    }
    virtual int get_literal_rsa_cipher_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_get_literal_rsa_cipher(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_rsa_cipher_ = 0;
        return err;
    }
    virtual int get_literal_rsa_cipher_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// random...
    virtual size_t random_plain(unsigned char *buff, size_t len) const {
        size_t size = 0;

        if ((buff) && (len)) {

            if (len == (size = random(buff, len))) {
                buff[0] &= 0x7F;
            }
        }
        return size;
    }
    //////////////////////////////////////////////////////////////////////////
    /// random
    virtual size_t random(unsigned char *buff, size_t len) const {
        static unsigned randnum = 0;
        static unsigned avail = 0;
        size_t size = 0;
        
        if ((buff) && (len)) {
            for (size = 0; size < len;) {
                if (avail < 1) {
                    randnum = (unsigned)rand();
                    avail = sizeof(randnum);
                }
                if (0 != (buff[size] = ((char)(randnum & 0xFF)))) {
                    ++size;
                }
                if ((randnum >>= 8) < 1) {
                    avail = 0;
                } else {
                    --avail;
                }
            }
        }
        return size;
    }
    //////////////////////////////////////////////////////////////////////////
    /// size_of
    virtual size_t size_of(const unsigned char *buff, size_t len) const {
        for (size_t i=0; len>0; i++, --len) {
            if (buff[i]) {
                return len;
            }
        }
        return 0;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...get_exponent
    const byte_t* (derives::*get_exponent_)(size_t &length);
    virtual const byte_t* get_exponent(size_t &length) {
        const byte_t* bytes = 0;
        if (get_exponent_) {
            bytes = (this->*get_exponent_)(length);
        } else {
            bytes = get_test_exponent(length);
        }
        return bytes;
    }
    virtual const byte_t* get_test_exponent(size_t &length) {
        const byte_t* bytes = 0;
        length = sizeof(::xos::app::console::crypto::rsa::rsa_public_exponent);
        bytes = ::xos::app::console::crypto::rsa::rsa_public_exponent;
        return bytes;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual const byte_t* get_literal_exponent(size_t &length) {
        const byte_t* bytes = 0;
        length = exponent_.length();
        bytes = exponent_.elements();
        return bytes;
    }
    virtual int set_get_literal_exponent(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_exponent_ = &derives::get_literal_exponent;
        return err;
    }
    virtual int get_literal_exponent_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_get_literal_exponent(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_exponent_ = 0;
        return err;
    }
    virtual int get_literal_exponent_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...get_modulus
    const byte_t* (derives::*get_modulus_)(size_t &length);
    virtual const byte_t* get_modulus(size_t &length) {
        const byte_t* bytes = 0;
        if (get_modulus_) {
            bytes = (this->*get_modulus_)(length);
        } else {
            bytes = get_test_modulus(length);
        }
        return bytes;
    }
    virtual const byte_t* get_test_modulus(size_t &length) {
        const byte_t* bytes = 0;
        length = sizeof(::xos::app::console::crypto::rsa::rsa_public_modulus);
        bytes = ::xos::app::console::crypto::rsa::rsa_public_modulus;
        return bytes;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual const byte_t* get_literal_modulus(size_t &length) {
        const byte_t* bytes = 0;
        length = modulus_.length();
        bytes = modulus_.elements();
        return bytes;;
    }
    virtual int set_get_literal_modulus(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_modulus_ = &derives::get_literal_modulus;
        return err;
    }
    virtual int get_literal_modulus_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_get_literal_modulus(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_modulus_ = 0;
        return err;
    }
    virtual int get_literal_modulus_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...get_p
    const byte_t* (derives::*get_p_)
    (const byte_t *&q, const byte_t *&dmp1, 
     const byte_t *&dmq1, const byte_t *&iqmp, size_t &length);
    virtual const byte_t* get_p
    (const byte_t *&q, const byte_t *&dmp1, 
     const byte_t *&dmq1, const byte_t *&iqmp, size_t &length) {
        const byte_t* bytes = 0;
        if (get_p_) {
            bytes = (this->*get_p_)(q, dmp1, dmq1, iqmp, length);
        } else {
            bytes = get_test_p(q, dmp1, dmq1, iqmp, length);
        }
        return bytes;
    }
    virtual const byte_t* get_test_p
    (const byte_t *&q, const byte_t *&dmp1, 
     const byte_t *&dmq1, const byte_t *&iqmp, size_t &length) {
        const byte_t* bytes = 0;
        length = sizeof(::xos::app::console::crypto::rsa::rsa_private_p);
        bytes = ::xos::app::console::crypto::rsa::rsa_private_p;
        q = ::xos::app::console::crypto::rsa::rsa_private_q;
        dmp1 = ::xos::app::console::crypto::rsa::rsa_private_dmp1;
        dmq1 = ::xos::app::console::crypto::rsa::rsa_private_dmq1;
        iqmp = ::xos::app::console::crypto::rsa::rsa_private_iqmp;
        return bytes;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual const byte_t* get_literal_p
    (const byte_t *&q, const byte_t *&dmp1, 
     const byte_t *&dmq1, const byte_t *&iqmp, size_t &length) {
        const byte_t* bytes = 0;
        length = p_.length();
        bytes = p_.elements();
        q = q_.elements();
        dmp1 = dmp1_.elements();
        dmq1 = dmq1_.elements();
        iqmp = iqmp_.elements();
        return bytes;;
    }
    virtual int set_get_literal_p(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_p_ = &derives::get_literal_p;
        return err;
    }
    virtual int get_literal_p_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_get_literal_p(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_p_ = 0;
        return err;
    }
    virtual int get_literal_p_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...rsa...
    virtual byte_t& rsa_plain(size_t& size) const {
        size = sizeof(rsa_plain_);
        return (byte_t&)(rsa_plain_[0]);
    }
    virtual byte_t& rsa_cipher(size_t& size) const {
        size = sizeof(rsa_cipher_);
        return (byte_t&)(rsa_cipher_[0]);
    }
    virtual byte_t& rsa_encipher(size_t& size) const {
        size = sizeof(rsa_encipher_);
        return (byte_t&)(rsa_encipher_[0]);
    }
    virtual byte_t& rsa_decipher(size_t& size) const {
        size = sizeof(rsa_decipher_);
        return (byte_t&)(rsa_decipher_[0]);
    }
    virtual byte_t& rsa_random(size_t& size) const {
        size = sizeof(rsa_random_);
        return (byte_t&)(rsa_random_[0]);
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...exponent...
    virtual uint32_t& set_exponent_value(const uint32_t& to) {
        uint32_t& exponent_value = this->exponent_value();
        exponent_value = to;
        return exponent_value;
    }
    virtual uint32_t& exponent_value() const {
        return (uint32_t&)exponent_value_;
    }
    virtual size_t& set_exponent_bits(const size_t& to) {
        size_t& exponent_bits = this->exponent_bits();
        exponent_bits = to;
        return exponent_bits;
    }
    virtual size_t& exponent_bits() const {
        return (size_t&)exponent_bits_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...modulus...
    virtual size_t& set_modulus_bits(const size_t& to) {
        size_t& modulus_bits = this->modulus_bits();
        modulus_bits = to;
        return modulus_bits;
    }
    virtual size_t& modulus_bits() const {
        return (size_t&)modulus_bits_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    enum {
        modbytes_min = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_MIN,
        modbytes_max = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_MAX
    };

    uint32_t exponent_value_;
    size_t exponent_bits_, modulus_bits_;

    byte_array_t exponent_, modulus_, 
                 p_, q_, dmp1_, dmq1_, iqmp_, 
                 rsa_plain_array_, rsa_cipher_array_;

    byte_t rsa_plain_[modbytes_max], rsa_cipher_[modbytes_max], 
           rsa_encipher_[modbytes_max], rsa_decipher_[modbytes_max], rsa_random_[modbytes_max];
}; /// class maint 
typedef maint<> main;

} /// namespace rsa 
} /// namespace crypto 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_HPP

