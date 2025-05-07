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
///   Date: 11/29/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_HPP

#include "xos/app/console/crypto/code/base/main_opt.hpp"
#include "xos/app/console/crypto/code/base/to_main_output.hpp"

#include "xos/io/crt/file/reader.hpp"
#include "xos/io/base64/output_to.hpp"
#include "xos/io/base64/reader_to_events.hpp"
#include "xos/io/base64/read_to_output.hpp"
#include "xos/io/base64/writer_to_events.hpp"
#include "xos/io/base64/writer_to.hpp"
#include "xos/io/base64/write_to_output.hpp"

#include "xos/io/hex/output_to.hpp"
#include "xos/io/hex/reader_to_events.hpp"
#include "xos/io/hex/read_to_output.hpp"
#include "xos/io/hex/writer_to_events.hpp"
#include "xos/io/hex/writer_to.hpp"
#include "xos/io/hex/write_to_output.hpp"

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace code {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::crypto::code::base::main_optt<>,  class TImplements = typename TExtends::implements>

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

    typedef to_main_output to_output_t;
    typedef xos::io::base64::reader_to base64_reader_t;
    typedef xos::io::base64::writer_to base64_writer_t;
    typedef xos::io::base64::output_tot<to_output_t> base64_to_output_t;
    typedef xos::io::base64::read_to_outputt<base64_to_output_t> base64_read_to_output_t;
    typedef xos::io::base64::write_to_outputt<base64_to_output_t> base64_write_to_output_t;

    typedef xos::io::hex::output_tot<to_output_t> hex_to_output_t;
    typedef xos::io::hex::reader_to hex_reader_t;
    typedef xos::io::hex::writer_to hex_writer_t;
    typedef xos::io::hex::read_to_outputt<hex_to_output_t> hex_read_to_output_t;
    typedef xos::io::hex::write_to_outputt<hex_to_output_t> hex_write_to_output_t;

    /// constructor / destructor
    maint()
    : run_(0),
      plain_text_("plain"), 
      base64_code_text_("cGxhaW4="),
      lower_hex_code_text_("706c61696e"),
      upper_hex_code_text_("706C61696E"),
      hex_code_text_(lower_hex_code_text_),
      code_text_(base64_code_text_),
      encode_text_size_(code_text_block_size), 
      decode_text_size_(code_text_block_size),
      encode_text_length_(0), decode_text_length_(0) {
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
    /// ...encode_source
    virtual int encode_source(const char_t* location) {
        int err = 1;
        const char_t* chars = 0;
        
        if ((chars = location) && (chars[0])) {
            io::crt::file::reader source;

            LOGGER_IS_LOGGED_INFO("source.open(chars = \"" << chars << "\")...");
            if ((source.open(chars))) {
                LOGGER_IS_LOGGED_INFO("...source.open(chars = \"" << chars << "\")");

                if (!(err = this->all_encode_source(source))) {} else {}

                LOGGER_IS_LOGGED_INFO("source.close() \"" << chars << "\"...");
                if ((source.close())) {
                    LOGGER_IS_LOGGED_INFO("...source.close() \"" << chars << "\"");
                } else {
                    LOGGER_IS_LOGGED_ERROR("...failed on source.close() \"" << chars << "\"");
                }
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed on source.open(chars = \"" << chars << "\")");
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...decode_source
    virtual int decode_source(const char_t* location) {
        int err = 1;
        const char_t* chars = 0;
        
        if ((chars = location) && (chars[0])) {
            io::crt::file::reader source;

            LOGGER_IS_LOGGED_INFO("source.open(chars = \"" << chars << "\")...");
            if ((source.open(chars))) {
                LOGGER_IS_LOGGED_INFO("...source.open(chars = \"" << chars << "\")");

                err = this->all_decode_source(source);

                LOGGER_IS_LOGGED_INFO("source.close() \"" << chars << "\"...");
                if ((source.close())) {
                    LOGGER_IS_LOGGED_INFO("...source.close() \"" << chars << "\"");
                } else {
                    LOGGER_IS_LOGGED_ERROR("...failed on source.close() \"" << chars << "\"");
                }
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed on source.open(chars = \"" << chars << "\")");
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...base64_encode_source
    virtual int base64_encode_source(io::reader& source) {
        int err = 0;
        ssize_t amount = 0;
        size_t size = 0;
        byte_t& byte = this->base64_source(size);
        
        LOGGER_IS_LOGGED_INFO("...in");
        if ((0 < (amount = (ssize_t)size))) {
            ssize_t count = 0;
            to_output_t output_to(*this);
            base64_to_output_t to_output(output_to);
            base64_write_to_output_t output_writer(to_output);
            base64_writer_t writer(output_writer, source);
            
            if (0 < (count = source.read(&byte, size))) {
                writer.on_begin(&byte, ((size_t)count));
                if (amount == count) {
                    do {
                        writer.on_read(&byte, ((size_t)count));
                        if (0 < (count = source.read(&byte, size))) {
                            this->outln("\\");
                        }
                    } while (amount == count);
                    if (0 < count) {
                        writer.on_read(&byte, ((size_t)count));
                    }
                } else {
                    if (0 < count) {
                        writer.on_read(&byte, ((size_t)count));
                    }
                }
                writer.on_end(&byte, ((size_t)count));
                this->outln();
            }
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...base64_decode_source
    virtual int base64_decode_source(io::reader& source) {
        int err = 0;
        ssize_t count = 0, amount = 0;
        byte_t byte = 0;

        LOGGER_IS_LOGGED_INFO("...in");
        if (0 < (amount = source.read(&byte, 1))) {
            to_output_t output_to(*this);
            base64_to_output_t to_output(output_to);
            base64_read_to_output_t output_reader(to_output);
            base64_reader_t reader(output_reader, source);
            
            reader.on_begin(&byte, 1);
            do {
                if ((0 > (reader.on_read(&byte, 1)))) {
                    break;
                }
                count += amount;
                amount = source.read(&byte, 1);
            } while (0 < amount);
            reader.on_end(&byte, 1);
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...lower_hex_encode_source
    virtual int lower_hex_encode_source(io::reader& source) {
        int err = 0;
        if (!(err = hex_encode_source(source))) {} else {}
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...upper_hex_encode_source
    virtual int upper_hex_encode_source(io::reader& source) {
        int err = 0;
        if (!(err = hex_encode_source(source, true))) {} else {}
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...hex_encode_source
    virtual int hex_encode_source(io::reader& source, const bool& upper = false) {
        int err = 0;
        ssize_t amount = 0;
        size_t size = 0;
        byte_t& byte = this->hex_source(size);
        
        LOGGER_IS_LOGGED_INFO("...in");
        if ((0 < (amount = (ssize_t)size))) {
            ssize_t count = 0;
            to_output_t output_to(*this);
            hex_to_output_t to_output(output_to);
            hex_write_to_output_t output_writer(to_output);
            hex_writer_t writer(output_writer, source);
            
            if (0 < (count = source.read(&byte, size))) {
                writer.on_begin(&byte, ((size_t)count));
                if (amount == count) {
                    do {
                        writer.on_read(&byte, ((size_t)count));
                        if (0 < (count = source.read(&byte, size))) {
                            this->outln("\\");
                        }
                    } while (amount == count);
                    if (0 < count) {
                        writer.on_read(&byte, ((size_t)count));
                    }
                } else {
                    if (0 < count) {
                        writer.on_read(&byte, ((size_t)count));
                    }
                }
                writer.on_end(&byte, ((size_t)count));
                this->outln();
            }
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...hex_decode_source
    virtual int hex_decode_source(io::reader& source) {
        int err = 0;
        ssize_t count = 0, amount = 0;
        byte_t byte = 0;

        LOGGER_IS_LOGGED_INFO("...in");
        if (0 < (amount = source.read(&byte, 1))) {
            to_output_t output_to(*this);
            hex_to_output_t to_output(output_to);
            hex_read_to_output_t output_reader(to_output);
            hex_reader_t reader(output_reader, source);
            
            reader.on_begin(&byte, 1);
            do {
                if ((0 > (reader.on_read(&byte, 1)))) {
                    break;
                }
                count += amount;
                amount = source.read(&byte, 1);
            } while (0 < amount);
            reader.on_end(&byte, 1);
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...encode_text_run
    virtual int default_encode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        if (!(err = base64_encode_text_run(argc, argv, env))) {
        } else {
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int base64_encode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0;
        size_t length = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        if ((chars = this->plain_text_chars(length))) {
            const bool output_lf = this->output_lf();
            ssize_t amount = 0;
            if (0 <= (amount = this->all_output_base64(chars, length, output_lf))) {
            } else {}
        } else {}
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int lower_hex_encode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0;
        size_t length = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        if ((chars = this->plain_text_chars(length))) {
            const bool output_lf = this->output_lf();
            ssize_t amount = 0;
            if (0 <= (amount = this->all_output_lower_hex(chars, length, output_lf))) {
            } else {}
        } else {}
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int upper_hex_encode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0;
        size_t length = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        if ((chars = this->plain_text_chars(length))) {
            const bool output_lf = this->output_lf();
            ssize_t amount = 0;
            if (0 <= (amount = this->all_output_upper_hex(chars, length, output_lf))) {
            } else {}
        } else {}
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...decode_text_run
    virtual int default_decode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        if (!(err = base64_decode_text_run(argc, argv, env))) {
        } else {
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int base64_decode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0;
        size_t length = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        if ((chars = this->base64_code_text_chars(length))) {
            const reader_string_t& code_text = this->base64_code_text();
            string_reader_t code_reader(code_text);
            byte_t* decode_text = 0;
            size_t sizeof_decode_text = 0;

            if ((decode_text = this->decode_text(sizeof_decode_text))) {
                ssize_t count = 0;

                if (0 < (count = this->base64_input_x(decode_text, sizeof_decode_text, code_reader))) {

                    this->set_decode_text_size(count);
                    if (!(err = this->on_decode_text_set(decode_text, sizeof_decode_text, count))) {
                        const bool output_lf = this->output_lf();
                        ssize_t amount = 0;
                        if (0 <= (amount = this->all_output_text((const char_t*)decode_text, count, output_lf))) {} else {}
                    }
                }
            }
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    virtual int hex_decode_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0;
        size_t length = 0;
        LOGGER_IS_LOGGED_INFO("...in");
        if ((chars = this->hex_code_text_chars(length))) {
            const reader_string_t& code_text = this->hex_code_text();
            string_reader_t code_reader(code_text);
            byte_t* decode_text = 0;
            size_t sizeof_decode_text = 0;

            if ((decode_text = this->decode_text(sizeof_decode_text))) {
                ssize_t count = 0;

                if (0 < (count = this->hex_input_x(decode_text, sizeof_decode_text, code_reader))) {

                    this->set_decode_text_size(count);
                    if (!(err = this->on_decode_text_set(decode_text, sizeof_decode_text, count))) {
                        const bool output_lf = this->output_lf();
                        ssize_t amount = 0;
                        if (0 <= (amount = this->all_output_text((const char_t*)decode_text, count, output_lf))) {} else {}
                    }
                }
            }
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...default_output_plain_text_run
    int (derives::*default_output_plain_text_run_)(int argc, char_t** argv, char_t** env);
    virtual int default_output_plain_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (default_output_plain_text_run_) {
            if (!(err = (this->*default_output_plain_text_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            const string_t& plain_text = this->plain_text();
            const char_t* chars = 0; size_t length = 0;
            if ((chars = plain_text.has_chars(length))) {
                const bool output_lf = this->output_lf();
                if (!(err = (0 > (this->all_output_text(chars, length, output_lf))))) {} else {}
            } else {}
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...default_output_code_text_run
    int (derives::*default_output_code_text_run_)(int argc, char_t** argv, char_t** env);
    virtual int default_output_code_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (default_output_code_text_run_) {
            if (!(err = (this->*default_output_code_text_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            const string_t& code_text = this->code_text();
            const char_t* chars = 0; size_t length = 0;
            if ((chars = code_text.has_chars(length))) {
                const bool output_lf = this->output_lf();
                if (!(err = (0 > (this->all_output_text(chars, length, output_lf))))) {} else {}
            } else {}
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...input_x...
    virtual ssize_t base64_input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        if ((block) && (length)) {
            count = reader.read64(block, length);
        }
        return count;
    }
    virtual ssize_t hex_input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        if ((block) && (length)) {
            count = reader.readx(block, length);
        }
        return count;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual int on_set_encode_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_plain_text(optarg);
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...on_set_decode_option
    int (derives::*on_set_decode_option_)(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env);
    virtual int on_set_decode_option(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (on_set_decode_option_) {
            if (!(err = (this->*on_set_decode_option_)(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = base64_on_set_decode_option(optarg, optind, argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int base64_on_set_decode_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_base64_code_text(optarg);
        } else {
        }
        return err;
    }
    virtual int set_base64_on_set_decode_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_decode_option_ = &derives::base64_on_set_decode_option;
        return err;
    }
    virtual int base64_on_set_decode_option_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_base64_on_set_decode_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_decode_option_ = 0;
        return err;
    }
    virtual int base64_on_set_decode_option_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int hex_on_set_decode_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_lower_hex_code_text(optarg);
        } else {
        }
        return err;
    }
    virtual int set_hex_on_set_decode_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_decode_option_ = &derives::hex_on_set_decode_option;
        return err;
    }
    virtual int hex_on_set_decode_option_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_hex_on_set_decode_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_decode_option_ = 0;
        return err;
    }
    virtual int hex_on_set_decode_option_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual int on_set_plain_text_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_plain_text(optarg);
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...on_set_code_text_option
    int (derives::*on_set_code_text_option_)(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env);
    virtual int on_set_code_text_option(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (on_set_code_text_option_) {
            if (!(err = (this->*on_set_code_text_option_)(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = base64_on_set_code_text_option(optarg, optind, argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int base64_on_set_code_text_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_base64_code_text(optarg);
        } else {
        }
        return err;
    }
    virtual int set_base64_on_set_code_text_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_code_text_option_ = &derives::base64_on_set_code_text_option;
        return err;
    }
    virtual int base64_on_set_code_text_option_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        set_code_text(base64_code_text());
        return err;
    }
    virtual int unset_base64_on_set_code_text_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_code_text_option_ = 0;
        return err;
    }
    virtual int base64_on_set_code_text_option_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int lower_hex_on_set_code_text_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_lower_hex_code_text(optarg);
        } else {
        }
        return err;
    }
    virtual int set_lower_hex_on_set_code_text_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_code_text_option_ = &derives::lower_hex_on_set_code_text_option;
        return err;
    }
    virtual int lower_hex_on_set_code_text_option_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        set_code_text(lower_hex_code_text());
        set_hex_code_text(code_text());
        return err;
    }
    virtual int unset_lower_hex_on_set_code_text_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_code_text_option_ = 0;
        return err;
    }
    virtual int lower_hex_on_set_code_text_option_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int upper_hex_on_set_code_text_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_upper_hex_code_text(optarg);
        } else {
        }
        return err;
    }
    virtual int set_upper_hex_on_set_code_text_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_code_text_option_ = &derives::upper_hex_on_set_code_text_option;
        return err;
    }
    virtual int upper_hex_on_set_code_text_option_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        set_code_text(upper_hex_code_text());
        set_hex_code_text(code_text());
        return err;
    }
    virtual int unset_upper_hex_on_set_code_text_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_code_text_option_ = 0;
        return err;
    }
    virtual int upper_hex_on_set_code_text_option_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...base64_option...
    virtual int on_base64_option_on
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = extends::on_base64_option_on(optarg, optind, argc, argv, env))) {
            if (!(err = this->set_base64_output_text(argc, argv, env))) {
                if (!(err = this->base64_output_text_set(argc, argv, env))) {
                    if (!(err = set_base64_on_set_code_text_option(argc, argv, env))) {
                        if (!(err = base64_on_set_code_text_option_set(argc, argv, env))) {
                            if (!(err = this->set_base64_encode_source(argc, argv, env))) {
                                if (!(err = this->base64_encode_source_set(argc, argv, env))) {
                                    if (!(err = this->set_base64_decode_source(argc, argv, env))) {
                                        if (!(err = this->base64_decode_source_set(argc, argv, env))) {
                                            if (!(err = this->set_base64_encode_text_run(argc, argv, env))) {
                                                if (!(err = this->base64_encode_text_run_set(argc, argv, env))) {
                                                    if (!(err = this->set_base64_decode_text_run(argc, argv, env))) {
                                                        if (!(err = this->base64_decode_text_run_set(argc, argv, env))) {
                                                        } else {}
                                                    } else {}
                                                } else {}
                                            } else {}
                                        } else {}
                                    } else {}
                                } else {}
                            } else {}
                        } else {}
                    } else {}
                } else {}
            } else {}
        } else {}
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...lower_hex_option...
    virtual int on_lower_hex_option_on
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = extends::on_lower_hex_option_on(optarg, optind, argc, argv, env))) {
            if (!(err = this->set_lower_hex_output_text(argc, argv, env))) {
                if (!(err = this->lower_hex_output_text_set(argc, argv, env))) {
                    if (!(err = set_lower_hex_on_set_code_text_option(argc, argv, env))) {
                        if (!(err = lower_hex_on_set_code_text_option_set(argc, argv, env))) {
                            if (!(err = this->set_lower_hex_encode_source(argc, argv, env))) {
                                if (!(err = this->lower_hex_encode_source_set(argc, argv, env))) {
                                    if (!(err = this->set_hex_decode_source(argc, argv, env))) {
                                        if (!(err = this->hex_decode_source_set(argc, argv, env))) {
                                            if (!(err = this->set_lower_hex_encode_text_run(argc, argv, env))) {
                                                if (!(err = this->lower_hex_encode_text_run_set(argc, argv, env))) {
                                                    if (!(err = this->set_hex_decode_text_run(argc, argv, env))) {
                                                        if (!(err = this->hex_decode_text_run_set(argc, argv, env))) {
                                                        } else {}
                                                    } else {}
                                                } else {}
                                            } else {}
                                        } else {}
                                    } else {}
                                } else {}
                            } else {}
                        } else {}
                    } else {}
                } else {}
            } else {}
        } else {}
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...upper_hex_option...
    virtual int on_upper_hex_option_on
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = extends::on_upper_hex_option_on(optarg, optind, argc, argv, env))) {
            if (!(err = this->set_upper_hex_output_text(argc, argv, env))) {
                if (!(err = this->upper_hex_output_text_set(argc, argv, env))) {
                    if (!(err = set_upper_hex_on_set_code_text_option(argc, argv, env))) {
                        if (!(err = upper_hex_on_set_code_text_option_set(argc, argv, env))) {
                            if (!(err = this->set_upper_hex_encode_source(argc, argv, env))) {
                                if (!(err = this->upper_hex_encode_source_set(argc, argv, env))) {
                                    if (!(err = this->set_hex_decode_source(argc, argv, env))) {
                                        if (!(err = this->hex_decode_source_set(argc, argv, env))) {
                                            if (!(err = this->set_upper_hex_encode_text_run(argc, argv, env))) {
                                                if (!(err = this->upper_hex_encode_text_run_set(argc, argv, env))) {
                                                    if (!(err = this->set_hex_decode_text_run(argc, argv, env))) {
                                                        if (!(err = this->hex_decode_text_run_set(argc, argv, env))) {
                                                        } else {}
                                                    } else {}
                                                } else {}
                                            } else {}
                                        } else {}
                                    } else {}
                                } else {}
                            } else {}
                        } else {}
                    } else {}
                } else {}
            } else {}
        } else {}
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...plain_text...
    string_t& set_plain_text(const string_t& to, size_t length) {
        string_t& plain_text = this->plain_text();
        plain_text.assign(to, length);
        return plain_text;
    }
    string_t& set_plain_text(const string_t& to) {
        string_t& plain_text = this->plain_text();
        plain_text.assign(to);
        return plain_text;
    }
    string_t& set_plain_text(const char_t* to, size_t length) {
        string_t& plain_text = this->plain_text();
        plain_text.assign(to, length);
        return plain_text;
    }
    string_t& set_plain_text(const char_t* to) {
        string_t& plain_text = this->plain_text();
        plain_text.assign(to);
        return plain_text;
    }
    const char_t* plain_text_chars(size_t& length) const {
        string_t& plain_text = this->plain_text();
        return plain_text.has_chars(length);
    }
    string_t& plain_text() const {
        return (string_t&)plain_text_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...base64_code_text...
    string_t& set_base64_code_text(const string_t& to, size_t length) {
        string_t& base64_code_text = this->base64_code_text();
        base64_code_text.assign(to, length);
        return base64_code_text;
    }
    string_t& set_base64_code_text(const string_t& to) {
        string_t& base64_code_text = this->base64_code_text();
        base64_code_text.assign(to);
        return base64_code_text;
    }
    string_t& set_base64_code_text(const char_t* to, size_t length) {
        string_t& base64_code_text = this->base64_code_text();
        base64_code_text.assign(to, length);
        return base64_code_text;
    }
    string_t& set_base64_code_text(const char_t* to) {
        string_t& base64_code_text = this->base64_code_text();
        base64_code_text.assign(to);
        return base64_code_text;
    }
    const char_t* base64_code_text_chars(size_t& length) const {
        string_t& base64_code_text = this->base64_code_text();
        return base64_code_text.has_chars(length);
    }
    string_t& base64_code_text() const {
        return (string_t&)base64_code_text_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...hex_code_text...
    string_t& set_hex_code_text(const string_t& to, size_t length) {
        string_t& hex_code_text = this->hex_code_text();
        hex_code_text.assign(to, length);
        return hex_code_text;
    }
    string_t& set_hex_code_text(const string_t& to) {
        string_t& hex_code_text = this->hex_code_text();
        hex_code_text.assign(to);
        return hex_code_text;
    }
    string_t& set_hex_code_text(const char_t* to, size_t length) {
        string_t& hex_code_text = this->hex_code_text();
        hex_code_text.assign(to, length);
        return hex_code_text;
    }
    string_t& set_hex_code_text(const char_t* to) {
        string_t& hex_code_text = this->hex_code_text();
        hex_code_text.assign(to);
        return hex_code_text;
    }
    const char_t* hex_code_text_chars(size_t& length) const {
        string_t& hex_code_text = this->hex_code_text();
        return hex_code_text.has_chars(length);
    }
    string_t& hex_code_text() const {
        return (string_t&)hex_code_text_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...lower_hex_code_text...
    string_t& set_lower_hex_code_text(const string_t& to, size_t length) {
        string_t& lower_hex_code_text = this->lower_hex_code_text();
        lower_hex_code_text.assign(to, length);
        return lower_hex_code_text;
    }
    string_t& set_lower_hex_code_text(const string_t& to) {
        string_t& lower_hex_code_text = this->lower_hex_code_text();
        lower_hex_code_text.assign(to);
        return lower_hex_code_text;
    }
    string_t& set_lower_hex_code_text(const char_t* to, size_t length) {
        string_t& lower_hex_code_text = this->lower_hex_code_text();
        lower_hex_code_text.assign(to, length);
        return lower_hex_code_text;
    }
    string_t& set_lower_hex_code_text(const char_t* to) {
        string_t& lower_hex_code_text = this->lower_hex_code_text();
        lower_hex_code_text.assign(to);
        return lower_hex_code_text;
    }
    const char_t* lower_hex_code_text_chars(size_t& length) const {
        string_t& lower_hex_code_text = this->lower_hex_code_text();
        return lower_hex_code_text.has_chars(length);
    }
    string_t& lower_hex_code_text() const {
        return (string_t&)lower_hex_code_text_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...upper_hex_code_text...
    string_t& set_upper_hex_code_text(const string_t& to, size_t length) {
        string_t& upper_hex_code_text = this->upper_hex_code_text();
        upper_hex_code_text.assign(to, length);
        return upper_hex_code_text;
    }
    string_t& set_upper_hex_code_text(const string_t& to) {
        string_t& upper_hex_code_text = this->upper_hex_code_text();
        upper_hex_code_text.assign(to);
        return upper_hex_code_text;
    }
    string_t& set_upper_hex_code_text(const char_t* to, size_t length) {
        string_t& upper_hex_code_text = this->upper_hex_code_text();
        upper_hex_code_text.assign(to, length);
        return upper_hex_code_text;
    }
    string_t& set_upper_hex_code_text(const char_t* to) {
        string_t& upper_hex_code_text = this->upper_hex_code_text();
        upper_hex_code_text.assign(to);
        return upper_hex_code_text;
    }
    const char_t* upper_hex_code_text_chars(size_t& length) const {
        string_t& upper_hex_code_text = this->upper_hex_code_text();
        return upper_hex_code_text.has_chars(length);
    }
    string_t& upper_hex_code_text() const {
        return (string_t&)upper_hex_code_text_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...code_text...
    string_t& set_code_text(const string_t& to, size_t length) {
        string_t& code_text = this->code_text();
        code_text.assign(to, length);
        return code_text;
    }
    string_t& set_code_text(const string_t& to) {
        string_t& code_text = this->code_text();
        code_text.assign(to);
        return code_text;
    }
    string_t& set_code_text(const char_t* to, size_t length) {
        string_t& code_text = this->code_text();
        code_text.assign(to, length);
        return code_text;
    }
    string_t& set_code_text(const char_t* to) {
        string_t& code_text = this->code_text();
        code_text.assign(to);
        return code_text;
    }
    const char_t* code_text_chars(size_t& length) const {
        string_t& code_text = this->code_text();
        return code_text.has_chars(length);
    }
    string_t& code_text() const {
        return (string_t&)code_text_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...code_text...
    /// ...
    //////////////////////////////////////////////////////////////////////////
    /// enum code_text_block_size_t
    enum { 
        code_text_kilo_size = 1024,
        code_text_block_kilo_size = 64,
        code_text_block_size = (code_text_block_kilo_size*code_text_kilo_size)
    }; /// enum code_text_block_size_t
    //////////////////////////////////////////////////////////////////////////
    /// ...encode_text...
    virtual int on_encode_text_set(byte_t* encode_text, size_t sizeof_encode_text, size_t encode_text_size) {
        int err = 0;
        return err;
    }
    virtual byte_t* set_encode_text(const byte_t* to, size_t length) {
        if ((to) && (length)) {
            size_t sizeof_encode_text = sizeof(encode_text_);
            if (length > sizeof_encode_text) {
                length = sizeof_encode_text;
            }
            encode_text_length_ = (encode_text_size_ = length);
            ::memset(encode_text_, 0, sizeof_encode_text);
            ::memcpy(encode_text_, to, length);
        }
        return encode_text_;
    }
    virtual size_t set_encode_text_size(size_t to) {
        encode_text_length_ = (encode_text_size_ = to);
        return encode_text_size_;
    }
    virtual size_t encode_text_size() const {
        return encode_text_size_;
    }
    virtual size_t encode_text_length() const {
        return encode_text_length_;
    }
    virtual byte_t* encode_text_data(size_t& sizeof_encode_text) const {
        sizeof_encode_text = sizeof(encode_text_);
        return (byte_t*)encode_text_;
    }
    virtual byte_t* encode_text(size_t& sizeof_encode_text) const {
        sizeof_encode_text = sizeof(encode_text_);
        if ((encode_text_size_) && (encode_text_size_ < sizeof_encode_text)) {
            sizeof_encode_text = encode_text_size_;
        }
        return (byte_t*)encode_text_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...decode_text
    virtual int on_decode_text_set(byte_t* decode_text, size_t sizeof_decode_text, size_t decode_text_size) {
        int err = 0;
        return err;
    }
    virtual byte_t* set_decode_text(const byte_t* to, size_t length) {
        if ((to) && (length)) {
            size_t sizeof_decode_text = sizeof(decode_text_);
            if (length > sizeof_decode_text) {
                length = sizeof_decode_text;
            }
            decode_text_length_ = (decode_text_size_ = length);
            ::memset(decode_text_, 0, sizeof_decode_text);
            ::memcpy(decode_text_, to, length);
        }
        return decode_text_;
    }
    virtual size_t set_decode_text_size(size_t to) {
        decode_text_length_ = (decode_text_size_ = to);
        return decode_text_size_;
    }
    virtual size_t decode_text_size() const {
        return decode_text_size_;
    }
    virtual size_t decode_text_length() const {
        return decode_text_length_;
    }
    virtual byte_t* decode_text_data(size_t& sizeof_decode_text) const {
        sizeof_decode_text = sizeof(decode_text_);
        return (byte_t*)decode_text_;
    }
    virtual byte_t* decode_text(size_t& sizeof_decode_text) const {
        sizeof_decode_text = sizeof(decode_text_);
        if ((decode_text_size_) && (decode_text_size_ < sizeof_decode_text)) {
            sizeof_decode_text = decode_text_size_;
        }
        return (byte_t*)decode_text_;
    }
    /// ...
    /// ...code_text...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...source...
    /// ...
    //////////////////////////////////////////////////////////////////////////
    /// enum base_source_size_t
    enum { 
        hex_source_size = 32,
        base64_source_size = 48,
        base_source_size = base64_source_size
    }; /// enum base_source_size_t
    //////////////////////////////////////////////////////////////////////////
    /// ...base64_source
    virtual byte_t& base64_source(size_t& size) const {
        size = base64_source_size;
        return (byte_t&)base_source_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...hex_source
    virtual byte_t& hex_source(size_t& size) const {
        size = hex_source_size;
        return (byte_t&)base_source_;
    }
    /// ...
    /// ...source...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    string_t plain_text_, base64_code_text_, 
             lower_hex_code_text_, upper_hex_code_text_, hex_code_text_, code_text_;
    
    size_t encode_text_size_, decode_text_size_,
           encode_text_length_, decode_text_length_;

    byte_t encode_text_[code_text_block_size],
           decode_text_[code_text_block_size],
           base_source_[base_source_size];
}; /// class maint 
typedef maint<> main;

} /// namespace base 
} /// namespace code 
} /// namespace crypto 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_CODE_BASE_MAIN_HPP
