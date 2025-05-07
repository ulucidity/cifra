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
///   File: miller_rabin.hpp
///
/// Author: $author$
///   Date: 4/25/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RANDOM_PRIME_MP_MILLER_RABIN_HPP
#define XOS_CRYPTO_RANDOM_PRIME_MP_MILLER_RABIN_HPP

#include "xos/crypto/random/prime/mp/license.hpp"
#include "xos/crypto/random/prime/miller_rabin.hpp"
#include "xos/crypto/random/prime/mp/reader.hpp"
#include "xos/base/extended/creator.hpp"

namespace xos {
namespace crypto {
namespace random {
namespace prime {
namespace mp {

/// class miller_rabin_implementt
template 
<class TNumberImplements = xos::crypto::random::prime::mp::number_implement,
 class TReader = xos::crypto::random::prime::mp::reader,  
 class TCreator = xos::creatort<TReader>, class TImplements = TCreator>

class exported miller_rabin_implementt
: virtual public TNumberImplements, virtual public TImplements {
public:
    typedef TNumberImplements NumberImplements, number_implements;
    typedef TImplements Implements, implements;
    typedef miller_rabin_implementt Derives, derives; 
    
    /// constructors / destructor
    virtual ~miller_rabin_implementt() {
    }

}; /// class miller_rabin_implementt
typedef miller_rabin_implementt<> miller_rabin_implement;

/// class miller_rabint
template 
<class TNumber = xos::crypto::random::prime::mp::number,
 class TReader = xos::crypto::random::prime::mp::reader,
 class TReaderObserver = typename TReader::reader_observer_t,
 class TRandomReader = xos::crypto::random::reader,
 class TMillerRabin = xos::crypto::random::prime::miller_rabint<BIGPRIME, TReader, TRandomReader, miller_rabin_implement>,
 class TExtends = xos::extended::creatort<miller_rabin_implement, TMillerRabin>, class TImplements = miller_rabin_implement>

class exported miller_rabint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements, implements;
    typedef TExtends Extends, extends;
    typedef miller_rabint Derives, derives; 
    
    typedef TNumber number_t;
    typedef TReaderObserver reader_observer_t;
    typedef TRandomReader random_reader_t;

    /// constructors / destructor
    miller_rabint(reader_observer_t* observer): m_reader_observer(observer) {
    }
    miller_rabint(): m_reader_observer(0) {
    }
    virtual ~miller_rabint() {
        if (!(this->destroyed())) {
            LOGGER_LOG_ERROR("...failed on destroyed() throwing create_exception destroy_failed...");
            throw (create_exception(destroy_failed));
        }
    }
private:
    miller_rabint(const miller_rabint& copy) {
        LOGGER_LOG_ERROR("...unexpected throwing exception exception_unexpected...");
        throw exception(exception_unexpected);
    }
public:

    /// create / destroy
    virtual bool create() {
        if ((this->destroyed())) {
            mpz_init_set_ui(&m_n_minus_1,0);
            mpz_init_set_ui(&m_x,0);
            mpz_init_set_ui(&m_one,1);
            mpz_init_set_ui(&m_z,0);
            mpz_init_set_ui(&m_q,0);
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual bool destroy() {
        if ((this->is_created())) {
            this->set_is_created(false);
            mpz_clear(&m_q);
            mpz_clear(&m_z);
            mpz_clear(&m_one);
            mpz_clear(&m_x);
            mpz_clear(&m_n_minus_1);
            return true;
        }
        return false;
    }

    /// probably_prime
    using Extends::probably_prime;
    virtual bool probably_prime(const number_t& n, size_t bytes, random_reader_t& random) {
        BIGPRIME *attached = 0;
        if ((attached = n.attached_to())) {
            return this->probably_prime(attached, bytes, random);
        }
        return false;
    }
    virtual bool probably_prime(BIGPRIME* n, size_t bytes, unsigned reps, random_reader_t& random) {
        if ((this->is_created())) {
            unsigned bits = (bytes<<3);
            unsigned i,j,k;

            mpz_sub(&m_n_minus_1, n, &m_one);

            /* find q and k, such that n = 1 + 2^k * q
             * ie q = (n-1)/2^k
             */
            mpz_set(&m_q, &m_n_minus_1);

            for (k=0; (mpz_get_ui(&m_q)&1)==0; k++)
                mpz_tdiv_q_2exp(&m_q, &m_q, 1);

            for (i = 0; i < reps ; i++) {
                /* find random x such that 1 < x < n
                 */
                do {
                    if (0 >= (this->ReadMSB(&m_x, bytes, random)))
                        return false;

                    /* make x < n
                     */
                    mpz_clrbit(&m_x, bits-1);
                } while (mpz_cmp(&m_x, &m_one) <= 0);

                /* z = x^q mod n
                 */
                mpz_powm(&m_z, &m_x, &m_q, n);

                /* if z == 0 or z == n-1 then possibly prime
                 */
                if ((mpz_cmp(&m_z, &m_one) == 0)
                    || (mpz_cmp(&m_z, &m_n_minus_1) == 0))
                    continue;

                for (j = 1; j < k; j++) {
                    /* z = z^2 mod n
                     */
                    mpz_powm_ui(&m_z, &m_z, 2, n);

                    /* if z == n-1 then possibly prime
                     */
                    if (mpz_cmp(&m_z, &m_n_minus_1) == 0)
                        break;

                    /* if z == 1 then not prime
                     */
                    if (mpz_cmp(&m_z, &m_one) == 0)
                        return false;
                }

                if (j>=k)
                    return false;
            }
            return true;
        }
        return false;
    }

    /// ...delegate...
    virtual reader_observer_t* delegate_observer(reader_observer_t* to) {
        m_reader_observer = to;
        return m_reader_observer;
    }
    virtual reader_observer_t* observer_delegated(BIGPRIME* n) const {
        return m_reader_observer;
    }

protected:
    reader_observer_t* m_reader_observer;
    MP_INT m_n_minus_1, m_x, m_one, m_z, m_q;
}; /// class miller_rabint
typedef miller_rabint<> miller_rabin;

} /// namespace mp
} /// namespace prime
} /// namespace random
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RANDOM_PRIME_MP_MILLER_RABIN_HPP
