#ifndef ZAVOD3D_HM_ENDIANNESS_H_
#define ZAVOD3D_HM_ENDIANNESS_H_

/* This file is a part of Zavod3D engine project.
It's licensed unser the MIT license (see "Licence.txt" for details).*/

#include "z3DLib/inttypes.h"

/** @page Endiannes Порядок байт.

    @code
    // Тест-пример
    void TestEndiannes(z3D::EndianType et) {

        using z3D::u8;
        using z3D::u32;
        using z3D::s32;

        s32 buf[] = {-84213561, 335605675};// 0xfa, 0xfb, 0x00, 0xc7; 0x14, 0x00, 0xef, 0xab
        const u8* p = reinterpret_cast<const u8*>(&buf[0]);
        u32 size = 8;

        while (size) {
            s32 x;
    #ifdef _WIN32
            // данные в p закодированы в little endian, потому что программа запущена на винде
            if (z3D::readBuiltin(p, size, x, et))
    #endif
                printf("  x: %d (%x)\n", x, x);
            else
                printf("error!\n");
        }

    }

    void TestEndiannes() {
    #ifdef _WIN32
        printf("right endian type:\n");
        TestEndiannes(z3D::kLittleEndian);
    #endif

    #ifdef _WIN32
        printf("wrong endian type:\n");
        TestEndiannes(z3D::kBigEndian);
    #endif
    }
    @endcode


*/
namespace z3D {

enum EndianType {
    kIgnoreEndian,
    kLittleEndian,
    kBigEndian
};

inline bool isLittleEndian() {
    u32 a = u32(1);
    return (*reinterpret_cast<u8*>(&a));
}

/** @brief Прочитать встроенный тип из буфера.
 *
 * Указатель на буфер смещается на число прочитанных байт, а его размер уменьшается на это число.
 *
 * @code
    // пример
    u8 buf[8] = {0xfa, 0xfb, 0x00, 0xc7, 0x14, 0x00, 0xef, 0xab};
    const u8* p = buf;
    u32 size = 8;
    while (size) {
        u32 x;
        if (z3D::readBuiltin(p, size, x))
            printf("x: %x\n", x);
    }
 * @endcode
 * @param pSrc [in,out] исходный буфер байт.
 * @param srcSize [in,out] размер исходного буфера (в байтах).
 * @param rslt ссылка на переменную для сохранения результата чтения.
 * @param endianType предполагаемый тип кодировки данных в буфере.
 * @return true, если операция завершилась успешно, false - при ошибке. Ошибка связана с
 * недостаточным размером исходного буфера.
 * @note Только для встроенных типов (integers, floats, char, wchar_t etc).
 */
template <typename T>
inline bool readBuiltin(const u8*& pSrc, u32& srcSize, T& rslt, EndianType endianType) {
    if (srcSize < sizeof(T)) return false;

    u8* pRslt = reinterpret_cast<u8*>(&rslt);
    const u8* pSrcEnd = pSrc + sizeof(T);
    if ((isLittleEndian() && endianType == kBigEndian) || (!isLittleEndian() && endianType == kLittleEndian)) {
        while (pSrc != pSrcEnd--) {
            *pRslt++ = *pSrcEnd;
        }
        pSrc += sizeof(T);
    }
    else {
        while (pSrc != pSrcEnd) {
            *pRslt++ = *pSrc++;
        }
    }
    srcSize -= sizeof(T);
    return true;
}

/** @brief Записать встроенный тип в буфер.
 *
 * Указатель на буфер смещается на число записанных байт, а его размер уменьшается на это число.
 *
 * @code
    // пример
    u8 buf[8] = {0xfa, 0xfb, 0x00, 0xc7, 0x14, 0x00, 0xef, 0xab};
    const u8* p = buf;
    u32 size = 8;
    while (size) {
        u32 x;
        if (z3D::readBuiltin(p, size, x))
            printf("x: %x\n", x);
    }
 * @endcode
 * @param pDst [in,out] буфер назначения.
 * @param dstSize [in,out] размер буфера назначения (в байтах).
 * @param v записываемое значение.
 * @param endianType предполагаемый тип кодировки данных в буфере.
 * @return true, если операция завершилась успешно, false - при ошибке. Ошибка связана с
 * недостаточным размером буфера назначения.
 * @note Только для встроенных типов (integers, floats, char, wchar_t etc).
 */
template <typename T>
inline bool writeBuiltin(u8*& pDst, u32& dstSize, T v, EndianType endianType) {
    if (dstSize < sizeof(T)) return false;

    u8* pVal = reinterpret_cast<u8*>(&v);
    u8* pDstEnd = pDst + sizeof(T);
    if ((isLittleEndian() && endianType == kBigEndian) || (!isLittleEndian() && endianType == kLittleEndian)) {
        while (pDst != pDstEnd--) {
            *pDstEnd = *pVal++;
        }
        pDst += sizeof(T);
    }
    else {
        while (pDst != pDstEnd) {
            *pDst++ = *pVal++;
        }
    }
    dstSize -= sizeof(T);
    return true;
}

} // end of z3D

#endif // ZAVOD3D_HM_ENDIANNESS_H_

