/* This file is a part of Zavod3D engine project.
It's licensed unser the MIT license (see "Licence.txt" for details).*/

#include "z3DLib/inttypes.h"
#include "z3DLib/endianness.h"
#include "z3DLib/utf.h"

namespace z3D {

static bool Utf16_makeSurrogates(u16& s1, u16& s2, u32 cp) {
    if (cp >= 0x10000) {
        u32 cpBmp = cp - 0x10000;
        s1 = u32(0xD800) + (cpBmp >> 10);
        s2 = u32(0xDC00) + (cpBmp &0x3FF);
        return true;
    }
    return false;
}

bool encodeAsUtf16(u8* dst, u32 dstSize, u32& nEncodedBytes, u32 cp, EndianType endianType) {
    u8* const dst0 = dst;
    if (cp >= 0x10000) {
        u16 s[2];
        Utf16_makeSurrogates(s[0], s[1], cp);

        if (!writeBuiltin(dst, dstSize, s[0], endianType)) {
            return false; // not enough buffer space
        }
        if (!writeBuiltin(dst, dstSize, s[1], endianType)) {
            return false; // not enough buffer space
        }
    }
    else {
        if (!writeBuiltin(dst, dstSize, u16(cp), endianType)) {
            return false; // not enough buffer space
        }
    }
    nEncodedBytes = dst - dst0;
    return true;
}



} // end of z3D
