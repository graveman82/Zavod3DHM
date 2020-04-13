#ifndef ZAVOD3D_HM_INTTYPES_H_
#define ZAVOD3D_HM_INTTYPES_H_

/* This file is a part of Zavod3D engine project.
It's licensed unser the MIT license (see "Licence.txt" for details).*/

namespace z3D {

#ifdef _MSC_VER
    typedef unsigned __int8 u8;
    typedef unsigned __int16 u16;
    typedef unsigned __int32 u32;

    typedef __int8 s8;
    typedef __int16 s16;
    typedef __int32 s32;


#else

    #include <stdint.h>

    typedef uint8_t u8;
    typedef uint16_t u16;
    typedef uint32_t u32;

    typedef int8_t s8;
    typedef int16_t s16;
    typedef int32_t s32;


#endif // _MSC_VER

} // end of z3D


#endif // ZAVOD3D_HM_INTTYPES_H_

