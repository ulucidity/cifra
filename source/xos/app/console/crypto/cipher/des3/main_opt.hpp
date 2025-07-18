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
///   Date: 11/15/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_OPT_HPP

#include "xos/app/console/crypto/cipher/base/main.hpp"

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_OX_CIPHER_NAME "des3"

//////////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_BEFORE_OX_PLAIN_END \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_END

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_BEFORE_OX_PLAIN \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_BEGIN \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_OX_CIPHER_NAME \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_PLAIN_END

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_BEFORE_OX_CIPHER_END \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_END

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_BEFORE_OX_CIPHER \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_BEGIN \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_OX_CIPHER_NAME \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_CIPHER_END

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_BEFORE_OX_RANDOM_END \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_END

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_BEFORE_OX_RANDOM \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_BEGIN \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_OX_CIPHER_NAME \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_BEFORE_OX_RANDOM_END

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_OPTIONS_CHARS_EXTEND \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_OPTIONS_OPTIONS_EXTEND \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_ARGS 0
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace cipher {
namespace des3 {

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
    main_optt()
    : run_(0), 
      before_0x_plain_(XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_BEFORE_OX_PLAIN), 
      after_0x_plain_(XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_AFTER_OX), 
      before_0x_cipher_(XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_BEFORE_OX_CIPHER), 
      after_0x_cipher_(XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_AFTER_OX), 
      before_0x_random_(XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_BEFORE_OX_RANDOM), 
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
    /// ...encipher_run
    virtual int default_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_des3_encipher_run(argc, argv, env)))...");
        if (!(err = all_des3_encipher_run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(err = all_des3_encipher_run(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(err = all_des3_encipher_run(argc, argv, env)))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...decipher_run
    virtual int default_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_des3_decipher_run(argc, argv, env)))...");
        if (!(err = all_des3_decipher_run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(err = all_des3_decipher_run(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(err = all_des3_decipher_run(argc, argv, env)))");
        }
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
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on_option
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    
    /// option_usage
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }

    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
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

    //////////////////////////////////////////////////////////////////////////
protected:
    string_t before_0x_plain_, after_0x_plain_,
             before_0x_cipher_, after_0x_cipher_,
             before_0x_random_, after_0x_random_;
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace des3 
} /// namespace cipher 
} /// namespace crypto 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_CIPHER_DES3_MAIN_OPT_HPP

