#ifndef ZAVOD3D_HM_UTF_H_
#define ZAVOD3D_HM_UTF_H_

/* This file is a part of Zavod3D engine project.
It's licensed unser the MIT license (see "Licence.txt" for details).*/

#include "z3DLib/endianness.h"

namespace z3D {

const u32 kUtf16Bom = 0xfeff;

/** @brief Сохраняет кодовую позицию Юникода в буфере байт как UTF-16.
    @code
    // Пример кода. Для проверки следует установить шрифт "aegyptus".
    // Вы должны увидеть в сгенерированном файле иероглифы быка, глаза, человека с поднятыми руками и ног, идущих вправо.
    // Можно поменять кодировку иероглифов и BOM на little endian - должно получиться то же самое.
    // Кодировку сгенерированного текста распознает Nodepad++ (меню "Кодировки").
    const z3D::u32 hieroglyphics[5] = {
    0x130D2, // бык
    0x13080, // глаз
    0x13020, // человек с поднятыми руками
    0x130BD, // ноги, идущие вправо
    0};

    void Test_encodeAsUtf16(z3D::EndianType et) {
        using z3D::u8;
        using z3D::u32;
        using z3D::u16;

        FILE* fp = fopen("data.txt", "wb");
        if (fp) {
            const u32 kBUF_SIZE = sizeof(u32) * 5;
            u8 buf[kBUF_SIZE] = {0};
            u8* pBuf = buf;
            u32 bufSize = kBUF_SIZE;

            // encoding
            const u32* pHieroglyphics = hieroglyphics;
            u32 nEncoded = 0;
            bool fErr = false;
            while (!fErr && *pHieroglyphics) {
                fErr = !z3D::encodeAsUtf16(pBuf, bufSize, nEncoded, *pHieroglyphics++, et);
                pBuf += nEncoded;
                bufSize -= nEncoded;
            }
            *pBuf = 0;

            // bom
            u16 bom = 0xfeff;
            z3D::fwriteBuiltin(fp, bom, et);

            fwrite(&buf[0], 1, kBUF_SIZE - 4, fp);
            fclose(fp);
        }

        fp = fopen("data.txt", "rb");
        if (fp) {
            u8 c;
            while (!feof(fp)) {
                fread(&c, 1, 1, fp);
                printf("Read byte: %x\n", c);
            }
            fclose(fp);
        }
    }
    @endcode
 */
bool encodeAsUtf16(u8* dst, u32 dstSize, u32& nEncodedBytes, u32 cp, EndianType endianType);

} // end of z3D

#endif // ZAVOD3D_HM_UTF_H_

