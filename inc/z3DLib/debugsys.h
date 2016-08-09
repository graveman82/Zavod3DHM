#ifndef Z3D_DEBUGSYS_H_
#define Z3D_DEBUGSYS_H_

/* This file is a part of Zavod3D engine project.
It's licensed unser the MIT license (see "Licence.txt" for details).*/

/** @addtogroup z3DDebugSystem
    @{
*/
/// Отладка не производится.
#define Z3D_DEBUG_LEVEL_NONE 0
/// Затраты процессорного времени на отладку несущественны (допустимо оставить в релизе).
#define Z3D_DEBUG_LEVEL_LOW 1
/// Обычный режим отладки при разработке(для хорошо оттестированного кода).
#define Z3D_DEBUG_LEVEL_MEDIUM 2
/// Обычный режим отладки при разработке (для ловли серьезных багов).
#define Z3D_DEBUG_LEVEL_HIGH 3
/// Для крайне серьезных и опасных ситуаций.
#define Z3D_DEBUG_LEVEL_EXTRA 4
/// Это для разного рода сошедших с ума на почве программирования личностей.
#define Z3D_DEBUG_LEVEL_PARANOIC 5

/** Уровень отладки [1-5] - чем выше, тем дотошнее.*/
#ifndef Z3D_DEBUG_LEVEL

    #define Z3D_DEBUG_LEVEL Z3D_DEBUG_LEVEL_NONE

#endif // Z3D_DEBUG_LEVEL



// Утверждения и отладочные сообщения
#if Z3D_DEBUG_LEVEL >= Z3D_DEBUG_LEVEL_LOW

