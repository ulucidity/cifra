///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
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
///   File: implement.hpp
///
/// Author: $author$
///   Date: 4/30/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_BASE_IMPLEMENT_HPP
#define XOS_CRYPTO_BASE_IMPLEMENT_HPP

#include "xos/crypto/base/exception.hpp"
#include "xos/base/chars.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/created.hpp"
#include "xos/base/opened.hpp"
#include "xos/base/array.hpp"
#include "xos/base/string.hpp"

namespace xos {
namespace crypto {

/// class implementt
template <class TImplements = xos::implement>
class exported implementt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef implementt derives;

    /// ...uint64...
    inline uint64_t msb_to_uint64(const byte_t* bytes) const {
        return MSBToU64(bytes);
    }
    inline byte_t* uint64_to_msb(byte_t* bytes, uint64_t value) const {
        return U64ToMSB(bytes, value);
    }
    inline uint64_t lsb_to_uint64(const byte_t* bytes) const {
        return LSBToU64(bytes);
    }
    inline byte_t* uint64_to_lsb(byte_t* bytes, uint64_t value) const {
        return U64ToLSB(bytes, value);
    }

    /// ...uint32...
    inline uint32_t msb_to_uint32(const byte_t* bytes) const {
        return MSBToU32(bytes);
    }
    inline byte_t* uint32_to_msb(byte_t* bytes, uint32_t value) const {
        return U32ToMSB(bytes, value);
    }
    inline uint32_t lsb_to_uint32(const byte_t* bytes) const {
        return LSBToU32(bytes);
    }
    inline byte_t* uint32_to_lsb(byte_t* bytes, uint32_t value) const {
        return U32ToLSB(bytes, value);
    }

    /// ...copy...
    inline byte_t* copy_repeat(byte_t* to, size_t tosize, const byte_t* from, size_t fromsize) const {
        return CopyRepeat(to, tosize, from, fromsize);
    }
    inline byte_t *copy_8(byte_t *to, const byte_t *from) const {
        return Copy8(to, from);
    }
    inline byte_t *copy_4(byte_t *to, const byte_t *from) const {
        return Copy4(to, from);
    }
    inline byte_t *copy_2(byte_t *to, const byte_t *from) const {
        return Copy2(to, from);
    }

    /// ...U64...
    inline UINT64 MSBToU64(const BYTE* bytes) const {
        UINT64 value = (((((((((((((((UINT64)bytes[0])<<8) | bytes[1])<<8) | bytes[2])<<8) | bytes[3])<<8) | bytes[4])<<8) | bytes[5])<<8) | bytes[6])<<8) | bytes[7];
        return value;
    }
    inline BYTE* U64ToMSB(BYTE* bytes, UINT64 value) const {
        *(bytes+=7)=(BYTE)(value & 0xFF);
        *(--bytes)=(BYTE)((value>>=8) & 0xFF);
        *(--bytes)=(BYTE)((value>>=8) & 0xFF);
        *(--bytes)=(BYTE)((value>>=8) & 0xFF);
        *(--bytes)=(BYTE)((value>>=8) & 0xFF);
        *(--bytes)=(BYTE)((value>>=8) & 0xFF);
        *(--bytes)=(BYTE)((value>>=8) & 0xFF);
        *(--bytes)=(BYTE)((value>>=8) & 0xFF);
        return bytes;
    }
    inline UINT64 LSBToU64(const BYTE* bytes) const {
        UINT64 value = (((((((((((((((UINT64)bytes[7])<<8) | bytes[6])<<8) | bytes[5])<<8) | bytes[4])<<8) | bytes[3])<<8) | bytes[2])<<8) | bytes[1])<<8) | bytes[0];
        return value;
    }
    inline BYTE* U64ToLSB(BYTE* bytes, UINT64 value) const {
        *(bytes)=(BYTE)(value & 0xFF);
        *(++bytes)=(BYTE)((value>>=8) & 0xFF);
        *(++bytes)=(BYTE)((value>>=8) & 0xFF);
        *(++bytes)=(BYTE)((value>>=8) & 0xFF);
        *(++bytes)=(BYTE)((value>>=8) & 0xFF);
        *(++bytes)=(BYTE)((value>>=8) & 0xFF);
        *(++bytes)=(BYTE)((value>>=8) & 0xFF);
        *(++bytes)=(BYTE)((value>>=8) & 0xFF);
        return bytes;
    }

    /// ...U32...
    inline UINT32 MSBToU32(const BYTE* bytes) const {
        UINT32 value = (((((((UINT32)bytes[0])<<8) | bytes[1])<<8) | bytes[2])<<8) | bytes[3];
        return value;
    }
    inline BYTE* U32ToMSB(BYTE* bytes, UINT32 value) const {
        *(bytes+=3)=(BYTE)(value & 0xFF);
        *(--bytes)=(BYTE)((value>>=8) & 0xFF);
        *(--bytes)=(BYTE)((value>>=8) & 0xFF);
        *(--bytes)=(BYTE)((value>>=8) & 0xFF);
        return bytes;
    }
    inline UINT32 LSBToU32(const BYTE* bytes) const {
        UINT32 value = (((((((UINT32)bytes[3])<<8) | bytes[2])<<8) | bytes[1])<<8) | bytes[0];
        return value;
    }
    inline BYTE* U32ToLSB(BYTE* bytes, UINT32 value) const {
        *(bytes)=(BYTE)(value & 0xFF);
        *(++bytes)=(BYTE)((value>>=8) & 0xFF);
        *(++bytes)=(BYTE)((value>>=8) & 0xFF);
        *(++bytes)=(BYTE)((value>>=8) & 0xFF);
        return bytes;
    }

    /// Copy...
    inline BYTE* CopyRepeat(BYTE* to, size_t tosize, const BYTE* from, size_t fromsize) const {
        for (size_t i = 0; i < tosize; i += fromsize) {
            for (size_t j = 0, k = i; (k < tosize) && (j < fromsize); ++k, ++j) {
                to[k] = from[j];
            }
        }
        return to;
    }
    inline BYTE *Copy8(BYTE *to, const BYTE *from) const {
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        return to;
    }
    inline BYTE *Copy4(BYTE *to, const BYTE *from) const {
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        *(to++) = *(from++);
        return to;
    }
    inline BYTE *Copy2(BYTE *to, const BYTE *from) const {
        *(to++) = *(from++);
        *(to++) = *(from++);
        return to;
    }
}; /// class implementt
typedef implementt<> implement;

} /// namespace crypto
} /// namespace xos

#endif /// ndef XOS_CRYPTO_BASE_IMPLEMENT_HPP 
