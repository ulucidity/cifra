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
///   File: generator.hpp
///
/// Author: $author$
///   Date: 4/21/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RANDOM_PRIME_GENERATOR_HPP
#define XOS_CRYPTO_RANDOM_PRIME_GENERATOR_HPP

#include "xos/crypto/base.hpp"

#if !defined(_RSA_NO_SMALL_PRIME_TEST)
#include "xos/crypto/random/prime/small_primes.hpp"
#define _RSA_SMALL_PRIME_DIFFERENCE 0x7
#else // !defined(_RSA_NO_SMALL_PRIME_TEST)
#endif // !defined(_RSA_NO_SMALL_PRIME_TEST)

#if !defined(_RSA_NO_MILLER_RABIN_TEST)
#define _RSA_MILLER_RABIN_REPS 25
#else // !defined(_RSA_NO_MILLER_RABIN_TEST)
#endif // !defined(_RSA_NO_MILLER_RABIN_TEST)

namespace xos {
namespace crypto {
namespace random {
namespace prime {

/// class generatort
template 
<typename TBIGPRIME,
 class TImplements = xos::crypto::implement, class TExtends = xos::crypto::extend>

class exported generatort: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements, implements;
    typedef TExtends Extends, extends;
    typedef generatort Derives, derives; 
    
    typedef TBIGPRIME BIGPRIME;

    /// constructors / destructor
    generatort():
#if !defined(_RSA_NO_MILLER_RABIN_TEST)
      m_no_miller_rabin_test(false),
      m_miller_rabin_reps(_RSA_MILLER_RABIN_REPS),
#else /// !defined(_RSA_NO_MILLER_RABIN_TEST)
      m_no_miller_rabin_test(true),
#endif /// !defined(_RSA_NO_MILLER_RABIN_TEST)

#if !defined(_RSA_NO_SMALL_PRIME_TEST)
      m_no_small_prime_test(false),
      m_small_primes(g_small_primes),
      m_small_prime_difference(_RSA_SMALL_PRIME_DIFFERENCE)
#else /// !defined(_RSA_NO_SMALL_PRIME_TEST)
      m_no_small_prime_test(true)
#endif /// !defined(_RSA_NO_SMALL_PRIME_TEST)
    {
    }
    virtual ~generatort() {
    }
private:
    generatort(const generatort& copy) {
        throw exception(exception_unexpected);
    }
public:

    /// ...no_miller_rabin_test
    virtual bool set_no_miller_rabin_test(bool to = true) {
#if !defined(_RSA_NO_MILLER_RABIN_TEST)
        m_no_miller_rabin_test = to;
#endif /// !defined(_RSA_NO_MILLER_RABIN_TEST)
        return m_no_miller_rabin_test;
    }
    virtual bool no_miller_rabin_test() const {
        return m_no_miller_rabin_test;
    }

    /// ...no_small_prime_test
    virtual bool set_no_small_prime_test(bool to = true) {
#if !defined(_RSA_NO_SMALL_PRIME_TEST)
        m_no_small_prime_test = to;
#endif /// !defined(_RSA_NO_SMALL_PRIME_TEST)
        return m_no_small_prime_test;
    }
    virtual bool no_small_prime_test() const {
        return m_no_small_prime_test;
    }

protected:
#if !defined(_RSA_NO_MILLER_RABIN_TEST)
    bool m_no_miller_rabin_test; 
    unsigned m_miller_rabin_reps;
#else /// !defined(_RSA_NO_MILLER_RABIN_TEST)
    const bool m_no_miller_rabin_test;
#endif /// !defined(_RSA_NO_MILLER_RABIN_TEST)

#if !defined(_RSA_NO_SMALL_PRIME_TEST)
    bool m_no_small_prime_test; 
    const unsigned short* m_small_primes; 
    long m_small_prime_difference, m_moduli[SMALL_PRIMES_SIZE];
#else /// !defined(_RSA_NO_SMALL_PRIME_TEST)
    const bool m_no_small_prime_test;
#endif /// !defined(_RSA_NO_SMALL_PRIME_TEST)
}; /// class generatort

} /// namespace prime
} /// namespace random
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RANDOM_PRIME_GENERATOR_HPP
