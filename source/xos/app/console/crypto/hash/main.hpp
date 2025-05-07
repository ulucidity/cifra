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
///   Date: 11/10/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HPP

#include "xos/app/console/crypto/hash/main_opt.hpp"
#include "xos/crypto/hash/openssl/md5.hpp"
#include "xos/crypto/hash/openssl/sha1.hpp"
#include "xos/crypto/hash/openssl/sha256.hpp"
#include "xos/crypto/hash/openssl/sha512.hpp"

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace hash {

/// class maint
template 
<class TExtends = xos::app::console::crypto::hash::main_optt<>,  class TImplements = typename TExtends::implements>

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
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// md5...
    xos::crypto::hash::md5* (derives::*md5_hash_algorithm_)() const;
    virtual xos::crypto::hash::algorithm* md5_hash_algorithm() const {
        if ((md5_hash_algorithm_)) {
            return (this->*md5_hash_algorithm_)();
        }
        return openssl_md5();
    }
    virtual xos::crypto::hash::md5* openssl_md5() const {
        return (xos::crypto::hash::md5*)&openssl_md5_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// sha1...
    xos::crypto::hash::sha1* (derives::*sha1_hash_algorithm_)() const;
    virtual xos::crypto::hash::algorithm* sha1_hash_algorithm() const {
        if ((sha1_hash_algorithm_)) {
            return (this->*sha1_hash_algorithm_)();
        }
        return openssl_sha1();
    }
    virtual xos::crypto::hash::sha1* openssl_sha1() const {
        return (xos::crypto::hash::sha1*)&openssl_sha1_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// sha256...
    xos::crypto::hash::sha256* (derives::*sha256_hash_algorithm_)() const;
    virtual xos::crypto::hash::algorithm* sha256_hash_algorithm() const {
        if ((sha256_hash_algorithm_)) {
            return (this->*sha256_hash_algorithm_)();
        }
        return openssl_sha256();
    }
    virtual xos::crypto::hash::sha256* openssl_sha256() const {
        return (xos::crypto::hash::sha256*)&openssl_sha256_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// sha512...
    xos::crypto::hash::sha512* (derives::*sha512_hash_algorithm_)() const;
    virtual xos::crypto::hash::algorithm* sha512_hash_algorithm() const {
        if ((sha512_hash_algorithm_)) {
            return (this->*sha512_hash_algorithm_)();
        }
        return openssl_sha512();
    }
    virtual xos::crypto::hash::sha512* openssl_sha512() const {
        return (xos::crypto::hash::sha512*)&openssl_sha512_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    xos::crypto::hash::openssl::md5 openssl_md5_;
    xos::crypto::hash::openssl::sha1 openssl_sha1_;
    xos::crypto::hash::openssl::sha256 openssl_sha256_;
    xos::crypto::hash::openssl::sha512 openssl_sha512_;
}; /// class maint 
typedef maint<> main;

} /// namespace hash 
} /// namespace crypto 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HPP

