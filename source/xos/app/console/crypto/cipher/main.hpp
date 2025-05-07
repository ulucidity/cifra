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
///   Date: 11/11/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_HPP

#include "xos/app/console/crypto/cipher/main_opt.hpp"

#include "xos/crypto/cipher/aes/devine/implemented.hpp"
#include "xos/crypto/cipher/des3/openssl/implemented.hpp"
#include "xos/crypto/cipher/rc4/etiris/implemented.hpp"

#include "xos/app/console/crypto/cipher/aes/keys.hpp"
#include "xos/app/console/crypto/cipher/des3/keys.hpp"
#include "xos/app/console/crypto/cipher/rc4/keys.hpp"

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace cipher {

/// class maint
template 
<class TExtends = xos::app::console::crypto::cipher::main_optt<>,  class TImplements = typename TExtends::implements>

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

    typedef xos::crypto::cipher::aes::implement aes_cipher_t;
    typedef xos::crypto::cipher::aes::devine::implemented devine_aes_cipher_t;
    typedef devine_aes_cipher_t default_aes_cipher_t;

    typedef xos::crypto::cipher::des3::implement des3_cipher_t;
    typedef xos::crypto::cipher::des3::openssl::implemented openssl_des3_cipher_t;
    typedef openssl_des3_cipher_t default_des3_cipher_t;

    typedef xos::crypto::cipher::rc4::implement rc4_cipher_t;
    typedef xos::crypto::cipher::rc4::etiris::implemented etiris_rc4_cipher_t;
    typedef etiris_rc4_cipher_t default_rc4_cipher_t;

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
    /// aes_encipher_run
    virtual int aes_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* plain_text = 0;
        size_t sizeof_plain_text = 0;
        ssize_t length = 0;

        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("((plain_text = this->aes_encipher_text(sizeof_plain_text)))...");
        if ((plain_text = this->aes_encipher_text(sizeof_plain_text))) {
            const byte_t* aes_key = 0;
            size_t sizeof_aes_key = 0;

            LOGGER_IS_LOGGED_INFO("...((plain_text = this->aes_encipher_text(" << sizeof_plain_text << ")))");
            LOGGER_IS_LOGGED_INFO("if ((aes_key = this->aes_key(sizeof_aes_key)))...");
            if ((aes_key = this->aes_key(sizeof_aes_key))) {
                const byte_t* aes_iv = 0;
                size_t sizeof_aes_iv = 0;

                LOGGER_IS_LOGGED_INFO("...if ((aes_key = this->aes_key(" << sizeof_aes_key << ")))");
                LOGGER_IS_LOGGED_INFO("((aes_iv = this->aes_iv(sizeof_aes_iv)))...");
                if ((aes_iv = this->aes_iv(sizeof_aes_iv))) {
                    byte_t* encipher_text = 0;
                    size_t sizeof_encipher_text = 0;
    
                    LOGGER_IS_LOGGED_INFO("...((aes_iv = this->aes_iv(" << sizeof_aes_iv << ")))");
                    LOGGER_IS_LOGGED_INFO("((encipher_text = this->encipher_text(sizeof_encipher_text)))...");
                    if ((encipher_text = this->encipher_text(sizeof_encipher_text))) {
                        default_aes_cipher_t aes(aes_key, sizeof_aes_key, aes_iv, sizeof_aes_iv);
                        
                        LOGGER_IS_LOGGED_INFO("...((encipher_text = this->encipher_text(" << sizeof_encipher_text << ")))");
                        LOGGER_IS_LOGGED_INFO("(0 < (length = aes.encrypt(encipher_text, " << sizeof_encipher_text << ", plain_text, " << sizeof_plain_text << ")))...");
                        if (0 < (length = aes.encrypt(encipher_text, sizeof_encipher_text, plain_text, sizeof_plain_text))) {
                            LOGGER_IS_LOGGED_INFO("...(0 < (length = aes.encrypt(encipher_text, " << sizeof_encipher_text << ", plain_text, " << sizeof_plain_text << ")))");
                            LOGGER_IS_LOGGED_INFO("this->output_x(encipher_text, " << length << ")...");
                            this->output_x(encipher_text, length);
                        }
                    }
                }
            }
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// aes_decipher_run
    virtual int aes_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        byte_t* encipher_text = 0;
        size_t sizeof_encipher_text = 0;
        ssize_t length = 0;

        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("((encipher_text = this->aes_decipher_text(sizeof_encipher_text)))...");
        if ((encipher_text = this->aes_decipher_text(sizeof_encipher_text))) {
            const byte_t* aes_key = 0;
            size_t sizeof_aes_key = 0;

            LOGGER_IS_LOGGED_INFO("...((encipher_text = this->aes_decipher_text(" << sizeof_encipher_text << ")))");
            LOGGER_IS_LOGGED_INFO("((aes_key = this->aes_key(sizeof_aes_key)))...");
            if ((aes_key = this->aes_key(sizeof_aes_key))) {
                const byte_t* aes_iv = 0;
                size_t sizeof_aes_iv = 0;

                LOGGER_IS_LOGGED_INFO("...((aes_key = this->aes_key(" << sizeof_aes_key << ")))");
                LOGGER_IS_LOGGED_INFO("((aes_iv = this->aes_iv(sizeof_aes_iv)))...");
                if ((aes_iv = this->aes_iv(sizeof_aes_iv))) {
                    byte_t* decipher_text = 0;
                    size_t sizeof_decipher_text = 0;
    
                    LOGGER_IS_LOGGED_INFO("...((aes_iv = this->aes_iv(" << sizeof_aes_iv << ")))");
                    LOGGER_IS_LOGGED_INFO("((decipher_text = this->decipher_text(sizeof_decipher_text))) ...");
                    if ((decipher_text = this->decipher_text(sizeof_decipher_text))) {
                        default_aes_cipher_t aes(aes_key, sizeof_aes_key, aes_iv, sizeof_aes_iv);
                        size_t encipher_text_size = this->encipher_text_size();
                        
                        LOGGER_IS_LOGGED_INFO("...((decipher_text = this->decipher_text(" << sizeof_decipher_text << "))) ");
                        LOGGER_IS_LOGGED_INFO("((encipher_text_size) && (encipher_text_size < " << sizeof_encipher_text << "))...");
                        if ((encipher_text_size) && (encipher_text_size < sizeof_encipher_text)) {
                            LOGGER_IS_LOGGED_INFO("...((encipher_text_size) && (encipher_text_size < " << sizeof_encipher_text << "))");
                            LOGGER_IS_LOGGED_INFO("sizeof_encipher_text = " << encipher_text_size << "...");
                            sizeof_encipher_text = encipher_text_size;
                        }
                        LOGGER_IS_LOGGED_INFO("(0 < (length = aes.decrypt(decipher_text, " << sizeof_decipher_text << ", encipher_text, " << sizeof_encipher_text << ")))...");
                        if (0 < (length = aes.decrypt(decipher_text, sizeof_decipher_text, encipher_text, sizeof_encipher_text))) {
                            LOGGER_IS_LOGGED_INFO("...(0 < (length = aes.decrypt(decipher_text, " << sizeof_decipher_text << ", encipher_text, " << sizeof_encipher_text << ")))");
                            LOGGER_IS_LOGGED_INFO("this->output_x(decipher_text, " << length << ")...");
                            this->output_x(decipher_text, length);
                        }
                    }
                }
            }
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

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
    /// rc4_encipher_run
    virtual int rc4_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* plain_text = 0;
        size_t sizeof_plain_text = 0;
        ssize_t length = 0;

        if ((plain_text = this->rc4_encipher_text(sizeof_plain_text))) {
            const byte_t* rc4_key = 0;
            size_t sizeof_rc4_key = 0;

            if ((rc4_key = this->rc4_key(sizeof_rc4_key))) {
                const byte_t* rc4_iv = 0;
                size_t sizeof_rc4_iv = 0;
                byte_t* encipher_text = 0;
                size_t sizeof_encipher_text = 0;

                if ((rc4_iv = this->rc4_iv(sizeof_rc4_iv))) {
                    err = error_unexpected;
                    return err;
                }
                if ((encipher_text = this->encipher_text(sizeof_encipher_text))) {
                    default_rc4_cipher_t rc4(rc4_key, sizeof_rc4_key);
                    
                    if (0 < (length = rc4.encrypt(encipher_text, sizeof_encipher_text, plain_text, sizeof_plain_text))) {
                        this->output_x(encipher_text, length);
                    }
                }
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// rc4_decipher_run
    virtual int rc4_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        byte_t* encipher_text = 0;
        size_t sizeof_encipher_text = 0;
        ssize_t length = 0;

        if ((encipher_text = this->rc4_decipher_text(sizeof_encipher_text))) {
            const byte_t* rc4_key = 0;
            size_t sizeof_rc4_key = 0;

            if ((rc4_key = this->rc4_key(sizeof_rc4_key))) {
                const byte_t* rc4_iv = 0;
                size_t sizeof_rc4_iv = 0;
                byte_t* decipher_text = 0;
                size_t sizeof_decipher_text = 0;

                if ((rc4_iv = this->rc4_iv(sizeof_rc4_iv))) {
                    err = error_unexpected;
                    return err;
                }
                if ((decipher_text = this->decipher_text(sizeof_decipher_text))) {
                    default_rc4_cipher_t rc4(rc4_key, sizeof_rc4_key);
                    size_t encipher_text_size = this->encipher_text_size();
                    
                    if ((encipher_text_size) && (encipher_text_size < sizeof_encipher_text)) {
                        sizeof_encipher_text = encipher_text_size;
                    }
                    if (0 < (length = rc4.decrypt(decipher_text, sizeof_decipher_text, encipher_text, sizeof_encipher_text))) {
                        this->output_x(decipher_text, length);
                    }
                }
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...aes...
    /// ...
    /// ...aes...key...
    virtual const byte_t* aes_cipher_key(size_t& sizeof_cipher_key) const {
        return aes_key(sizeof_cipher_key);
    }
    const byte_t* (derives::*aes_key_)(size_t& sizeof_aes_key) const;
    virtual const byte_t* aes_key(size_t& sizeof_aes_key) const {
        if (aes_key_) {
            return (this->*aes_key_)(sizeof_aes_key);
        }
        return test_aes_key(sizeof_aes_key);
    }
    virtual const byte_t* test_aes_key(size_t& sizeof_aes_key) const {
        sizeof_aes_key = sizeof(cipher::aes_key);
        return cipher::aes_key;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...aes...iv...
    virtual const byte_t* aes_cipher_iv(size_t& sizeof_cipher_iv) const {
        return aes_iv(sizeof_cipher_iv);
    }
    const byte_t* (derives::*aes_iv_)(size_t& sizeof_aes_iv) const;
    virtual const byte_t* aes_iv(size_t& sizeof_aes_iv) const {
        if (aes_iv_) {
            return (this->*aes_iv_)(sizeof_aes_iv);
        }
        return test_aes_iv(sizeof_aes_iv);
    }
    virtual const byte_t* test_aes_iv(size_t& sizeof_aes_iv) const {
        sizeof_aes_iv = sizeof(cipher::aes_iv);
        return cipher::aes_iv;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...aes...cipher_text...
    const char_t* aes_encipher_text(size_t& length) const {
        const char_t* chars = 0;
        
        LOGGER_IS_LOGGED_INFO("(!(chars = this->plain_text(length)))...");
        if (!(chars = this->plain_text(length))) {
            const byte_t* bytes = 0;
            LOGGER_IS_LOGGED_INFO("...(!(chars = this->plain_text(length)))");
            LOGGER_IS_LOGGED_INFO("((bytes = test_aes_plain_text(length)))...");
            if ((bytes = test_aes_plain_text(length))) {
                LOGGER_IS_LOGGED_INFO("...((\"" << ((const char_t*)bytes) << "\" = test_aes_plain_text(" << length << ")))");
                chars = (const char_t*)bytes;
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on ((bytes = test_aes_plain_text(length)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(\"" << chars << "\" = this->plain_text(" << length << ")))");
        }
        return chars;
    }
    virtual byte_t* aes_decipher_text(size_t& size) {
        byte_t* bytes = 0; size_t length = 0;
        if (0 < (length = this->encipher_text_length())) {
            bytes = this->encipher_text(size);
        } else {
            const byte_t* text = 0;
            if ((text = test_aes_cipher_text(length))) {
                bytes = this->set_encipher_text(text, length);
                size = length;
            }
        }
        return bytes;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...aes_plain_text...
    const byte_t* (derives::*aes_plain_text_)(const char_t*& chars, size_t& sizeof_aes_plain_text) const;
    virtual const byte_t* aes_plain_text(const char_t*& chars, size_t& sizeof_aes_plain_text) const {
        if (aes_plain_text_) {
            return (this->*aes_plain_text_)(chars, sizeof_aes_plain_text);
        }
        return test_aes_plain_text(sizeof_aes_plain_text);
    }
    virtual const byte_t* test_aes_plain_text(size_t& sizeof_plain_text) const {
        static const byte_t plain_text[8*4] = {
            0x37,0x36,0x35,0x34,0x33,0x32,0x31,0x20,
            0x4E,0x6F,0x77,0x20,0x69,0x73,0x20,0x74,
            0x68,0x65,0x20,0x74,0x69,0x6D,0x65,0x20,
            0x66,0x6F,0x72,0x20,0x00,0x31,0x00,0x00
        };
        sizeof_plain_text = sizeof(plain_text);
        return plain_text;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...aes_cipher_text...
    const byte_t* (derives::*aes_cipher_text_)(size_t& sizeof_aes_cipher_text) const;
    virtual const byte_t* aes_cipher_text(size_t& sizeof_aes_cipher_text) const {
        if (aes_cipher_text_) {
            return (this->*aes_cipher_text_)(sizeof_aes_cipher_text);
        }
        return test_aes_cipher_text(sizeof_aes_cipher_text);
    }
    virtual const byte_t* test_aes_cipher_text(size_t& sizeof_cipher_text) const {
        static const byte_t cipher_text[8*4] = {
            0x38,0x2A,0xB1,0xB3,0xD5,0x33,0x6B,0x09,
            0x64,0xDE,0x64,0x01,0x32,0x4C,0x05,0x38,
            0x4B,0xBB,0x0A,0x3A,0x7B,0xF5,0xE5,0x0C,
            0x20,0xA7,0x80,0xD1,0x5E,0xC3,0x37,0xEF
        };
        sizeof_cipher_text = sizeof(cipher_text);
        return cipher_text;
    }
    /// ...
    /// ...aes...
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
    /// ...rc4...
    /// ...
    /// ...rc4...key...
    virtual const byte_t* rc4_cipher_key(size_t& sizeof_cipher_key) const {
        return rc4_key(sizeof_cipher_key);
    }
    const byte_t* (derives::*rc4_key_)(size_t& sizeof_rc4_key) const;
    virtual const byte_t* rc4_key(size_t& sizeof_rc4_key) const {
        if (rc4_key_) {
            return (this->*rc4_key_)(sizeof_rc4_key);
        }
        return test_rc4_key(sizeof_rc4_key);
    }
    virtual const byte_t* test_rc4_key(size_t& sizeof_rc4_key) const {
        sizeof_rc4_key = sizeof(cipher::rc4_key);
        return cipher::rc4_key;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...rc4...iv...
    virtual const byte_t* rc4_cipher_iv(size_t& sizeof_cipher_iv) const {
        return rc4_iv(sizeof_cipher_iv);
    }
    const byte_t* (derives::*rc4_iv_)(size_t& sizeof_rc4_iv) const;
    virtual const byte_t* rc4_iv(size_t& sizeof_rc4_iv) const {
        if (rc4_iv_) {
            return (this->*rc4_iv_)(sizeof_rc4_iv);
        }
        return test_rc4_iv(sizeof_rc4_iv);
    }
    virtual const byte_t* test_rc4_iv(size_t& sizeof_rc4_iv) const {
        sizeof_rc4_iv = 0;
        return 0;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...rc4...cipher_text...
    const char_t* rc4_encipher_text(size_t& length) const {
        const char_t* chars = 0;
        if (!(chars = this->plain_text(length))) {
            const byte_t* bytes = 0;
            if ((bytes = test_rc4_plain_text(length))) {
                chars = (const char_t*)bytes;
            }
        }
        return chars;
    }
    virtual byte_t* rc4_decipher_text(size_t& size) {
        byte_t* bytes = 0; size_t length = 0;
        if (0 < (length = this->encipher_text_length())) {
            bytes = this->encipher_text(size);
        } else {
            const byte_t* text = 0;
            if ((text = test_rc4_cipher_text(length))) {
                bytes = this->set_encipher_text(text, length);
                size = length;
            }
        }
        return bytes;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...rc4_plain_text...
    const byte_t* (derives::*rc4_plain_text_)(const char_t*& chars, size_t& sizeof_rc4_plain_text) const;
    virtual const byte_t* rc4_plain_text(const char_t*& chars, size_t& sizeof_rc4_plain_text) const {
        if (rc4_plain_text_) {
            return (this->*rc4_plain_text_)(chars, sizeof_rc4_plain_text);
        }
        return test_rc4_plain_text(sizeof_rc4_plain_text);
    }
    virtual const byte_t* test_rc4_plain_text(size_t& sizeof_plain_text) const {
        static const byte_t plain_text[8*3+4] = {
            0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0,
            0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0,
            0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0,
            0x12, 0x34, 0x56, 0x78,
        };
        sizeof_plain_text = sizeof(plain_text);
        return plain_text;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...rc4_cipher_text...
    const byte_t* (derives::*rc4_cipher_text_)(size_t& sizeof_rc4_cipher_text) const;
    virtual const byte_t* rc4_cipher_text(size_t& sizeof_rc4_cipher_text) const {
        if (rc4_cipher_text_) {
            return (this->*rc4_cipher_text_)(sizeof_rc4_cipher_text);
        }
        return test_rc4_cipher_text(sizeof_rc4_cipher_text);
    }
    virtual const byte_t* test_rc4_cipher_text(size_t& sizeof_cipher_text) const {
        static const byte_t cipher_text[8*3+4] = {
            0x66, 0xa0, 0x94, 0x9f, 0x8a, 0xf7, 0xd6, 0x89,
            0x1f, 0x7f, 0x83, 0x2b, 0xa8, 0x33, 0xc0, 0x0c,
            0x89, 0x2e, 0xbe, 0x30, 0x14, 0x3c, 0xe2, 0x87,
            0x40, 0x01, 0x1e, 0xcf,
        };
        sizeof_cipher_text = sizeof(cipher_text);
        return cipher_text;
    }
    /// ...
    /// ...rc4...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class maint 
typedef maint<> main;

} /// namespace cipher 
} /// namespace crypto 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_HPP
