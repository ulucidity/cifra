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
#ifndef XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPT_HPP

#include "xos/app/console/crypto/cipher/base/main.hpp"

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPT "algorithm"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_AES_C "a"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_DES3_C "d"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_RC4_C "r"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_IDENTITY_C "i"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_AES_S "aes"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_DES3_S "des3"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_RC4_S "rc4"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_IDENTITY_S "identity"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_AES \
    "(" XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_AES_C \
    ")" XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_AES_S
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_DES3 \
    "(" XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_DES3_C \
    ")" XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_DES3_S
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_RC4 \
    "(" XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_RC4_C \
    ")" XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_RC4_S
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_IDENTITY \
    "(" XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_IDENTITY_C \
    ")" XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_IDENTITY_S
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG \
    "[{ " XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_AES \
    ", " XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_DES3 \
    ", " XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_RC4  \
    ", " XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_IDENTITY " }]"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTUSE "cipher algorithm"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTVAL_S "a::"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTVAL_C 'a'
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ARGS 0
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace cipher {

/// class main_optt
template 
<class TExtends = xos::app::console::crypto::cipher::base::maint<>,  class TImplements = typename TExtends::implements>

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
    main_optt(): run_(0) {
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
    /// ...encipher_run
    int (derives::*encipher_run_)(int argc, char_t** argv, char_t** env);
    virtual int encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (encipher_run_) {
            if (!(err = (this->*encipher_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = extends::encipher_run(argc, argv, env)))...");
            if (!(err = extends::encipher_run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(err = extends::encipher_run(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(err = extends::encipher_run(argc, argv, env)))");
            }
        }
        return err;
    }
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
            LOGGER_IS_LOGGED_INFO("(!(err = extends::decipher_run(argc, argv, env)))...");
            if (!(err = extends::decipher_run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(err = extends::decipher_run(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(err = extends::decipher_run(argc, argv, env)))");
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...aes_encipher_run
    virtual int aes_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_aes_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_aes_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_aes_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_aes_encipher_run(argc, argv, env))) {
            int err2 = 0;
            err = aes_encipher_run(argc, argv, env);
            if ((err2 = after_aes_encipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_aes_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encipher_run_ = &derives::all_aes_encipher_run;
        return err;
    }
    virtual int aes_encipher_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_aes_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encipher_run_ = 0;
        return err;
    }
    virtual int aes_encipher_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...aes_decipher_run
    virtual int aes_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_aes_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_aes_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_aes_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_aes_decipher_run(argc, argv, env))) {
            int err2 = 0;
            err = aes_decipher_run(argc, argv, env);
            if ((err2 = after_aes_decipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_aes_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        decipher_run_ = &derives::all_aes_decipher_run;
        return err;
    }
    virtual int aes_decipher_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_aes_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        decipher_run_ = 0;
        return err;
    }
    virtual int aes_decipher_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...des3_encipher_run
    virtual int des3_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_des3_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_des3_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_des3_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_des3_encipher_run(argc, argv, env))) {
            int err2 = 0;
            err = des3_encipher_run(argc, argv, env);
            if ((err2 = after_des3_encipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_des3_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encipher_run_ = &derives::all_des3_encipher_run;
        return err;
    }
    virtual int des3_encipher_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_des3_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encipher_run_ = 0;
        return err;
    }
    virtual int des3_encipher_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...des3_decipher_run
    virtual int des3_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_des3_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_des3_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_des3_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_des3_decipher_run(argc, argv, env))) {
            int err2 = 0;
            err = des3_decipher_run(argc, argv, env);
            if ((err2 = after_des3_decipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_des3_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        decipher_run_ = &derives::all_des3_decipher_run;
        return err;
    }
    virtual int des3_decipher_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_des3_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        decipher_run_ = 0;
        return err;
    }
    virtual int des3_decipher_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...rc4_encipher_run
    virtual int rc4_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_rc4_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_rc4_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_rc4_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_rc4_encipher_run(argc, argv, env))) {
            int err2 = 0;
            err = rc4_encipher_run(argc, argv, env);
            if ((err2 = after_rc4_encipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_rc4_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encipher_run_ = &derives::all_rc4_encipher_run;
        return err;
    }
    virtual int rc4_encipher_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_rc4_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encipher_run_ = 0;
        return err;
    }
    virtual int rc4_encipher_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...rc4_decipher_run
    virtual int rc4_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_rc4_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_rc4_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_rc4_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_rc4_decipher_run(argc, argv, env))) {
            int err2 = 0;
            err = rc4_decipher_run(argc, argv, env);
            if ((err2 = after_rc4_decipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_rc4_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        decipher_run_ = &derives::all_rc4_decipher_run;
        return err;
    }
    virtual int rc4_decipher_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_rc4_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        decipher_run_ = 0;
        return err;
    }
    virtual int rc4_decipher_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...aes_cipher_algorithm_option...
    virtual int on_set_aes_cipher_algorithm_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_aes_cipher_algorithm_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_aes_encipher_run(argc, argv, env))) {
                if (!(err = aes_encipher_run_set(argc, argv, env))) {
                    if (!(err = set_aes_decipher_run(argc, argv, env))) {
                        if (!(err = aes_decipher_run_set(argc, argv, env))) {
                        } else {}
                    } else {}
                } else {}
            } else {}
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...des3_cipher_algorithm_option...
    virtual int on_set_des3_cipher_algorithm_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_des3_cipher_algorithm_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_des3_encipher_run(argc, argv, env))) {
                if (!(err = des3_encipher_run_set(argc, argv, env))) {
                    if (!(err = set_des3_decipher_run(argc, argv, env))) {
                        if (!(err = des3_decipher_run_set(argc, argv, env))) {
                        } else {}
                    } else {}
                } else {}
            } else {}
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...rc4_cipher_algorithm_option...
    virtual int on_set_rc4_cipher_algorithm_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_rc4_cipher_algorithm_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_rc4_encipher_run(argc, argv, env))) {
                if (!(err = rc4_encipher_run_set(argc, argv, env))) {
                    if (!(err = set_rc4_decipher_run(argc, argv, env))) {
                        if (!(err = rc4_decipher_run_set(argc, argv, env))) {
                        } else {}
                    } else {}
                } else {}
            } else {}
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...identity_cipher_algorithm_option...
    virtual int on_set_identity_cipher_algorithm_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_identity_cipher_algorithm_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = this->set_identity_encipher_run(argc, argv, env))) {
                if (!(err = this->identity_encipher_run_set(argc, argv, env))) {
                    if (!(err = this->set_identity_decipher_run(argc, argv, env))) {
                        if (!(err = this->identity_decipher_run_set(argc, argv, env))) {
                        } else {}
                    } else {}
                } else {}
            } else {}
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...cipher_algorithm_option...
    virtual int on_get_cipher_algorithm_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_cipher_algorithm_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_cipher_algorithm_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if ((!(optarg[1]) && (XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_AES_C[0] == (optarg[0])))
                || !(chars_t::compare(optarg, XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_AES_S))) {
                if (!(err = on_set_aes_cipher_algorithm_option(optarg, optind, argc, argv, env))) {
                    if (!(err = on_aes_cipher_algorithm_option_set(optarg, optind, argc, argv, env))) {
                    } else {
                    }
                } else {
                }
            } else {
                if ((!(optarg[1]) && (XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_DES3_C[0] == (optarg[0])))
                    || !(chars_t::compare(optarg, XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_DES3_S))) {
                    if (!(err = on_set_des3_cipher_algorithm_option(optarg, optind, argc, argv, env))) {
                        if (!(err = on_des3_cipher_algorithm_option_set(optarg, optind, argc, argv, env))) {
                        } else {
                        }
                    } else {
                    }
                } else {
                    if ((!(optarg[1]) && (XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_RC4_C[0] == (optarg[0])))
                        || !(chars_t::compare(optarg, XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_RC4_S))) {
                        if (!(err = on_set_rc4_cipher_algorithm_option(optarg, optind, argc, argv, env))) {
                            if (!(err = on_rc4_cipher_algorithm_option_set(optarg, optind, argc, argv, env))) {
                            } else {
                            }
                        } else {
                        }
                    } else {
                        if ((!(optarg[1]) && (XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_IDENTITY_C[0] == (optarg[0])))
                            || !(chars_t::compare(optarg, XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG_IDENTITY_S))) {
                            if (!(err = on_set_identity_cipher_algorithm_option(optarg, optind, argc, argv, env))) {
                                if (!(err = on_identity_cipher_algorithm_option_set(optarg, optind, argc, argv, env))) {
                                } else {
                                }
                            } else {
                            }
                        } else {
                            err = this->on_invalid_option_arg_value(optarg, optind, argc, argv, env);
                        }
                    }
                }
            }
        } else {
        }
        return err;
    }
    virtual int on_cipher_algorithm_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_cipher_algorithm_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_cipher_algorithm_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_cipher_algorithm_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_cipher_algorithm_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_cipher_algorithm_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* cipher_algorithm_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTARG;
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

        case XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTVAL_C:
            err = this->on_cipher_algorithm_option(optval, optarg, optname, optind, argc, argv, env);
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

        case XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_ALGORITHM_OPTVAL_C:
            chars = this->cipher_algorithm_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }

    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace cipher 
} /// namespace crypto 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPT_HPP
