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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 11/6/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_OPT_HPP

#include "xos/app/console/crypto/base/main.hpp"

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_DEFINE "XOS_APP_CONSOLE_CRYPTO_RSA_KEY_PAIR_CONST_HPP"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_DEFINE "XOS_APP_CONSOLE_CRYPTO_RSA_PUBLIC_KEY_CONST_HPP"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_DEFINE "XOS_APP_CONSOLE_CRYPTO_RSA_PRIVATE_KEY_CONST_HPP"

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_EXPONENT_BITS 24
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_EXPONENT_BYTES 3
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_EXPONENT_VALUE 0x010001

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_MIN 128
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_MAX 8192
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS 2048

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_MIN 32
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_MAX 1024
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES 256

//////////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_MIN_OPTARG XOS_2CHARS(XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_MIN)
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_MAX_OPTARG XOS_2CHARS(XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_MAX)
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTARG_OPTIONAL \
    "[" XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_MIN_OPTARG \
    ".." XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_MAX_OPTARG "]"

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_MIN_OPTARG XOS_2CHARS(XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_MIN)
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_MAX_OPTARG XOS_2CHARS(XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_MAX)
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTARG_OPTIONAL \
    "[" XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_MIN_OPTARG \
    ".." XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_MAX_OPTARG "]"

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_PAIR_OPT "generate"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_PAIR_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_PAIR_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_PAIR_OPTARG XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTARG_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_PAIR_OPTUSE "generate RSA key pair"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_PAIR_OPTVAL_S "n::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_PAIR_OPTVAL_C 'n'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_PAIR_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_PAIR_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_PAIR_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_PAIR_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_PAIR_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_KEY_PAIR_OPT "test"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_KEY_PAIR_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_KEY_PAIR_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_KEY_PAIR_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_KEY_PAIR_OPTUSE "test RSA key pair"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_KEY_PAIR_OPTVAL_S "t::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_KEY_PAIR_OPTVAL_C 't'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_KEY_PAIR_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_KEY_PAIR_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_KEY_PAIR_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_KEY_PAIR_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_KEY_PAIR_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPT "encrypt"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTUSE "RSA public encrypt/decrypt"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTVAL_S "e::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTVAL_C 'e'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPT "decrypt"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTUSE "RSA private decrypt/encrypt"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTVAL_S "d::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTVAL_C 'd'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPT "plain"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTUSE "plain text to encrypt"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTVAL_S "p::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTVAL_C 'p'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPT "cipher"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTUSE "cipher text to decrypt"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTVAL_S "c::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTVAL_C 'c'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPT "key-pair"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTUSE "key pair"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTVAL_S "k::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTVAL_C 'k'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPT "private-key"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTUSE "private key"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTVAL_S "r::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTVAL_C 'r'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPT "public-key"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTUSE "public key"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTVAL_S "u::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTVAL_C 'u'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPT "bits"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTARG XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTARG_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTUSE "modulus bits"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTVAL_S "i::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTVAL_C 'i'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPT "bytes"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTARG XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTARG_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTUSE "modulus bytes"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTVAL_S "y::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTVAL_C 'y'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPT "miller-rabin"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTUSE "do miller rabin primality test"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTVAL_S "m::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTVAL_C 'm'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPT "fermat-witness"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTUSE "do fermat witness primality test"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTVAL_S "w::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTVAL_C 'w'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_RANDOM_NUMBER_OPT "random"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_RANDOM_NUMBER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_RANDOM_NUMBER_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_RANDOM_NUMBER_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_RANDOM_NUMBER_OPTUSE "use random number"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_RANDOM_NUMBER_OPTVAL_S "a::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_RANDOM_NUMBER_OPTVAL_C 'a'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_RANDOM_NUMBER_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_RANDOM_NUMBER_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_RANDOM_NUMBER_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_RANDOM_NUMBER_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_RANDOM_NUMBER_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PSEUDO_RANDOM_NUMBER_OPT "pseudo-random"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PSEUDO_RANDOM_NUMBER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PSEUDO_RANDOM_NUMBER_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PSEUDO_RANDOM_NUMBER_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PSEUDO_RANDOM_NUMBER_OPTUSE "use pseudo random number"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PSEUDO_RANDOM_NUMBER_OPTVAL_S "s::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PSEUDO_RANDOM_NUMBER_OPTVAL_C 's'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PSEUDO_RANDOM_NUMBER_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PSEUDO_RANDOM_NUMBER_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PSEUDO_RANDOM_NUMBER_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PSEUDO_RANDOM_NUMBER_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PSEUDO_RANDOM_NUMBER_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPT "bn-integer"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTUSE "use bn integer library"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTVAL_S "b::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTVAL_C 'b'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPT "gmp-integer"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTUSE "use gmp integer library"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTVAL_S "g::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTVAL_C 'g'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_PAIR_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_KEY_PAIR_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_RANDOM_NUMBER_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PSEUDO_RANDOM_NUMBER_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_PAIR_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_KEY_PAIR_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_RANDOM_NUMBER_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PSEUDO_RANDOM_NUMBER_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE_IO_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE_IO_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ARGS 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace rsa {

