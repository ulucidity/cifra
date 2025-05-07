///////////////////////////////////////////////////////////////////////
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
///   Date: 4/23/2022
///
/// Tatu Ylonen's prime generation modified to be a C++ class that
/// uses Eric Young's big number library instead of gmp used in the
/// original C version.
/// 
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RANDOM_PRIME_BN_GENERATOR_HPP
#define XOS_CRYPTO_RANDOM_PRIME_BN_GENERATOR_HPP

#include "xos/crypto/random/prime/bn/license.hpp"
#include "xos/crypto/random/prime/bn/number.hpp"
#include "xos/crypto/random/prime/bn/reader.hpp"
#include "xos/crypto/random/prime/generator.hpp"
#include "xos/base/extended/creator.hpp"

#if !defined(_RSA_NO_MILLER_RABIN_TEST)
#include "xos/crypto/random/prime/bn/miller_rabin.hpp"
#endif /// !defined(_CRSA_NO_MILLER_RABIN_TEST)

namespace xos {
namespace crypto {
namespace random {
namespace prime {
namespace bn {

/// class generatort
template 
<class TNumber = xos::crypto::random::prime::bn::number,
 class TReader = xos::crypto::random::prime::bn::reader,
 class TRandomReader = xos::crypto::random::reader,
 class TNumberExtend = typename TNumber::number_extend_t,
 class TNumberImplement = typename TNumber::number_implement_t,
 class TReaderImplement = typename TReader::reader_implement_t,
 class TReaderObserver = typename TReader::reader_observer_t,
#if !defined(_RSA_NO_MILLER_RABIN_TEST)
 class TMillerRabin = xos::crypto::random::prime::bn::miller_rabin,
#endif /// !defined(_CRSA_NO_MILLER_RABIN_TEST)
 class TImplements = xos::creatort<TReaderImplement>, 
 class TGenerator = xos::crypto::random::prime::generatort<BIGPRIME, TImplements, TReader>,
 class TExtends = xos::extended::creatort<TImplements, TGenerator> >

class exported generatort
: virtual public TNumberImplement, virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements, implements;
    typedef TExtends Extends, extends;
    typedef generatort Derives, derives; 
    
    typedef TNumber number_t;
    typedef TNumberExtend number_extend_t;
    typedef TNumberImplement number_implement_t;
    typedef TReaderObserver reader_observer_t;
    typedef TRandomReader random_reader_t;
    
#if !defined(_RSA_NO_MILLER_RABIN_TEST)
    typedef TMillerRabin miller_rabin_t;
#endif /// !defined(_CRSA_NO_MILLER_RABIN_TEST)

    /// constructors / destructor
    generatort(reader_observer_t* reader_observer) 
    : m_reader_observer(reader_observer),
      m_temp1(0), m_temp2(0), m_ctx(0)
#if !defined(_RSA_NO_MILLER_RABIN_TEST)
      , m_miller_rabin(m_reader_observer)
#endif /// !defined(_RSA_NO_MILLER_RABIN_TEST)
    {
    }
    generatort() 
    : m_reader_observer(0),
      m_temp1(0), m_temp2(0), m_ctx(0)
#if !defined(_RSA_NO_MILLER_RABIN_TEST)
      , m_miller_rabin(m_reader_observer)
#endif /// !defined(_RSA_NO_MILLER_RABIN_TEST)
    {
    }
    virtual ~generatort() {
        if (!(this->destroyed())) {
            LOGGER_LOG_ERROR("...failed on destroyed() throwing create_exception destroy_failed...");
            throw (create_exception(destroy_failed));
        }
    }
private:
    generatort(const generatort& copy) {
        LOGGER_LOG_ERROR("...unexpected throwing exception exception_unexpected...");
        throw exception(exception_unexpected);
    }
public:

    /// create / destroy
    virtual bool create() {
        return create(false);
    }
    virtual bool create(bool no_miller_rabin_test) {
        if ((this->destroyed())) {
            if ((m_temp1 = BN_new())) {
            if ((m_temp2 = BN_new())) {
            if ((m_ctx = BN_CTX_new())) {
#if !defined(_RSA_NO_MILLER_RABIN_TEST)
            if ((m_miller_rabin.create())) {
                this->m_no_miller_rabin_test = no_miller_rabin_test;
#endif /// !defined(_CRSA_NO_MILLER_RABIN_TEST)
                return true;
#if !defined(_RSA_NO_MILLER_RABIN_TEST)
                m_miller_rabin.destroy(); }
#endif /// !defined(_CRSA_NO_MILLER_RABIN_TEST)
                this->BN_CTX_free(m_ctx); }
                this->BN_free(m_temp2); }
                this->BN_free(m_temp1); }
        }
        return false;
    }
    virtual bool destroy() {
        if ((this->is_created())) {
            bool is_true = true;
            this->set_is_created(false);
#if !defined(_RSA_NO_MILLER_RABIN_TEST)
            this->m_no_miller_rabin_test = false;
            is_true = m_miller_rabin.destroy();
#endif /// !defined(_CRSA_NO_MILLER_RABIN_TEST)
            this->BN_CTX_free(m_ctx);
            this->BN_free(m_temp2);
            this->BN_free(m_temp1);
            return is_true;
        }
        return false;
    }

