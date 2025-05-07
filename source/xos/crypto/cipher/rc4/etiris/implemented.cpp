///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
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
///   File: implemented.cpp
///
/// Author: $author$
///   Date: 2/2/2021
///////////////////////////////////////////////////////////////////////
#include "xos/crypto/cipher/rc4/etiris/implemented.hpp"

#if defined(ERROR_INVALID_PARAMETER)
#define XOS_CRYPTO_CIPHER_RC4_ETIRIS_ERROR_INVALID_PARAMETER ERROR_INVALID_PARAMETER
#undef ERROR_INVALID_PARAMETER
#endif /// defined(ERROR_INVALID_PARAMETER)

namespace xos {
namespace crypto {
namespace cipher {
namespace rc4 {
namespace etiris {

/// enum ERROR
enum {
    ERROR_INVALID_PARAMETER = error_invalid_parameter,

    ERROR_KEY_SIZE = error_invalid_parameter_size,
    ERROR_KEY_SIZE_UNDER = error_invalid_parameter_size,
    ERROR_KEY_SIZE_OVER = error_invalid_parameter_size,

    ERROR_IV_SIZE = error_invalid_parameter_size,
    ERROR_IV_SIZE_UNDER = error_invalid_parameter_size,
    ERROR_IV_SIZE_OVER = error_invalid_parameter_size,

    ERROR_OUT_SIZE = error_invalid_parameter_size,
    ERROR_OUT_SIZE_UNDER = error_invalid_parameter_size,
    ERROR_OUT_SIZE_OVER = error_invalid_parameter_size
}; /// enum ERROR

///  Class: implemented

/// initialize / clear
ssize_t implemented::initialize
(const void* key, size_t keylen, const void* iv, size_t ivlen, const void* padd, size_t paddlen) {
    size_t i,j,k;
	byte_t t;

    if (iv || ivlen || padd || paddlen)
        return -ERROR_INVALID_PARAMETER;

    if (0 >= keylen)
        keylen = strlen((const char*)key);

	m_x=0;
	m_y=0;
	i=0;
	j=0;

	for (k=0; k<256; k++)
		m_data[k]=k;

	for (k=0; k<256; k++) {
		t = m_data[k];
		j = (((const byte_t*)key)[i] + t + j) & 0xff;

		if (++i >= keylen) 
            i = 0;

		m_data[k] = m_data[j];
		m_data[j] = t;
	}
    return keylen;
}
void implemented::clear() {
    m_x=0; m_y=0;
    memset(m_data, 0, sizeof(m_data));
}

/// ..crypt...
ssize_t implemented::encrypt(void* out, size_t outsize, const void* in, size_t inlen) {
    size_t outlen;
    byte_t t;

    if (0 >= inlen)
        inlen = strlen((const char*)in);

    for (outlen=0; outlen<inlen; outlen++) {
        m_y += (t = m_data[++m_x]);
        m_data[m_x] = m_data[m_y];
        m_data[m_y] = t;
        ((byte_t*)out)[outlen] = ((const byte_t*)in)[outlen]^m_data[(m_data[m_x]+t)&255];
    }
    return outlen;
}
ssize_t implemented::decrypt(void* out, size_t outsize, const void* in, size_t inlen) {
    size_t outlen;
    byte_t t;

    for (outlen=0; outlen<inlen; outlen++) {
        m_y += (t = m_data[++m_x]);
        m_data[m_x] = m_data[m_y];
        m_data[m_y] = t;
        ((byte_t*)out)[outlen] = ((const byte_t*)in)[outlen]^m_data[(m_data[m_x]+t)&255];
    }
    return outlen;
}

#if defined(XOS_CRYPTO_CIPHER_RC4_ETIRIS_IMPLEMENTED_INSTANCE)
static implemented the_implemented;
#endif /// defined(XOS_CRYPTO_CIPHER_RC4_ETIRIS_IMPLEMENTED_INSTANCE)

} /// namespace etiris
} /// namespace rc4
} /// namespace cipher
} /// namespace crypto
} /// namespace xos

#if defined(XOS_CRYPTO_CIPHER_RC4_ETIRIS_ERROR_INVALID_PARAMETER)
#define ERROR_INVALID_PARAMETER XOS_CRYPTO_CIPHER_RC4_ETIRIS_ERROR_INVALID_PARAMETER
#undef XOS_CRYPTO_CIPHER_RC4_ETIRIS_ERROR_INVALID_PARAMETER
#endif /// defined(XOS_CRYPTO_CIPHER_RC4_ETIRIS_ERROR_INVALID_PARAMETER)
