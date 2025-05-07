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
#ifndef XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_HPP

#include "xos/app/console/crypto/cipher/des3/main_opt.hpp"
#include "xos/crypto/cipher/des3/openssl/implemented.hpp"
#include "xos/app/console/crypto/cipher/des3/keys.hpp"

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace cipher {
namespace des3 {

/// class maint
template 
<class TExtends = xos::app::console::crypto::cipher::des3::main_optt<>,  class TImplements = typename TExtends::implements>

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

    typedef xos::crypto::cipher::des3::implement des3_cipher_t;
    typedef xos::crypto::cipher::des3::openssl::implemented openssl_des3_cipher_t;
    typedef openssl_des3_cipher_t default_des3_cipher_t;

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
    /// des3_encipher_run
    virtual int des3_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* plain_text = 0;
        size_t sizeof_plain_text = 0;
        ssize_t length = 0;

        if ((plain_text = this->des3_encipher_text(sizeof_plain_text))) {
            const byte_t* des3_key = 0;
            size_t sizeof_des3_key = 0;

            if ((des3_key = this->des3_key(sizeof_des3_key))) {
                const byte_t* des3_iv = 0;
                size_t sizeof_des3_iv = 0;

                if ((des3_iv = this->des3_iv(sizeof_des3_iv))) {
                    byte_t* encipher_text = 0;
                    size_t sizeof_encipher_text = 0;
    
                    if ((encipher_text = this->encipher_text(sizeof_encipher_text))) {
                        default_des3_cipher_t des3(des3_key, sizeof_des3_key, des3_iv, sizeof_des3_iv);
                        
                        if (0 < (length = des3.encrypt(encipher_text, sizeof_encipher_text, plain_text, sizeof_plain_text))) {
                            this->output_x(encipher_text, length);
                        }
                    }
                }
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// des3_decipher_run
    virtual int des3_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        byte_t* encipher_text = 0;
        size_t sizeof_encipher_text = 0;
        ssize_t length = 0;

        if ((encipher_text = this->des3_decipher_text(sizeof_encipher_text))) {
            const byte_t* des3_key = 0;
            size_t sizeof_des3_key = 0;

            if ((des3_key = this->des3_key(sizeof_des3_key))) {
                const byte_t* des3_iv = 0;
                size_t sizeof_des3_iv = 0;

                if ((des3_iv = this->des3_iv(sizeof_des3_iv))) {
                    byte_t* decipher_text = 0;
                    size_t sizeof_decipher_text = 0;
    
                    if ((decipher_text = this->decipher_text(sizeof_decipher_text))) {
                        default_des3_cipher_t des3(des3_key, sizeof_des3_key, des3_iv, sizeof_des3_iv);
                        size_t encipher_text_size = this->encipher_text_size();
                        
                        if ((encipher_text_size) && (encipher_text_size < sizeof_encipher_text)) {
                            sizeof_encipher_text = encipher_text_size;
                        }
                        if (0 < (length = des3.decrypt(decipher_text, sizeof_decipher_text, encipher_text, sizeof_encipher_text))) {
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
    /// ...des3...
    /// ...
    /// ...des3...key...
    virtual const byte_t* des3_cipher_key(size_t& sizeof_cipher_key) const {
        return des3_key(sizeof_cipher_key);
    }
    const byte_t* (derives::*des3_key_)(size_t& sizeof_des3_key) const;
    virtual const byte_t* des3_key(size_t& sizeof_des3_key) const {
        if (des3_key_) {
            return (this->*des3_key_)(sizeof_des3_key);
        }
        return test_des3_key(sizeof_des3_key);
    }
    virtual const byte_t* test_des3_key(size_t& sizeof_des3_key) const {
        sizeof_des3_key = sizeof(cipher::des3_key);
        return cipher::des3_key;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...des3...iv...
    virtual const byte_t* des3_cipher_iv(size_t& sizeof_cipher_iv) const {
        return des3_iv(sizeof_cipher_iv);
    }
    const byte_t* (derives::*des3_iv_)(size_t& sizeof_des3_iv) const;
    virtual const byte_t* des3_iv(size_t& sizeof_des3_iv) const {
        if (des3_iv_) {
            return (this->*des3_iv_)(sizeof_des3_iv);
        }
        return test_des3_iv(sizeof_des3_iv);
    }
    virtual const byte_t* test_des3_iv(size_t& sizeof_des3_iv) const {
        sizeof_des3_iv = sizeof(cipher::des3_iv);
        return cipher::des3_iv;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...des3...cipher_text...
    const char_t* des3_encipher_text(size_t& length) const {
        const char_t* chars = 0;
        if (!(chars = this->plain_text(length))) {
            const byte_t* bytes = 0;
            if ((bytes = test_des3_plain_text(length))) {
                chars = (const char_t*)bytes;
            }
        }
        return chars;
    }
    virtual byte_t* des3_decipher_text(size_t& size) {
        byte_t* bytes = 0; size_t length = 0;
        if (0 < (length = this->encipher_text_length())) {
            bytes = this->encipher_text(size);
        } else {
            const byte_t* text = 0;
            if ((text = test_des3_cipher_text(length))) {
                bytes = this->set_encipher_text(text, length);
                size = length;
            }
        }
        return bytes;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...des3_plain_text...
    const byte_t* (derives::*des3_plain_text_)(const char_t*& chars, size_t& sizeof_des3_plain_text) const;
    virtual const byte_t* des3_plain_text(const char_t*& chars, size_t& sizeof_des3_plain_text) const {
        if (des3_plain_text_) {
            return (this->*des3_plain_text_)(chars, sizeof_des3_plain_text);
        }
        return test_des3_plain_text(sizeof_des3_plain_text);
    }
    virtual const byte_t* test_des3_plain_text(size_t& sizeof_plain_text) const {
        static const byte_t plain_text[8*4] = {
            0x37,0x36,0x35,0x34,0x33,0x32,0x31,0x20,
            0x4E,0x6F,0x77,0x20,0x69,0x73,0x20,0x74,
            0x68,0x65,0x20,0x74,0x69,0x6D,0x65,0x20,
            0x66,0x6F,0x72,0x20,0x00,0x00,0x00,0x00
        };
        sizeof_plain_text = sizeof(plain_text);
        return plain_text;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...des3_cipher_text...
    const byte_t* (derives::*des3_cipher_text_)(size_t& sizeof_des3_cipher_text) const;
    virtual const byte_t* des3_cipher_text(size_t& sizeof_des3_cipher_text) const {
        if (des3_cipher_text_) {
            return (this->*des3_cipher_text_)(sizeof_des3_cipher_text);
        }
        return test_des3_cipher_text(sizeof_des3_cipher_text);
    }
    virtual const byte_t* test_des3_cipher_text(size_t& sizeof_cipher_text) const {
        static const byte_t cipher_text[8*4] = {
            0x3F,0xE3,0x01,0xC9,0x62,0xAC,0x01,0xD0,
            0x22,0x13,0x76,0x3C,0x1C,0xBD,0x4C,0xDC,
            0x79,0x96,0x57,0xC0,0x64,0xEC,0xF5,0xD4,
            0x1C,0x67,0x38,0x12,0xCF,0xDE,0x96,0x75
        };
        sizeof_cipher_text = sizeof(cipher_text);
        return cipher_text;
    }
    /// ...
    /// ...des3...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class maint 
typedef maint<> main;

} /// namespace des3 
} /// namespace cipher 
} /// namespace crypto 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_HPP

