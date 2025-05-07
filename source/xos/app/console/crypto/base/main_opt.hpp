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
///   Date: 11/4/2024, 11/25/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPT_HPP

#include "xos/app/console/cifra/version/main.hpp"

#define XOS_APP_CONSOLE_MAIN_OPTARG_ON "on"
#define XOS_APP_CONSOLE_MAIN_OPTARG_OFF "off"
#define XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF \
    "{ " XOS_APP_CONSOLE_MAIN_OPTARG_ON \
    " | " XOS_APP_CONSOLE_MAIN_OPTARG_OFF " }"
#define XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF_OPTIONAL \
    "[" XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF "]"

#define XOS_APP_CONSOLE_MAIN_OPTARG_NUMBER "1..n"
#define XOS_APP_CONSOLE_MAIN_OPTARG_NUMBER_OPTIONAL \
    "[" XOS_APP_CONSOLE_MAIN_OPTARG_NUMBER "]"

#define XOS_APP_CONSOLE_MAIN_OPTARG_STRING "string"
#define XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL \
    "[" XOS_APP_CONSOLE_MAIN_OPTARG_STRING "]"

///////////////////////////////////////////////////////////////////////

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NAME "crypto"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN "_plain_text"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER "_cipher_text"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM "_random_text"

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BEFORE_0X_BEGIN "static const byte_t "
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BEFORE_0X_END "[] = {"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_AFTER_0X "};"

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BEFORE_0X_PLAIN_END \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BEFORE_0X_END

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BEFORE_0X_PLAIN \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BEFORE_0X_BEGIN \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NAME \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BEFORE_0X_PLAIN_END

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BEFORE_0X_CIPHER_END \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BEFORE_0X_END

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BEFORE_0X_CIPHER \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BEFORE_0X_BEGIN \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NAME \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BEFORE_0X_CIPHER_END

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BEFORE_0X_RANDOM_END \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BEFORE_0X_END

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BEFORE_0X_RANDOM \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BEFORE_0X_BEGIN \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NAME \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BEFORE_0X_RANDOM_END

