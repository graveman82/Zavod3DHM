#ifndef ZAVOD3D_HM_ENDIANNESS_FILE_H_
#define ZAVOD3D_HM_ENDIANNESS_FILE_H_

/* This file is a part of Zavod3D engine project.
It's licensed unser the MIT license (see "Licence.txt" for details).*/

#include "z3DLib/endianness.h"

namespace z3D {

/** @brief Прочитать встроенный тип из файла.
 *
 * @param fp файловый дескриптор.
 * @param rslt ссылка на переменную для сохранения результата чтения.
 * @param endianType предполагаемый тип кодировки данных в файле.
 * @return true, если операция завершилась успешно, false - при ошибке.
 * @note Только для встроенных типов (integers, floats, char, wchar_t etc).
 */
template <typename T>
inline bool freadBuiltin(FILE* fp, T& rslt, EndianType endianType) {
    if (!fp) return false;

    u8 buf[sizeof(T)];
    const u8* pSrc = buf;
    u32 srcSize = sizeof(T);
#ifdef ZHM_FREAD_TRY_MODE_ON
    long fpOffs = ftell(fp);
#endif
    if (fread(pSrc, 1, srcSize, fp) < srcSize) {
        if (ferror(fp))
            return false;
        else if (feof(fp)) {
#ifdef ZHM_FREAD_TRY_MODE_ON
            if (fpp != -1) {
                fseek(fp, fpOffs, SEEK_SET);
            }
#endif
            return false;
        }
    }
    return readBuiltin(pSrc, srcSize, rslt, endianType);
}

/** @brief Записать встроенный тип в файл.
 *
 * @param fp файловый дескриптор.
 * @param v записываемое значение.
 * @param endianType предполагаемый тип кодировки данных в файле.
 * @return true, если операция завершилась успешно, false - при ошибке.
 * @note Только для встроенных типов (integers, floats, char, wchar_t etc).
 */
template <typename T>
inline bool fwriteBuiltin(FILE* fp, T v, EndianType endianType) {
    if (!fp) return false;

    u8 buf[sizeof(T)];
    u8* pDst = buf;
    u32 dstSize = sizeof(T);

    if (!writeBuiltin(pDst, dstSize, v, endianType))
        return false;

    pDst = buf;
    dstSize = sizeof(T);
    if (fwrite(pDst, 1, dstSize, fp) < dstSize) {
        if (ferror(fp))
            return false;
    };
    return true;
}

} // end of z3D

#endif // ZAVOD3D_HM_ENDIANNESS_FILE_H_