    /// generate
    virtual ssize_t generate(const number_t& prime, size_t bytes, random_reader_t& random) {
        BIGPRIME *attached = 0;
        if ((attached = prime.attached_to())) {
            return generate(attached, bytes, random);
        }
        return 0;
    }
    virtual ssize_t generate(BIGPRIME* prime, size_t bytes, random_reader_t& random) {
        return generate(prime, bytes, random, 0);
    }
    virtual ssize_t generate(BIGPRIME* prime, size_t bytes, random_reader_t& random, reader_observer_t* reader_observer) {
        size_t count = 0;
        bool retry = true;
        unsigned bits = (bytes << 3);

#if !defined(_RSA_NO_SMALL_PRIME_TEST)
        long difference, small_prime;
        unsigned i, num_primes;
#endif /// !defined(_RSA_NO_SMALL_PRIME_TEST)

        reader_observer_t* old_reader_observer = m_reader_observer;
        if ((reader_observer)) {
            m_reader_observer = reader_observer;
#if !defined(_RSA_NO_MILLER_RABIN_TEST)
            m_miller_rabin.delegate_observer(reader_observer);
#endif /// !defined(_CRSA_NO_MILLER_RABIN_TEST)
        }

        do {
            /* Pick a random integer of the appropriate size.
             */
            if (0 >= (count = this->ReadMSB(prime, bytes, random))) {
                return count;
            }

            /* Set the lowest bit to make it odd.
             */
            BN_set_bit(prime,0);

            /* Set the highest bit to make it n bits.
             */
            BN_set_bit(prime,(bits-1));

#if defined(_RSA_SET_TWO_HIGHEST_BITS)
            /* Set the second highest bit.
             */
            BN_set_bit(prime,(bits-2));
#endif /// defined(_RSA_SET_TWO_HIGHEST_BITS)

#if !defined(_RSA_NO_SMALL_PRIME_TEST)
            /* Initialize moduli of the small primes with respect to the
             * random number.
             */
            if (bits < 16) {
                /* Don't use the table for very small numbers.
                 */
                num_primes = 0;
            } else {
                for (num_primes = 0; this->m_small_primes[num_primes] != 0; num_primes++) {
                    this->m_moduli[num_primes] = BN_mod_word(prime, this->m_small_primes[num_primes]);
                }
            }

            /* Look for numbers that are not evenly divisible
             * by any of the small primes.
             */
            for (difference = 0; difference <= this->m_small_prime_difference; difference += 2) {
                /* Check if it is a multiple of any small prime. Note that this
                 * updates the moduli into negative values as difference grows.
                 */
                for (i = 0; i < num_primes; i++) {
                    while ((this->m_moduli[i] + difference) >= (small_prime = (long)(this->m_small_primes[i]))) {
                        this->m_moduli[i] -= small_prime;
                    }
                    if ((this->m_moduli[i] + difference) == 0) {
                        break;
                    }
                }

                if (i < num_primes) {
                    /* Multiple of a known prime.
                     */
                    continue;
                }
                /* It passed the small prime test (not divisible by any of them).
                 * Compute the number in question.
                 */
                BN_add_word(prime,difference);
#endif /// !defined(_RSA_NO_SMALL_PRIME_TEST)

                /* Perform the fermat test for witness 2. This means
                 * it is not prime if 2^n mod n != 2.
                 */
                BN_set_word(m_temp1,2);
                BN_mod_exp(m_temp2,m_temp1,prime,prime,m_ctx);
                if (BN_cmp(m_temp1,m_temp2)) {
                    /* Failed the fermat test for witness 2.
                     */
                    continue;
                }
#if !defined(_RSA_NO_MILLER_RABIN_TEST)
                if (!(this->m_no_miller_rabin_test)) {
                    /* Perform the Miller Rabin primality test.
                     */
                    if (!(m_miller_rabin.probably_prime
                        (prime, bytes, this->m_miller_rabin_reps, random))) {
                        /* Failed the Miller Rabin probable primality test.
                         */
                        continue;
                    }
                }
#endif /// !defined(_CRSA_NO_MILLER_RABIN_TEST)

                /* Found a (probable) prime.
                 * Sanity check: does it still have the high bit set
                 * (we might have wrapped around)?
                 */
                if (BN_is_bit_set(prime,bits-1)) {
                    /* passed sanity check!
                     * it does still have the high bit set
                     */
                    retry = false;
                }
#if !defined(_RSA_NO_SMALL_PRIME_TEST)
                break;
            }
#endif /// !defined(_RSA_NO_SMALL_PRIME_TEST)

        } while (retry);
        
        if ((reader_observer)) {
#if !defined(_RSA_NO_MILLER_RABIN_TEST)
            m_miller_rabin.delegate_observer(old_reader_observer);
#endif /// !defined(_CRSA_NO_MILLER_RABIN_TEST)
            m_reader_observer = old_reader_observer;
        }
        return bytes;
    }

    /// observer...
    virtual reader_observer_t* observer_delegated(BIGPRIME* n) const {
        return m_reader_observer;
    }

protected:
    reader_observer_t* m_reader_observer;
    BIGNUM *m_temp1, *m_temp2;
    BN_CTX *m_ctx;
#if !defined(_RSA_NO_MILLER_RABIN_TEST)
    miller_rabin_t m_miller_rabin;
#endif /// !defined(_RSA_NO_MILLER_RABIN_TEST)
}; /// class generatort
typedef generatort<> generator;

} /// namespace bn
} /// namespace prime
} /// namespace random
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RANDOM_PRIME_BN_GENERATOR_HPP
