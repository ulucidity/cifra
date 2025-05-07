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
///   Date: 11/4/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_HPP

#include "xos/app/console/crypto/base/main_opt.hpp"
#include "xos/crypto/pseudo/random/number/generator.hpp"
#include "xos/io/hex/read_to_arrays.hpp"
#include "xos/io/hex/read_to_array.hpp"
#include "xos/io/crt/file/reader.hpp"
#include "xos/base/array.hpp"
#include "xos/crypto/array.hpp"

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::crypto::base::main_optt<>,  class TImplements = typename TExtends::implements>

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

    typedef xos::byte_array byte_array_t;
    typedef xos::crypto::array crypto_array_t;

    /// constructor / destructor
    maint()
    : run_(0), 

      input_x_(0), output_x_(0), 
      output_x_ln_(true), output_x_ln_length_(80), 
      output_hex_nextln_('\\'), output_hex_cols_(32), 
      output_hex_(0), output_hex_x_(0), 
      output_0x_nextln_(","), output_0x_next_(", "), 
      output_0x_cols_(16), output_0x_(0), output_0x_x_(0),
      output_base64_nextln_(output_hex_nextln_), output_base64_cols_(48),
      bits_(2048*8), bytes_((bits_ + (8 - 1)) / 8),

      base64_output_(false), 
      const_0x_output_(false), 
      verbose_output_(false),
      output_lf_(true),

      default_plain_text_("plain"), 
      default_cipher_text_("cipher"),
      default_random_text_("random"),
      plain_text_(default_plain_text_), 
      cipher_text_(default_cipher_text_),
      random_text_(default_random_text_) {
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
    /// ...generate_pseudo_random_number_run
    virtual int generate_pseudo_random_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        unsigned& bytes = this->bytes();

        if ((0 < bytes)) {
            xos::crypto::array& random_array = this->random_array();

            if (bytes == (random_array.set_length(bytes))) {
                byte_t* random_bytes = 0; size_t random_length = 0;

                if ((random_bytes = random_array.has_elements(random_length))) {
                    size_t random_generated = 0;
                    xos::crypto::pseudo::random::number::generator random_generator;

                    if (random_length == (random_generated = random_generator.generate(random_bytes, random_length))) {
                    } else {
                    }
                } else {
                }
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_plain_run
    virtual int default_output_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool& output_lf = this->output_lf();
        const char_t* plain_text = 0;
        size_t sizeof_plain_text = 0;

        if ((plain_text = this->plain_text(sizeof_plain_text))) {
            if ((output_lf)) {
                this->outln(plain_text, sizeof_plain_text);
            } else {
                this->out(plain_text, sizeof_plain_text);
            }
        } else {
        }
        return err;
    }
    virtual int x_output_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* plain_text = 0;
        size_t sizeof_plain_text = 0;

        if ((plain_text = this->plain_text(sizeof_plain_text))) {
            output_x(plain_text, sizeof_plain_text);
        } else {
        }
        return err;
    }
    virtual int Ox_before_output_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool& output_lf = this->output_lf();
        const string_t& before_0x_plain = this->before_0x_plain();
        if ((output_lf)) {
            this->outln(before_0x_plain);
        } else {
            this->out(before_0x_plain);
        }
        return err;
    }
    virtual int Ox_after_output_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool& output_lf = this->output_lf();
        const string_t& after_0x_plain = this->after_0x_plain();
        if ((output_lf)) {
            this->outln(after_0x_plain);
        } else {
            this->out(after_0x_plain);
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_cipher_run
    virtual int default_output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool& output_lf = this->output_lf();
        const char_t* cipher_text = 0;
        size_t sizeof_cipher_text = 0;

        if ((cipher_text = this->cipher_text(sizeof_cipher_text))) {
            if ((output_lf)) {
                this->outln(cipher_text, sizeof_cipher_text);
            } else {
                this->out(cipher_text, sizeof_cipher_text);
            }
        } else {
        }
        return err;
    }
    virtual int x_output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* cipher_text = 0;
        size_t sizeof_cipher_text = 0;

        if ((cipher_text = this->cipher_text(sizeof_cipher_text))) {
            output_x(cipher_text, sizeof_cipher_text);
        } else {
        }
        return err;
    }
    virtual int Ox_before_output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool& output_lf = this->output_lf();
        const string_t& before_0x_cipher = this->before_0x_cipher();
        if ((output_lf)) {
            this->outln(before_0x_cipher);
        } else {
            this->out(before_0x_cipher);
        }
        return err;
    }
    virtual int Ox_after_output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool& output_lf = this->output_lf();
        const string_t& after_0x_cipher = this->after_0x_cipher();
        if ((output_lf)) {
            this->outln(after_0x_cipher);
        } else {
            this->out(after_0x_cipher);
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_random_run
    virtual int default_output_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool& output_lf = this->output_lf();
        const char_t* random_text = 0;
        size_t sizeof_random_text = 0;

        if ((random_text = this->random_text(sizeof_random_text))) {
            if ((output_lf)) {
                this->outln(random_text, sizeof_random_text);
            } else {
                this->out(random_text, sizeof_random_text);
            }
        } else {
        }
        return err;
    }
    virtual int x_output_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* random_text = 0;
        size_t sizeof_random_text = 0;

        if ((random_text = this->random_text(sizeof_random_text))) {
            output_x(random_text, sizeof_random_text);
        } else {
        }
        return err;
    }
    virtual int Ox_before_output_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool& output_lf = this->output_lf();
        const string_t& before_0x_random = this->before_0x_random();
        if ((output_lf)) {
            this->outln(before_0x_random);
        } else {
            this->out(before_0x_random);
        }
        return err;
    }
    virtual int Ox_after_output_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool& output_lf = this->output_lf();
        const string_t& after_0x_random = this->after_0x_random();
        if ((output_lf)) {
            this->outln(after_0x_random);
        } else {
            this->out(after_0x_random);
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_random_number_run
    virtual int output_random_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const byte_t* random_bytes = 0; 
        size_t random_length = 0;
        xos::crypto::array& random_array = this->random_array();

        if ((random_bytes = random_array.has_elements(random_length))) {
            output_x(random_bytes, random_length);
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...random_array
    xos::crypto::array random_array_;
    virtual xos::crypto::array& random_array() const {
        return (xos::crypto::array&)random_array_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...input_x
    ssize_t (derives::*input_x_)(void* block, size_t length, char_reader_t& reader);
    virtual ssize_t input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        if ((this->input_x_)) {
            count = (this->*input_x_)(block, length, reader);
        } else {
            count = lower_input_x(block, length, reader);
        }
        return count;
    }
    virtual ssize_t base64_input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        if ((block) && (length)) {
            count = reader.read64(block, length);
        }
        return count;
    }
    virtual ssize_t upper_input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        if ((block) && (length)) {
           count = reader.readx(block, length);
        }
        return count;
    }
    virtual ssize_t lower_input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        if ((block) && (length)) {
            count = reader.readx(block, length);
        }
        return count;
    }
    virtual ssize_t before_input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t after_input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t all_input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        if (0 <= (count = before_input_x(block, length, reader))) {
            ssize_t count2 = 0;
            count = input_x(block, length, reader);
            if (0 > (count2 = after_input_x(block, length, reader))) {
                if (0 <= (count)) count = count2;
            }
        }
        return count;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_x
    int (derives::*output_x_)(const void* block, size_t length);
    virtual int output_x(const void* block, size_t length) {
        int err = 0;
        if ((this->output_x_)) {
            err = (this->*output_x_)(block, length);
        } else {
            err = lower_output_x(block, length);
        }
        return err;
    }
    virtual int base64_output_x(const void* block, size_t length) {
        int err = 0;
        if ((block) && (length)) {
            if (output_x_ln()) {
                this->out64ln(block, length);
            } else {
                this->out64(block, length);
            }
        }
        return err;
    }
    int (derives::*Ox_output_x_)(const void* block, size_t length);
    virtual int Ox_output_x(const void* block, size_t length) {
        int err = 0;
        if ((this->Ox_output_x_)) {
            err = (this->*Ox_output_x_)(block, length);
        } else {
            err = lower_0x_output_x(block, length);
        }
        return err;
    }
    virtual int upper_0x_output_x(const void* block, size_t length) {
        int err = 0;
        if ((block) && (length)) {
            if (output_x_ln()) {
                this->out0Xln(block, length);
            } else {
                this->out0X(block, length);
            }
        }
        return err;
    }
    virtual int lower_0x_output_x(const void* block, size_t length) {
        int err = 0;
        if ((block) && (length)) {
            if (output_x_ln()) {
                this->out0xln(block, length);
            } else {
                this->out0x(block, length);
            }
        }
        return err;
    }
    virtual int upper_output_x(const void* block, size_t length) {
        int err = 0;
        if ((block) && (length)) {
            if (output_x_ln()) {
                this->outXln(block, length);
            } else {
                this->outX(block, length);
            }
        }
        return err;
    }
    virtual int lower_output_x(const void* block, size_t length) {
        int err = 0;
        if ((block) && (length)) {
            if (output_x_ln()) {
                this->outxln(block, length);
            } else {
                this->outx(block, length);
            }
        }
        return err;
    }
    virtual int text_output_x(const void* block, size_t length) {
        int err = 0;
        const char_t* chars = 0;
        if ((chars = ((const char_t*)block)) && (length)) {
            if (output_x_ln()) {
                this->outln(chars, length);
            } else {
                this->out(chars, length);
            }
        }
        return err;
    }
    virtual int before_output_x(const void* block, size_t length) {
        int err = 0;
        return err;
    }
    virtual int after_output_x(const void* block, size_t length) {
        int err = 0;
        return err;
    }
    virtual int all_output_x(const void* block, size_t length) {
        int err = 0;
        if (!(err = before_output_x(block, length))) {
            int err2 = 0;
            err = output_x(block, length);
            if ((err2 = after_output_x(block, length))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_base64_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        input_x_ = &derives::base64_input_x;
        output_x_ = &derives::base64_output_x;
        return err;
    }
    virtual int set_0x_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_x_ = &derives::Ox_output_x;
        return err;
    }
    virtual int set_upper_0x_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        Ox_output_x_ = &derives::upper_0x_output_x;
        return err;
    }
    virtual int set_lower_0x_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        Ox_output_x_ = &derives::lower_0x_output_x;
        return err;
    }
    virtual int set_upper_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        input_x_ = &derives::upper_input_x;
        output_x_ = &derives::upper_output_x;
        return err;
    }
    virtual int set_lower_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        input_x_ = &derives::lower_input_x;
        output_x_ = &derives::lower_output_x;
        return err;
    }
    virtual int set_text_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_x_ = &derives::text_output_x;
        return err;
    }
    virtual int unset_text_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_x_ = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_x
    virtual int output_x(const char_t* chars, const void* block, size_t length) {
        int err = 0;
        if ((chars)) {
            this->outln(chars, length);
        } else {
            err = this->all_output_x(block, length);
        }
        return err;
    }
    virtual int before_output_x(const char_t* chars, const void* block, size_t length) {
        int err = 0;
        return err;
    }
    virtual int after_output_x(const char_t* chars, const void* block, size_t length) {
        int err = 0;
        return err;
    }
    virtual int all_output_x(const char_t* chars, const void* block, size_t length) {
        int err = 0;
        if (!(err = before_output_x(chars, block, length))) {
            int err2 = 0;
            err = output_x(chars, block, length);
            if ((err2 = after_output_x(chars, block, length))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_hex
    char_t output_hex_nextln_; size_t output_hex_cols_;
    int (derives::*output_hex_)(const void* out, size_t len);
    virtual int output_hex(const void* out, size_t len) {
        int err = 0;
        if (output_hex_) {
            err = (this->*output_hex_)(out, len);
        } else {
            err = default_output_hex(out, len);
        }
        return err;
    }
    virtual int default_output_hex(const void* out, size_t len) {
        int err = 0;
        const byte_t *bytes = 0;

        if ((bytes = ((const byte_t*)out)) && (len)) {
            char_t nextln = output_hex_nextln_;
            size_t cols = output_hex_cols_, col = 0;

            for (col = 0; len; --len, ++bytes, ++col) {
                if (cols <= (col)) {
                    this->outln(&nextln, 1);
                    col = 0;
                }
                this->output_hex_x(bytes, 1);
            }
            this->outln();
        }
        return err;
    }
    int (derives::*output_hex_x_)(const void* out, size_t len);
    virtual int output_hex_x(const void* out, size_t len) {
        int err = 0;
        if (output_hex_x_) {
            err = (this->*output_hex_x_)(out, len);
        } else {
            err = lower_output_hex_x(out, len);
        }
        return err;
    }
    virtual int lower_output_hex_x(const void* out, size_t len) {
        int err = 0;
        const byte_t *bytes = 0;

        if ((bytes = ((const byte_t*)out)) && (len)) {
            this->outx(bytes, len);
        }
        return err;
    }
    virtual int upper_output_hex_x(const void* out, size_t len) {
        int err = 0;
        const byte_t *bytes = 0;

        if ((bytes = ((const byte_t*)out)) && (len)) {
            this->outX(bytes, len);
        }
        return err;
    }
    virtual int set_lower_output_hex_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_hex_x_ = &derives::lower_output_hex_x;
        return err;
    }
    virtual int set_upper_output_hex_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_hex_x_ = &derives::upper_output_hex_x;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_0x
    string_t output_0x_nextln_, output_0x_next_; size_t output_0x_cols_;
    int (derives::*output_0x_)(const void* out, size_t len);
    virtual int output_0x(const void* out, size_t len) {
        int err = 0;
        if (output_0x_) {
            err = (this->*output_0x_)(out, len);
        } else {
            err = default_output_0x(out, len);
        }
        return err;
    }
    virtual int default_output_0x(const void* out, size_t len) {
        int err = 0;
        const byte_t *bytes = 0;

        if ((bytes = ((const byte_t*)out)) && (len)) {
            const string_t &next = output_0x_next_, &nextln = output_0x_nextln_;
            size_t cols = output_0x_cols_, col = 0;

            this->output_0x_x(bytes, 1);
            for (col = 1, ++bytes, --len; len; --len, ++bytes, ++col) {
                if (cols <= (col)) {
                    this->outln(nextln);
                    col = 0;
                } else {
                    this->out(next);
                }
                this->output_0x_x(bytes, 1);
            }
            this->outln();
        }
        return err;
    }
    int (derives::*output_0x_x_)(const void* out, size_t len);
    virtual int output_0x_x(const void* out, size_t len) {
        int err = 0;
        if (output_0x_x_) {
            err = (this->*output_0x_x_)(out, len);
        } else {
            err = lower_output_0x_x(out, len);
        }
        return err;
    }
    virtual int lower_output_0x_x(const void* out, size_t len) {
        int err = 0;
        const byte_t *bytes = 0;

        if ((bytes = ((const byte_t*)out)) && (len)) {
            this->out0x(bytes, len);
        }
        return err;
    }
    virtual int upper_output_0x_x(const void* out, size_t len) {
        int err = 0;
        const byte_t *bytes = 0;

        if ((bytes = ((const byte_t*)out)) && (len)) {
            this->out0X(bytes, len);
        }
        return err;
    }
    virtual int set_lower_output_0x_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_0x_x_ = &derives::lower_output_0x_x;
        return err;
    }
    virtual int set_upper_output_0x_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_0x_x_ = &derives::upper_output_0x_x;
        return err;
    }
    virtual const string_t& output_0x_nextln() const {
        return output_0x_nextln_;
    }
    virtual const string_t& output_0x_next() const {
        return output_0x_next_;
    }
    virtual size_t output_0x_cols() const {
        return output_0x_cols_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_base64
    char_t output_base64_nextln_; size_t output_base64_cols_;
    virtual int output_base64(const void* out, size_t len) {
        int err = 0;
        const byte_t *bytes = 0;

        if ((bytes = ((const byte_t*)out)) && (len)) {
            string_t& output_string = this->output_string();
            char_t nextln = output_base64_nextln_;
            size_t cols = output_base64_cols_, col = 0, length = 0;
            const char* chars = 0;

            output_string.clear();
            for (col = 0; len; --len, ++bytes, ++col) {
                if (cols <= (col)) {
                    if ((chars = output_string.has_chars(length))) {
                        this->out64(chars, length);
                        output_string.clear();
                    }
                    this->outln(&nextln, 1);
                    col = 0;
                }
                output_string.append((const char*)bytes, 1);
            }
            if ((chars = output_string.has_chars(length))) {
                this->out64(chars, length);
                output_string.clear();
            }
            this->outln();
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_hex_verbage_sized
    typedef int (derives::*output_hex_verbage_sized_t)(const char_t* verbage, const void* out, size_t len);
    output_hex_verbage_sized_t output_hex_verbage_sized_;
    virtual int output_hex_verbage_sized(const char_t* verbage, const byte_array_t& array) {
        int err = 0;
        size_t length = 0;
        const byte_t* bytes = 0; 
        if ((bytes = array.has_elements(length))) {
            err = output_hex_verbage_sized(verbage, bytes, length);
        }
        return err;
    }
    virtual int output_hex_verbage_sized(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if (output_hex_verbage_sized_) {
            err = (this->*output_hex_verbage_sized_)(verbage, out, len);
        } else {
            err = default_output_hex_verbage_sized(verbage, out, len);
        }
        return err;
    }
    virtual int default_output_hex_verbage_sized(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if ((out) && (len)) {
            bool verbose = this->verbose();
            if ((verbose) && (verbage) && (verbage[0])) {
                unsigned_to_string size(len);
                this->out(verbage);
                this->out("[");
                this->out(size);
                this->outln("]:\\");
            }
            this->output_hex(out, len);
            if ((verbose) && (verbage) && (verbage[0])) {
                this->outln();
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_const_0x_verbage_sized...
    virtual int output_const_0x_verbage_sized(const char_t* verbage, const byte_array_t& array) {
        int err = 0;
        size_t length = 0;
        const byte_t* bytes = 0; 
        if ((bytes = array.has_elements(length))) {
            err = output_const_0x_verbage_sized(verbage, bytes, length);
        }
        return err;
    }
    virtual int output_const_0x_verbage_sized(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        err = output_0x_verbage_sized
        ("const byte_t ", " = {", "};", verbage, out, len);
        return err;
    }
    virtual int output_0x_verbage_sized
    (const char_t* before, const char_t* between, const char_t* after, 
     const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if ((out) && (len)) {
            if ((before) && (before[0])) {
                this->out(before);
            }
            if ((verbage) && (verbage[0])) {
                unsigned_to_string size(len);
                this->out(verbage);
                this->out("[");
                this->out(size);
                this->out("]");
            }
            if ((between) && (between[0])) {
                this->outln(between);
            }
            this->output_0x(out, len);
            if ((after) && (after[0])) {
                this->outln(after);
            } else {
                if ((verbage) && (verbage[0])) {
                    this->outln();
                }
            }
        }
        return err;
    }
    virtual output_hex_verbage_sized_t set_output_const_0x_verbage_sized() {
        output_hex_verbage_sized_t output_hex_verbage_sized = output_hex_verbage_sized_;
        output_hex_verbage_sized_ = &derives::output_const_0x_verbage_sized;
        return output_hex_verbage_sized;
    }
    virtual output_hex_verbage_sized_t unset_output_0x_verbage_sized(output_hex_verbage_sized_t to) {
        output_hex_verbage_sized_t output_hex_verbage_sized = output_hex_verbage_sized_;
        output_hex_verbage_sized_ = to;
        return output_hex_verbage_sized;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int output_hex_verbage(const char_t* verbage, const byte_array_t& array) {
        int err = 0;
        size_t length = 0;
        const byte_t* bytes = 0; 
        if ((bytes = array.has_elements(length))) {
            err = output_hex_verbage(verbage, bytes, length);
        }
        return err;
    }
    virtual int output_hex_verbage(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if ((out) && (len)) {
            bool verbose = this->verbose();
            if ((verbose) && (verbage) && (verbage[0])) {
                this->out(verbage);
                this->outln(":\\");
            }
            this->output_hex(out, len);
            if ((verbose) && (verbage) && (verbage[0])) {
                this->outln();
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_base64_verbage_sized
    typedef int (derives::*output_base64_verbage_sized_t)(const char_t* verbage, const void* out, size_t len);
    output_base64_verbage_sized_t output_base64_verbage_sized_;
    virtual int output_base64_verbage_sized(const char_t* verbage, const byte_array_t& array) {
        int err = 0;
        size_t length = 0;
        const byte_t* bytes = 0; 
        if ((bytes = array.has_elements(length))) {
            err = output_base64_verbage_sized(verbage, bytes, length);
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int output_base64_verbage_sized(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if (output_base64_verbage_sized_) {
            err = (this->*output_base64_verbage_sized_)(verbage, out, len);
        } else {
            err = default_output_base64_verbage_sized(verbage, out, len);
        }
        return err;
    }
    virtual int default_output_base64_verbage_sized(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if ((out) && (len)) {
            bool verbose = this->verbose();
            if ((verbose) && (verbage) && (verbage[0])) {
                unsigned_to_string size(len);
                this->out(verbage);
                this->out("[");
                this->out(size);
                this->outln("]:\\");
            }
            this->output_base64(out, len);
            if ((verbose) && (verbage) && (verbage[0])) {
                this->outln();
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int output_base64_verbage(const char_t* verbage, const byte_array_t& array) {
        int err = 0;
        size_t length = 0;
        const byte_t* bytes = 0; 
        if ((bytes = array.has_elements(length))) {
            err = output_base64_verbage(verbage, bytes, length);
        }
        return err;
    }
    virtual int output_base64_verbage(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if ((out) && (len)) {
            bool verbose = this->verbose();
            if ((verbose) && (verbage) && (verbage[0])) {
                this->out(verbage);
                this->outln(":\\");
            }
            this->output_base64(out, len);
            if ((verbose) && (verbage) && (verbage[0])) {
                this->outln();
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_base64_verbose_sized
    typedef int (derives::*output_base64_verbose_sized_t)(const char_t* verbage, const void* out, size_t len);
    output_base64_verbose_sized_t output_base64_verbose_sized_;
    virtual int output_base64_verbose_sized(const char_t* verbage, const byte_array_t& array) {
        int err = 0;
        size_t length = 0;
        const byte_t* bytes = 0; 
        if ((bytes = array.has_elements(length))) {
            err = output_base64_verbose_sized(verbage, bytes, length);
        }
        return err;
    }
    virtual int output_base64_verbose_sized(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if (output_base64_verbose_sized_) {
            err = (this->*output_base64_verbose_sized_)(verbage, out, len);
        } else {
            err = default_output_base64_verbose_sized(verbage, out, len);
        }
        return err;
    }
    virtual int default_output_base64_verbose_sized(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if ((out) && (len)) {
            bool verbose = this->verbose();
            if ((verbose) && (verbage) && (verbage[0])) {
                unsigned_to_string size(len);
                this->out(verbage);
                this->out("[");
                this->out(size);
                this->outln("]:\\");
                this->output_base64(out, len);
                this->outln();
            }
        }
        return err;
    }
    virtual int output_base64_verbose(const char_t* verbage, const byte_array_t& array) {
        int err = 0;
        size_t length = 0;
        const byte_t* bytes = 0; 
        if ((bytes = array.has_elements(length))) {
            err = output_base64_verbose(verbage, bytes, length);
        }
        return err;
    }
    virtual int output_base64_verbose(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if ((out) && (len)) {
            bool verbose = this->verbose();
            if ((verbose) && (verbage) && (verbage[0])) {
                this->out(verbage);
                this->outln(":\\");
                this->output_base64(out, len);
                this->outln();
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...on_set_option_on
    virtual int on_set_option_on
    (bool& on, const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t arg(optarg);
            int unequal = 0;
            if (!(unequal = arg.compare(XOS_APP_CONSOLE_MAIN_OPTARG_ON))) {
                on = true;
            } else {
                if (!(unequal = arg.compare(XOS_APP_CONSOLE_MAIN_OPTARG_OFF))) {
                    on = false;
                } else {
                    err = 1;
                }
            }
        } else {
            err = 1;
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on_plain_text_set
    virtual int on_plain_text_set(const char_t* to) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on_cipher_text_set
    virtual int on_cipher_text_set(const char_t* to) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...plain_text_option...
    virtual int on_set_plain_text_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_plain_text(optarg);
            if (!(err = on_plain_text_set(optarg))) {
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...cipher_text_option...
    virtual int on_set_cipher_text_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_cipher_text(optarg);
            if (!(err = on_cipher_text_set(optarg))) {
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...random_text_option...
    /// ...on_set_random_text_option
    int (derives::*on_set_random_text_option_)(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env);
    virtual int on_set_random_text_option(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (on_set_random_text_option_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*on_set_random_text_option_)(optarg, optind, argc, argv, env)))...");
            if (!(err = (this->*on_set_random_text_option_)(optarg, optind, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*on_set_random_text_option_)(optarg, optind, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*on_set_random_text_option_)(optarg, optind, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_on_set_random_text_option(optarg, optind, argc, argv, env)))...");
            if (!(err = default_on_set_random_text_option(optarg, optind, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_on_set_random_text_option(optarg, optind, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_on_set_random_text_option(optarg, optind, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_on_set_random_text_option
    (const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            err = on_set_random_bytes_option(optarg, optind, argc, argv, env);
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...bytes_on_set_random_text_option
    virtual int bytes_on_set_random_text_option(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            err = on_set_random_bytes_option(optarg, optind, argc, argv, env);
        } else {
        }
        return err;
    }
    virtual int set_bytes_on_set_random_text_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_random_text_option_ = &derives::bytes_on_set_random_text_option;
        return err;
    }
    virtual int bytes_on_set_random_text_option_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_bytes_on_set_random_text_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_random_text_option_ = 0;
        return err;
    }
    virtual int bytes_on_set_random_text_option_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...bits_on_set_random_text_option
    virtual int bits_on_set_random_text_option(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            err = on_set_random_bits_option(optarg, optind, argc, argv, env);
        } else {
        }
        return err;
    }
    virtual int set_bits_on_set_random_text_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_random_text_option_ = &derives::bits_on_set_random_text_option;
        return err;
    }
    virtual int bits_on_set_random_text_option_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_bits_on_set_random_text_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_random_text_option_ = 0;
        return err;
    }
    virtual int bits_on_set_random_text_option_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...random_bits_option...
    virtual int on_set_random_bits_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t arg(optarg);
            unsigned n = 0;
            if ((0 < (n = arg.to_unsigned()))) {
                set_bytes_to_bits(n);
            } else {
            }
        } else {
        }
        err = set_bits_on_set_random_text_option(argc, argv, env);
        return err;
    }
    virtual int on_random_bits_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        err = set_bits_on_set_random_text_option(argc, argv, env);
        return err;
    }
    virtual int on_random_bits_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        err = set_bits_on_set_random_text_option(argc, argv, env);
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...random_bytes_option...
    virtual int on_set_random_bytes_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t arg(optarg);
            unsigned n = 0;
            if ((0 < (n = arg.to_unsigned()))) {
                set_bits_to_bytes(n);
            } else {
            }
        } else {
        }
        err = set_bytes_on_set_random_text_option(argc, argv, env);
        return err;
    }
    virtual int on_set_random_bytes_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        err = set_bytes_on_set_random_text_option(argc, argv, env);
        return err;
    }
    virtual int on_set_random_bytes_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        err = set_bytes_on_set_random_text_option(argc, argv, env);
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...base64_io_option...
    virtual int on_base64_io_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_base64_output_x(argc, argv, env))) {
            if (!(err = this->set_x_output_random_run(argc, argv, env))) {
                if (!(err = this->set_x_output_cipher_run(argc, argv, env))) {
                    if (!(err = this->set_x_output_plain_run(argc, argv, env))) {
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_base64_io_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...upper_hex_io_option...
    virtual int on_upper_hex_io_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_upper_output_x(argc, argv, env))) {
            if (!(err = this->set_x_output_random_run(argc, argv, env))) {
                if (!(err = this->set_x_output_cipher_run(argc, argv, env))) {
                    if (!(err = this->set_x_output_plain_run(argc, argv, env))) {
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_upper_hex_io_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...lower_hex_io_option...
    virtual int on_lower_hex_io_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_lower_output_x(argc, argv, env))) {
            if (!(err = this->set_x_output_random_run(argc, argv, env))) {
                if (!(err = this->set_x_output_cipher_run(argc, argv, env))) {
                    if (!(err = this->set_x_output_plain_run(argc, argv, env))) {
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_lower_hex_io_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...Ox_output_option...
    virtual int on_Ox_output_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_0x_output_x(argc, argv, env))) {
            if (!(err = this->set_0x_output_random_run(argc, argv, env))) {
                if (!(err = this->set_0x_output_cipher_run(argc, argv, env))) {
                    if (!(err = this->set_0x_output_plain_run(argc, argv, env))) {
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_Ox_output_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...text_output_option...
    virtual int on_text_output_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_text_output_x(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_text_output_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...noline_output_option...
    virtual int on_noline_output_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        set_no_output_lf();
        set_no_output_x_ln();
        return err;
    }
    virtual int on_noline_output_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            bool on = false;
            if (!(err = on_set_option_on(on, optarg, optind, argc, argv, env))) {
                set_no_output_lf(on);
                set_no_output_x_ln();
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...verbose_output_option...
    virtual int on_verbose_output_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        set_verbose_output();
        return err;
    }
    virtual int on_verbose_output_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            bool on = false;
            if (!(err = on_set_option_on(on, optarg, optind, argc, argv, env))) {
                set_verbose_output(on);
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...quiet_output_option...
    virtual int on_quiet_output_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        set_quiet_output();
        return err;
    }
    virtual int on_quiet_output_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            bool on = false;
            if (!(err = on_set_option_on(on, optarg, optind, argc, argv, env))) {
                set_quiet_output(on);
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_x_ln
    bool output_x_ln_;
    virtual bool& set_no_output_x_ln(const bool& to = true) {
        bool& output_x_ln = this->output_x_ln();
        output_x_ln = !to;
        return output_x_ln;
    }
    virtual bool& set_output_x_ln(const bool& to = true) {
        bool& output_x_ln = this->output_x_ln();
        output_x_ln = to;
        return output_x_ln;
    }
    virtual bool& output_x_ln() const {
        return (bool&)output_x_ln_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_x_ln_length
    size_t output_x_ln_length_;
    virtual size_t& set_output_x_ln_length(const size_t& to = true) {
        size_t& output_x_ln_length = this->output_x_ln_length();
        output_x_ln_length = to;
        return output_x_ln_length;
    }
    virtual size_t& output_x_ln_length() const {
        return (size_t&)output_x_ln_length_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...bits
    unsigned bits_, bytes_;
    virtual unsigned& set_bits_to_bytes(const unsigned& to_bytes) {
        unsigned& bytes = this->bytes();
        unsigned& bits = this->bits();
        bits = ((bytes = to_bytes) * 8);
        return bits;
    }
    virtual unsigned& set_bits(const unsigned& to) {
        unsigned& bits = this->bits();
        bits = to;
        return bits;
    }
    virtual unsigned& bits() const {
        return (unsigned&)bits_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ..bytes
    virtual unsigned& set_bytes_to_bits(const unsigned& to_bits) {
        unsigned& bits = this->bits();
        unsigned& bytes = this->bytes();
        bytes = ((bits = (to_bits + (8 - 1))) / 8);
        return bytes;
    }
    virtual unsigned& set_bytes(const unsigned& to) {
        unsigned& bytes = this->bytes();
        bytes = to;
        return bytes;
    }
    virtual unsigned& bytes() const {
        return (unsigned&)bytes_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...default_plain_text
    virtual const char_t* set_default_plain_text(const char_t* to, size_t length) {
        default_plain_text_.assign(to, length);
        return default_plain_text_.chars();
    }
    virtual const char_t* set_default_plain_text(const char_t* to) {
        default_plain_text_.assign(to);
        return default_plain_text_.chars();
    }
    virtual const char_t* default_plain_text(size_t& length) const {
        return default_plain_text_.has_chars(length);
    }
    virtual const string_t& default_plain_text_string() const {
        return default_plain_text_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...default_cipher_text
    virtual const char_t* set_default_cipher_text(const char_t* to, size_t length) {
        default_cipher_text_.assign(to, length);
        return default_cipher_text_.chars();
    }
    virtual const char_t* set_default_cipher_text(const char_t* to) {
        default_cipher_text_.assign(to);
        return default_cipher_text_.chars();
    }
    virtual const char_t* default_cipher_text(size_t& length) const {
        return default_cipher_text_.has_chars(length);
    }
    virtual const string_t& default_cipher_text_string() const {
        return default_cipher_text_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...default_random_text
    virtual const char_t* set_default_random_text(const char_t* to, size_t length) {
        default_random_text_.assign(to, length);
        return default_random_text_.chars();
    }
    virtual const char_t* set_default_random_text(const char_t* to) {
        default_random_text_.assign(to);
        return default_random_text_.chars();
    }
    virtual const char_t* default_random_text(size_t& length) const {
        return default_random_text_.has_chars(length);
    }
    virtual const string_t& default_random_text_string() const {
        return default_random_text_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...plain_text
    virtual const char_t* set_plain_text(const char_t* to, size_t length) {
        string_t& plain_text = this->plain_text();
        plain_text.assign(to, length);
        return plain_text.chars();
    }
    virtual const char_t* set_plain_text(const char_t* to) {
        string_t& plain_text = this->plain_text();
        plain_text.assign(to);
        return plain_text.chars();
    }
    virtual const char_t* plain_text(size_t& length) const {
        const string_t& plain_text = this->plain_text();
        return plain_text.has_chars(length);
    }
    virtual const string_t& plain_text_string() const {
        const string_t& plain_text = this->plain_text();
        return plain_text;
    }
    virtual string_t& plain_text() const {
        return (string_t&)plain_text_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...cipher_text
    virtual const char_t* set_cipher_text(const char_t* to, size_t length) {
        cipher_text_.assign(to, length);
        return cipher_text_.chars();
    }
    virtual const char_t* set_cipher_text(const char_t* to) {
        cipher_text_.assign(to);
        return cipher_text_.chars();
    }
    virtual const char_t* cipher_text(size_t& length) const {
        return cipher_text_.has_chars(length);
    }
    virtual const string_t& cipher_text_string() const {
        return cipher_text_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...random_text
    virtual const char_t* set_random_text(const char_t* to, size_t length) {
        random_text_.assign(to, length);
        return random_text_.chars();
    }
    virtual const char_t* set_random_text(const char_t* to) {
        random_text_.assign(to);
        return random_text_.chars();
    }
    virtual const char_t* random_text(size_t& length) const {
        return random_text_.has_chars(length);
    }
    virtual const string_t& random_text_string() const {
        return random_text_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_string
    virtual string_t& set_output_string(const string_t& to) {
        string_t& output_string = this->output_string();
        output_string.assign(to);
        return output_string;
    }
    virtual string_t& output_string() const {
        return (string_t&)output_string_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...reader_string
    virtual reader_string_t& set_reader_string(const string_t& to) {
        reader_string_t& reader_string = this->reader_string();
        reader_string.assign(to);
        return reader_string;
    }
    virtual reader_string_t& reader_string() const {
        return (reader_string_t&)reader_string_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...base64_output
    virtual bool set_base64_output(const bool to = true) {
        base64_output_ = to;
        return base64_output_;
    }
    virtual bool base64_output() const {
        return base64_output_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...const_0x_output
    virtual bool set_const_0x_output(const bool to = true) {
        const_0x_output_ = to;
        return const_0x_output_;
    }
    virtual bool const_0x_output() const {
        return const_0x_output_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...verbose_output
    virtual bool& set_quiet_output(const bool& to = true) {
        bool& verbose_output = this->verbose_output();
        verbose_output = !to;
        return verbose_output;
    }
    virtual bool& set_verbose_output(const bool& to = true) {
        bool& verbose_output = this->verbose_output();
        verbose_output = to;
        return verbose_output;
    }
    virtual bool& verbose_output() const {
        return (bool&)verbose_output_;
    }
    virtual bool& verbose() const {
        bool& verbose_output = this->verbose_output();
        return verbose_output;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_lf
    virtual bool& set_no_output_lf(const bool& to = true) {
        bool& output_lf = this->output_lf();
        output_lf = !to;
        return output_lf;
    }
    virtual bool& set_output_lf(const bool& to = true) {
        bool& output_lf = this->output_lf();
        output_lf = to;
        return output_lf;
    }
    virtual bool& output_lf() const {
        return (bool&)output_lf_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    bool base64_output_, const_0x_output_, verbose_output_, output_lf_;
    string_t default_plain_text_, default_cipher_text_, default_random_text_,
             plain_text_, cipher_text_, random_text_, output_string_;
    reader_string_t reader_string_;
}; /// class maint 
typedef maint<> main;

} /// namespace base 
} /// namespace crypto 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_HPP

