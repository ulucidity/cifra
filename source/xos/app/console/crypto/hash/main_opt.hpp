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
///   Date: 11/10/2024, 2/21/2025
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPT_HPP

#include "xos/app/console/crypto/hash/base/main.hpp"
#include "xos/crypto/hash/md5.hpp"
#include "xos/crypto/hash/sha1.hpp"
#include "xos/crypto/hash/sha256.hpp"
#include "xos/crypto/hash/sha512.hpp"

#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPT "algorithm"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_MD5_C "d"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA1_C "1"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA256_C "2"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA512_C "5"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_MD5_S "md5"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA1_S "sha1"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA256_S "sha256"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA512_S "sha512"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_MD5 \
    "(" XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_MD5_C \
    ")" XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_MD5_S
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA1 \
    "(" XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA1_C \
    ")" XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA1_S
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA256 \
    "(" XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA256_C \
    ")" XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA256_S
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA512 \
    "(" XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA512_C \
    ")" XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA512_S
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG \
    "[{ " XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_MD5 \
    ", " XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA1 \
    ", " XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA256  \
    ", " XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA512 " }]"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTUSE "hash algorithm"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTVAL_S "a::"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTVAL_C 'a'
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_MD5_ALGORITHM_OPT "md5"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_MD5_ALGORITHM_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_MD5_ALGORITHM_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_MD5_ALGORITHM_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_MD5_ALGORITHM_OPTUSE "md5 hash algorithm"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_MD5_ALGORITHM_OPTVAL_S "d::"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_MD5_ALGORITHM_OPTVAL_C 'd'
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_MD5_ALGORITHM_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_MD5_ALGORITHM_OPT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_MD5_ALGORITHM_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_MD5_ALGORITHM_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_MD5_ALGORITHM_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA1_ALGORITHM_OPT "sha1"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA1_ALGORITHM_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA1_ALGORITHM_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA1_ALGORITHM_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA1_ALGORITHM_OPTUSE "sha1 hash algorithm"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA1_ALGORITHM_OPTVAL_S "1::"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA1_ALGORITHM_OPTVAL_C '1'
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA1_ALGORITHM_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA1_ALGORITHM_OPT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA1_ALGORITHM_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA1_ALGORITHM_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA1_ALGORITHM_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA256_ALGORITHM_OPT "sha256"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA256_ALGORITHM_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA256_ALGORITHM_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA256_ALGORITHM_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA256_ALGORITHM_OPTUSE "sha256 hash algorithm"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA256_ALGORITHM_OPTVAL_S "2::"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA256_ALGORITHM_OPTVAL_C '2'
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA256_ALGORITHM_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA256_ALGORITHM_OPT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA256_ALGORITHM_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA256_ALGORITHM_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA256_ALGORITHM_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA512_ALGORITHM_OPT "sha512"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA512_ALGORITHM_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA512_ALGORITHM_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA512_ALGORITHM_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA512_ALGORITHM_OPTUSE "sha512 hash algorithm"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA512_ALGORITHM_OPTVAL_S "5::"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA512_ALGORITHM_OPTVAL_C '5'
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA512_ALGORITHM_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA512_ALGORITHM_OPT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA512_ALGORITHM_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA512_ALGORITHM_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA512_ALGORITHM_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTVAL_S \
   XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_MD5_ALGORITHM_OPTVAL_S \
   XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA1_ALGORITHM_OPTVAL_S \
   XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA256_ALGORITHM_OPTVAL_S \
   XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA512_ALGORITHM_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTION \
   XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_MD5_ALGORITHM_OPTION \
   XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA1_ALGORITHM_OPTION \
   XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA256_ALGORITHM_OPTION \
   XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA512_ALGORITHM_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HASH_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HASH_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_ARGS XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_ARGS
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_ARGV XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_ARGV

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace hash {

/// class main_optt
template 
<class TExtends = xos::app::console::crypto::hash::base::maint<>,  class TImplements = typename TExtends::implements>

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
    /// ...hash_algorithm
    xos::crypto::hash::algorithm* (derives::*hash_algorithm_)() const;
    virtual xos::crypto::hash::algorithm* hash_algorithm() const {
        if ((this->hash_algorithm_)) {
            return (this->*hash_algorithm_)();
        }
        return default_hash_algorithm();
    }
    virtual xos::crypto::hash::algorithm* default_hash_algorithm() const {
        return md5_hash_algorithm();
    }
    //////////////////////////////////////////////////////////////////////////
    virtual xos::crypto::hash::algorithm* md5_hash_algorithm() const {
        return 0;
    }
    virtual int set_md5_hash_algorithm(int argc, char_t** argv, char_t** env) {
        int err = 0;
        hash_algorithm_ = &derives::md5_hash_algorithm;
        return err;
    }
    virtual int md5_hash_algorithm_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->set_hash_run(argc, argv, env))) {
            if (!(err = this->hash_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int unset_md5_hash_algorithm(int argc, char_t** argv, char_t** env) {
        int err = 0;
        hash_algorithm_ = 0;
        return err;
    }
    virtual int md5_hash_algorithm_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual xos::crypto::hash::algorithm* sha1_hash_algorithm() const {
        return 0;
    }
    virtual int set_sha1_hash_algorithm(int argc, char_t** argv, char_t** env) {
        int err = 0;
        hash_algorithm_ = &derives::sha1_hash_algorithm;
        return err;
    }
    virtual int sha1_hash_algorithm_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->set_hash_run(argc, argv, env))) {
            if (!(err = this->hash_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int unset_sha1_hash_algorithm(int argc, char_t** argv, char_t** env) {
        int err = 0;
        hash_algorithm_ = 0;
        return err;
    }
    virtual int sha1_hash_algorithm_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual xos::crypto::hash::algorithm* sha256_hash_algorithm() const {
        return 0;
    }
    virtual int set_sha256_hash_algorithm(int argc, char_t** argv, char_t** env) {
        int err = 0;
        hash_algorithm_ = &derives::sha256_hash_algorithm;
        return err;
    }
    virtual int sha256_hash_algorithm_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->set_hash_run(argc, argv, env))) {
            if (!(err = this->hash_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int unset_sha256_hash_algorithm(int argc, char_t** argv, char_t** env) {
        int err = 0;
        hash_algorithm_ = 0;
        return err;
    }
    virtual int sha256_hash_algorithm_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual xos::crypto::hash::algorithm* sha512_hash_algorithm() const {
        return 0;
    }
    virtual int set_sha512_hash_algorithm(int argc, char_t** argv, char_t** env) {
        int err = 0;
        hash_algorithm_ = &derives::sha512_hash_algorithm;
        return err;
    }
    virtual int sha512_hash_algorithm_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->set_hash_run(argc, argv, env))) {
            if (!(err = this->hash_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int unset_sha512_hash_algorithm(int argc, char_t** argv, char_t** env) {
        int err = 0;
        hash_algorithm_ = 0;
        return err;
    }
    virtual int sha512_hash_algorithm_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...hash_algorithm_option...
    virtual int on_get_hash_algorithm_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_hash_algorithm_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_hash_algorithm_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if ((!(optarg[1]) && (XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_MD5_C[0] == (optarg[0])))
                || !(chars_t::compare(optarg, XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_MD5_S))) {
                if (!(err = set_md5_hash_algorithm(argc, argv, env))) {
                    if (!(err = md5_hash_algorithm_set(argc, argv, env))) {
                    } else {
                    }
                } else {
                }
            } else {
                if ((!(optarg[1]) && (XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA1_C[0] == (optarg[0])))
                    || !(chars_t::compare(optarg, XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA1_S))) {
                    if (!(err = set_sha1_hash_algorithm(argc, argv, env))) {
                        if (!(err = sha1_hash_algorithm_set(argc, argv, env))) {
                        } else {
                        }
                    } else {
                    }
                } else {
                    if ((!(optarg[1]) && (XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA256_C[0] == (optarg[0])))
                        || !(chars_t::compare(optarg, XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA256_S))) {
                        if (!(err = set_sha256_hash_algorithm(argc, argv, env))) {
                            if (!(err = sha256_hash_algorithm_set(argc, argv, env))) {
                            } else {
                            }
                        } else {
                        }
                    } else {
                        if ((!(optarg[1]) && (XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA512_C[0] == (optarg[0])))
                            || !(chars_t::compare(optarg, XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG_SHA512_S))) {
                            if (!(err = set_sha512_hash_algorithm(argc, argv, env))) {
                                if (!(err = sha512_hash_algorithm_set(argc, argv, env))) {
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
    virtual int on_hash_algorithm_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_hash_algorithm_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_hash_algorithm_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_hash_algorithm_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_hash_algorithm_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_hash_algorithm_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* hash_algorithm_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...md5_algorithm_option...
    virtual int on_get_md5_algorithm_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_md5_algorithm_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_md5_hash_algorithm(argc, argv, env))) {
            if (!(err = md5_hash_algorithm_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_md5_algorithm_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_md5_algorithm_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_md5_hash_algorithm(argc, argv, env))) {
                if (!(err = md5_hash_algorithm_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_md5_algorithm_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_md5_algorithm_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_md5_algorithm_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_md5_algorithm_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_md5_algorithm_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* md5_algorithm_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_MD5_ALGORITHM_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_MD5_ALGORITHM_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...sha1_algorithm_option...
    virtual int on_get_sha1_algorithm_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_sha1_algorithm_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_sha1_hash_algorithm(argc, argv, env))) {
            if (!(err = sha1_hash_algorithm_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_sha1_algorithm_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_sha1_algorithm_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_sha1_hash_algorithm(argc, argv, env))) {
                if (!(err = sha1_hash_algorithm_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_sha1_algorithm_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_sha1_algorithm_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_sha1_algorithm_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_sha1_algorithm_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_sha1_algorithm_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* sha1_algorithm_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA1_ALGORITHM_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA1_ALGORITHM_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...sha256_algorithm_option...
    virtual int on_get_sha256_algorithm_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_sha256_algorithm_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_sha256_hash_algorithm(argc, argv, env))) {
            if (!(err = sha256_hash_algorithm_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_sha256_algorithm_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_sha256_hash_algorithm(argc, argv, env))) {
                if (!(err = sha256_hash_algorithm_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_sha256_algorithm_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_sha256_algorithm_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_sha256_algorithm_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_sha256_algorithm_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_sha256_algorithm_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_sha256_algorithm_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* sha256_algorithm_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA256_ALGORITHM_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA256_ALGORITHM_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...sha512_algorithm_option...
    virtual int on_get_sha512_algorithm_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_sha512_algorithm_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_sha512_hash_algorithm(argc, argv, env))) {
            if (!(err = sha512_hash_algorithm_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_sha512_algorithm_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_sha512_algorithm_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_sha512_hash_algorithm(argc, argv, env))) {
                if (!(err = sha512_hash_algorithm_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_sha512_algorithm_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_sha512_algorithm_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_sha512_algorithm_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_sha512_algorithm_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_sha512_algorithm_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* sha512_algorithm_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA512_ALGORITHM_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA512_ALGORITHM_OPTARG;
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

        case XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTVAL_C:
            err = this->on_hash_algorithm_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_MD5_ALGORITHM_OPTVAL_C:
            err = this->on_md5_algorithm_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA1_ALGORITHM_OPTVAL_C:
            err = this->on_sha1_algorithm_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA256_ALGORITHM_OPTVAL_C:
            err = this->on_sha256_algorithm_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA512_ALGORITHM_OPTVAL_C:
            err = this->on_sha512_algorithm_option(optval, optarg, optname, optind, argc, argv, env);
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

        case XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HASH_ALGORITHM_OPTVAL_C:
            chars = this->hash_algorithm_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_MD5_ALGORITHM_OPTVAL_C:
            chars = this->md5_algorithm_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA1_ALGORITHM_OPTVAL_C:
            chars = this->sha1_algorithm_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA256_ALGORITHM_OPTVAL_C:
            chars = this->sha256_algorithm_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_SHA512_ALGORITHM_OPTVAL_C:
            chars = this->sha512_algorithm_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }

    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace hash 
} /// namespace crypto 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPT_HPP

