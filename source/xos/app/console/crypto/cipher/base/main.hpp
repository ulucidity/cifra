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
#ifndef XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_HPP

#include "xos/app/console/crypto/cipher/base/main_opt.hpp"
#include "xos/crypto/cipher/identity/implemented.hpp"

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CB_SIZE 128
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_SIZE 1024

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CB_IVSIZE 1
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_IVSIZE 1
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_IVSIZE_MIN \
    (XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CB_IVSIZE*XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CB_SIZE)
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_IVSIZE_MAX \
    (XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_IVSIZE*XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_SIZE)
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_IVSIZE \
    (XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_IVSIZE*XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_SIZE)

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CB_KEYSIZE 2
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_KEYSIZE 2
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KEYSIZE_MIN \
    (XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CB_KEYSIZE*XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CB_SIZE)
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KEYSIZE_MAX \
    (XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_KEYSIZE*XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_SIZE)
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KEYSIZE \
    (XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_KEYSIZE*XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_SIZE)

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_BLOCKSIZE 64
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_BLOCKSIZE \
    (XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_BLOCKSIZE*XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_SIZE)

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace cipher {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::crypto::cipher::base::main_optt<>,  class TImplements = typename TExtends::implements>

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

    typedef xos::crypto::cipher::implement cipher_t;
    typedef xos::crypto::cipher::identity::implement identity_cipher_t;
    typedef xos::crypto::cipher::identity::implemented implemented_identity_cipher_t;

    /// constructor / destructor
    maint()
    : run_(0),
      
      cipher_iv_size_min_(XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_IVSIZE_MIN), 
      cipher_iv_size_max_(XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_IVSIZE_MAX), 
      cipher_iv_size_(XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_IVSIZE), 

      cipher_key_size_min_(XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KEYSIZE_MIN), 
      cipher_key_size_max_(XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KEYSIZE_MAX), 
      cipher_key_size_(XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KEYSIZE), 

      encipher_text_size_(XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_BLOCKSIZE), 
      decipher_text_size_(XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_BLOCKSIZE),
      encipher_text_length_(0), decipher_text_length_(0) {
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
    /// ...identity_encipher_run
    virtual int identity_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* plain_text = 0;
        size_t sizeof_plain_text = 0;

        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("((plain_text = this->plain_text(sizeof_plain_text)) && (0 < sizeof_plain_text))...");
        if ((plain_text = this->plain_text(sizeof_plain_text)) && (0 < sizeof_plain_text)) {
            byte_t* encipher_text = 0;
            size_t sizeof_encipher_text = 0;

            LOGGER_IS_LOGGED_INFO("...((plain_text = this->plain_text(" << sizeof_plain_text << ")) && (0 < " << sizeof_plain_text << "))");
            LOGGER_IS_LOGGED_INFO("((encipher_text = this->encipher_text(sizeof_encipher_text)) && (1 < sizeof_encipher_text))...");
            if ((encipher_text = this->encipher_text(sizeof_encipher_text)) && (1 < sizeof_encipher_text)) {
                ssize_t count = 0;
                size_t length = 0;

                LOGGER_IS_LOGGED_INFO("...((encipher_text = this->encipher_text(" << sizeof_encipher_text << ")) && (1 < " << sizeof_encipher_text << "))");
                LOGGER_IS_LOGGED_INFO("(((length = " << sizeof_plain_text << ") >= " << sizeof_encipher_text << "))...");
                if (((length = sizeof_plain_text) >= sizeof_encipher_text)) {
                    LOGGER_IS_LOGGED_INFO("...(((" << length << " = " << sizeof_plain_text << ") >= " << sizeof_encipher_text << "))");
                    LOGGER_IS_LOGGED_INFO("" << length << " = " << sizeof_encipher_text << "-1...");
                    length = sizeof_encipher_text-1;
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (((length = " << sizeof_plain_text << ") >= " << sizeof_encipher_text << "))");
                }
                LOGGER_IS_LOGGED_INFO("((0 < (" << length << ")))...");
                if ((0 < (length))) {
                    implemented_identity_cipher_t identity;
                    
                    LOGGER_IS_LOGGED_INFO("...((0 < (" << length << ")))");
                    LOGGER_IS_LOGGED_INFO("((0 < (count = identity.encrypt(encipher_text, " << sizeof_encipher_text << ", plain_text, " << length << "))))...");
                    if ((0 < (count = identity.encrypt(encipher_text, sizeof_encipher_text, plain_text, length)))) {
                        LOGGER_IS_LOGGED_INFO("...((0 < (count = identity.encrypt(encipher_text, " << sizeof_encipher_text << ", plain_text, " << length << "))))");
                        LOGGER_IS_LOGGED_INFO("this->output_x(encipher_text, " << length << ")...");
                        this->output_x(encipher_text, length);
                        LOGGER_IS_LOGGED_INFO("...this->output_x(encipher_text, " << length << ")");
                    } else {
                        LOGGER_IS_LOGGED_INFO("...failed on ((0 < (count = identity.encrypt(encipher_text, " << sizeof_encipher_text << ", plain_text, " << length << "))))");
                    }
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on ((0 < (length)))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on ((encipher_text = this->encipher_text(sizeof_encipher_text)) && (1 < sizeof_encipher_text))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on ((plain_text = this->plain_text(sizeof_plain_text)) && (0 < sizeof_plain_text))");
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...identity_decipher_run
    virtual int identity_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t encipher_text_length = 0;

        LOGGER_IS_LOGGED_INFO("...in");
        if ((encipher_text_length = this->encipher_text_length())) {
            byte_t* encipher_text = 0;
            size_t sizeof_encipher_text = 0;

            if ((encipher_text = this->encipher_text(sizeof_encipher_text)) && (0 < sizeof_encipher_text)) {
                byte_t* decipher_text = 0;
                size_t sizeof_decipher_text = 0;

                if ((decipher_text = this->decipher_text(sizeof_decipher_text)) && (1 < sizeof_decipher_text)) {
                    ssize_t count = 0;
                    ssize_t length = 0;
                    if (((length = sizeof_encipher_text) >= sizeof_decipher_text)) {
                        length = sizeof_decipher_text-1;
                    }
                    if ((0 < (length))) {
                        implemented_identity_cipher_t identity;
                        count = identity.decrypt(decipher_text, sizeof_decipher_text, encipher_text, length);
                        if ((0 < (count))) {
                            this->output_x(decipher_text, length);
                        } else {
                        }
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...default_output_cipher_run
    int (derives::*default_output_cipher_run_)(int argc, char_t** argv, char_t** env);
    virtual int default_output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (default_output_cipher_run_) {
            if (!(err = (this->*default_output_cipher_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = this->x_output_cipher_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...encipher_default_output_cipher_run
    virtual int encipher_default_output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* encipher_chars = 0;
        const byte_t* encipher_text = 0;
        size_t sizeof_encipher_text = 0;
        
        LOGGER_IS_LOGGED_INFO("((encipher_chars = (const char_t*)(encipher_text = this->encipher_text(sizeof_encipher_text))))...");
        if ((encipher_chars = (const char_t*)(encipher_text = this->encipher_text(sizeof_encipher_text)))) {
            LOGGER_IS_LOGGED_INFO("...((\"" << encipher_chars << "\" = (const char_t*)(encipher_text = this->encipher_text(" << sizeof_encipher_text << "))))");
            LOGGER_IS_LOGGED_INFO("this->output_x(\"" << encipher_chars << "\", " << sizeof_encipher_text << ")...");
            this->output_x(encipher_text, sizeof_encipher_text);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on ((encipher_chars = (const char_t*)(encipher_text = this->encipher_text(sizeof_encipher_text))))");
        }
        return err;
    }
    virtual int set_encipher_default_output_cipher_run() {
        int err = 0;
        default_output_cipher_run_ = &derives::encipher_default_output_cipher_run;
        return err;
    }
    virtual int encipher_default_output_cipher_run_set() {
        int err = 0;
        return err;
    }
    virtual int unset_encipher_default_output_cipher_run() {
        int err = 0;
        default_output_cipher_run_ = 0;
        return err;
    }
    virtual int encipher_default_output_cipher_run_unset() {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...on_cipher_text_set
    int (derives::*on_cipher_text_set_)(const char_t* to);
    virtual int on_cipher_text_set(const char_t* to) {
        int err = 0;
        if (on_cipher_text_set_) {
            if (!(err = (this->*on_cipher_text_set_)(to))) {
            } else {
            }
        } else {
            if (!(err = encoded_on_cipher_text_set(to))) {
            } else {
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int encoded_on_cipher_text_set(const char_t* to) {
        int err = 0;
        const char_t* chars = 0;
        size_t length = 0;

        LOGGER_IS_LOGGED_INFO("((chars = this->cipher_text(length)))...");
        if ((chars = this->cipher_text(length))) {
            const string_t& cipher_text = this->cipher_text_string();
            const reader_string_t& reader_string = this->set_reader_string(cipher_text);
            string_reader_t cipher_reader(reader_string);
            byte_t* encipher_text = 0;
            size_t sizeof_encipher_text = 0;

            LOGGER_IS_LOGGED_INFO("...((\"" << chars << "\" = this->cipher_text(" << length << ")))");
            LOGGER_IS_LOGGED_INFO("((encipher_text = this->encipher_text(sizeof_encipher_text)))...");
            if ((encipher_text = this->encipher_text(sizeof_encipher_text))) {
                ssize_t count = 0;

                LOGGER_IS_LOGGED_INFO("...((encipher_text = this->encipher_text(" << sizeof_encipher_text << ")))");
                LOGGER_IS_LOGGED_INFO("(0 < (count = this->input_x(encipher_text, " << sizeof_encipher_text << ", cipher_reader)))...");
                if (0 < (count = this->input_x(encipher_text, sizeof_encipher_text, cipher_reader))) {

                    LOGGER_IS_LOGGED_INFO("...(0 < (" << count << " = this->input_x(encipher_text, " << sizeof_encipher_text << ", cipher_reader)))");
                    LOGGER_IS_LOGGED_INFO("this->set_encipher_text_size(" << count << ")...");
                    this->set_encipher_text_size(count);
                    LOGGER_IS_LOGGED_INFO("(!(err = this->on_encipher_text_set(encipher_text, " << sizeof_encipher_text << ", " << count << ")))...");
                    if (!(err = this->on_encipher_text_set(encipher_text, sizeof_encipher_text, count))) {
                        LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->on_encipher_text_set(encipher_text, " << sizeof_encipher_text << ", " << count << ")))");
                    } else {
                        LOGGER_IS_LOGGED_INFO("...failed on (!(err = this->on_encipher_text_set(encipher_text, " << sizeof_encipher_text << ", count)))");
                    }
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (0 < (count = this->input_x(encipher_text, " << sizeof_encipher_text << ", cipher_reader)))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on ((encipher_text = this->encipher_text(" << sizeof_encipher_text << ")))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on ((chars = this->cipher_text(length)))");
        }
        return err;
    }
    virtual int set_encoded_on_cipher_text_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_cipher_text_set_ = &derives::encoded_on_cipher_text_set;
        return err;
    }
    virtual int encoded_on_cipher_text_set_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_encoded_on_cipher_text_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_cipher_text_set_ = 0;
        return err;
    }
    virtual int encoded_on_cipher_text_set_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int decoded_on_cipher_text_set(const char_t* to) {
        int err = 0;
        const char_t* chars = 0; size_t length = 0;
        byte_t* encipher_text = 0; size_t sizeof_encipher_text = 0;

        LOGGER_IS_LOGGED_INFO("((chars = this->cipher_text(length)))...");
        if ((chars = this->cipher_text(length))) {
            LOGGER_IS_LOGGED_INFO("...((chars = this->cipher_text(" << length << ")))");
            LOGGER_IS_LOGGED_INFO("((encipher_text = this->encipher_text(sizeof_encipher_text)))...");
            if ((encipher_text = this->encipher_text(sizeof_encipher_text))) {
                LOGGER_IS_LOGGED_INFO("...((encipher_text = this->encipher_text(" << sizeof_encipher_text << ")))");
                LOGGER_IS_LOGGED_INFO("((" << sizeof_encipher_text << " < " << length << "))...");
                if ((sizeof_encipher_text < length)) {
                    LOGGER_IS_LOGGED_INFO("...((" << sizeof_encipher_text << " < " << length << "))");
                    length = sizeof_encipher_text;
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on ((" << sizeof_encipher_text << " < " << length << "))");
                }
                LOGGER_IS_LOGGED_INFO("this->set_encipher_text_size(" << length << ");...");
                this->set_encipher_text_size(length);
                LOGGER_IS_LOGGED_INFO("(!(err = this->on_encipher_text_set(encipher_text, " << sizeof_encipher_text << ", " << length << ")))...");
                if (!(err = this->on_encipher_text_set(encipher_text, sizeof_encipher_text, length))) {
                    LOGGER_IS_LOGGED_INFO("...(!(err = this->on_encipher_text_set(encipher_text, " << sizeof_encipher_text << ", " << length << ")))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (!(err = this->on_encipher_text_set(encipher_text, " << sizeof_encipher_text << ", " << length << ")))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on ((encipher_text = this->encipher_text(" << sizeof_encipher_text << ")))");
            }            
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on ((chars = this->cipher_text(length)))");
        }
        return err;
    }
    virtual int set_decoded_on_cipher_text_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_cipher_text_set_ = &derives::decoded_on_cipher_text_set;
        return err;
    }
    virtual int decoded_on_cipher_text_set_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_decoded_on_cipher_text_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_cipher_text_set_ = 0;
        return err;
    }
    virtual int decoded_on_cipher_text_set_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on_set_key_option
    virtual int on_set_key_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            const string_t cipher_key_text(optarg);
            const reader_string_t& reader_string = this->set_reader_string(cipher_key_text);
            string_reader_t cipher_reader(reader_string);
            byte_t* cipher_key = 0;
            size_t sizeof_cipher_key = 0;

            if ((cipher_key = this->cipher_key_data(sizeof_cipher_key))) {
                ssize_t count = 0;

                if (0 < (count = this->input_x(cipher_key, sizeof_cipher_key, cipher_reader))) {
                    this->set_cipher_key_size(count);
                    err = this->on_cipher_key_set(cipher_key, sizeof_cipher_key, count);
                }
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on_set_iv_option
    virtual int on_set_iv_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            const string_t cipher_iv_text(optarg);
            const reader_string_t& reader_string = this->set_reader_string(cipher_iv_text);
            string_reader_t cipher_reader(reader_string);
            byte_t* cipher_iv = 0;
            size_t sizeof_cipher_iv = 0;

            if ((cipher_iv = this->cipher_iv_data(sizeof_cipher_iv))) {
                ssize_t count = 0;

                if (0 < (count = this->input_x(cipher_iv, sizeof_cipher_iv, cipher_reader))) {
                    this->set_cipher_iv_size(count);
                    err = this->on_cipher_iv_set(cipher_iv, sizeof_cipher_iv, count);
                }
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...cipher_key...
    virtual int on_cipher_key_set
    (const byte_t* cipher_key, size_t sizeof_cipher_key, size_t cipher_key_size) {
        int err = 0;
        return err;
    }
    virtual byte_t* cipher_key_data(size_t& sizeof_cipher_key) const {
        byte_t* this_cipher_key = this->cipher_key();
        sizeof_cipher_key = this->sizeof_cipher_key();
        return this_cipher_key;
    }
    virtual byte_t* set_cipher_key_size(size_t sizeof_cipher_key) {
        byte_t* this_cipher_key = this->cipher_key();
        size_t& this_cipher_key_size = this->cipher_key_size();
        size_t this_sizeof_cipher_key = this->sizeof_cipher_key();
        if (this_sizeof_cipher_key < (this_cipher_key_size = sizeof_cipher_key)) {
            this_cipher_key_size = this_sizeof_cipher_key;
        }
        return this_cipher_key;
    }
    virtual const byte_t* set_cipher_key(const byte_t* cipher_key, size_t sizeof_cipher_key) {
        byte_t* this_cipher_key = this->cipher_key();
        size_t& this_cipher_key_size = this->cipher_key_size();
        if ((cipher_key) && (0 < sizeof_cipher_key)) {
            size_t cipher_key_size = this->sizeof_cipher_key();
            if (cipher_key_size <= (this_cipher_key_size = sizeof_cipher_key)) {
                this_cipher_key_size = cipher_key_size;
            } else {
                ::memset(this_cipher_key, 0, this_cipher_key_size);
            }
            ::memcpy(this_cipher_key, cipher_key, this_cipher_key_size);
        } else {
        }
        return this_cipher_key;
    }
    virtual const byte_t* cipher_key(size_t& sizeof_cipher_key) const {
        const byte_t* this_cipher_key = this->cipher_key();
        size_t& this_cipher_key_size = this->cipher_key_size();
        sizeof_cipher_key = this->sizeof_cipher_key();
        if ((this_cipher_key_size) && (this_cipher_key_size < sizeof_cipher_key)) {
            sizeof_cipher_key = this_cipher_key_size;
        }
        return this_cipher_key;
    }
    virtual byte_t* cipher_key() const {
        return (byte_t*)cipher_key_;
    }
    virtual size_t& cipher_key_size() const {
        return (size_t&)cipher_key_size_;
    }
    virtual size_t sizeof_cipher_key() const {
        return sizeof(cipher_key_);
    }
    virtual size_t& set_cipher_key_size_min(size_t to) {
        cipher_key_size_min_ = to;
        return cipher_key_size_min_;
    }
    virtual size_t& cipher_key_size_min() const {
        return (size_t&)cipher_key_size_min_;
    }
    virtual size_t& set_cipher_key_size_max(size_t to) {
        cipher_key_size_max_ = to;
        return cipher_key_size_max_;
    }
    virtual size_t& cipher_key_size_max() const {
        return (size_t&)cipher_key_size_max_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...cipher_iv...
    virtual int on_cipher_iv_set
    (const byte_t* cipher_iv, size_t sizeof_cipher_iv, size_t cipher_iv_size) {
        int err = 0;
        return err;
    }
    virtual byte_t* cipher_iv_data(size_t& sizeof_cipher_iv) const {
        byte_t* this_cipher_iv = this->cipher_iv();
        sizeof_cipher_iv = this->sizeof_cipher_iv();
        return this_cipher_iv;
    }
    virtual byte_t* set_cipher_iv_size(size_t sizeof_cipher_iv) {
        byte_t* this_cipher_iv = this->cipher_iv();
        size_t& this_cipher_iv_size = this->cipher_iv_size();
        size_t this_sizeof_cipher_iv = this->sizeof_cipher_iv();
        if (this_sizeof_cipher_iv < (this_cipher_iv_size = sizeof_cipher_iv)) {
            this_cipher_iv_size = this_sizeof_cipher_iv;
        }
        return this_cipher_iv;
    }
    virtual const byte_t* set_cipher_iv(const byte_t* cipher_iv, size_t sizeof_cipher_iv) {
        byte_t* this_cipher_iv = this->cipher_iv();
        size_t& this_cipher_iv_size = this->cipher_iv_size();
        if ((cipher_iv) && (0 < sizeof_cipher_iv)) {
            size_t cipher_iv_size = this->sizeof_cipher_iv();
            if (cipher_iv_size <= (this_cipher_iv_size = sizeof_cipher_iv)) {
                this_cipher_iv_size = cipher_iv_size;
            } else {
                ::memset(this_cipher_iv, 0, this_cipher_iv_size);
            }
            ::memcpy(this_cipher_iv, cipher_iv, this_cipher_iv_size);
        } else {
        }
        return this_cipher_iv;
    }
    virtual const byte_t* cipher_iv(size_t& sizeof_cipher_iv) const {
        const byte_t* this_cipher_iv = this->cipher_iv();
        size_t& this_cipher_iv_size = this->cipher_iv_size();
        sizeof_cipher_iv = this->sizeof_cipher_iv();
        if ((this_cipher_iv_size) && (this_cipher_iv_size < sizeof_cipher_iv)) {
            sizeof_cipher_iv = this_cipher_iv_size;
        }
        return this_cipher_iv;
    }
    virtual byte_t* cipher_iv() const {
        return (byte_t*)cipher_iv_;
    }
    virtual size_t& cipher_iv_size() const {
        return (size_t&)cipher_iv_size_;
    }
    virtual size_t sizeof_cipher_iv() const {
        return sizeof(cipher_iv_);
    }
    virtual size_t& set_cipher_iv_size_min(size_t to) {
        cipher_iv_size_min_ = to;
        return cipher_iv_size_min_;
    }
    virtual size_t& cipher_iv_size_min() const {
        return (size_t&)cipher_iv_size_min_;
    }
    virtual size_t& set_cipher_iv_size_max(size_t to) {
        cipher_iv_size_max_ = to;
        return cipher_iv_size_max_;
    }
    virtual size_t& cipher_iv_size_max() const {
        return (size_t&)cipher_iv_size_max_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...encipher_text
    virtual int on_encipher_text_set
    (byte_t* encipher_text, size_t sizeof_encipher_text, size_t encipher_text_size) {
        int err = 0;
        if (!(err = set_encipher_default_output_cipher_run())) {
            if (!(err = encipher_default_output_cipher_run_set())) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual byte_t* set_encipher_text(const byte_t* to, size_t length) {
        if ((to) && (length)) {
            size_t sizeof_encipher_text = sizeof(encipher_text_);
            if (length > sizeof_encipher_text) {
                length = sizeof_encipher_text;
            }
            ::memcpy(encipher_text_, to, length);
        }
        return encipher_text_;
    }
    virtual size_t set_encipher_text_size(size_t to) {
        encipher_text_length_ = (encipher_text_size_ = to);
        return encipher_text_size_;
    }
    virtual size_t encipher_text_size() const {
        return encipher_text_size_;
    }
    virtual size_t encipher_text_length() const {
        return encipher_text_length_;
    }
    virtual byte_t* encipher_text_data(size_t& sizeof_encipher_text) const {
        sizeof_encipher_text = sizeof(encipher_text_);
        return (byte_t*)encipher_text_;
    }
    virtual byte_t* encipher_text(size_t& sizeof_encipher_text) const {
        sizeof_encipher_text = sizeof(encipher_text_);
        if ((encipher_text_size_) && (encipher_text_size_ < sizeof_encipher_text)) {
            sizeof_encipher_text = encipher_text_size_;
        }
        return (byte_t*)encipher_text_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...decipher_text
    virtual size_t set_decipher_text_size(size_t to) {
        decipher_text_length_ = (decipher_text_size_ = to);
        return decipher_text_size_;
    }
    virtual size_t decipher_text_size() const {
        return decipher_text_size_;
    }
    virtual byte_t* decipher_text(size_t& sizeof_decipher_text) const {
        sizeof_decipher_text = sizeof(decipher_text_);
        return (byte_t*)decipher_text_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    size_t cipher_iv_size_min_, cipher_iv_size_max_, cipher_iv_size_, 
           cipher_key_size_min_, cipher_key_size_max_, cipher_key_size_, 
           encipher_text_size_, decipher_text_size_,
           encipher_text_length_, decipher_text_length_;

    byte_t cipher_iv_[XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_IVSIZE],
           cipher_key_[XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KEYSIZE],
           encipher_text_[XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_BLOCKSIZE],
           decipher_text_[XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_BLOCKSIZE];
}; /// class maint 
typedef maint<> main;

} /// namespace base 
} /// namespace cipher 
} /// namespace crypto 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_HPP
