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
///   File: key_generator.hpp
///
/// Author: $author$
///   Date: 4/24/2022
/// 
/// Tatu Ylonen's RSA key generation function modified to be a C++
/// class that uses Eric Young's big number library instead of gmp used
/// in the original C version.
/// 
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RSA_BN_KEY_GENERATOR_HPP
#define XOS_CRYPTO_RSA_BN_KEY_GENERATOR_HPP

#include "xos/crypto/rsa/bn/license.hpp"
#include "xos/crypto/rsa/bn/private_key.hpp"
#include "xos/crypto/rsa/bn/public_key.hpp"
#include "xos/crypto/rsa/bn/key.hpp"
#include "xos/crypto/random/prime/bn/generator.hpp"

namespace xos {
namespace crypto {
namespace rsa {
namespace bn {

/// class key_generatort
template 
<class TPrivateKey = xos::crypto::rsa::bn::private_key,
 class TPublicKey = xos::crypto::rsa::bn::public_key,
 class TPrimeGenerator = xos::crypto::random::prime::bn::generator,
 class TNumberExtend  = typename TPrimeGenerator::number_extend_t,
 class TNumberImplement = typename TPrimeGenerator::number_implement_t,
 class TReaderObserver  = typename TPrimeGenerator::reader_observer_t,
 class TRandomReader  = typename TPrimeGenerator::random_reader_t,
 class TExtends = TNumberExtend, class TImplements = TNumberImplement>

class exported key_generatort: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements, implements;
    typedef TExtends Extends, extends;
    typedef key_generatort Derives, derives; 
    
    typedef TPrivateKey private_key_t;
    typedef TPublicKey public_key_t;
    typedef TPrimeGenerator prime_generator_t;
    typedef TNumberExtend number_extend_t;
    typedef TNumberImplement number_implement_t;
    typedef TReaderObserver reader_observer_t;
    typedef TRandomReader random_reader_t;

    /// constructors / destructor
    key_generatort(reader_observer_t* reader_observer): m_prime_generator(reader_observer) {
    }
    key_generatort() {
    }
    virtual ~key_generatort() {
    }
private:
    key_generatort(const key_generatort& copy) {
        LOGGER_LOG_ERROR("...unexpected throwing exception exception_unexpected...");
        throw exception(exception_unexpected);
    }
public:

