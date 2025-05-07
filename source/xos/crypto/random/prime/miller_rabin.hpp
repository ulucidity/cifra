///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
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
///   File: miller_rabin.hpp
///
/// Author: $author$
///   Date: 4/22/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RANDOM_PRIME_MILLER_RABIN_HPP
#define XOS_CRYPTO_RANDOM_PRIME_MILLER_RABIN_HPP

#include "xos/crypto/random/prime/reader.hpp"

#define CRYPTO_RANDOM_PRIME_MILLER_RABIN_REPS 25

namespace xos {
namespace crypto {
namespace random {
namespace prime {

/// class miller_rabint
template 
<typename TBIGPRIME,
 class TReader, class TRandomReader,
 class TImplements = xos::crypto::implement, class TExtends = xos::crypto::extend>

class exported miller_rabint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements, implements;
    typedef TExtends Extends, extends;
    typedef miller_rabint Derives, derives; 
    
    typedef TBIGPRIME BIGPRIME;
    typedef TReader reader_t;
    typedef TRandomReader random_reader_t;

    /// constructors / destructor
    miller_rabint(const unsigned& reps): m_reps(reps) {
    }
    miller_rabint(): m_reps(CRYPTO_RANDOM_PRIME_MILLER_RABIN_REPS) {
    }
    virtual ~miller_rabint() {
    }
private:
    miller_rabint(const miller_rabint& copy) {
        LOGGER_LOG_ERROR("...unexpected throwing exception exception_unexpected...");
        throw exception(exception_unexpected);
    }
public:

    /// probably_prime
    virtual bool probably_prime(BIGPRIME* n, size_t bytes, random_reader_t& random) {
        return this->probably_prime(n, bytes, reps(), random);
    }
    virtual bool probably_prime(BIGPRIME* n, size_t bytes, unsigned reps, random_reader_t& random) {
        return false;
    }

    /// ProbablyPrime
    virtual bool ProbablyPrime(BIGPRIME* n, size_t bytes, random_reader_t& random) {
        return this->probably_prime(n, bytes, random);
    }
    virtual bool ProbablyPrime(BIGPRIME* n, size_t bytes, unsigned reps, random_reader_t& random) {
        return this->probably_prime(n, bytes, reps, random);
    }

    /// ...reps
    virtual unsigned set_reps(const unsigned& to) {
        m_reps = to;
        return m_reps;
    }
    virtual unsigned reps() const {
        return m_reps;
    }

protected:
    unsigned m_reps;
}; /// class miller_rabint

} /// namespace prime
} /// namespace random
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RANDOM_PRIME_MILLER_RABIN_HPP
