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
///   Date: 11/29/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_OPT_HPP

#include "xos/app/console/output/base/main.hpp"

#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ENCODE_OPT "encode"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ENCODE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ENCODE_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ENCODE_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ENCODE_OPTUSE "encode plain text"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ENCODE_OPTVAL_S "e::"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ENCODE_OPTVAL_C 'e'
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ENCODE_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ENCODE_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ENCODE_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ENCODE_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ENCODE_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_DECODE_OPT "decode"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_DECODE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_DECODE_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_DECODE_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_DECODE_OPTUSE "decode code text"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_DECODE_OPTVAL_S "d::"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_DECODE_OPTVAL_C 'd'
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_DECODE_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_DECODE_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_DECODE_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_DECODE_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_DECODE_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_PLAIN_TEXT_OPT "plain"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_PLAIN_TEXT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_PLAIN_TEXT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_PLAIN_TEXT_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_PLAIN_TEXT_OPTUSE "plain text"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_PLAIN_TEXT_OPTVAL_S "p::"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_PLAIN_TEXT_OPTVAL_C 'p'
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_PLAIN_TEXT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_PLAIN_TEXT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_PLAIN_TEXT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_PLAIN_TEXT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_PLAIN_TEXT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_CODE_TEXT_OPT "code"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_CODE_TEXT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_CODE_TEXT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_CODE_TEXT_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_CODE_TEXT_OPTUSE "code text"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_CODE_TEXT_OPTVAL_S "c::"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_CODE_TEXT_OPTVAL_C 'c'
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_CODE_TEXT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_CODE_TEXT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_CODE_TEXT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_CODE_TEXT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_CODE_TEXT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_BASE64_OPT "64"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_BASE64_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_BASE64_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_BASE64_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_BASE64_OPTUSE "base64 code text"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_BASE64_OPTVAL_S "4::"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_BASE64_OPTVAL_C '4'
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_BASE64_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_BASE64_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_BASE64_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_BASE64_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_BASE64_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_LOWER_HEX_OPT "hex"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_LOWER_HEX_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_LOWER_HEX_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_LOWER_HEX_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_LOWER_HEX_OPTUSE "lower case hex code text"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_LOWER_HEX_OPTVAL_S "x::"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_LOWER_HEX_OPTVAL_C 'x'
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_LOWER_HEX_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_LOWER_HEX_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_LOWER_HEX_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_LOWER_HEX_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_LOWER_HEX_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_UPPER_HEX_OPT "HEX"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_UPPER_HEX_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_UPPER_HEX_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_UPPER_HEX_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_UPPER_HEX_OPTUSE "upper case hex code text"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_UPPER_HEX_OPTVAL_S "X::"
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_UPPER_HEX_OPTVAL_C 'X'
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_UPPER_HEX_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_UPPER_HEX_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_UPPER_HEX_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_UPPER_HEX_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_UPPER_HEX_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ENCODE_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_DECODE_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_PLAIN_TEXT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_CODE_TEXT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_BASE64_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_LOWER_HEX_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_UPPER_HEX_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ENCODE_OPTION \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_DECODE_OPTION \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_PLAIN_TEXT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_CODE_TEXT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_BASE64_OPTION \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_LOWER_HEX_OPTION \
    XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_UPPER_HEX_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_OUTPUT_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_OUTPUT_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ARGS 0
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace code {
namespace base {

/// class main_optt
template 
<class TExtends = xos::app::console::output::base::maint<>,  class TImplements = typename TExtends::implements>

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
    /// ...code_source_text_run
    virtual int code_source_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* arg = 0;
        if ((arg = this->has_argument(argc, argv, 0))) {
            if (!(err = all_code_source_run(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = all_code_text_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int before_code_source_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_code_source_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_code_source_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_code_source_text_run(argc, argv, env))) {
            int err2 = 0;
            err = code_source_text_run(argc, argv, env);
            if ((err2 = after_code_source_text_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_code_source_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_code_source_text_run;
        return err;
    }
    virtual int code_source_text_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_code_source_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int code_source_text_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...code_source_run
    int (derives::*code_source_run_)(int argc, char_t** argv, char_t** env);
    virtual int code_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (code_source_run_) {
            if (!(err = (this->*code_source_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_code_source_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_code_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_code_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_code_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_code_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_code_source_run(argc, argv, env))) {
            int err2 = 0;
            err = code_source_run(argc, argv, env);
            if ((err2 = after_code_source_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_code_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_code_source_run;
        return err;
    }
    virtual int code_source_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_code_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int code_source_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...encode_source_run
    int (derives::*encode_source_run_)(int argc, char_t** argv, char_t** env);
    virtual int encode_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (encode_source_run_) {
            if (!(err = (this->*encode_source_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_encode_source_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_encode_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* arg = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        if ((arg = this->has_argument(argc, argv, 0))) {
            if (!(err = all_encode_source(arg))) {} else {}
        } else {
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_encode_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_encode_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_encode_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_encode_source_run(argc, argv, env))) {
            int err2 = 0;
            err = encode_source_run(argc, argv, env);
            if ((err2 = after_encode_source_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_encode_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        code_source_run_ = &derives::all_encode_source_run;
        return err;
    }
    virtual int encode_source_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_encode_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        code_source_run_ = 0;
        return err;
    }
    virtual int encode_source_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...decode_source_run
    int (derives::*decode_source_run_)(int argc, char_t** argv, char_t** env);
    virtual int decode_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (decode_source_run_) {
            if (!(err = (this->*decode_source_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_decode_source_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_decode_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* arg = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        if ((arg = this->has_argument(argc, argv, 0))) {
            err = all_decode_source(arg);
        } else {
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_decode_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_decode_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_decode_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_decode_source_run(argc, argv, env))) {
            int err2 = 0;
            err = decode_source_run(argc, argv, env);
            if ((err2 = after_decode_source_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_decode_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        code_source_run_ = &derives::all_decode_source_run;
        return err;
    }
    virtual int decode_source_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_decode_source_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        code_source_run_ = 0;
        return err;
    }
    virtual int decode_source_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...code_text_run
    int (derives::*code_text_run_)(int argc, char_t** argv, char_t** env);
    virtual int code_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (code_text_run_) {
            if (!(err = (this->*code_text_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_code_text_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_code_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_code_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_code_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_code_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_code_text_run(argc, argv, env))) {
            int err2 = 0;
            err = code_text_run(argc, argv, env);
            if ((err2 = after_code_text_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_code_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_code_text_run;
        return err;
    }
    virtual int code_text_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_code_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int code_text_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...encode_text_run
    int (derives::*encode_text_run_)(int argc, char_t** argv, char_t** env);
    virtual int encode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (encode_text_run_) {
            if (!(err = (this->*encode_text_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_encode_text_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_encode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_encode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_encode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_encode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_encode_text_run(argc, argv, env))) {
            int err2 = 0;
            err = encode_text_run(argc, argv, env);
            if ((err2 = after_encode_text_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_encode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        code_text_run_ = &derives::all_encode_text_run;
        return err;
    }
    virtual int encode_text_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_encode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        code_text_run_ = 0;
        return err;
    }
    virtual int encode_text_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...base64_encode_text_run
    virtual int base64_encode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_base64_encode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encode_text_run_ = &derives::base64_encode_text_run;
        return err;
    }
    virtual int base64_encode_text_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_base64_encode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encode_text_run_ = 0;
        return err;
    }
    virtual int base64_encode_text_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...lower_hex_encode_text_run
    virtual int lower_hex_encode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_lower_hex_encode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encode_text_run_ = &derives::lower_hex_encode_text_run;
        return err;
    }
    virtual int lower_hex_encode_text_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_lower_hex_encode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encode_text_run_ = 0;
        return err;
    }
    virtual int lower_hex_encode_text_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...upper_hex_encode_text_run
    virtual int upper_hex_encode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_upper_hex_encode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encode_text_run_ = &derives::upper_hex_encode_text_run;
        return err;
    }
    virtual int upper_hex_encode_text_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_upper_hex_encode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encode_text_run_ = 0;
        return err;
    }
    virtual int upper_hex_encode_text_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...decode_text_run
    int (derives::*decode_text_run_)(int argc, char_t** argv, char_t** env);
    virtual int decode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (decode_text_run_) {
            if (!(err = (this->*decode_text_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_decode_text_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_decode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_decode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_decode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_decode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_decode_text_run(argc, argv, env))) {
            int err2 = 0;
            err = decode_text_run(argc, argv, env);
            if ((err2 = after_decode_text_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_decode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        code_text_run_ = &derives::all_decode_text_run;
        return err;
    }
    virtual int decode_text_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_decode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        code_text_run_ = 0;
        return err;
    }
    virtual int decode_text_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...base64_decode_text_run
    virtual int base64_decode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_base64_decode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        decode_text_run_ = &derives::base64_decode_text_run;
        return err;
    }
    virtual int base64_decode_text_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_base64_decode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        decode_text_run_ = 0;
        return err;
    }
    virtual int base64_decode_text_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...hex_decode_text_run
    virtual int hex_decode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_hex_decode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        decode_text_run_ = &derives::hex_decode_text_run;
        return err;
    }
    virtual int hex_decode_text_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_hex_decode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        decode_text_run_ = 0;
        return err;
    }
    virtual int hex_decode_text_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_plain_text_run
    int (derives::*output_plain_text_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_plain_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_plain_text_run_) {
            if (!(err = (this->*output_plain_text_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_output_plain_text_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_output_plain_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_output_plain_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_plain_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_plain_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_plain_text_run(argc, argv, env))) {
            int err2 = 0;
            err = output_plain_text_run(argc, argv, env);
            if ((err2 = after_output_plain_text_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_plain_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_plain_text_run;
        return err;
    }
    virtual int output_plain_text_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_plain_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_plain_text_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_code_text_run
    int (derives::*output_code_text_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_code_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_code_text_run_) {
            if (!(err = (this->*output_code_text_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_output_code_text_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_output_code_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_output_code_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_code_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_code_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_code_text_run(argc, argv, env))) {
            int err2 = 0;
            err = output_code_text_run(argc, argv, env);
            if ((err2 = after_output_code_text_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_code_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_code_text_run;
        return err;
    }
    virtual int output_code_text_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_code_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_code_text_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...encode_source
    virtual int encode_source(const char_t* location) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_encode_source(const char_t* location) {
        int err = 0;
        return err;
    }
    virtual int after_encode_source(const char_t* location) {
        int err = 0;
        return err;
    }
    virtual int all_encode_source(const char_t* location) {
        int err = 0;
        if (!(err = before_encode_source(location))) {
            int err2 = 0;
            err = encode_source(location);
            if ((err2 = after_encode_source(location))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...decode_source
    virtual int decode_source(const char_t* location) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_decode_source(const char_t* location) {
        int err = 0;
        return err;
    }
    virtual int after_decode_source(const char_t* location) {
        int err = 0;
        return err;
    }
    virtual int all_decode_source(const char_t* location) {
        int err = 0;
        if (!(err = before_decode_source(location))) {
            int err2 = 0;
            err = decode_source(location);
            if ((err2 = after_decode_source(location))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...encode_source
    int (derives::*encode_source_)(io::reader& source);
    virtual int encode_source(io::reader& source) {
        int err = 0;
        if (encode_source_) {
            err = (this->*encode_source_)(source);
        } else {
            err = default_encode_source(source);
        }
        return err;
    }
    virtual int default_encode_source(io::reader& source) {
        int err = 0;
        if (!(err = all_base64_encode_source(source))) {} else {}
        return err;
    }
    virtual int before_encode_source(io::reader& source) {
        int err = 0;
        return err;
    }
    virtual int after_encode_source(io::reader& source) {
        int err = 0;
        return err;
    }
    virtual int all_encode_source(io::reader& source) {
        int err = 0;
        if (!(err = before_encode_source(source))) {
            int err2 = 0;
            err = encode_source(source);
            if ((err2 = after_encode_source(source))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...decode_source
    int (derives::*decode_source_)(io::reader& source);
    virtual int decode_source(io::reader& source) {
        int err = 0;
        if (decode_source_) {
            err = (this->*decode_source_)(source);
        } else {
            err = default_decode_source(source);
        }
        return err;
    }
    virtual int default_decode_source(io::reader& source) {
        int err = 0;
        if (!(err = all_base64_decode_source(source))) {} else {}
        return err;
    }
    virtual int before_decode_source(io::reader& source) {
        int err = 0;
        return err;
    }
    virtual int after_decode_source(io::reader& source) {
        int err = 0;
        return err;
    }
    virtual int all_decode_source(io::reader& source) {
        int err = 0;
        if (!(err = before_decode_source(source))) {
            int err2 = 0;
            err = decode_source(source);
            if ((err2 = after_decode_source(source))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...base64_encode_source
    virtual int base64_encode_source(io::reader& source) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_base64_encode_source(io::reader& source) {
        int err = 0;
        return err;
    }
    virtual int after_base64_encode_source(io::reader& source) {
        int err = 0;
        return err;
    }
    virtual int all_base64_encode_source(io::reader& source) {
        int err = 0;
        if (!(err = before_base64_encode_source(source))) {
            int err2 = 0;
            err = base64_encode_source(source);
            if ((err2 = after_base64_encode_source(source))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_base64_encode_source(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encode_source_ = &derives::all_base64_encode_source;
        return err;
    }
    virtual int base64_encode_source_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_base64_encode_source(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encode_source_ = 0;
        return err;
    }
    virtual int base64_encode_source_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...base64_decode_source
    virtual int base64_decode_source(io::reader& source) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_base64_decode_source(io::reader& source) {
        int err = 0;
        return err;
    }
    virtual int after_base64_decode_source(io::reader& source) {
        int err = 0;
        return err;
    }
    virtual int all_base64_decode_source(io::reader& source) {
        int err = 0;
        if (!(err = before_base64_decode_source(source))) {
            int err2 = 0;
            err = base64_decode_source(source);
            if ((err2 = after_base64_decode_source(source))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_base64_decode_source(int argc, char_t** argv, char_t** env) {
        int err = 0;
        decode_source_ = &derives::all_base64_decode_source;
        return err;
    }
    virtual int base64_decode_source_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_base64_decode_source(int argc, char_t** argv, char_t** env) {
        int err = 0;
        decode_source_ = 0;
        return err;
    }
    virtual int base64_decode_source_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...lower_hex_encode_source
    virtual int lower_hex_encode_source(io::reader& source) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_lower_hex_encode_source(io::reader& source) {
        int err = 0;
        return err;
    }
    virtual int after_lower_hex_encode_source(io::reader& source) {
        int err = 0;
        return err;
    }
    virtual int all_lower_hex_encode_source(io::reader& source) {
        int err = 0;
        if (!(err = before_lower_hex_encode_source(source))) {
            int err2 = 0;
            err = lower_hex_encode_source(source);
            if ((err2 = after_lower_hex_encode_source(source))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_lower_hex_encode_source(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encode_source_ = &derives::all_lower_hex_encode_source;
        return err;
    }
    virtual int lower_hex_encode_source_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_lower_hex_encode_source(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encode_source_ = 0;
        return err;
    }
    virtual int lower_hex_encode_source_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...upper_hex_encode_source
    virtual int upper_hex_encode_source(io::reader& source) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_upper_hex_encode_source(io::reader& source) {
        int err = 0;
        return err;
    }
    virtual int after_upper_hex_encode_source(io::reader& source) {
        int err = 0;
        return err;
    }
    virtual int all_upper_hex_encode_source(io::reader& source) {
        int err = 0;
        if (!(err = before_upper_hex_encode_source(source))) {
            int err2 = 0;
            err = upper_hex_encode_source(source);
            if ((err2 = after_upper_hex_encode_source(source))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_upper_hex_encode_source(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encode_source_ = &derives::all_upper_hex_encode_source;
        return err;
    }
    virtual int upper_hex_encode_source_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_upper_hex_encode_source(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encode_source_ = 0;
        return err;
    }
    virtual int upper_hex_encode_source_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...hex_decode_source
    virtual int hex_decode_source(io::reader& source) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int before_hex_decode_source(io::reader& source) {
        int err = 0;
        return err;
    }
    virtual int after_hex_decode_source(io::reader& source) {
        int err = 0;
        return err;
    }
    virtual int all_hex_decode_source(io::reader& source) {
        int err = 0;
        if (!(err = before_hex_decode_source(source))) {
            int err2 = 0;
            err = hex_decode_source(source);
            if ((err2 = after_hex_decode_source(source))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_hex_decode_source(int argc, char_t** argv, char_t** env) {
        int err = 0;
        decode_source_ = &derives::all_hex_decode_source;
        return err;
    }
    virtual int hex_decode_source_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_hex_decode_source(int argc, char_t** argv, char_t** env) {
        int err = 0;
        decode_source_ = 0;
        return err;
    }
    virtual int hex_decode_source_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...encode_option...
    virtual int on_get_encode_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_encode_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_code_source_text_run(argc, argv, env))) {
            if (!(err = code_source_text_run_set(argc, argv, env))) {
                if (!(err = set_encode_source_run(argc, argv, env))) {
                    if (!(err = encode_source_run_set(argc, argv, env))) {
                        if (!(err = set_encode_text_run(argc, argv, env))) {
                            if (!(err = encode_text_run_set(argc, argv, env))) {
                            } else {}
                        } else {}
                    } else {}
                } else {}
            } else {}
        } else {}
        return err;
    }
    virtual int on_set_encode_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_encode_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_code_source_text_run(argc, argv, env))) {
                if (!(err = code_source_text_run_set(argc, argv, env))) {
                    if (!(err = set_encode_source_run(argc, argv, env))) {
                        if (!(err = encode_source_run_set(argc, argv, env))) {
                            if (!(err = set_encode_text_run(argc, argv, env))) {
                                if (!(err = encode_text_run_set(argc, argv, env))) {
                                } else {}
                            } else {}
                        } else {}
                    } else {}
                } else {}
            } else {}
        } else {
        }
        return err;
    }
    virtual int on_encode_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_encode_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_encode_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_encode_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_encode_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* encode_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ENCODE_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ENCODE_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...decode_option...
    virtual int on_get_decode_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_decode_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_code_source_text_run(argc, argv, env))) {
            if (!(err = code_source_text_run_set(argc, argv, env))) {
                if (!(err = set_decode_source_run(argc, argv, env))) {
                    if (!(err = decode_source_run_set(argc, argv, env))) {
                        if (!(err = set_decode_text_run(argc, argv, env))) {
                            if (!(err = decode_text_run_set(argc, argv, env))) {
                            } else {}
                        } else {}
                    } else {}
                } else {}
            } else {}
        } else {}
        return err;
    }
    virtual int on_set_decode_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_decode_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_code_source_text_run(argc, argv, env))) {
                if (!(err = code_source_text_run_set(argc, argv, env))) {
                    if (!(err = set_decode_source_run(argc, argv, env))) {
                        if (!(err = decode_source_run_set(argc, argv, env))) {
                            if (!(err = set_decode_text_run(argc, argv, env))) {
                                if (!(err = decode_text_run_set(argc, argv, env))) {
                                } else {}
                            } else {}
                        } else {}
                    } else {}
                } else {}
            } else {}
        } else {
        }
        return err;
    }
    virtual int on_decode_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_decode_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_decode_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_decode_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_decode_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* decode_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_DECODE_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_DECODE_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...plain_text_option...
    virtual int on_get_plain_text_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_plain_text_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_plain_text_run(argc, argv, env))) {
            if (!(err = output_plain_text_run_set(argc, argv, env))) {
            } else {}
        } else {}
        return err;
    }
    virtual int on_set_plain_text_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_plain_text_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_output_plain_text_run(argc, argv, env))) {
                if (!(err = output_plain_text_run_set(argc, argv, env))) {
                } else {}
            } else {}
        } else {
        }
        return err;
    }
    virtual int on_plain_text_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_plain_text_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_plain_text_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_plain_text_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_plain_text_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* plain_text_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_PLAIN_TEXT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_PLAIN_TEXT_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...code_text_option...
    virtual int on_get_code_text_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_code_text_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_code_text_run(argc, argv, env))) {
            if (!(err = output_code_text_run_set(argc, argv, env))) {
            } else {}
        } else {}
        return err;
    }
    virtual int on_set_code_text_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_code_text_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_output_code_text_run(argc, argv, env))) {
                if (!(err = output_code_text_run_set(argc, argv, env))) {
                } else {}
            } else {}
        } else {
        }
        return err;
    }
    virtual int on_code_text_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_code_text_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_code_text_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_code_text_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_code_text_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* code_text_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_CODE_TEXT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_CODE_TEXT_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...base64_option...
    virtual int on_base64_option_on
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_base64_option_off
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_get_base64_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_base64_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_base64_option_on(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_set_base64_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_base64_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            bool on = false;
            if ((this->on_set_onoff_option_on(on, optarg, optind, argc, argv, env))) {
                if (!(err = on_base64_option_on(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
                if (!(err = on_base64_option_off(optarg, optind, argc, argv, env))) {
                } else {
                }
            }
        } else {
        }
        return err;
    }
    virtual int on_base64_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_base64_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_base64_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_base64_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_base64_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* base64_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_BASE64_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_BASE64_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...lower_hex_option...
    virtual int on_lower_hex_option_on
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_lower_hex_option_off
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_get_lower_hex_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_lower_hex_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_lower_hex_option_on(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_set_lower_hex_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_lower_hex_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            bool on = false;
            if ((this->on_set_onoff_option_on(on, optarg, optind, argc, argv, env))) {
                if (!(err = on_lower_hex_option_on(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
                if (!(err = on_lower_hex_option_off(optarg, optind, argc, argv, env))) {
                } else {
                }
            }
        } else {
        }
        return err;
    }
    virtual int on_lower_hex_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_lower_hex_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_lower_hex_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_lower_hex_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_lower_hex_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* lower_hex_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_LOWER_HEX_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_LOWER_HEX_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...upper_hex_option...
    virtual int on_upper_hex_option_on
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_upper_hex_option_off
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_get_upper_hex_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_upper_hex_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_upper_hex_option_on(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_set_upper_hex_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_upper_hex_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            bool on = false;
            if ((this->on_set_onoff_option_on(on, optarg, optind, argc, argv, env))) {
                if (!(err = on_upper_hex_option_on(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
                if (!(err = on_upper_hex_option_off(optarg, optind, argc, argv, env))) {
                } else {
                }
            }
        } else {
        }
        return err;
    }
    virtual int on_upper_hex_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_upper_hex_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_upper_hex_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_upper_hex_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_upper_hex_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* upper_hex_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_UPPER_HEX_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_UPPER_HEX_OPTARG;
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

        case XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ENCODE_OPTVAL_C:
            err = this->on_encode_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_DECODE_OPTVAL_C:
            err = this->on_decode_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_PLAIN_TEXT_OPTVAL_C:
            err = this->on_plain_text_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_CODE_TEXT_OPTVAL_C:
            err = this->on_code_text_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_BASE64_OPTVAL_C:
            err = this->on_base64_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_LOWER_HEX_OPTVAL_C:
            err = this->on_lower_hex_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_UPPER_HEX_OPTVAL_C:
            err = this->on_upper_hex_option(optval, optarg, optname, optind, argc, argv, env);
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

        case XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ENCODE_OPTVAL_C:
            chars = this->encode_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_DECODE_OPTVAL_C:
            chars = this->decode_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_PLAIN_TEXT_OPTVAL_C:
            chars = this->plain_text_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_CODE_TEXT_OPTVAL_C:
            chars = this->code_text_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_BASE64_OPTVAL_C:
            chars = this->base64_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_LOWER_HEX_OPTVAL_C:
            chars = this->lower_hex_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_UPPER_HEX_OPTVAL_C:
            chars = this->upper_hex_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }

    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    /// argument
    virtual const char_t* has_argument(int argc, char_t** argv, int argn) const {
        const char_t* arg = 0;
        int argind = 0;
        if (((argind = this->arguments_index())+argn+1) == argc) {
            if ((argv) && (arg = argv[argind])) {
                if (!(arg[0])) {
                    arg = 0;
                } else {}
            } else {}
        } else {}
        return arg;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace base 
} /// namespace code 
} /// namespace crypto 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_OPT_HPP