///////////////////////////////////////////////////////////////////////

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPT "plain"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPTUSE "plain text"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPTVAL_S "p::"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPTVAL_C 'p'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPT "cipher"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPTUSE "cipher text"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPTVAL_S "c::"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPTVAL_C 'c'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_TEXT_OPT "random"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_TEXT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_TEXT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_TEXT_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_NUMBER_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_TEXT_OPTUSE "random text"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_TEXT_OPTVAL_S "r::"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_TEXT_OPTVAL_C 'r'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_TEXT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_TEXT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_TEXT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_TEXT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_TEXT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BITS_OPT "bits"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BITS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BITS_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BITS_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_NUMBER_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BITS_OPTUSE "random bits"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BITS_OPTVAL_S "i::"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BITS_OPTVAL_C 'i'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BITS_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BITS_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BITS_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BITS_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BITS_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BYTES_OPT "bytes"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BYTES_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BYTES_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BYTES_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_NUMBER_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BYTES_OPTUSE "random bytes"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BYTES_OPTVAL_S "y::"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BYTES_OPTVAL_C 'y'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BYTES_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BYTES_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BYTES_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BYTES_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BYTES_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPT "64"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTUSE "base 64 encoded io"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTVAL_S "4::"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTVAL_C '4'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPT "HEX"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTUSE "uppercase hex encoded io"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTVAL_S "X::"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTVAL_C 'X'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPT "hex"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTUSE "lowercase hex encoded io"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTVAL_S "x::"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTVAL_C 'x'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPT "0x"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTUSE "0x hex output"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTVAL_S "0::"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTVAL_C '0'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPT "text"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTUSE "text output"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTVAL_S "t::"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTVAL_C 't'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPT "noline"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTUSE "no line feed on output"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTVAL_S "n::"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTVAL_C 'n'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPT "verbose"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTUSE "verbose output"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTVAL_S "v::"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTVAL_C 'v'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPT "quiet"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTUSE "quiet output"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTVAL_S "q::"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTVAL_C 'q'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE_VERBOSE_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE_VERBOSE_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE_IO_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE_IO_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_OX_IO_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_OX_IO_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_IO_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_IO_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_TEXT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BITS_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BYTES_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_TEXT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BITS_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BYTES_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_TEXT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BITS_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BYTES_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_TEXT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BITS_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BYTES_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE_VERBOSE_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CIFRA_VERSION_MAIN_LOGGING_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE_VERBOSE_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CIFRA_VERSION_MAIN_LOGGING_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE_IO_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE_IO_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CIFRA_VERSION_MAIN_LOGGING_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE_IO_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE_IO_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CIFRA_VERSION_MAIN_LOGGING_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_OX_IO_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_OX_IO_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CIFRA_VERSION_MAIN_LOGGING_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_OX_IO_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_OX_IO_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CIFRA_VERSION_MAIN_LOGGING_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_IO_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_IO_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CIFRA_VERSION_MAIN_LOGGING_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_IO_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_IO_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CIFRA_VERSION_MAIN_LOGGING_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CIFRA_VERSION_MAIN_LOGGING_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CIFRA_VERSION_MAIN_LOGGING_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CIFRA_VERSION_MAIN_LOGGING_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CIFRA_VERSION_MAIN_LOGGING_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CIFRA_VERSION_MAIN_LOGGING_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CIFRA_VERSION_MAIN_LOGGING_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_ARGS 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace base {

/// class main_optt
template 
<class TExtends = xos::app::console::cifra::version::maint<>,  class TImplements = typename TExtends::implements>

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

    /// constructor / destructor
    main_optt()
    : run_(0), 
      before_0x_plain_(XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BEFORE_0X_PLAIN), 
      after_0x_plain_(XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_AFTER_0X), 
      before_0x_cipher_(XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BEFORE_0X_CIPHER), 
      after_0x_cipher_(XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_AFTER_0X), 
      before_0x_random_(XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BEFORE_0X_RANDOM), 
      after_0x_random_(XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_AFTER_0X) {
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
    /// ...plain_run
    virtual int plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_get_plain_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_plain_run(argc, argv, env))) {
            int err2 = 0;
            err = plain_run(argc, argv, env);
            if ((err2 = after_plain_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_plain_run;
        return err;
    }
    virtual int plain_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int plain_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...cipher_run
    virtual int cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_get_cipher_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_cipher_run(argc, argv, env))) {
            int err2 = 0;
            err = cipher_run(argc, argv, env);
            if ((err2 = after_cipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_cipher_run;
        return err;
    }
    virtual int cipher_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int cipher_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...random_run
    virtual int random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_get_random_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_random_run(argc, argv, env))) {
            int err2 = 0;
            err = random_run(argc, argv, env);
            if ((err2 = after_random_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_random_run;
        return err;
    }
    virtual int random_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int random_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...get_plain_run
    virtual int get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_output_plain_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_get_plain_run(argc, argv, env))) {
            int err2 = 0;
            err = get_plain_run(argc, argv, env);
            if ((err2 = after_get_plain_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_get_plain_run;
        return err;
    }
    virtual int get_plain_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int get_plain_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...get_cipher_run
    virtual int get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_output_cipher_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_get_cipher_run(argc, argv, env))) {
            int err2 = 0;
            err = get_cipher_run(argc, argv, env);
            if ((err2 = after_get_cipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_get_cipher_run;
        return err;
    }
    virtual int get_cipher_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int get_cipher_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...get_random_run
    virtual int get_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_generate_random_number_run(argc, argv, env))) {
            if (!(err = all_output_random_number_run(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int before_get_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_get_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_get_random_run(argc, argv, env))) {
            int err2 = 0;
            err = get_random_run(argc, argv, env);
            if ((err2 = after_get_random_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_get_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_get_random_run;
        return err;
    }
    virtual int get_random_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_get_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int get_random_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_plain_run
    int (derives::*output_plain_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_plain_run_) {
            if (!(err = (this->*output_plain_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_output_plain_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_output_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...before_output_plain_run
    int (derives::*before_output_plain_run_)(int argc, char_t** argv, char_t** env);
    virtual int before_output_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (before_output_plain_run_) {
            if (!(err = (this->*before_output_plain_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_before_output_plain_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_before_output_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int Ox_before_output_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...after_output_plain_run
    int (derives::*after_output_plain_run_)(int argc, char_t** argv, char_t** env);
    virtual int after_output_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (after_output_plain_run_) {
            if (!(err = (this->*after_output_plain_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_after_output_plain_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_after_output_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int Ox_after_output_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int all_output_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_plain_run(argc, argv, env))) {
            int err2 = 0;
            err = output_plain_run(argc, argv, env);
            if ((err2 = after_output_plain_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int x_output_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_x_output_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_plain_run_ = &derives::x_output_plain_run;
        return err;
    }
    virtual int unset_x_output_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_plain_run_ = 0;
        return err;
    }
    virtual int set_0x_output_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_plain_run_ = &derives::x_output_plain_run;
        before_output_plain_run_ = &derives::Ox_before_output_plain_run;
        after_output_plain_run_ = &derives::Ox_after_output_plain_run;
        return err;
    }
    virtual int unset_0x_output_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_plain_run_ = 0;
        before_output_plain_run_ = 0;
        after_output_plain_run_ = 0;
        return err;
    }
    virtual int unset_output_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_plain_run_ = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_cipher_run
    int (derives::*output_cipher_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_cipher_run_) {
            if (!(err = (this->*output_cipher_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_output_cipher_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...before_output_cipher_run
    int (derives::*before_output_cipher_run_)(int argc, char_t** argv, char_t** env);
    virtual int before_output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (before_output_cipher_run_) {
            if (!(err = (this->*before_output_cipher_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_before_output_cipher_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_before_output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int Ox_before_output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...after_output_cipher_run
    int (derives::*after_output_cipher_run_)(int argc, char_t** argv, char_t** env);
    virtual int after_output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (after_output_cipher_run_) {
            if (!(err = (this->*after_output_cipher_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_after_output_cipher_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_after_output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int Ox_after_output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int all_output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_cipher_run(argc, argv, env))) {
            int err2 = 0;
            err = output_cipher_run(argc, argv, env);
            if ((err2 = after_output_cipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int x_output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_x_output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_cipher_run_ = &derives::x_output_cipher_run;
        return err;
    }
    virtual int unset_x_output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_cipher_run_ = 0;
        return err;
    }
    virtual int set_0x_output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_cipher_run_ = &derives::x_output_cipher_run;
        before_output_cipher_run_ = &derives::Ox_before_output_cipher_run;
        after_output_cipher_run_ = &derives::Ox_after_output_cipher_run;
        return err;
    }
    virtual int unset_0x_output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_cipher_run_ = 0;
        before_output_cipher_run_ = 0;
        after_output_cipher_run_ = 0;
        return err;
    }
    virtual int unset_output_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_cipher_run_ = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_random_run
    int (derives::*output_random_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_random_run_) {
            if (!(err = (this->*output_random_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_output_random_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_output_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...before_output_random_run
    int (derives::*before_output_random_run_)(int argc, char_t** argv, char_t** env);
    virtual int before_output_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (before_output_random_run_) {
            if (!(err = (this->*before_output_random_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_before_output_random_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_before_output_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int Ox_before_output_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...after_output_random_run
    int (derives::*after_output_random_run_)(int argc, char_t** argv, char_t** env);
    virtual int after_output_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (after_output_random_run_) {
            if (!(err = (this->*after_output_random_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_after_output_random_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_after_output_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int Ox_after_output_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int all_output_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_random_run(argc, argv, env))) {
            int err2 = 0;
            err = output_random_run(argc, argv, env);
            if ((err2 = after_output_random_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...x_output_random_run
    virtual int x_output_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_x_output_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_random_run_ = &derives::x_output_random_run;
        return err;
    }
    virtual int unset_x_output_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_random_run_ = 0;
        return err;
    }
    virtual int set_0x_output_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_random_run_ = &derives::x_output_random_run;
        before_output_random_run_ = &derives::Ox_before_output_random_run;
        after_output_random_run_ = &derives::Ox_after_output_random_run;
        return err;
    }
    virtual int unset_0x_output_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_random_run_ = 0;
        before_output_random_run_ = 0;
        after_output_random_run_ = 0;
        return err;
    }
    virtual int unset_output_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_random_run_ = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_random_number_run
    virtual int output_random_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_output_random_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_random_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int after_output_random_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = after_output_random_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int all_output_random_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_random_number_run(argc, argv, env))) {
            int err2 = 0;
            err = output_random_number_run(argc, argv, env);
            if ((err2 = after_output_random_number_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...generate_random_number_run
    virtual int generate_random_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_generate_pseudo_random_number_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_generate_random_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_generate_random_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_generate_random_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_generate_random_number_run(argc, argv, env))) {
            int err2 = 0;
            err = generate_random_number_run(argc, argv, env);
            if ((err2 = after_generate_random_number_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...generate_pseudo_random_number_run
    virtual int generate_pseudo_random_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_generate_pseudo_random_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_generate_pseudo_random_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_generate_pseudo_random_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_generate_pseudo_random_number_run(argc, argv, env))) {
            int err2 = 0;
            err = generate_pseudo_random_number_run(argc, argv, env);
            if ((err2 = after_generate_pseudo_random_number_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

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
        if (!(err = set_get_plain_run(argc, argv, env))) {
            if (!(err = get_plain_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
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
            if (!(err = set_get_plain_run(argc, argv, env))) {
                if (!(err = get_plain_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
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
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPTARG;
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
        if (!(err = set_get_cipher_run(argc, argv, env))) {
            if (!(err = get_cipher_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
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
            if (!(err = set_get_cipher_run(argc, argv, env))) {
                if (!(err = get_cipher_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
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
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...random_text_option...
    virtual int on_get_random_text_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_random_text_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_get_random_run(argc, argv, env))) {
            if (!(err = get_random_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_random_text_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_random_text_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_get_random_run(argc, argv, env))) {
                if (!(err = get_random_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_random_text_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_random_text_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_random_text_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_random_text_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_random_text_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* random_text_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_TEXT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_TEXT_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...random_bits_option...
    virtual int on_get_random_bits_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_random_bits_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_random_bits_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_random_bits_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_random_bits_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_random_bits_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_random_bits_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_random_bits_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_random_bits_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* random_bits_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BITS_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BITS_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...random_bytes_option...
    virtual int on_get_random_bytes_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_random_bytes_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_random_bytes_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_random_bytes_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_random_bytes_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_random_bytes_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_random_bytes_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_random_bytes_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_random_bytes_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* random_bytes_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BYTES_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BYTES_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...base64_io_option...
    virtual int on_get_base64_io_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_base64_io_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_base64_io_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
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
    virtual int on_base64_io_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_base64_io_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_base64_io_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_base64_io_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_base64_io_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* base64_io_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...upper_hex_io_option...
    virtual int on_get_upper_hex_io_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_upper_hex_io_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_upper_hex_io_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
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
    virtual int on_upper_hex_io_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_upper_hex_io_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_upper_hex_io_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_upper_hex_io_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_upper_hex_io_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* upper_hex_io_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...lower_hex_io_option...
    virtual int on_get_lower_hex_io_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_lower_hex_io_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_lower_hex_io_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
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
    virtual int on_lower_hex_io_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_lower_hex_io_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_lower_hex_io_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_lower_hex_io_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_lower_hex_io_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* lower_hex_io_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...Ox_output_option...
    virtual int on_get_Ox_output_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_Ox_output_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_Ox_output_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
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
    virtual int on_Ox_output_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_Ox_output_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_Ox_output_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_Ox_output_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_Ox_output_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* Ox_output_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...text_output_option...
    virtual int on_get_text_output_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_text_output_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_text_output_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
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
    virtual int on_text_output_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_text_output_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_text_output_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_text_output_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_text_output_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* text_output_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...noline_output_option...
    virtual int on_get_noline_output_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_noline_output_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_noline_output_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_noline_output_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_noline_output_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_noline_output_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_noline_output_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_noline_output_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_noline_output_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* noline_output_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...verbose_output_option...
    virtual int on_get_verbose_output_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_verbose_output_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_verbose_output_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_verbose_output_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_verbose_output_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_verbose_output_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_verbose_output_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_verbose_output_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_verbose_output_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* verbose_output_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...quiet_output_option...
    virtual int on_get_quiet_output_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_quiet_output_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_quiet_output_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_quiet_output_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_quiet_output_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_quiet_output_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_quiet_output_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_quiet_output_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_quiet_output_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* quiet_output_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTARG;
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

        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPTVAL_C:
            err = this->on_plain_text_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPTVAL_C:
            err = this->on_cipher_text_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_TEXT_OPTVAL_C:
            err = this->on_random_text_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BITS_OPTVAL_C:
            err = this->on_random_bits_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BYTES_OPTVAL_C:
            err = this->on_random_bytes_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTVAL_C:
            err = this->on_base64_io_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTVAL_C:
            err = this->on_upper_hex_io_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTVAL_C:
            err = this->on_lower_hex_io_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTVAL_C:
            err = this->on_Ox_output_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTVAL_C:
            err = this->on_text_output_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTVAL_C:
            err = this->on_noline_output_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTVAL_C:
            err = this->on_verbose_output_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTVAL_C:
            err = this->on_quiet_output_option(optval, optarg, optname, optind, argc, argv, env);
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

        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_TEXT_OPTVAL_C:
            chars = this->plain_text_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_TEXT_OPTVAL_C:
            chars = this->cipher_text_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_TEXT_OPTVAL_C:
            chars = this->random_text_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BITS_OPTVAL_C:
            chars = this->random_bits_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_RANDOM_BYTES_OPTVAL_C:
            chars = this->random_bytes_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_IO_OPTVAL_C:
            chars = this->base64_io_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_IO_OPTVAL_C:
            chars = this->upper_hex_io_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_IO_OPTVAL_C:
            chars = this->lower_hex_io_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OX_OUTPUT_OPTVAL_C:
            chars = this->Ox_output_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OUTPUT_OPTVAL_C:
            chars = this->text_output_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NOLINE_OUTPUT_OPTVAL_C:
            chars = this->noline_output_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_VERBOSE_OUTPUT_OPTVAL_C:
            chars = this->verbose_output_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_QUIET_OUTPUT_OPTVAL_C:
            chars = this->quiet_output_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }

    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual string_t& before_0x_plain() const {
        return (string_t&)before_0x_plain_;
    }
    virtual string_t& after_0x_plain() const {
        return (string_t&)after_0x_plain_;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual string_t& before_0x_cipher() const {
        return (string_t&)before_0x_cipher_;
    }
    virtual string_t& after_0x_cipher() const {
        return (string_t&)after_0x_cipher_;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual string_t& before_0x_random() const {
        return (string_t&)before_0x_random_;
    }
    virtual string_t& after_0x_random() const {
        return (string_t&)after_0x_random_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    string_t before_0x_plain_, after_0x_plain_, 
             before_0x_cipher_, after_0x_cipher_, 
             before_0x_random_, after_0x_random_;
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace base 
} /// namespace crypto 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPT_HPP

