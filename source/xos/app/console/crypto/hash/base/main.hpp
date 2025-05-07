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
///   Date: 11/9/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HPP

#include "xos/app/console/crypto/hash/base/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace hash {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::crypto::hash::base::main_optt<>,  class TImplements = typename TExtends::implements>

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

    enum { KILO = 1024, 
           KEYSIZE = KILO, 
           HASHSIZE = KILO , 
           BLOCKSIZE = KILO*64 };

    /// constructor / destructor
    maint(): run_(0), hmac_key_size_(0), block_size_(BLOCKSIZE) {
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
    /// ...output_identity_hash_run
    virtual int output_identity_hash_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0; size_t length = 0;
        const string_t& plain_text = this->plain_text(length);
        
        LOGGER_IS_LOGGED_INFO("((chars = plain_text.has_chars(length)))...");
        if ((chars = plain_text.has_chars(length))) {
            LOGGER_IS_LOGGED_INFO("...((\"" << chars << "\" = plain_text.has_chars(" << length << ")))");
            if (!(err = this->output_hash(chars, length))) {
            } else {
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on ((chars = plain_text.has_chars(length)))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...plain_option...
    virtual int on_set_plain_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("((optarg) && (optarg[0]))...");
        if ((optarg) && (optarg[0])) {
            LOGGER_IS_LOGGED_INFO("...((optarg) && (optarg[0]))");
            LOGGER_IS_LOGGED_INFO("this->set_plain_text(\"" << optarg << "\")...");
            this->set_plain_text(optarg);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on ((optarg) && (optarg[0]))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on_set_key_option
    virtual int on_set_key_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("((optarg) && (optarg[0]))...");
        if ((optarg) && (optarg[0])) {
            const string_t hmac_key_text(optarg);
            const reader_string_t& reader_string = this->set_reader_string(hmac_key_text);
            string_reader_t hmac_reader(reader_string);
            byte_t* hmac_key = 0;
            size_t sizeof_hmac_key = 0;

            LOGGER_IS_LOGGED_INFO("...((optarg) && (optarg[0]))");
            LOGGER_IS_LOGGED_INFO("...const string_t hmac_key_text(\"" << optarg << "\")");
            LOGGER_IS_LOGGED_INFO("((hmac_key = this->hmac_key_data(sizeof_hmac_key)))...");
            if ((hmac_key = this->hmac_key_data(sizeof_hmac_key))) {
                ssize_t count = 0;

                LOGGER_IS_LOGGED_INFO("...((hmac_key = this->hmac_key_data(" << sizeof_hmac_key << ")))");
                LOGGER_IS_LOGGED_INFO("(0 < (count = this->input_x(hmac_key, sizeof_hmac_key, hmac_reader)))...");
                if (0 < (count = this->input_x(hmac_key, sizeof_hmac_key, hmac_reader))) {
                    LOGGER_IS_LOGGED_INFO("...(0 < (" << count << " = this->input_x(hmac_key, sizeof_hmac_key, hmac_reader)))");
                    LOGGER_IS_LOGGED_INFO("this->set_hmac_key_size(" << count << ")...");
                    this->set_hmac_key_size(count);
                    err = this->on_hmac_key_set(hmac_key, sizeof_hmac_key, count, argc, argv, env);
                }
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on ((optarg) && (optarg[0]))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int on_hmac_key_set
    (byte_t* hmac_key, size_t sizeof_hmac_key, size_t hmac_key_size, 
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_hmac_hash_initialize(argc, argv, env))) {
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...hmac_key...
    virtual byte_t* hmac_key_data(size_t& size) const {
        size = sizeof(hmac_key_);
        return (byte_t*)hmac_key_;
    }
    virtual byte_t* set_hmac_key_size(size_t size) {
        hmac_key_size_ = size;
        return (byte_t*)hmac_key_;
    }
    virtual const byte_t* hmac_key(size_t& size) const {
        size = sizeof(hmac_key_);
        if ((hmac_key_size_ >= 0) && (hmac_key_size_ < size)) {
            size = hmac_key_size_;
        }
        return (const byte_t*)&hmac_key_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...hash...
    virtual byte_t* hash(size_t& size) const {
        size = sizeof(hash_);
        return (byte_t*)&hash_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...block...
    virtual byte_t* set_block_to_size(size_t& size) {
        if (0 < (size = block_size())) {
            if (size <= (block_.set_length(size))) {
                return block_.elements();
            }
        }
        return 0;
    }
    virtual size_t set_block_size(size_t to) {
        block_size_ = to;
        return block_size();
    }
    virtual size_t block_size() const {
        return block_size_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    using extends::plain_text;
    virtual string_t& plain_text() const {
        return (string_t&)plain_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    size_t hmac_key_size_, block_size_;
    byte_t hmac_key_[HASHSIZE], hash_[HASHSIZE];
    byte_arrayt<BLOCKSIZE> block_;
    string_t plain_;
}; /// class maint 
typedef maint<> main;

} /// namespace base 
} /// namespace hash 
} /// namespace crypto 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HPP