    /// generate
    virtual bool generate
    (private_key_t& privatekey, public_key_t& publickey,
     size_t modbytes, const byte_t* exponent, unsigned expbytes, random_reader_t& random) {
        const bool no_miller_rabin_test = false;
        bool success = false;
        success = generate
        (privatekey, publickey, modbytes, exponent, expbytes, 
         random, no_miller_rabin_test, 0);
        return success;
    }
    virtual bool generate
    (private_key_t& privatekey, public_key_t& publickey,
     size_t modbytes, const byte_t* exponent, unsigned expbytes,
     random_reader_t& random, reader_observer_t* reader_observer) {
        const bool no_miller_rabin_test = false;
        bool success = false;
        success = generate
        (privatekey, publickey, modbytes, exponent, expbytes, 
         random, no_miller_rabin_test, reader_observer);
        return success;
    }
    virtual bool generate
    (private_key& privatekey, public_key& publickey,
     size_t modbytes, const byte_t* exponent, unsigned expbytes,
     random_reader_t& random, const bool& no_miller_rabin_test, reader_observer_t* reader_observer) {
        bool success = false;

        BIGINT& p = privatekey.p();
        BIGINT& q = privatekey.q();
        BIGINT& dmp1 = privatekey.dmp1();
        BIGINT& dmq1 = privatekey.dmq1();
        BIGINT& iqmp = privatekey.iqmp();
        BIGINT& e = publickey.exponent();
        BIGINT& n = publickey.modulus();
        BIGINT p_minus_1, q_minus_1, phi, F, G, d, one, temp;

        unsigned bytes, bits, ebits, modbits;
        bool retryp, retryq;
        int cmp;

        /* Compute the number of bits in each prime.
         */
        bytes = modbytes/2;
        bits = bytes*8;
        ebits = expbytes*8;
        modbits = bits*2;

        if ((m_prime_generator.create(no_miller_rabin_test))) {
            if ((publickey.create(modbytes,expbytes))) {
                if ((privatekey.create(bytes))) {
                    BIGPRIME* pp = p;
                    BIGPRIME* qp = q;
                    BN_CTX* ctx = 0;

                    if ((ctx = privatekey.ctx())) {
                    if ((p_minus_1 = BN_new())) {
                    if ((q_minus_1 = BN_new())) {
                    if ((phi = BN_new())) {
                    if ((G = BN_new())) {
                    if ((F = BN_new())) {
                    if ((one = BN_new())) {
                    if ((temp = BN_new())) {
                        BN_set_word(one,1);

                        success = true;
                        do {
                            retryp = false;

                            /* Generate random number p.
                             */
                            if (0 >= (m_prime_generator.generate(pp,bytes,random,reader_observer))) {
                                success = false;
                                break;
                            }
                            do {
                                retryq = false;

                                /* Generate random number q.
                                 */
                                if (0 >= (m_prime_generator.generate(qp,bytes,random,reader_observer))) {
                                    success = false;
                                    break;
                                }

                                /* n = p * q (the public modulus).
                                 */
                                BN_mul(n,p,q);

                                /* Make sure that p*q will be modbits in size.
                                 */
                                if (BN_num_bits(n)!=(int)modbits) {
                                    /* Not big enough so we will try again.
                                     */
                                    retryp = true;
                                    continue;
                                }

                                /* See if q < p.
                                 */
                                cmp = BN_cmp(p,q);
                                if (!cmp) {
                                    /* q == p
                                     */
                                    retryq = true;
                                    continue;
                                } else if (cmp<0) {
                                    /* p < q
                                     */
                                    BN_copy(p_minus_1,q);
                                    BN_copy(q_minus_1,p);
                                    /* swap p and q
                                     */
                                    BN_copy(q,p);
                                    BN_copy(p,q_minus_1);
                                } else {
                                    /* p > q
                                     */
                                    BN_copy(p_minus_1,p);
                                    BN_copy(q_minus_1,q);
                                }

                                /* Make sure that p and q are not too close together
                                 */
                                BN_sub(temp,p_minus_1,q_minus_1);
                                BN_rshift(p_minus_1,p_minus_1,10);

                                if (BN_cmp(temp,p_minus_1)<0) {
                                    /* p-q < p>>10 (they are too close)
                                     */
                                    retryq = true;
                                    continue;
                                }

                                /* Make certain p and q are relatively prime
                                 * (in case one or both were false positives...
                                 * Though this is quite improbable).
                                 */
                                BN_gcd(temp,p,q,ctx);

                                if (BN_cmp(temp,one)) {
                                    /* No, p and q are not relatively prime
                                     */
                                    retryq = true;
                                    continue;
                                }

                                /* Derive the RSA private key from the primes.
                                 * Given mutual primes p and q, derive RSA key components n, e, d, and u.
                                 * The exponent e will be at least ebits bits in size.
                                 * p must be smaller than q.
                                 */

                                /* Compute p-1 and q-1.
                                 */
                                BN_sub(p_minus_1,p,one);
                                BN_sub(q_minus_1,q,one);

                                /* phi = (p - 1) * (q - 1); the number of positive integers less than p*q
                                 * that are relatively prime to p*q.
                                 */
                                BN_mul(phi,p_minus_1,q_minus_1);

                                /* G is the number of "spare key sets" for a given modulus n.  The smaller
                                 * G is, the better.  The smallest G can get is 2.
                                 * F = phi / G; the number of relative prime numbers per spare key set.
                                 */
                                BN_gcd(G,p_minus_1,q_minus_1,ctx);
                                BN_div(F,temp,phi,G,ctx);

                                if (exponent) {
                                    BN_set_msb(e,exponent,expbytes);
                                } else {
                                    /* Find a suitable e (the public exponent).
                                     */
                                    BN_set_word(e,1);
                                    BN_lshift(e,e,ebits);
                                    BN_add_word(e,1);

                                    /* make lowest bit 1
                                    /* Keep adding 2 until it is relatively prime to (p-1)(q-1).
                                     */
                                    do {
                                        BN_gcd(temp,e,phi,ctx);
                                        if ((cmp = BN_cmp(temp,one))>0)
                                            BN_add_word(e,2);
                                    } while (cmp>0);
                                }

                                /* d is the multiplicative inverse of e, mod F.  Could also be mod
                                 * (p-1)(q-1); however, we try to choose the smallest possible d.
                                 */
                                d = BN_mod_inverse(e,F,ctx);
                                if (d) {
                                    /* Compute dmp1 = d mod p-1.
                                     */
                                    BN_mod(dmp1,d,p_minus_1,ctx);

                                    /* Compute dmq1 = d mod q-1.
                                     */
                                    BN_mod(dmq1,d,q_minus_1,ctx);
                                    BN_free(d);
                                }

                                /* iqmp is the multiplicative inverse of q, mod p, if q < p.  It is used
                                 * when doing private key RSA operations using the chinese remainder
                                 * theorem method.
                                 */
                                d = BN_mod_inverse(q,p,ctx);
                                if (d) {
                                    BN_copy(iqmp,d);
                                    BN_free(d);
                                }

                            } while (retryq);

                        } while (retryp);

                    BN_free(temp); }
                    BN_free(one); }
                    BN_free(F); }
                    BN_free(G); }
                    BN_free(phi); }
                    BN_free(q_minus_1); }
                    BN_free(p_minus_1); }
                    (ctx = 0); }

                    if (!success)
                        privatekey.destroy();
                }
                if (!success)
                    publickey.destroy();
            }
            m_prime_generator.destroy();
        }
        return success;
    }

protected:
    prime_generator_t m_prime_generator;
}; /// class key_generatort
typedef key_generatort<> key_generator;

} /// namespace bn
} /// namespace rsa
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RSA_BN_KEY_GENERATOR_HPP
