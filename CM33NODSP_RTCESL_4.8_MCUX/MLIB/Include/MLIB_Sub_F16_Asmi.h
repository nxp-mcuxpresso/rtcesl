/*******************************************************************************
*
* Copyright 2013-2016, Freescale Semiconductor, Inc.
* Copyright 2016-2024 NXP
*
* NXP Proprietary. This software is owned or controlled by NXP and may
* only be used strictly in accordance with the applicable license terms. 
* By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that
* you have read, and that you agree to comply with and are bound by,
* such license terms.  If you do not agree to be bound by the applicable
* license terms, then you may not retain, install, activate or otherwise
* use the software.
* 
*
****************************************************************************//*!
*
* @brief  Subtraction
* 
*******************************************************************************/
#ifndef _MLIB_SUB_F16_ASM_H_
#define _MLIB_SUB_F16_ASM_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "mlib_types.h"

/*******************************************************************************
* Macros
*******************************************************************************/  
#define MLIB_SubSat_F16_Asmi(f16Min, f16Sub) MLIB_SubSat_F16_FAsmi(f16Min, f16Sub)

/***************************************************************************//*!
*
* f16Out = f16Min - f16Sub
* With saturation
*******************************************************************************/
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET
static inline frac16_t MLIB_SubSat_F16_FAsmi(register frac16_t f16Min, register frac16_t f16Sub)
{
    register frac32_t f32Val = 0x8000;

    #if defined(__CC_ARM)                               /* For ARM Compiler */
        __asm volatile{ sxth f16Min, f16Min             /* Transforms 16-bit input f16Min to 32-bit */
                        sxth f16Sub, f16Sub             /* Transforms 16-bit input f16Sub to 32-bit */
                        subs f16Min, f16Min, f16Sub     /* f16Min = f16Min - f16Sub */

                        cmp f32Val, f16Min              /* Compares f16Min with 0x7FFF */
                        bgt NegTest                     /* If f16Min < 0x8000, then goes to NegTest */
                        subs f16Min, f32Val, #1         /* If f16Min >= 0x8000, then f16Min = 0x7FFF */
                        b SatEnd                        /* Goes to SatEnd */
                    NegTest:
                        sxth f32Val, f32Val             /* f32Val = 0xFFFF8000 */
                        cmp f32Val, f16Min              /* Compares f16Min with 0xFFFF8000 */
                        ble SatEnd                      /* If f16Min >= 0xFFFF8000, then goes to SatEnd */
                        mov f16Min, f32Val};            /* If f16Min < 0xFFFF8000, then f16Min = 0xFFFF8000 */
                    SatEnd:
    #elif defined(__GNUC__) && defined(__ARMCC_VERSION) 
        __asm volatile(
                        "sxth %2, %2 \n\t"              /* Transforms 16-bit input f16Min to 32-bit */
                        "sxth %0, %0 \n\t"              /* Transforms 16-bit input f16Sub to 32-bit */
                        "subs %2, %2, %0 \n\t"          /* f16Min = f16Min - f16Sub */

                        "cmp %1, %2 \n\t"               /* Compares f16Min with 0x8000 */
                        "bgt MLIB_SUB_F16_NegTest%= \n\t" /* If f16Min < 0x8000, then jumps through two commands */
                        "subs %2, %1, #1 \n\t"          /* If f16Min >= 0x8000, then f16Min = 0x7FFF */
                        "b MLIB_SUB_F16_SatEnd%= \n\t"    /* Jumps through four commands */
                    "MLIB_SUB_F16_NegTest%=: \n\t"
                        "sxth %1, %1 \n\t"              /* f32Val = 0xFFFF8000 */
                        "cmp %1, %2 \n\t"               /* Compares f16Min with 0xFFFF8000 */
                        "ble MLIB_SUB_F16_SatEnd%= \n\t"/* If f16Min >= 0xFFFF8000, then jumps through next commands */
                        "mov %2, %1 \n\t"               /* If f16Min < 0xFFFF8000, then f16Min = 0xFFFF8000 */
                    "MLIB_SUB_F16_SatEnd%=: \n\t"
                        : "+l"(f16Sub), "+l"(f32Val), "+l"(f16Min):);
    #else
        __asm volatile(
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax unified \n"        /* Using unified asm syntax */
                        #endif
                        "sxth %2, %2 \n"                /* Transforms 16-bit input f16Min to 32-bit */
                        "sxth %0, %0 \n"                /* Transforms 16-bit input f16Sub to 32-bit */
                        "subs %2, %2, %0 \n"            /* f16Min = f16Min - f16Sub */

                        "cmp %1, %2 \n"                 /* Compares f16Min with 0x8000 */
                        "bgt .+6 \n"                    /* If f16Min < 0x8000, then jumps through two commands */
                        "subs %2, %1, #1 \n"            /* If f16Min >= 0x8000, then f16Min = 0x7FFF */
                        "b .+10 \n"                     /* Jumps through four commands */

                        "sxth %1, %1 \n"                /* f32Val = 0xFFFF8000 */
                        "cmp %1, %2 \n"                 /* Compares f16Min with 0xFFFF8000 */
                        "ble .+4 \n"                    /* If f16Min >= 0xFFFF8000, then jumps through next commands */
                        "mov %2, %1 \n"                 /* If f16Min < 0xFFFF8000, then f16Min = 0xFFFF8000 */
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f16Sub), "+l"(f32Val), "+l"(f16Min):);
    #endif

    return f16Min;
}
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_RESTORE 

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_SUB_F16_ASM_H_ */