/// class main_optt
template 
<class TExtends = xos::app::console::crypto::base::maint<>,  class TImplements = typename TExtends::implements>

class main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

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

    typedef typename extends::byte_array_t byte_array_t;
    typedef typename extends::crypto_array_t crypto_array_t;

    /// constructor / destructor
    main_optt()
    : run_(0),
      key_pair_define_(XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_DEFINE),
      public_key_define_(XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_DEFINE),
      private_key_define_(XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_DEFINE) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt &copy) {
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
    /// ...generate_key_pair_run
    int (derives::*generate_key_pair_run_)(int argc, char_t** argv, char_t** env);
    virtual int generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (generate_key_pair_run_) {
            err = (this->*generate_key_pair_run_)(argc, argv, env);
        } else {
            err = default_generate_key_pair_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = all_bn_generate_key_pair_run(argc, argv, env);
        return err;
    }
    virtual int before_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_generate_key_pair_run(argc, argv, env))) {
            int err2 = 0;
            err = generate_key_pair_run(argc, argv, env);
            if ((err2 = after_generate_key_pair_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_generate_key_pair_run;
        return err;
    }
    virtual int generate_key_pair_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int generate_key_pair_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...bn_generate_key_pair_run
    virtual int bn_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_bn_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_bn_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_bn_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_bn_generate_key_pair_run(argc, argv, env))) {
            int err2 = 0;
            err = bn_generate_key_pair_run(argc, argv, env);
            if ((err2 = after_bn_generate_key_pair_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_bn_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        generate_key_pair_run_ = &derives::all_bn_generate_key_pair_run;
        return err;
    }
    virtual int bn_generate_key_pair_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_bn_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        generate_key_pair_run_ = 0;
        return err;
    }
    virtual int bn_generate_key_pair_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...gmp_generate_key_pair_run
    virtual int gmp_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_gmp_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_gmp_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_gmp_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_gmp_generate_key_pair_run(argc, argv, env))) {
            int err2 = 0;
            err = gmp_generate_key_pair_run(argc, argv, env);
            if ((err2 = after_gmp_generate_key_pair_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_gmp_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        generate_key_pair_run_ = &derives::all_gmp_generate_key_pair_run;
        return err;
    }
    virtual int gmp_generate_key_pair_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_gmp_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        generate_key_pair_run_ = 0;
        return err;
    }
    virtual int gmp_generate_key_pair_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// test_key_pair_run
    int (derives::*test_key_pair_run_)(int argc, char_t** argv, char_t** env);
    virtual int test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (test_key_pair_run_) {
            err = (this->*test_key_pair_run_)(argc, argv, env);
        } else {
            err = default_test_key_pair_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = all_bn_test_key_pair_run(argc, argv, env);
        return err;
    }
    virtual int before_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_test_key_pair_run(argc, argv, env))) {
            int err2 = 0;
            err = test_key_pair_run(argc, argv, env);
            if ((err2 = after_test_key_pair_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_test_key_pair_run;
        return err;
    }
    virtual int test_key_pair_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int test_key_pair_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...bn_test_key_pair_run
    virtual int bn_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_bn_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_bn_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_bn_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_bn_test_key_pair_run(argc, argv, env))) {
            int err2 = 0;
            err = bn_test_key_pair_run(argc, argv, env);
            if ((err2 = after_bn_test_key_pair_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_bn_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        test_key_pair_run_ = &derives::all_bn_test_key_pair_run;
        return err;
    }
    virtual int bn_test_key_pair_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_bn_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        test_key_pair_run_ = 0;
        return err;
    }
    virtual int bn_test_key_pair_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...gmp_test_key_pair_run
    virtual int gmp_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_gmp_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_gmp_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_gmp_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_gmp_test_key_pair_run(argc, argv, env))) {
            int err2 = 0;
            err = gmp_test_key_pair_run(argc, argv, env);
            if ((err2 = after_gmp_test_key_pair_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_gmp_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        test_key_pair_run_ = &derives::all_gmp_test_key_pair_run;
        return err;
    }
    virtual int gmp_test_key_pair_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_gmp_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        test_key_pair_run_ = 0;
        return err;
    }
    virtual int gmp_test_key_pair_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...generate_key_pair_option...
    virtual int on_get_generate_key_pair_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_generate_key_pair_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_generate_key_pair_run(argc, argv, env))) {
            if (!(err = generate_key_pair_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_generate_key_pair_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_generate_key_pair_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_generate_key_pair_run(argc, argv, env))) {
                if (!(err = generate_key_pair_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_generate_key_pair_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_generate_key_pair_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_generate_key_pair_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_generate_key_pair_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_generate_key_pair_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* generate_key_pair_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_PAIR_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_PAIR_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...test_key_pair_option...
    virtual int on_get_test_key_pair_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_test_key_pair_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_test_key_pair_run(argc, argv, env))) {
            if (!(err = test_key_pair_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_test_key_pair_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_test_key_pair_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_test_key_pair_run(argc, argv, env))) {
                if (!(err = test_key_pair_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_test_key_pair_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_test_key_pair_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_test_key_pair_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_test_key_pair_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_test_key_pair_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* test_key_pair_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_KEY_PAIR_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_KEY_PAIR_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...encrypt_option...
    virtual int on_get_encrypt_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_encrypt_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_encrypt_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_encrypt_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_encrypt_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_encrypt_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_encrypt_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_encrypt_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_encrypt_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* encrypt_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...decrypt_option...
    virtual int on_get_decrypt_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_decrypt_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_decrypt_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_decrypt_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_decrypt_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_decrypt_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_decrypt_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_decrypt_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_decrypt_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* decrypt_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...plain_text_option...
    virtual int on_get_plain_text_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_plain_text_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_plain_text_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_plain_text_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_plain_text_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_plain_text_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_plain_text_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_plain_text_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_plain_text_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* plain_text_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...cipher_text_option...
    virtual int on_get_cipher_text_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_cipher_text_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_cipher_text_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_cipher_text_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_cipher_text_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_cipher_text_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_cipher_text_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_cipher_text_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_cipher_text_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* cipher_text_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...key_pair_option...
    virtual int on_get_key_pair_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_key_pair_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_key_pair_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_key_pair_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_key_pair_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_key_pair_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_key_pair_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_key_pair_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_key_pair_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* key_pair_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...private_key_option...
    virtual int on_get_private_key_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_private_key_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_private_key_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_private_key_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_private_key_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_private_key_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_private_key_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_private_key_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_private_key_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* private_key_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...public_key_option...
    virtual int on_get_public_key_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_public_key_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_public_key_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_public_key_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_public_key_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_public_key_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_public_key_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_public_key_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_public_key_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* public_key_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...modulus_bits_option...
    virtual int on_get_modulus_bits_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_modulus_bits_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_modulus_bits_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_modulus_bits_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_modulus_bits_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_modulus_bits_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_modulus_bits_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_modulus_bits_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_modulus_bits_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* modulus_bits_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...modulus_bytes_option...
    virtual int on_get_modulus_bytes_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_modulus_bytes_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_modulus_bytes_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_modulus_bytes_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_modulus_bytes_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_modulus_bytes_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_modulus_bytes_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_modulus_bytes_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_modulus_bytes_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* modulus_bytes_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...miller_rabin_option...
    virtual int on_get_miller_rabin_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_miller_rabin_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_miller_rabin_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_miller_rabin_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_miller_rabin_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_miller_rabin_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_miller_rabin_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_miller_rabin_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_miller_rabin_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* miller_rabin_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...fermat_witness_option...
    virtual int on_get_fermat_witness_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_fermat_witness_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_fermat_witness_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_fermat_witness_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_fermat_witness_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_fermat_witness_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_fermat_witness_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_fermat_witness_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_fermat_witness_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* fermat_witness_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...random_number_option...
    virtual int on_get_random_number_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_random_number_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_random_number_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_random_number_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_random_number_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_random_number_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_random_number_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_random_number_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_random_number_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* random_number_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_RANDOM_NUMBER_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_RANDOM_NUMBER_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...pseudo_random_number_option...
    virtual int on_get_pseudo_random_number_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_pseudo_random_number_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_pseudo_random_number_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_pseudo_random_number_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_pseudo_random_number_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_pseudo_random_number_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_pseudo_random_number_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_pseudo_random_number_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_pseudo_random_number_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* pseudo_random_number_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PSEUDO_RANDOM_NUMBER_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PSEUDO_RANDOM_NUMBER_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...bn_integer_option...
    virtual int on_get_bn_integer_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_bn_integer_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_bn_integer_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_bn_integer_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_bn_integer_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_bn_integer_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_bn_integer_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_bn_integer_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_bn_integer_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* bn_integer_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...gmp_integer_option...
    virtual int on_get_gmp_integer_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_gmp_integer_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_gmp_integer_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_gmp_integer_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_gmp_integer_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_gmp_integer_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_gmp_integer_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_gmp_integer_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_gmp_integer_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* gmp_integer_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on_option
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_PAIR_OPTVAL_C:
            err = this->on_generate_key_pair_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_KEY_PAIR_OPTVAL_C:
            err = this->on_test_key_pair_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTVAL_C:
            err = this->on_encrypt_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTVAL_C:
            err = this->on_decrypt_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTVAL_C:
            err = this->on_plain_text_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTVAL_C:
            err = this->on_cipher_text_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTVAL_C:
            err = this->on_key_pair_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTVAL_C:
            err = this->on_private_key_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTVAL_C:
            err = this->on_public_key_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTVAL_C:
            err = this->on_modulus_bits_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTVAL_C:
            err = this->on_modulus_bytes_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTVAL_C:
            err = this->on_miller_rabin_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTVAL_C:
            err = this->on_fermat_witness_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_RANDOM_NUMBER_OPTVAL_C:
            err = this->on_random_number_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PSEUDO_RANDOM_NUMBER_OPTVAL_C:
            err = this->on_pseudo_random_number_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTVAL_C:
            err = this->on_bn_integer_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTVAL_C:
            err = this->on_gmp_integer_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    
    /// option_usage
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_PAIR_OPTVAL_C:
            chars = this->generate_key_pair_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_KEY_PAIR_OPTVAL_C:
            chars = this->test_key_pair_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTVAL_C:
            chars = this->encrypt_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTVAL_C:
            chars = this->decrypt_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTVAL_C:
            chars = this->plain_text_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTVAL_C:
            chars = this->cipher_text_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTVAL_C:
            chars = this->key_pair_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTVAL_C:
            chars = this->private_key_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTVAL_C:
            chars = this->public_key_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTVAL_C:
            chars = this->modulus_bits_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTVAL_C:
            chars = this->modulus_bytes_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTVAL_C:
            chars = this->miller_rabin_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTVAL_C:
            chars = this->fermat_witness_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_RANDOM_NUMBER_OPTVAL_C:
            chars = this->random_number_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PSEUDO_RANDOM_NUMBER_OPTVAL_C:
            chars = this->pseudo_random_number_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTVAL_C:
            chars = this->bn_integer_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTVAL_C:
            chars = this->gmp_integer_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }

    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...key_..._define...
    virtual const char_t* key_pair_define_chars() const {
        string_t &key_pair_define = this->key_pair_define();
        return key_pair_define.chars();
    }
    virtual const char_t* public_key_define_chars() const {
        string_t &public_key_define = this->public_key_define();
        return public_key_define.chars();
    }
    virtual const char_t* private_key_define_chars() const {
        string_t &private_key_define = this->private_key_define();
        return private_key_define.chars();
    }
    virtual string_t &key_pair_define() const {
        return (string_t &)key_pair_define_;
    }
    virtual string_t &public_key_define() const {
        return (string_t &)public_key_define_;
    }
    virtual string_t &private_key_define() const {
        return (string_t &)private_key_define_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    string_t key_pair_define_, public_key_define_, private_key_define_; 
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace rsa 
} /// namespace crypto 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_OPT_HPP

