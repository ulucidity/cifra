///////////////////////////////////////////////////////////////////////
/// FIPS-197 compliant AES implementation
///
/// Copyright (C) 2006-2007  Christophe Devine
///
/// This program is free software; you can redistribute it and/or modify
/// it under the terms of the GNU General Public License as published by
/// the Free Software Foundation; either version 2 of the License, or
/// (at your option) any later version.
///
/// This program is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
/// GNU General Public License for more details.
///
/// You should have received a copy of the GNU General Public License along
/// with this program; if not, write to the Free Software Foundation, Inc.,
/// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
///
/// The AES block cipher was designed by Vincent Rijmen and Joan Daemen.
///
/// http://csrc.nist.gov/encryption/aes/rijndael/Rijndael.pdf
/// http://csrc.nist.gov/publications/fips/fips197/fips-197.pdf
///
///   File: extend.cpp
///
/// Author: $author$
///   Date: 1/27/2021
///
/// Christophe Devine's implementation of AES modified to be a C++ class
/// implementation.
///////////////////////////////////////////////////////////////////////
#include "xos/crypto/cipher/aes/devine/extend.hpp"
#include "xos/crypto/cipher/aes/devine/constants.cpp"

namespace xos {
namespace crypto {
namespace cipher {
namespace aes {
namespace devine {

///  Class: extend
void extend::ClearKeySchedule() {
    nr = 0; rk = 0;
    memset(buf, 0, sizeof(buf));
}
ssize_t extend::InitEncryptKeySchedule(const uint8_t* key, unsigned keysize) {
    unsigned i, j;
    uint32_t *RK;

    switch( keysize ) {
        case 16:
            nr = 10;
            break;
        case 24:
            nr = 12;
            break;
        case 32:
            nr = 14;
            break;
        default:
            return -ERROR_KEY_SIZE;
    }

    RK = (rk = buf);

    for( j = 0, i = 0; i < (keysize >> 2); i++, j+=4 )
        RK[i] = LSBToU32(key+j);

    switch( nr ) {
        case 10:
            for( i = 0; i < 10; i++, RK += 4 ) {
                RK[4]  = RK[0] ^ RCON[i] ^
                    ( FSb[ ( RK[3] >>  8 ) & 0xFF ]       ) ^
                    ( FSb[ ( RK[3] >> 16 ) & 0xFF ] <<  8 ) ^
                    ( FSb[ ( RK[3] >> 24 ) & 0xFF ] << 16 ) ^
                    ( FSb[ ( RK[3]       ) & 0xFF ] << 24 );

                RK[5]  = RK[1] ^ RK[4];
                RK[6]  = RK[2] ^ RK[5];
                RK[7]  = RK[3] ^ RK[6];
            }
            break;

        case 12:
            for( i = 0; i < 8; i++, RK += 6 ) {
                RK[6]  = RK[0] ^ RCON[i] ^
                    ( FSb[ ( RK[5] >>  8 ) & 0xFF ]       ) ^
                    ( FSb[ ( RK[5] >> 16 ) & 0xFF ] <<  8 ) ^
                    ( FSb[ ( RK[5] >> 24 ) & 0xFF ] << 16 ) ^
                    ( FSb[ ( RK[5]       ) & 0xFF ] << 24 );

                RK[7]  = RK[1] ^ RK[6];
                RK[8]  = RK[2] ^ RK[7];
                RK[9]  = RK[3] ^ RK[8];
                RK[10] = RK[4] ^ RK[9];
                RK[11] = RK[5] ^ RK[10];
            }
            break;

        case 14:
            for( i = 0; i < 7; i++, RK += 8 ) {
                RK[8]  = RK[0] ^ RCON[i] ^
                    ( FSb[ ( RK[7] >>  8 ) & 0xFF ]       ) ^
                    ( FSb[ ( RK[7] >> 16 ) & 0xFF ] <<  8 ) ^
                    ( FSb[ ( RK[7] >> 24 ) & 0xFF ] << 16 ) ^
                    ( FSb[ ( RK[7]       ) & 0xFF ] << 24 );

                RK[9]  = RK[1] ^ RK[8];
                RK[10] = RK[2] ^ RK[9];
                RK[11] = RK[3] ^ RK[10];

                RK[12] = RK[4] ^
                    ( FSb[ ( RK[11]       ) & 0xFF ]       ) ^
                    ( FSb[ ( RK[11] >>  8 ) & 0xFF ] <<  8 ) ^
                    ( FSb[ ( RK[11] >> 16 ) & 0xFF ] << 16 ) ^
                    ( FSb[ ( RK[11] >> 24 ) & 0xFF ] << 24 );

                RK[13] = RK[5] ^ RK[12];
                RK[14] = RK[6] ^ RK[13];
                RK[15] = RK[7] ^ RK[14];
            }
            break;

        default:
            return -ERROR_KEY_SIZE;
    }
    return keysize;
}

} /// namespace devine
} /// namespace aes
} /// namespace cipher
} /// namespace crypto
} /// namespace xos
