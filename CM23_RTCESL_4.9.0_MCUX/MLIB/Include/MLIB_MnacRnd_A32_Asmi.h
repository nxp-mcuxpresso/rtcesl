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
* @brief  Multiply negate accumulate with rounding
* 
*******************************************************************************/
#ifndef _MLIB_MNACRND_A32_ASM_H_
#define _MLIB_MNACRND_A32_ASM_H_

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
#define MLIB_MnacRnd_A32ass_Asmi(a32Accum, f16Mult1, f16Mult2)                 \
        MLIB_MnacRnd_A32ass_FAsmi(a32Accum, f16Mult1, f16Mult2)
  
/***************************************************************************//*!
*
* a32Out = - a32Accum + ( f16Mult1 * f16Mult2)
*
*******************************************************************************/  
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET
static inline acc32_t MLIB_MnacRnd_A32ass_FAsmi(register acc32_t a32Accum, 
                                                register frac16_t f16Mult1, register frac16_t f16Mult2)
{
    #if defined(__CC_ARM)                                    /* For ARM Compiler */
        __asm volatile{ sxth f16Mult1, f16Mult1              /* Converts 16-bit input to 32-bit */
                        sxth f16Mult2, f16Mult2              /* Converts 16-bit input to 32-bit */
                        muls f16Mult1, f16Mult1, f16Mult2    /* f16Mult1 * f16Mult2 */
                        asrs f16Mult1, f16Mult1, #7          /* f16Mult1 >> 7 for fractional multiplication */
                        adds f16Mult1, f16Mult1, #128        /* Rounding */
                        asrs f16Mult1, f16Mult1, #8          /* f16Mult1 >> 8 for fractional multiplication */
                        subs a32Accum, f16Mult1, a32Accum }; /* f16Mult1 * f16Mult2 - a32Accum*/
    #elif defined(__GNUC__) && defined(__ARMCC_VERSION) 
        __asm volatile(
                        "sxth %1, %1 \n\t"                   /* Converts 16-bit input to 32-bit */
                        "sxth %2, %2 \n\t"                   /* Converts 16-bit input to 32-bit */
                        "muls %1, %1, %2 \n\t"               /* f16Mult1 * f16Mult2 */
                        "asrs %1, %1, #7 \n\t"               /* f16Mult1 >> 7 for fractional multiplication */
                        "adds %1, %1, #128 \n\t"             /* Rounding */
                        "asrs %1, %1, #8 \n\t"               /* f16Mult1 >> 8 for fractional multiplication */
                        "subs %0, %1, %0 \n\t"               /* f16Mult1 * f16Mult2 - a32Accum*/
                        : "+l"(a32Accum), "+l"(f16Mult1), "+l"(f16Mult2):);
    #else
        __asm volatile(
                        #if defined(__GNUC__)                /* For GCC compiler */
                            ".syntax unified \n"             /* Using unified asm syntax */
                        #endif 
                        "sxth %1, %1 \n"                     /* Converts 16-bit input to 32-bit */
                        "sxth %2, %2 \n"                     /* Converts 16-bit input to 32-bit */
                        "muls %1, %1, %2 \n"                 /* f16Mult1 * f16Mult2 */
                        "asrs %1, %1, #7 \n"                 /* f16Mult1 >> 7 for fractional multiplication */
                        "adds %1, %1, #128 \n"               /* Rounding */
                        "asrs %1, %1, #8 \n"                 /* f16Mult1 >> 8 for fractional multiplication */
                        "subs %0, %1, %0 \n"                 /* f16Mult1 * f16Mult2 - a32Accum*/
                        #if defined(__GNUC__)                /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(a32Accum), "+l"(f16Mult1), "+l"(f16Mult2):);
    #endif

    return a32Accum;
}
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_RESTORE 

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_MNACRND_A32_ASM_H_ */