#define Z3D_ASSERT(exp, fmt, fPopMsg)                                                                                           \
{                                                                                                                               \
    if (!(exp))                                                                                                                 \
    {                                                                                                                           \
        z3D::DebugTool::OutputMsg (z3D::DebugTool::kAssert, #exp, Z3D_FILEANDLINE, fPopMsg, fmt);                               \
        Z3D_DEBUG_BP();                                                                                                         \
    }                                                                                                                           \
}
#define Z3D_ASSERT1(exp, fmt, a1, fPopMsg)                                                                                      \
{                                                                                                                               \
    if (!(exp))                                                                                                                 \
    {                                                                                                                           \
        z3D::DebugTool::OutputMsg (z3D::DebugTool::kAssert, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1);                           \
        Z3D_DEBUG_BP();                                                                                                         \
    }                                                                                                                           \
}
#define Z3D_ASSERT2(exp, fmt, a1, a2, fPopMsg)                                                                                  \
{                                                                                                                               \
    if (!(exp))                                                                                                                 \
    {                                                                                                                           \
        z3D::DebugTool::OutputMsg (z3D::DebugTool::kAssert, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2);                       \
        Z3D_DEBUG_BP();                                                                                                         \
    }                                                                                                                           \
}
#define Z3D_ASSERT3(exp, fmt, a1, a2, a3, fPopMsg)                                                                              \
{                                                                                                                               \
    if (!(exp))                                                                                                                 \
    {                                                                                                                           \
        z3D::DebugTool::OutputMsg (z3D::DebugTool::kAssert, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3);                   \
        Z3D_DEBUG_BP();                                                                                                         \
    }                                                                                                                           \
}
#define Z3D_ASSERT4(exp, fmt, a1, a2, a3, a4, fPopMsg)                                                                          \
{                                                                                                                               \
    if (!(exp))                                                                                                                 \
    {                                                                                                                           \
        z3D::DebugTool::OutputMsg (z3D::DebugTool::kAssert, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3, a4);               \
        Z3D_DEBUG_BP();                                                                                                         \
    }                                                                                                                           \
}
#define Z3D_ASSERT5(exp, fmt, a1, a2, a3, a4, a5, fPopMsg)                                                                      \
{                                                                                                                               \
    if (!(exp))                                                                                                                 \
    {                                                                                                                           \
        z3D::DebugTool::OutputMsg (z3D::DebugTool::kAssert, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3, a4, a5);           \
        Z3D_DEBUG_BP();                                                                                                         \
    }                                                                                                                           \
}
#define Z3D_ASSERT6(exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg)                                                                  \
{                                                                                                                               \
    if (!(exp))                                                                                                                 \
    {                                                                                                                           \
        z3D::DebugTool::OutputMsg (z3D::DebugTool::kAssert, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3, a4, a5, a6);       \
        Z3D_DEBUG_BP();                                                                                                         \
    }                                                                                                                           \
}
#define Z3D_ASSERT7(exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg)                                                              \
{                                                                                                                               \
    if (!(exp))                                                                                                                 \
    {                                                                                                                           \
        z3D::DebugTool::OutputMsg (z3D::DebugTool::kAssert, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3, a4, a5, a6, a7);   \
        Z3D_DEBUG_BP();                                                                                                         \
    }                                                                                                                           \
}
#define Z3D_ASSERT8(exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg)                                                              \
{                                                                                                                                   \
    if (!(exp))                                                                                                                     \
    {                                                                                                                               \
        z3D::DebugTool::OutputMsg (z3D::DebugTool::kAssert, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3, a4, a5, a6, a7, a8);   \
        Z3D_DEBUG_BP();                                                                                                             \
    }                                                                                                                               \
}

#define Z3D_DEBUG(  exp, fmt, fPopMsg) z3D::DebugTool::OutputMsg (z3D::DebugTool::kDebug, #exp, Z3D_FILEANDLINE, fPopMsg, fmt)
#define Z3D_DEBUG1( exp, fmt, a1, fPopMsg) z3D::DebugTool::OutputMsg (z3D::DebugTool::kDebug, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1)
#define Z3D_DEBUG2( exp, fmt, a1, a2, fPopMsg) z3D::DebugTool::OutputMsg (z3D::DebugTool::kDebug, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2)
#define Z3D_DEBUG3( exp, fmt, a1, a2, a3, fPopMsg) z3D::DebugTool::OutputMsg (z3D::DebugTool::kDebug, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3)
#define Z3D_DEBUG4( exp, fmt, a1, a2, a3, a4, fPopMsg) z3D::DebugTool::OutputMsg (z3D::DebugTool::kDebug, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3, a4)
#define Z3D_DEBUG5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) z3D::DebugTool::OutputMsg (z3D::DebugTool::kDebug, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3, a4, a5)
#define Z3D_DEBUG6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) z3D::DebugTool::OutputMsg (z3D::DebugTool::kDebug, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3, a4, a5, a6)
#define Z3D_DEBUG7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) z3D::DebugTool::OutputMsg (z3D::DebugTool::kDebug, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3, a4, a5, a6, a7)
#define Z3D_DEBUG8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) z3D::DebugTool::OutputMsg (z3D::DebugTool::kDebug, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3, a4, a5, a6, a7, a8)

#else
#define Z3D_ASSERT( exp, fmt, fPopMsg)  ((void) 0)
#define Z3D_ASSERT1(exp, fmt, a1, fPopMsg)  ((void) 0)
#define Z3D_ASSERT2(exp, fmt, a1, a2, fPopMsg)  ((void) 0)
#define Z3D_ASSERT3(exp, fmt, a1, a2, a3, fPopMsg)  ((void) 0)
#define Z3D_ASSERT4(exp, fmt, a1, a2, a3, a4, fPopMsg)  ((void) 0)
#define Z3D_ASSERT5(exp, fmt, a1, a2, a3, a4, a5, fPopMsg)  ((void) 0)
#define Z3D_ASSERT6(exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) ((void) 0)
#define Z3D_ASSERT7(exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) ((void) 0)
#define Z3D_ASSERT8(exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) ((void) 0)

#define Z3D_DEBUG(  exp, fmt, fPopMsg) ((void) 0)
#define Z3D_DEBUG1( exp, fmt, a1, fPopMsg) ((void) 0)
#define Z3D_DEBUG2( exp, fmt, a1, a2, fPopMsg) ((void) 0)
#define Z3D_DEBUG3( exp, fmt, a1, a2, a3, fPopMsg) ((void) 0)
#define Z3D_DEBUG4( exp, fmt, a1, a2, a3, a4, fPopMsg) ((void) 0)
#define Z3D_DEBUG5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) ((void) 0)
#define Z3D_DEBUG6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) ((void) 0)
#define Z3D_DEBUG7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) ((void) 0)
#define Z3D_DEBUG8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) ((void) 0)

#endif // Z3D_DEBUG_LEVEL >= Z3D_DEBUG_LEVEL_LOW


#if Z3D_DEBUG_LEVEL >= Z3D_DEBUG_LEVEL_LOW

    #define Z3D_ASSERT_LOW(  exp, fmt, fPopMsg) Z3D_ASSERT(  exp, fmt, fPopMsg)
    #define Z3D_ASSERT_LOW1( exp, fmt, a1, fPopMsg) Z3D_ASSERT1( exp, fmt, a1, fPopMsg)
    #define Z3D_ASSERT_LOW2( exp, fmt, a1, a2, fPopMsg) Z3D_ASSERT2( exp, fmt, a1, a2, fPopMsg)
    #define Z3D_ASSERT_LOW3( exp, fmt, a1, a2, a3, fPopMsg) Z3D_ASSERT3( exp, fmt, a1, a2, a3, fPopMsg)
    #define Z3D_ASSERT_LOW4( exp, fmt, a1, a2, a3, a4, fPopMsg) Z3D_ASSERT4( exp, fmt, a1, a2, a3, a4, fPopMsg)
    #define Z3D_ASSERT_LOW5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) Z3D_ASSERT5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg)
    #define Z3D_ASSERT_LOW6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) Z3D_ASSERT6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg)
    #define Z3D_ASSERT_LOW7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) Z3D_ASSERT7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg)
    #define Z3D_ASSERT_LOW8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) Z3D_ASSERT8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg)

    #define Z3D_DEBUG_LOW(  exp, fmt, fPopMsg) Z3D_DEBUG(  exp, fmt, fPopMsg)
    #define Z3D_DEBUG_LOW1( exp, fmt, a1, fPopMsg) Z3D_DEBUG1( exp, fmt, a1, fPopMsg)
    #define Z3D_DEBUG_LOW2( exp, fmt, a1, a2, fPopMsg) Z3D_DEBUG2( exp, fmt, a1, a2, fPopMsg)
    #define Z3D_DEBUG_LOW3( exp, fmt, a1, a2, a3, fPopMsg) Z3D_DEBUG3( exp, fmt, a1, a2, a3, fPopMsg)
    #define Z3D_DEBUG_LOW4( exp, fmt, a1, a2, a3, a4, fPopMsg) Z3D_DEBUG4( exp, fmt, a1, a2, a3, a4, fPopMsg)
    #define Z3D_DEBUG_LOW5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) Z3D_DEBUG5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg)
    #define Z3D_DEBUG_LOW6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) Z3D_DEBUG6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg)
    #define Z3D_DEBUG_LOW7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) Z3D_DEBUG7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg)
    #define Z3D_DEBUG_LOW8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) Z3D_DEBUG8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg)
#else
    #define Z3D_ASSERT_LOW(  exp, fmt, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_LOW1( exp, fmt, a1, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_LOW2( exp, fmt, a1, a2, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_LOW3( exp, fmt, a1, a2, a3, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_LOW4( exp, fmt, a1, a2, a3, a4, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_LOW5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_LOW6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_LOW7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_LOW8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) ((void) 0)

    #define Z3D_DEBUG_LOW(  exp, fmt, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_LOW1( exp, fmt, a1, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_LOW2( exp, fmt, a1, a2, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_LOW3( exp, fmt, a1, a2, a3, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_LOW4( exp, fmt, a1, a2, a3, a4, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_LOW5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_LOW6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_LOW7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_LOW8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) ((void) 0)
#endif // Z3D_DEBUG_LEVEL >= Z3D_DEBUG_LEVEL_LOW

#if Z3D_DEBUG_LEVEL >= Z3D_DEBUG_LEVEL_MEDIUM

    #define Z3D_ASSERT_MEDIUM(  exp, fmt, fPopMsg) Z3D_ASSERT(  exp, fmt, fPopMsg)
    #define Z3D_ASSERT_MEDIUM1( exp, fmt, a1, fPopMsg) Z3D_ASSERT1( exp, fmt, a1, fPopMsg)
    #define Z3D_ASSERT_MEDIUM2( exp, fmt, a1, a2, fPopMsg) Z3D_ASSERT2( exp, fmt, a1, a2, fPopMsg)
    #define Z3D_ASSERT_MEDIUM3( exp, fmt, a1, a2, a3, fPopMsg) Z3D_ASSERT3( exp, fmt, a1, a2, a3, fPopMsg)
    #define Z3D_ASSERT_MEDIUM4( exp, fmt, a1, a2, a3, a4, fPopMsg) Z3D_ASSERT4( exp, fmt, a1, a2, a3, a4, fPopMsg)
    #define Z3D_ASSERT_MEDIUM5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) Z3D_ASSERT5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg)
    #define Z3D_ASSERT_MEDIUM6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) Z3D_ASSERT6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg)
    #define Z3D_ASSERT_MEDIUM7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) Z3D_ASSERT7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg)
    #define Z3D_ASSERT_MEDIUM8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) Z3D_ASSERT8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg)

    #define Z3D_DEBUG_MEDIUM(  exp, fmt, fPopMsg) Z3D_DEBUG(  exp, fmt, fPopMsg)
    #define Z3D_DEBUG_MEDIUM1( exp, fmt, a1, fPopMsg) Z3D_DEBUG1( exp, fmt, a1, fPopMsg)
    #define Z3D_DEBUG_MEDIUM2( exp, fmt, a1, a2, fPopMsg) Z3D_DEBUG2( exp, fmt, a1, a2, fPopMsg)
    #define Z3D_DEBUG_MEDIUM3( exp, fmt, a1, a2, a3, fPopMsg) Z3D_DEBUG3( exp, fmt, a1, a2, a3, fPopMsg)
    #define Z3D_DEBUG_MEDIUM4( exp, fmt, a1, a2, a3, a4, fPopMsg) Z3D_DEBUG4( exp, fmt, a1, a2, a3, a4, fPopMsg)
    #define Z3D_DEBUG_MEDIUM5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) Z3D_DEBUG5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg)
    #define Z3D_DEBUG_MEDIUM6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) Z3D_DEBUG6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg)
    #define Z3D_DEBUG_MEDIUM7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) Z3D_DEBUG7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg)
    #define Z3D_DEBUG_MEDIUM8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) Z3D_DEBUG8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg)
#else
    #define Z3D_ASSERT_MEDIUM(  exp, fmt, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_MEDIUM1( exp, fmt, a1, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_MEDIUM2( exp, fmt, a1, a2, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_MEDIUM3( exp, fmt, a1, a2, a3, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_MEDIUM4( exp, fmt, a1, a2, a3, a4, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_MEDIUM5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_MEDIUM6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_MEDIUM7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_MEDIUM8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) ((void) 0)

    #define Z3D_DEBUG_MEDIUM(  exp, fmt, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_MEDIUM1( exp, fmt, a1, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_MEDIUM2( exp, fmt, a1, a2, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_MEDIUM3( exp, fmt, a1, a2, a3, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_MEDIUM4( exp, fmt, a1, a2, a3, a4, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_MEDIUM5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_MEDIUM6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_MEDIUM7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_MEDIUM8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) ((void) 0)
#endif // Z3D_DEBUG_LEVEL >= Z3D_DEBUG_LEVEL_MEDIUM

#if Z3D_DEBUG_LEVEL >= Z3D_DEBUG_LEVEL_HIGH

    #define Z3D_ASSERT_HIGH(  exp, fmt, fPopMsg) Z3D_ASSERT(  exp, fmt, fPopMsg)
    #define Z3D_ASSERT_HIGH1( exp, fmt, a1, fPopMsg) Z3D_ASSERT1( exp, fmt, a1, fPopMsg)
    #define Z3D_ASSERT_HIGH2( exp, fmt, a1, a2, fPopMsg) Z3D_ASSERT2( exp, fmt, a1, a2, fPopMsg)
    #define Z3D_ASSERT_HIGH3( exp, fmt, a1, a2, a3, fPopMsg) Z3D_ASSERT3( exp, fmt, a1, a2, a3, fPopMsg)
    #define Z3D_ASSERT_HIGH4( exp, fmt, a1, a2, a3, a4, fPopMsg) Z3D_ASSERT4( exp, fmt, a1, a2, a3, a4, fPopMsg)
    #define Z3D_ASSERT_HIGH5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) Z3D_ASSERT5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg)
    #define Z3D_ASSERT_HIGH6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) Z3D_ASSERT6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg)
    #define Z3D_ASSERT_HIGH7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) Z3D_ASSERT7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg)
    #define Z3D_ASSERT_HIGH8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) Z3D_ASSERT8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg)

    #define Z3D_DEBUG_HIGH(  exp, fmt, fPopMsg) Z3D_DEBUG(  exp, fmt, fPopMsg)
    #define Z3D_DEBUG_HIGH1( exp, fmt, a1, fPopMsg) Z3D_DEBUG1( exp, fmt, a1, fPopMsg)
    #define Z3D_DEBUG_HIGH2( exp, fmt, a1, a2, fPopMsg) Z3D_DEBUG2( exp, fmt, a1, a2, fPopMsg)
    #define Z3D_DEBUG_HIGH3( exp, fmt, a1, a2, a3, fPopMsg) Z3D_DEBUG3( exp, fmt, a1, a2, a3, fPopMsg)
    #define Z3D_DEBUG_HIGH4( exp, fmt, a1, a2, a3, a4, fPopMsg) Z3D_DEBUG4( exp, fmt, a1, a2, a3, a4, fPopMsg)
    #define Z3D_DEBUG_HIGH5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) Z3D_DEBUG5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg)
    #define Z3D_DEBUG_HIGH6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) Z3D_DEBUG6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg)
    #define Z3D_DEBUG_HIGH7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) Z3D_DEBUG7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg)
    #define Z3D_DEBUG_HIGH8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) Z3D_DEBUG8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg)
#else
    #define Z3D_ASSERT_HIGH(  exp, fmt, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_HIGH1( exp, fmt, a1, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_HIGH2( exp, fmt, a1, a2, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_HIGH3( exp, fmt, a1, a2, a3, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_HIGH4( exp, fmt, a1, a2, a3, a4, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_HIGH5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_HIGH6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_HIGH7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_HIGH8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) ((void) 0)

    #define Z3D_DEBUG_HIGH(  exp, fmt, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_HIGH1( exp, fmt, a1, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_HIGH2( exp, fmt, a1, a2, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_HIGH3( exp, fmt, a1, a2, a3, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_HIGH4( exp, fmt, a1, a2, a3, a4, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_HIGH5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_HIGH6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_HIGH7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_HIGH8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) ((void) 0)
#endif // Z3D_DEBUG_LEVEL >= Z3D_DEBUG_LEVEL_HIGH

#if Z3D_DEBUG_LEVEL >= Z3D_DEBUG_LEVEL_EXTRA

    #define Z3D_ASSERT_EXTRA(  exp, fmt, fPopMsg) Z3D_ASSERT(  exp, fmt, fPopMsg)
    #define Z3D_ASSERT_EXTRA1( exp, fmt, a1, fPopMsg) Z3D_ASSERT1( exp, fmt, a1, fPopMsg)
    #define Z3D_ASSERT_EXTRA2( exp, fmt, a1, a2, fPopMsg) Z3D_ASSERT2( exp, fmt, a1, a2, fPopMsg)
    #define Z3D_ASSERT_EXTRA3( exp, fmt, a1, a2, a3, fPopMsg) Z3D_ASSERT3( exp, fmt, a1, a2, a3, fPopMsg)
    #define Z3D_ASSERT_EXTRA4( exp, fmt, a1, a2, a3, a4, fPopMsg) Z3D_ASSERT4( exp, fmt, a1, a2, a3, a4, fPopMsg)
    #define Z3D_ASSERT_EXTRA5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) Z3D_ASSERT5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg)
    #define Z3D_ASSERT_EXTRA6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) Z3D_ASSERT6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg)
    #define Z3D_ASSERT_EXTRA7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) Z3D_ASSERT7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg)
    #define Z3D_ASSERT_EXTRA8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) Z3D_ASSERT8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg)

    #define Z3D_DEBUG_EXTRA(  exp, fmt, fPopMsg) Z3D_DEBUG(  exp, fmt, fPopMsg)
    #define Z3D_DEBUG_EXTRA1( exp, fmt, a1, fPopMsg) Z3D_DEBUG1( exp, fmt, a1, fPopMsg)
    #define Z3D_DEBUG_EXTRA2( exp, fmt, a1, a2, fPopMsg) Z3D_DEBUG2( exp, fmt, a1, a2, fPopMsg)
    #define Z3D_DEBUG_EXTRA3( exp, fmt, a1, a2, a3, fPopMsg) Z3D_DEBUG3( exp, fmt, a1, a2, a3, fPopMsg)
    #define Z3D_DEBUG_EXTRA4( exp, fmt, a1, a2, a3, a4, fPopMsg) Z3D_DEBUG4( exp, fmt, a1, a2, a3, a4, fPopMsg)
    #define Z3D_DEBUG_EXTRA5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) Z3D_DEBUG5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg)
    #define Z3D_DEBUG_EXTRA6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) Z3D_DEBUG6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg)
    #define Z3D_DEBUG_EXTRA7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) Z3D_DEBUG7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg)
    #define Z3D_DEBUG_EXTRA8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) Z3D_DEBUG8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg)
#else
    #define Z3D_ASSERT_EXTRA(  exp, fmt, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_EXTRA1( exp, fmt, a1, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_EXTRA2( exp, fmt, a1, a2, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_EXTRA3( exp, fmt, a1, a2, a3, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_EXTRA4( exp, fmt, a1, a2, a3, a4, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_EXTRA5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_EXTRA6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_EXTRA7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_EXTRA8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) ((void) 0)

    #define Z3D_DEBUG_EXTRA(  exp, fmt, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_EXTRA1( exp, fmt, a1, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_EXTRA2( exp, fmt, a1, a2, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_EXTRA3( exp, fmt, a1, a2, a3, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_EXTRA4( exp, fmt, a1, a2, a3, a4, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_EXTRA5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_EXTRA6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_EXTRA7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_EXTRA8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) ((void) 0)
#endif // Z3D_DEBUG_LEVEL >= Z3D_DEBUG_LEVEL_EXTRA

#if Z3D_DEBUG_LEVEL >= Z3D_DEBUG_LEVEL_PARANOIC

    #define Z3D_ASSERT_PARANOIC(  exp, fmt, fPopMsg) Z3D_ASSERT(  exp, fmt, fPopMsg)
    #define Z3D_ASSERT_PARANOIC1( exp, fmt, a1, fPopMsg) Z3D_ASSERT1( exp, fmt, a1, fPopMsg)
    #define Z3D_ASSERT_PARANOIC2( exp, fmt, a1, a2, fPopMsg) Z3D_ASSERT2( exp, fmt, a1, a2, fPopMsg)
    #define Z3D_ASSERT_PARANOIC3( exp, fmt, a1, a2, a3, fPopMsg) Z3D_ASSERT3( exp, fmt, a1, a2, a3, fPopMsg)
    #define Z3D_ASSERT_PARANOIC4( exp, fmt, a1, a2, a3, a4, fPopMsg) Z3D_ASSERT4( exp, fmt, a1, a2, a3, a4, fPopMsg)
    #define Z3D_ASSERT_PARANOIC5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) Z3D_ASSERT5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg)
    #define Z3D_ASSERT_PARANOIC6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) Z3D_ASSERT6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg)
    #define Z3D_ASSERT_PARANOIC7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) Z3D_ASSERT7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg)
    #define Z3D_ASSERT_PARANOIC8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) Z3D_ASSERT8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg)

    #define Z3D_DEBUG_PARANOIC(  exp, fmt, fPopMsg) Z3D_DEBUG(  exp, fmt, fPopMsg)
    #define Z3D_DEBUG_PARANOIC1( exp, fmt, a1, fPopMsg) Z3D_DEBUG1( exp, fmt, a1, fPopMsg)
    #define Z3D_DEBUG_PARANOIC2( exp, fmt, a1, a2, fPopMsg) Z3D_DEBUG2( exp, fmt, a1, a2, fPopMsg)
    #define Z3D_DEBUG_PARANOIC3( exp, fmt, a1, a2, a3, fPopMsg) Z3D_DEBUG3( exp, fmt, a1, a2, a3, fPopMsg)
    #define Z3D_DEBUG_PARANOIC4( exp, fmt, a1, a2, a3, a4, fPopMsg) Z3D_DEBUG4( exp, fmt, a1, a2, a3, a4, fPopMsg)
    #define Z3D_DEBUG_PARANOIC5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) Z3D_DEBUG5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg)
    #define Z3D_DEBUG_PARANOIC6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) Z3D_DEBUG6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg)
    #define Z3D_DEBUG_PARANOIC7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) Z3D_DEBUG7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg)
    #define Z3D_DEBUG_PARANOIC8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) Z3D_DEBUG8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg)
#else
    #define Z3D_ASSERT_PARANOIC(  exp, fmt, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_PARANOIC1( exp, fmt, a1, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_PARANOIC2( exp, fmt, a1, a2, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_PARANOIC3( exp, fmt, a1, a2, a3, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_PARANOIC4( exp, fmt, a1, a2, a3, a4, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_PARANOIC5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_PARANOIC6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_PARANOIC7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) ((void) 0)
    #define Z3D_ASSERT_PARANOIC8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) ((void) 0)

    #define Z3D_DEBUG_PARANOIC(  exp, fmt, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_PARANOIC1( exp, fmt, a1, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_PARANOIC2( exp, fmt, a1, a2, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_PARANOIC3( exp, fmt, a1, a2, a3, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_PARANOIC4( exp, fmt, a1, a2, a3, a4, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_PARANOIC5( exp, fmt, a1, a2, a3, a4, a5, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_PARANOIC6( exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_PARANOIC7( exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) ((void) 0)
    #define Z3D_DEBUG_PARANOIC8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) ((void) 0)
#endif // Z3D_DEBUG_LEVEL >= Z3D_DEBUG_LEVEL_PARANOIC


// Программная точка останова для отладки
#if Z3D_DEBUG_LEVEL >= Z3D_DEBUG_LEVEL_LOW

    #ifdef _MSC_VER
        #define Z3D_DEBUG_BP() do{ __asm int 3 } while (0)
    #endif // _MSC_VER

    #ifdef __GNUC__
        #define Z3D_DEBUG_BP() do{__asm__ ("int $3\n\t");}while (0)
    #endif // __GNUC__

#else
    #define Z3D_DEBUG_BP(skip)
#endif //Z3D_DEBUG_LEVEL >= Z3D_DEBUG_LEVEL_LOW



#ifdef Z3D_DEBUG
#define Z3D_FILEANDLINE __FILE__, __LINE__
#else
#define Z3D_FILEANDLINE "", 0
#endif


// Сообщения
#define Z3D_INFO(   fmt) z3D::DebugTool::OutputMsg (z3D::DebugTool::kInfo, "", "", 0, z3D::DebugTool::kPopNoMsg, fmt)
#define Z3D_INFO1(  fmt, a1) z3D::DebugTool::OutputMsg (z3D::DebugTool::kInfo, "", "", 0, z3D::DebugTool::kPopNoMsg, fmt, a1)
#define Z3D_INFO2(  fmt, a1, a2) z3D::DebugTool::OutputMsg (z3D::DebugTool::kInfo, "", "", 0, z3D::DebugTool::kPopNoMsg, fmt, a1, a2)
#define Z3D_INFO3(  fmt, a1, a2, a3) z3D::DebugTool::OutputMsg (z3D::DebugTool::kInfo, "", "", 0, z3D::DebugTool::kPopNoMsg, fmt, a1, a2, a3)
#define Z3D_INFO4(  fmt, a1, a2, a3, a4) z3D::DebugTool::OutputMsg (z3D::DebugTool::kInfo, "", "", 0, z3D::DebugTool::kPopNoMsg, fmt, a1, a2, a3, a4)
#define Z3D_INFO5(  fmt, a1, a2, a3, a4, a5) z3D::DebugTool::OutputMsg (z3D::DebugTool::kInfo, "", "", 0, z3D::DebugTool::kPopNoMsg, fmt, a1, a2, a3, a4, a5)
#define Z3D_INFO6(  fmt, a1, a2, a3, a4, a5, a6) z3D::DebugTool::OutputMsg (z3D::DebugTool::kInfo, "", "", 0, z3D::DebugTool::kPopNoMsg, fmt, a1, a2, a3, a4, a5, a6)
#define Z3D_INFO7(  fmt, a1, a2, a3, a4, a5, a6, a7) z3D::DebugTool::OutputMsg (z3D::DebugTool::kInfo, "", "", 0, z3D::DebugTool::kPopNoMsg, fmt, a1, a2, a3, a4, a5, a6, a7)
#define Z3D_INFO8(  fmt, a1, a2, a3, a4, a5, a6, a7, a8) z3D::DebugTool::OutputMsg (z3D::DebugTool::kInfo, "", "", 0, z3D::DebugTool::kPopNoMsg, fmt, a1, a2, a3, a4, a5, a6, a7, a8)

// Трассировочные сообщения
#define Z3D_TRACE(  fmt, fPopMsg) z3D::DebugTool::OutputMsg (z3D::DebugTool::kTrace, "", Z3D_FILEANDLINE, fPopMsg, fmt)
#define Z3D_TRACE1( fmt, a1, fPopMsg) z3D::DebugTool::OutputMsg (z3D::DebugTool::kTrace, "", Z3D_FILEANDLINE, fPopMsg, fmt, a1)
#define Z3D_TRACE2( fmt, a1, a2, fPopMsg) z3D::DebugTool::OutputMsg (z3D::DebugTool::kTrace, "", Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2)
#define Z3D_TRACE3( fmt, a1, a2, a3, fPopMsg) z3D::DebugTool::OutputMsg (z3D::DebugTool::kTrace, "", Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3)
#define Z3D_TRACE4( fmt, a1, a2, a3, a4, fPopMsg) z3D::DebugTool::OutputMsg (z3D::DebugTool::kTrace, "", Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3, a4)
#define Z3D_TRACE5( fmt, a1, a2, a3, a4, a5, fPopMsg) z3D::DebugTool::OutputMsg (z3D::DebugTool::kTrace, "", Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3, a4, a5)
#define Z3D_TRACE6( fmt, a1, a2, a3, a4, a5, a6, fPopMsg) z3D::DebugTool::OutputMsg (z3D::DebugTool::kTrace, "", Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3, a4, a5, a6)
#define Z3D_TRACE7( fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) z3D::DebugTool::OutputMsg (z3D::DebugTool::kTrace, "", Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3, a4, a5, a6, a7)
#define Z3D_TRACE8( fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) z3D::DebugTool::OutputMsg (z3D::DebugTool::kTrace, "", Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3, a4, a5, a6, a7, a8)

// Сообщения об ошибках
#define Z3D_ERROR(  type, exp, fmt, fPopMsg) z3D::DebugTool::OutputMsg (type, #exp, Z3D_FILEANDLINE, fPopMsg, fmt)
#define Z3D_ERROR1( type, exp, fmt, a1, fPopMsg) z3D::DebugTool::OutputMsg (type, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1)
#define Z3D_ERROR2( type, exp, fmt, a1, a2, fPopMsg) z3D::DebugTool::OutputMsg (type, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2)
#define Z3D_ERROR3( type, exp, fmt, a1, a2, a3, fPopMsg) z3D::DebugTool::OutputMsg (type, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3)
#define Z3D_ERROR4( type, exp, fmt, a1, a2, a3, a4, fPopMsg) z3D::DebugTool::OutputMsg (type, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3, a4)
#define Z3D_ERROR5( type, exp, fmt, a1, a2, a3, a4, a5, fPopMsg) z3D::DebugTool::OutputMsg (type, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3, a4, a5)
#define Z3D_ERROR6( type, exp, fmt, a1, a2, a3, a4, a5, a6, fPopMsg) z3D::DebugTool::OutputMsg (type, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3, a4, a5, a6)
#define Z3D_ERROR7( type, exp, fmt, a1, a2, a3, a4, a5, a6, a7, fPopMsg) z3D::DebugTool::OutputMsg (type, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3, a4, a5, a6, a7)
#define Z3D_ERROR8( type, exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8, fPopMsg) z3D::DebugTool::OutputMsg (type, #exp, Z3D_FILEANDLINE, fPopMsg, fmt, a1, a2, a3, a4, a5, a6, a7, a8)


// Уровни предупреждений
#ifndef Z3D_WARN_LEVEL
#define Z3D_WARN_LEVEL Z3D_WARN_LEVEL_HIGH
#endif // Z3D_WARN_LEVEL

#define Z3D_WARN_LEVEL_NONE        ///< предупреждения не выводятся.
#define Z3D_WARN_LEVEL_LOW 1       ///< затраты процессорного времени на предупреждения несущественны.
#define Z3D_WARN_LEVEL_HIGH 2      ///< обычный режим вывода предупреждений при разработке (для потенциально опасных мест).


// Предупреждения
#define Z3D_WARNING(  exp, fmt) z3D::DebugTool::OutputMsg (z3D::DebugTool::kWarning, #exp, Z3D_FILEANDLINE, z3D::DebugTool::kPopNoMsg, fmt)
#define Z3D_WARNING1( exp, fmt, a1) z3D::DebugTool::OutputMsg (z3D::DebugTool::kWarning, #exp, Z3D_FILEANDLINE, z3D::DebugTool::kPopNoMsg, fmt, a1)
#define Z3D_WARNING2( exp, fmt, a1, a2) z3D::DebugTool::OutputMsg (z3D::DebugTool::kWarning, #exp, Z3D_FILEANDLINE, z3D::DebugTool::kPopNoMsg, fmt, a1, a2)
#define Z3D_WARNING3( exp, fmt, a1, a2, a3) z3D::DebugTool::OutputMsg (z3D::DebugTool::kWarning, #exp, Z3D_FILEANDLINE, z3D::DebugTool::kPopNoMsg, fmt, a1, a2, a3)
#define Z3D_WARNING4( exp, fmt, a1, a2, a3, a4) z3D::DebugTool::OutputMsg (z3D::DebugTool::kWarning, #exp, Z3D_FILEANDLINE, z3D::DebugTool::kPopNoMsg, fmt, a1, a2, a3, a4)
#define Z3D_WARNING5( exp, fmt, a1, a2, a3, a4, a5) z3D::DebugTool::OutputMsg (z3D::DebugTool::kWarning, #exp, Z3D_FILEANDLINE, z3D::DebugTool::kPopNoMsg, fmt, a1, a2, a3, a4, a5)
#define Z3D_WARNING6( exp, fmt, a1, a2, a3, a4, a5, a6) z3D::DebugTool::OutputMsg (z3D::DebugTool::kWarning, #exp, Z3D_FILEANDLINE, z3D::DebugTool::kPopNoMsg, fmt, a1, a2, a3, a4, a5, a6)
#define Z3D_WARNING7( exp, fmt, a1, a2, a3, a4, a5, a6, a7) z3D::DebugTool::OutputMsg (z3D::DebugTool::kWarning, #exp, Z3D_FILEANDLINE, z3D::DebugTool::kPopNoMsg, fmt, a1, a2, a3, a4, a5, a6, a7)
#define Z3D_WARNING8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8) z3D::DebugTool::OutputMsg (z3D::DebugTool::kWarning, #exp, Z3D_FILEANDLINE, z3D::DebugTool::kPopNoMsg, fmt, a1, a2, a3, a4, a5, a6, a7, a8)

#if Z3D_WARN_LEVEL >= Z3D_WARN_LEVEL_LOW
    #define Z3D_WARNING_LOW(  exp, fmt) Z3D_WARNING(  exp, fmt)
    #define Z3D_WARNING_LOW1( exp, fmt, a1) Z3D_WARNING1( exp, fmt, a1)
    #define Z3D_WARNING_LOW2( exp, fmt, a1, a2) Z3D_WARNING2( exp, fmt, a1, a2)
    #define Z3D_WARNING_LOW3( exp, fmt, a1, a2, a3) Z3D_WARNING3( exp, fmt, a1, a2, a3)
    #define Z3D_WARNING_LOW4( exp, fmt, a1, a2, a3, a4) Z3D_WARNING4( exp, fmt, a1, a2, a3, a4)
    #define Z3D_WARNING_LOW5( exp, fmt, a1, a2, a3, a4, a5) Z3D_WARNING5( exp, fmt, a1, a2, a3, a4, a5)
    #define Z3D_WARNING_LOW6( exp, fmt, a1, a2, a3, a4, a5, a6) Z3D_WARNING6( exp, fmt, a1, a2, a3, a4, a5, a6)
    #define Z3D_WARNING_LOW7( exp, fmt, a1, a2, a3, a4, a5, a6, a7) Z3D_WARNING7( exp, fmt, a1, a2, a3, a4, a5, a6, a7)
    #define Z3D_WARNING_LOW8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8) Z3D_WARNING8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8)
#else
    #define Z3D_WARNING_LOW(  exp, fmt) ((void) 0)
    #define Z3D_WARNING_LOW1( exp, fmt, a1) ((void) 0)
    #define Z3D_WARNING_LOW2( exp, fmt, a1, a2) ((void) 0)
    #define Z3D_WARNING_LOW3( exp, fmt, a1, a2, a3) ((void) 0)
    #define Z3D_WARNING_LOW4( exp, fmt, a1, a2, a3, a4) ((void) 0)
    #define Z3D_WARNING_LOW5( exp, fmt, a1, a2, a3, a4, a5) ((void) 0)
    #define Z3D_WARNING_LOW6( exp, fmt, a1, a2, a3, a4, a5, a6) ((void) 0)
    #define Z3D_WARNING_LOW7( exp, fmt, a1, a2, a3, a4, a5, a6, a7) ((void) 0)
    #define Z3D_WARNING_LOW8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8) ((void) 0)
#endif // Z3D_WARN_LEVEL >= Z3D_WARN_LEVEL_LOW

#if Z3D_WARN_LEVEL >= Z3D_WARN_LEVEL_HIGH
    #define Z3D_WARNING_HIGH(  exp, fmt) Z3D_WARNING(  exp, fmt)
    #define Z3D_WARNING_HIGH1( exp, fmt, a1) Z3D_WARNING1( exp, fmt, a1)
    #define Z3D_WARNING_HIGH2( exp, fmt, a1, a2) Z3D_WARNING2( exp, fmt, a1, a2)
    #define Z3D_WARNING_HIGH3( exp, fmt, a1, a2, a3) Z3D_WARNING3( exp, fmt, a1, a2, a3)
    #define Z3D_WARNING_HIGH4( exp, fmt, a1, a2, a3, a4) Z3D_WARNING4( exp, fmt, a1, a2, a3, a4)
    #define Z3D_WARNING_HIGH5( exp, fmt, a1, a2, a3, a4, a5) Z3D_WARNING5( exp, fmt, a1, a2, a3, a4, a5)
    #define Z3D_WARNING_HIGH6( exp, fmt, a1, a2, a3, a4, a5, a6) Z3D_WARNING6( exp, fmt, a1, a2, a3, a4, a5, a6)
    #define Z3D_WARNING_HIGH7( exp, fmt, a1, a2, a3, a4, a5, a6, a7) Z3D_WARNING7( exp, fmt, a1, a2, a3, a4, a5, a6, a7)
    #define Z3D_WARNING_HIGH8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8) Z3D_WARNING8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8)
#else
    #define Z3D_WARNING_HIGH(  exp, fmt) ((void) 0)
    #define Z3D_WARNING_HIGH1( exp, fmt, a1) ((void) 0)
    #define Z3D_WARNING_HIGH2( exp, fmt, a1, a2) ((void) 0)
    #define Z3D_WARNING_HIGH3( exp, fmt, a1, a2, a3) ((void) 0)
    #define Z3D_WARNING_HIGH4( exp, fmt, a1, a2, a3, a4) ((void) 0)
    #define Z3D_WARNING_HIGH5( exp, fmt, a1, a2, a3, a4, a5) ((void) 0)
    #define Z3D_WARNING_HIGH6( exp, fmt, a1, a2, a3, a4, a5, a6) ((void) 0)
    #define Z3D_WARNING_HIGH7( exp, fmt, a1, a2, a3, a4, a5, a6, a7) ((void) 0)
    #define Z3D_WARNING_HIGH8( exp, fmt, a1, a2, a3, a4, a5, a6, a7, a8) ((void) 0)
#endif // Z3D_WARN_LEVEL >= Z3D_WARN_LEVEL_HIGH







namespace z3D
{


/**
    @ingroup z3DDebugSystem
    @brief Запись сообщения в файл лога.
    @param fmt строка формата, после которой могут идти дополнительные аргументы.
*/
void Log(const char* fmt, ...);



/**
    @ingroup z3DDebugSystem
    Отладочный инструмент.
*/
class DebugTool
{
    // Запрещаем создание экземпляра
    DebugTool();

public:

    static const bool kPopMsg;      ///< вызвать диалоговое окно.
    static const bool kPopNoMsg;    ///< не вызывать диалогового окна.

    /// Тип сообщения
    enum eMsgType
    {
        kInfo,      ///< Полезная информация.
        kTrace,     ///< Трассировка.
        kAssert,    ///< Утверждение.
        kDebug,     ///< Отладочная информация.
        kWarning,   ///< Предупреждение о возможной потенциальной ошибке.
        kError,     ///< Ошибка, при которой возможно продолжение работы приложения.
        kFatal      ///< Ошибка, при которой приложение завершает работу.
    };


    /**
        @brief вывод сообщения.
        @param msgType тип сообщения.
        @param exp строка выражения.
        @param filename имя файла, связанного с сообщением.
        @param iLine номер строки в файле, связанном с сообщением.
        @param fPopMsg флаг вывода диалогового окна с сообщением (при true выводить, при false - нет).
        @param fmt строка формата, после которой могут идти дополнительные аргументы.
        @note для простых сообщений (тип kInfo) параметры filename, nLine, exp
                игнорируются (можно передать нули). Для сообщений об ошибках и т.п. через
                filename передается имя файла с ошибкой, nLine - номер строки с ошибкой,
                exp - выражение с ошибкой.

    */
    static void OutputMsg(eMsgType msgType,
                        const char* exp,
                        const char* filename,
                        int iLine,
                        bool fPopMsg,
                        const char* fmt, ...);

private:
    /*
        @brief подготовка сообщения к выводу.
        @param msgType тип сообщения.
        @param exp строка выражения.
        @param filename имя файла, связанного с сообщением.
        @param nLine номер строки в файле, связанном с сообщением.
        @param fmt строка формата.

    */
    static size_t Prepare(eMsgType msgType,
                       const char* exp,
                       const char* filename,
                       int iLine,
                       const char* fmt);


    static char typeStrHeader_[32];
    static char typeStrFooter_[32];
    static char detailsWord_[32]; // для слова "Details: "
    static char filenameLine_[270];

};



} // end of z3D
/**
    @}
*/

#endif // Z3D_DEBUGSYS_H_


