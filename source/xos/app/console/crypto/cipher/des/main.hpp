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
///   Date: 11/15/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_CIPHER_DES_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_DES_MAIN_HPP

#include "xos/app/console/crypto/cipher/des/main_opt.hpp"
#include "xos/crypto/cipher/des/openssl/implemented.hpp"
#include "xos/app/console/crypto/cipher/des/keys.hpp"

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace cipher {
namespace des {

/// class maint
template 
<class TExtends = xos::app::console::crypto::cipher::des::main_optt<>,  class TImplements = typename TExtends::implements>

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

    typedef typename extends::cipher_t cipher_t;
    typedef typename extends::identity_cipher_t identity_cipher_t;
    typedef typename extends::implemented_identity_cipher_t implemented_identity_cipher_t;

    typedef xos::crypto::cipher::des::implement des_cipher_t;
    typedef xos::crypto::cipher::des::openssl::implemented openssl_des_cipher_t;
    typedef openssl_des_cipher_t default_des_cipher_t;

    /// constructor / destructor
    maint(): run_(0) {
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
    /// des_encipher_run
    virtual int des_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* plain_text = 0;
        size_t sizeof_plain_text = 0;
        ssize_t length = 0;

        if ((plain_text = this->des_encipher_text(sizeof_plain_text))) {
            const byte_t* des_key = 0;
            size_t sizeof_des_key = 0;

            if ((des_key = this->des_key(sizeof_des_key))) {
                const byte_t* des_iv = 0;
                size_t sizeof_des_iv = 0;

                if ((des_iv = this->des_iv(sizeof_des_iv))) {
                    byte_t* encipher_text = 0;
                    size_t sizeof_encipher_text = 0;
    
                    if ((encipher_text = this->encipher_text(sizeof_encipher_text))) {
                        default_des_cipher_t des(des_key, sizeof_des_key, des_iv, sizeof_des_iv);
                        
                        if (0 < (length = des.encrypt(encipher_text, sizeof_encipher_text, plain_text, sizeof_plain_text))) {
                            this->output_x(encipher_text, length);
                        }
                    }
                }
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// des_decipher_run
    virtual int des_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        byte_t* encipher_text = 0;
        size_t sizeof_encipher_text = 0;
        ssize_t length = 0;

        if ((encipher_text = this->des_decipher_text(sizeof_encipher_text))) {
            const byte_t* des_key = 0;
            size_t sizeof_des_key = 0;

            if ((des_key = this->des_key(sizeof_des_key))) {
                const byte_t* des_iv = 0;
                size_t sizeof_des_iv = 0;

                if ((des_iv = this->des_iv(sizeof_des_iv))) {
                    byte_t* decipher_text = 0;
                    size_t sizeof_decipher_text = 0;
    
                    if ((decipher_text = this->decipher_text(sizeof_decipher_text))) {
                        default_des_cipher_t des(des_key, sizeof_des_key, des_iv, sizeof_des_iv);
                        size_t encipher_text_size = this->encipher_text_size();
                        
                        if ((encipher_text_size) && (encipher_text_size < sizeof_encipher_text)) {
                            sizeof_encipher_text = encipher_text_size;
                        }
                        if (0 < (length = des.decrypt(decipher_text, sizeof_decipher_text, encipher_text, sizeof_encipher_text))) {
                            this->output_x(decipher_text, length);
                        }
                    }
                }
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...des...
    /// ...
    /// ...des...key...
    virtual const byte_t* des_cipher_key(size_t& sizeof_cipher_key) const {
        return des_key(sizeof_cipher_key);
    }
    const byte_t* (derives::*des_key_)(size_t& sizeof_des_key) const;
    virtual const byte_t* des_key(size_t& sizeof_des_key) const {
        if (des_key_) {
            return (this->*des_key_)(sizeof_des_key);
        }
        return test_des_key(sizeof_des_key);
    }
    virtual const byte_t* test_des_key(size_t& sizeof_des_key) const {
        sizeof_des_key = sizeof(cipher::des_key);
        return cipher::des_key;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...des...iv...
    virtual const byte_t* des_cipher_iv(size_t& sizeof_cipher_iv) const {
        return des_iv(sizeof_cipher_iv);
    }
    const byte_t* (derives::*des_iv_)(size_t& sizeof_des_iv) const;
    virtual const byte_t* des_iv(size_t& sizeof_des_iv) const {
        if (des_iv_) {
            return (this->*des_iv_)(sizeof_des_iv);
        }
        return test_des_iv(sizeof_des_iv);
    }
    virtual const byte_t* test_des_iv(size_t& sizeof_des_iv) const {
        sizeof_des_iv = sizeof(cipher::des_iv);
        return cipher::des_iv;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...des...cipher_text...
    const char_t* des_encipher_text(size_t& length) const {
        const char_t* chars = 0;
        if (!(chars = this->plain_text(length))) {
            const byte_t* bytes = 0;
            if ((bytes = test_des_plain_text(length))) {
                chars = (const char_t*)bytes;
            }
        }
        return chars;
    }
    virtual byte_t* des_decipher_text(size_t& size) {
        byte_t* bytes = 0; size_t length = 0;
        if (0 < (length = this->encipher_text_length())) {
            bytes = this->encipher_text(size);
        } else {
            const byte_t* text = 0;
            if ((text = test_des_cipher_text(length))) {
                bytes = this->set_encipher_text(text, length);
                size = length;
            }
        }
        return bytes;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...des_plain_text...
    const byte_t* (derives::*des_plain_text_)(const char_t*& chars, size_t& sizeof_des_plain_text) const;
    virtual const byte_t* des_plain_text(const char_t*& chars, size_t& sizeof_des_plain_text) const {
        if (des_plain_text_) {
            return (this->*des_plain_text_)(chars, sizeof_des_plain_text);
        }
        return test_des_plain_text(sizeof_des_plain_text);
    }
    virtual const byte_t* test_des_plain_text(size_t& sizeof_plain_text) const {
        static const byte_t plain_text[8*4] = {
            0x37,0x36,0x35,0x34,0x33,0x32,0x31,0x20,
            0x4E,0x6F,0x77,0x20,0x69,0x73,0x20,0x74,
            0x68,0x65,0x20,0x74,0x69,0x6D,0x65,0x20,
            0x66,0x6F,0x72,0x20,0x00,0x00,0x00,0x00,
        };
        sizeof_plain_text = sizeof(plain_text);
        return plain_text;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...des_cipher_text...
    const byte_t* (derives::*des_cipher_text_)(size_t& sizeof_des_cipher_text) const;
    virtual const byte_t* des_cipher_text(size_t& sizeof_des_cipher_text) const {
        if (des_cipher_text_) {
            return (this->*des_cipher_text_)(sizeof_des_cipher_text);
        }
        return test_des_cipher_text(sizeof_des_cipher_text);
    }
    virtual const byte_t* test_des_cipher_text(size_t& sizeof_cipher_text) const {
        static const byte_t cipher_text[8*4] = {
            0xcc,0xd1,0x73,0xff,0xab,0x20,0x39,0xf4,
            0xac,0xd8,0xae,0xfd,0xdf,0xd8,0xa1,0xeb,
            0x46,0x8e,0x91,0x15,0x78,0x88,0xba,0x68,
            0x1d,0x26,0x93,0x97,0xf7,0xfe,0x62,0xb4
        };
        sizeof_cipher_text = sizeof(cipher_text);
        return cipher_text;
    }
    /// ...
    /// ...des...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class maint 
typedef maint<> main;

} /// namespace des 
} /// namespace cipher 
} /// namespace crypto 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_CIPHER_DES_MAIN_HPP

