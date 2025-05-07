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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 11/11/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPT_HPP

#include "xos/app/console/crypto/base/main.hpp"

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OX_CIPHER_NAME "identity"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_BEGIN "static const byte_t "
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_END "[] = {"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_AFTER_OX "};"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OX_KEY "_key"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OX_IV "_iv"

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_KEY_END \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OX_KEY XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_END

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_KEY \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_BEGIN \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OX_CIPHER_NAME \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_KEY_END

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_IV_END \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OX_IV XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_END

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_IV \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_BEGIN \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OX_CIPHER_NAME \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_IV_END

//////////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_PLAIN_END \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_END

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_PLAIN \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_BEGIN \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OX_CIPHER_NAME \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_PLAIN_END

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_CIPHER_END \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_END

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_CIPHER \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_BEGIN \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OX_CIPHER_NAME \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_CIPHER_END

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_RANDOM_END \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_END

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_RANDOM \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_BEGIN \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OX_CIPHER_NAME \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_RANDOM_END

///////////////////////////////////////////////////////////////////////

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPT "encrypt"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTUSE "encrypt plain text"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTVAL_S "e::"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTVAL_C 'e'
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPT "decrypt"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTUSE "decrypt cipher text"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTVAL_S "d::"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTVAL_C 'd'
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_KEY_OPT "key"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_KEY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_KEY_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_KEY_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_KEY_OPTUSE "cipher encryption key"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_KEY_OPTVAL_S "k::"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_KEY_OPTVAL_C 'k'
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_KEY_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_KEY_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_KEY_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_KEY_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_KEY_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_IV_OPT "iv"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_IV_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_IV_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_IV_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_IV_OPTUSE "cipher initialization vector"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_IV_OPTVAL_S "i::"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_IV_OPTVAL_C 'i'
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_IV_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_IV_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_IV_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_IV_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_IV_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_KEY_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_IV_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_KEY_OPTION \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_IV_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_IO_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_IO_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ARGS 0
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace cipher {
namespace base {

/// class main_optt
template 
<class TExtends = xos::app::console::crypto::base::maint<>,  class TImplements = typename TExtends::implements>

class main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

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

    /// constructor / destructor
    main_optt()
    : run_(0), 
      Ox_cipher_name_(XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OX_CIPHER_NAME),
      before_Ox_begin_(XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_BEGIN),
      before_Ox_end_(XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_END),
      after_Ox_(XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_AFTER_OX),

      Ox_key_(XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OX_KEY),
      Ox_iv_(XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OX_IV),
      before_Ox_key_end_(XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_KEY_END), 
      before_Ox_key_(XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_KEY), 
      after_Ox_key_(XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_AFTER_OX), 
      before_Ox_iv_end_(XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_IV_END), 
      before_Ox_iv_(XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_IV), 
      after_Ox_iv_(XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_AFTER_OX), 

      before_0x_plain_(XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_PLAIN), 
      after_0x_plain_(XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_AFTER_OX), 
      before_0x_cipher_(XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_CIPHER), 
      after_0x_cipher_(XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_AFTER_OX), 
      before_0x_random_(XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_RANDOM), 
      after_0x_random_(XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_AFTER_OX) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt &copy) {
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
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_identity_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_identity_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_identity_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_identity_encipher_run(argc, argv, env))) {
            int err2 = 0;
            err = identity_encipher_run(argc, argv, env);
            if ((err2 = after_identity_encipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...identity_decipher_run
    virtual int identity_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_identity_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_identity_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_identity_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_identity_decipher_run(argc, argv, env))) {
            int err2 = 0;
            err = identity_decipher_run(argc, argv, env);
            if ((err2 = after_identity_decipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...encipher_run
    int (derives::*encipher_run_)(int argc, char_t** argv, char_t** env);
    virtual int encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (encipher_run_) {
            if (!(err = (this->*encipher_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_encipher_run(argc, argv, env)))...");
            if (!(err = default_encipher_run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(err = default_encipher_run(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...faoled on (!(err = default_encipher_run(argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_identity_encipher_run(argc, argv, env)))...");
        if (!(err = all_identity_encipher_run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(err = all_identity_encipher_run(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(err = all_identity_encipher_run(argc, argv, env)))");
        }
        return err;
    }
    virtual int before_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_encipher_run(argc, argv, env))) {
            int err2 = 0;
            err = encipher_run(argc, argv, env);
            if ((err2 = after_encipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_encipher_run;
        return err;
    }
    virtual int encipher_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int encipher_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int set_identity_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encipher_run_ = &derives::all_identity_encipher_run;
        return err;
    }
    virtual int identity_encipher_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_identity_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encipher_run_ = 0;
        return err;
    }
    virtual int identity_encipher_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...decipher_run
    int (derives::*decipher_run_)(int argc, char_t** argv, char_t** env);
    virtual int decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (decipher_run_) {
            if (!(err = (this->*decipher_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_decipher_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_identity_decipher_run(argc, argv, env)))...");
        if (!(err = all_identity_decipher_run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(err = all_identity_decipher_run(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(err = all_identity_decipher_run(argc, argv, env)))");
        }
        return err;
    }
    virtual int before_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_decipher_run(argc, argv, env))) {
            int err2 = 0;
            err = decipher_run(argc, argv, env);
            if ((err2 = after_decipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_decipher_run;
        return err;
    }
    virtual int decipher_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int decipher_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int set_identity_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        decipher_run_ = &derives::all_identity_decipher_run;
        return err;
    }
    virtual int identity_decipher_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_identity_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        decipher_run_ = 0;
        return err;
    }
    virtual int identity_decipher_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...get_cipher_key_run
    virtual int get_cipher_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const byte_t* cipher_key = 0;
        size_t sizeof_cipher_key = 0;

        if ((cipher_key = this->cipher_key(sizeof_cipher_key))) {
            this->output_x(cipher_key, sizeof_cipher_key);
        } else {
        }
        return err;
    }
    virtual int before_get_cipher_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_cipher_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_get_cipher_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_get_cipher_key_run(argc, argv, env))) {
            int err2 = 0;
            err = get_cipher_key_run(argc, argv, env);
            if ((err2 = after_get_cipher_key_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_get_cipher_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_get_cipher_key_run;
        return err;
    }
    virtual int get_cipher_key_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_get_cipher_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int get_cipher_key_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...get_cipher_iv_run
    virtual int get_cipher_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const byte_t* cipher_iv = 0;
        size_t sizeof_cipher_iv = 0;

        if ((cipher_iv = this->cipher_iv(sizeof_cipher_iv))) {
            this->output_x(cipher_iv, sizeof_cipher_iv);
        } else {
        }
        return err;
    }
    virtual int before_get_cipher_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_cipher_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_get_cipher_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_get_cipher_iv_run(argc, argv, env))) {
            int err2 = 0;
            err = get_cipher_iv_run(argc, argv, env);
            if ((err2 = after_get_cipher_iv_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_get_cipher_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_get_cipher_iv_run;
        return err;
    }
    virtual int get_cipher_iv_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_get_cipher_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int get_cipher_iv_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// out0Xln
    virtual ssize_t out0Xln(const void* out, size_t length, bool upper_case = true) {
        ssize_t count = out0xln(out, length, upper_case);
        return count;
    }
    using extends::out0xln;
    virtual ssize_t out0xln(const void* out, size_t length, bool upper_case = false) {
        ssize_t count = 0;
        size_t output_0x_cols = this->output_0x_cols();
        file_t f = this->out_std_out();
        const byte_t* col = 0;
        
        if ((col = (const byte_t*)out) && (output_0x_cols) && (length) && (output_0x_cols >= length)) {
            count = this->out0xln(f, col, length, upper_case);
        } else {
            const string_t& output_0x_nextln = this->output_0x_nextln();
            size_t remain = length;
            ssize_t amount = 0;
            do {
                if (0 < (amount = this->out0x(f, col, output_0x_cols, upper_case))) {
                    col += output_0x_cols;
                    count += amount;
                    if (0 < (amount = this->outln(output_0x_nextln))) {
                        count += amount;
                    } else {
                        if ((0 > amount)) {
                            count = amount;
                            break;
                        }
                    }
                } else {
                    if ((0 > amount)) {
                        count = amount;
                        break;
                    }
                }
                if (output_0x_cols >= (remain -= output_0x_cols)) {
                    if (0 < (amount = this->out0xln(f, col, remain, upper_case))) {
                        count += amount;
                    } else {
                        if ((0 > amount)) {
                            count = amount;
                        }
                    }
                }
            } while (output_0x_cols < remain);
        }
        return count;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...encrypt_option...
    virtual int on_get_encrypt_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_encrypt_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_encipher_run(argc, argv, env))) {
            if (!(err = encipher_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_encrypt_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_encrypt_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_encipher_run(argc, argv, env))) {
                if (!(err = encipher_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_encrypt_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_encrypt_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_encrypt_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_encrypt_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_encrypt_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* encrypt_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...decrypt_option...
    virtual int on_get_decrypt_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_decrypt_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_decipher_run(argc, argv, env))) {
            if (!(err = decipher_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_decrypt_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_decrypt_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_decipher_run(argc, argv, env))) {
                if (!(err = decipher_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_decrypt_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_decrypt_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_decrypt_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_decrypt_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_decrypt_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* decrypt_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...cipher_key_option...
    virtual int on_get_cipher_key_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_cipher_key_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_get_cipher_key_run(argc, argv, env))) {
            if (!(err = get_cipher_key_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_cipher_key_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_cipher_key_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_get_cipher_key_run(argc, argv, env))) {
                if (!(err = get_cipher_key_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_cipher_key_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_cipher_key_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_cipher_key_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_cipher_key_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_cipher_key_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* cipher_key_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_KEY_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_KEY_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...cipher_iv_option...
    virtual int on_get_cipher_iv_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_cipher_iv_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_get_cipher_iv_run(argc, argv, env))) {
            if (!(err = get_cipher_iv_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_cipher_iv_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_cipher_iv_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_get_cipher_iv_run(argc, argv, env))) {
                if (!(err = get_cipher_iv_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_cipher_iv_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_cipher_iv_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_cipher_iv_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_cipher_iv_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_cipher_iv_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* cipher_iv_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_IV_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_IV_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on_option
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTVAL_C:
            err = this->on_encrypt_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTVAL_C:
            err = this->on_decrypt_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_KEY_OPTVAL_C:
            err = this->on_cipher_key_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_IV_OPTVAL_C:
            err = this->on_cipher_iv_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    
    /// option_usage
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTVAL_C:
            chars = this->encrypt_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTVAL_C:
            chars = this->decrypt_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_KEY_OPTVAL_C:
            chars = this->cipher_key_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_CIPHER_IV_OPTVAL_C:
            chars = this->cipher_iv_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }

    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...cipher_key...
    virtual byte_t* cipher_key_data(size_t& sizeof_cipher_key) const {
        sizeof_cipher_key= 0;
        return 0;
    }
    virtual const byte_t* cipher_key(size_t& sizeof_cipher_key) const {
        sizeof_cipher_key= 0;
        return 0;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...cipher_iv...
    virtual byte_t* cipher_iv_data(size_t& sizeof_cipher_iv) const {
        sizeof_cipher_iv = 0;
        return 0;
    }
    virtual const byte_t* cipher_iv(size_t& sizeof_cipher_iv) const {
        sizeof_cipher_iv = 0;
        return 0;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual string_t& set_Ox_cipher_name() {
        string_t& Ox_cipher_name = this->Ox_cipher_name();
        set_before_Ox_key();
        set_before_Ox_iv();
        return Ox_cipher_name;
    }
    virtual string_t& Ox_cipher_name() const {
        return (string_t&)Ox_cipher_name_;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual string_t& before_Ox_begin() const {
        return (string_t&)before_Ox_begin_;
    }
    virtual string_t& before_Ox_end() const {
        return (string_t&)before_Ox_end_;
    }
    virtual string_t& after_Ox() const {
        return (string_t&)after_Ox_;
    }
    virtual string_t& Ox_key() const {
        return (string_t&)Ox_key_;
    }
    virtual string_t& Ox_iv() const {
        return (string_t&)Ox_iv_;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual string_t& set_before_Ox_key() {
        string_t& before_Ox_key = this->before_Ox_key();
        before_Ox_key.assign(before_Ox_begin());
        before_Ox_key.append(Ox_cipher_name());
        before_Ox_key.append(before_Ox_key_end());
        return before_Ox_key;
    }
    virtual string_t& before_Ox_key_end() const {
        return (string_t&)before_Ox_key_end_;
    }
    virtual string_t& before_Ox_key() const {
        return (string_t&)before_Ox_key_;
    }
    virtual string_t& after_Ox_key() const {
        return (string_t&)after_Ox_key_;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual string_t& set_before_Ox_iv() {
        string_t& before_Ox_iv = this->before_Ox_iv();
        before_Ox_iv.assign(before_Ox_begin());
        before_Ox_iv.append(Ox_cipher_name());
        before_Ox_iv.append(before_Ox_iv_end());
        return before_Ox_iv;
    }
    virtual string_t& before_Ox_iv_end() const {
        return (string_t&)before_Ox_iv_end_;
    }
    virtual string_t& before_Ox_iv() const {
        return (string_t&)before_Ox_iv_;
    }
    virtual string_t& after_Ox_iv() const {
        return (string_t&)after_Ox_iv_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual string_t& before_0x_plain() const {
        return (string_t&)before_0x_plain_;
    }
    virtual string_t& after_0x_plain() const {
        return (string_t&)after_0x_plain_;
    }
    virtual string_t& before_0x_cipher() const {
        return (string_t&)before_0x_cipher_;
    }
    virtual string_t& after_0x_cipher() const {
        return (string_t&)after_0x_cipher_;
    }
    virtual string_t& before_0x_random() const {
        return (string_t&)before_0x_random_;
    }
    virtual string_t& after_0x_random() const {
        return (string_t&)after_0x_random_;
    }

    //////////////////////////////////////////////////////////////////////////
protected:
    string_t Ox_cipher_name_,
             before_Ox_begin_, before_Ox_end_, after_Ox_, Ox_key_, Ox_iv_,
             before_Ox_key_end_, before_Ox_key_, after_Ox_key_, 
             before_Ox_iv_end_, before_Ox_iv_, after_Ox_iv_, 
             before_0x_plain_, after_0x_plain_,
             before_0x_cipher_, after_0x_cipher_,
             before_0x_random_, after_0x_random_;
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace base 
} /// namespace cipher 
} /// namespace crypto 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPT_HPP

