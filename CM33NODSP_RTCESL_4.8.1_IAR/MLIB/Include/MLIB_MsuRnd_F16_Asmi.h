/*******************************************************************************
*
* Copyright (c) 2013 - 2016, Freescale Semiconductor, Inc.
* Copyright 2016-2021, 2024 NXP
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
* @brief  Multiply subtract with rounding
* 
*******************************************************************************/
#ifndef _MLIB_MSURND_F16_ASM_H_
#define _MLIB_MSURND_F16_ASM_H_

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
#define MLIB_MsuRndSat_F16_Asmi(f16Accum, f16Mult1, f16Mult2)                  \
        MLIB_MsuRndSat_F16_FAsmi(f16Accum, f16Mult1, f16Mult2)

/***************************************************************************//*!
*
* f16Out = f16Accum - ( f16Mult1 * f16Mult2)
* With saturation
*******************************************************************************/
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET
static inline frac16_t MLIB_MsuRndSat_F16_FAsmi(register frac16_t f16Accum, 
                                                register frac16_t f16Mult1, register frac16_t f16Mult2)
{
    #if defined(__CC_ARM)                                     /* For ARM Compiler */
        __asm volatile{ sxth f16Accum, f16Accum               /* Converts 16-bit input to 32-bit */
                        sxth f16Mult1, f16Mult1               /* Converts 16-bit input to 32-bit */
                        sxth f16Mult2, f16Mult2               /* Converts 16-bit input to 32-bit */
                        muls f16Mult1, f16Mult1, f16Mult2     /* f16Mult1 * f16Mult2 */
                        asrs f16Mult1, f16Mult1, #7           /* f16Mult1 >> 7 */
                        adds f16Mult1, f16Mult1, #128         /* Rounding */
                        asrs f16Mult1, f16Mult1, #8           /* f16Mult1 >> 8 */
                        subs f16Accum, f16Accum, f16Mult1     /* f16Accum - f16Mult1 * f16Mult2 */

                        movs f16Mult1, #128                   /* f16Mult1 = 0x80 */
                        lsls f16Mult1, f16Mult1, #8           /* f16Mult1 = 0x8000 */

                        cmp f16Mult1, f16Accum                /* Compares f16Accum with 0x8000 */
                        bgt NegTest                           /* If f16Accum < 0x8000, then goes to NegTest */
                        subs f16Accum, f16Mult1, #1           /* If f16Accum >= 0x8000, then f16Accum = 0x7FFF */
                        b SatEnd                              /* Goes to SatEnd */
                     NegTest:
                        sxth f16Mult1, f16Mult1               /* f16Mult1 = 0xFFFF8000 */
                        cmp f16Mult1, f16Accum                /* Compares f16Accum with 0xFFFF8000 */
                        ble SatEnd                            /* If f16Accum >= 0xFFFF8000, then goes to SatEnd */
                        mov f16Accum, f16Mult1                /* If f16Accum < 0xFFFF8000, then f16Mult1 = 0xFFFF8000 */
                     SatEnd: };
    #elif defined(__GNUC__) && defined(__ARMCC_VERSION) 
        __asm volatile(
                        "sxth %0, %0 \n\t"                    /* Converts 16-bit input to 32-bit */
                        "sxth %1, %1 \n\t"                    /* Converts 16-bit input to 32-bit */
                        "sxth %2, %2 \n\t"                    /* Converts 16-bit input to 32-bit */
                        "muls %1, %1, %2 \n\t"                /* f16Mult1 * f16Mult2 */
                        "asrs %1, %1, #7 \n\t"                /* f16Mult1 >> 7 */
                        "adds %1, %1, #128 \n\t"              /* Rounding */
                        "asrs %1, %1, #8 \n\t"                /* f16Mult1 >> 8 */
                        "subs %0, %0, %1 \n\t"                /* f16Accum - f16Mult1 * f16Mult2 */

                        "movs %1, #128 \n\t"                  /* f16Mult1 = 0x80 */
                        "lsls %1, %1, #8 \n\t"                /* f16Mult1 = 0x8000 */

                        "cmp %1, %0 \n\t"                     /* Compares f16Accum with 0x8000 */
                        "bgt MLIB_MsuRndSat_F16_NegTest%= \n\t" /* If f16Accum < 0x8000, then jumps through two commands */
                        "subs %0, %1, #1 \n\t"                /* If f16Accum >= 0x8000, then f16Accum = 0x7FFF */
                        "b MLIB_MsuRndSat_F16_SatEnd%= \n\t"    /* Jumps through four commands */
                    "MLIB_MsuRndSat_F16_NegTest%=: \n\t"
                        "sxth %1, %1 \n\t"                    /* f16Mult1 = 0xFFFF8000 */
                        "cmp %1, %0 \n\t"                     /* Compares f16Accum with 0xFFFF8000 */
                        "ble MLIB_MsuRndSat_F16_SatEnd%= \n\t"  /* If f16Accum >= 0xFFFF8000, then jumps through next commands */
                        "mov %0, %1 \n\t"                     /* If f16Accum < 0xFFFF8000, then f16Accum = 0xFFFF8000 */
                    "MLIB_MsuRndSat_F16_SatEnd%=: \n\t"
                        : "+l"(f16Accum), "+l"(f16Mult1), "+l"(f16Mult2):);
    #else
        __asm volatile(
                        #if defined(__GNUC__)                 /* For GCC compiler */
                            ".syntax unified \n"              /* Using unified asm syntax */
                        #endif
                        "sxth %0, %0 \n"                      /* Converts 16-bit input to 32-bit */
                        "sxth %1, %1 \n"                      /* Converts 16-bit input to 32-bit */
                        "sxth %2, %2 \n"                      /* Converts 16-bit input to 32-bit */
                        "muls %1, %1, %2 \n"                  /* f16Mult1 * f16Mult2 */
                        "asrs %1, %1, #7 \n"                  /* f16Mult1 >> 7 */
                        "adds %1, %1, #128 \n"                /* Rounding */
                        "asrs %1, %1, #8 \n"                  /* f16Mult1 >> 8 */
                        "subs %0, %0, %1 \n"                  /* f16Accum - f16Mult1 * f16Mult2 */

                        "movs %1, #128 \n"                    /* f16Mult1 = 0x80 */
                        "lsls %1, %1, #8 \n"                  /* f16Mult1 = 0x8000 */

                        "cmp %1, %0 \n"                       /* Compares f16Accum with 0x8000 */
                        "bgt .+6 \n"                          /* If f16Accum < 0x8000, then jumps through two commands */
                        "subs %0, %1, #1 \n"                  /* If f16Accum >= 0x8000, then f16Accum = 0x7FFF */
                        "b .+10 \n"                           /* Jumps through four commands */
                        "sxth %1, %1 \n"                      /* f16Mult1 = 0xFFFF8000 */
                        "cmp %1, %0 \n"                       /* Compares f16Accum with 0xFFFF8000 */
                        "ble .+4 \n"                          /* If f16Accum >= 0xFFFF8000, then jumps through next commands */
                        "mov %0, %1 \n"                       /* If f16Accum < 0xFFFF8000, then f16Accum = 0xFFFF8000 */
                        #if defined(__GNUC__)                 /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f16Accum), "+l"(f16Mult1), "+l"(f16Mult2):);
    #endif

    return f16Accum;
}
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_RESTORE 

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_MSURND_F16_ASM_H_ */
