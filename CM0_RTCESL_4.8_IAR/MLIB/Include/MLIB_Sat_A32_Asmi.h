/*******************************************************************************
*
* Copyright 2013-2016 Freescale Semiconductor, Inc.
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
* @brief  Saturation
* 
*******************************************************************************/
#ifndef _MLIB_SAT_A32_ASM_H_
#define _MLIB_SAT_A32_ASM_H_

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
#define MLIB_Sat_F16a_Asmi(a32Accum) MLIB_Sat_F16a_FAsmi(a32Accum)

/***************************************************************************//*!
*
* Takes the fractional part from number in accumulator format and saturate if the original number is greater than 1. 
* 
*******************************************************************************/ 
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET
static inline frac16_t MLIB_Sat_F16a_FAsmi(register acc32_t a32Accum)
{
    register frac16_t f16Val=0;

    #if defined(__CC_ARM)                               /* For ARM Compiler */
        __asm volatile{ sxth f16Val, a32Accum           /* Takes fractional part */
                        cmp f16Val, a32Accum            /* Compares a32Accum and f16Val */
                        beq SatEnd                      /* If a32Accum != f16Val, then saturates output */
                        movs f16Val, #0x80              /* f16Val = 0x80 */
                        lsls f16Val, f16Val, #8         /* f16Val = 0x8000 */
                        subs f16Val, #1                 /* f16Val = 0x7FFF */
                        asrs a32Accum, a32Accum, #31    /* a32Accum >> 31 */
                        subs f16Val, f16Val, a32Accum   /* f16Val = 0x7FFF - a32Accum */
                    SatEnd: };
    #elif defined(__GNUC__) && defined(__ARMCC_VERSION) 
        __asm volatile(
                        "sxth %0, %1 \n\t"              /* Takes fractional part */
                        "cmp %0, %1 \n\t"               /* Compares a32Accum and f16Val */
                        "beq MLIB_Sat_F16a_SatEnd%= \n\t" /* If a32Accum != f16Val, then saturates output */
                        "movs %0, #0x80 \n\t"           /* f16Val = 0x80 */
                        "lsls %0, %0, #8 \n\t"          /* f16Val = 0x8000 */
                        "subs %0, #1 \n\t"              /* f16Val = 0x7FFF */
                        "asrs %1, %1, #31 \n\t"         /* a32Accum >> 31 */
                        "subs %0, %0, %1 \n\t"          /* f16Val = 0x7FFF - a32Accum */
                    "MLIB_Sat_F16a_SatEnd%=:"
                        :"=&l"(f16Val), "+l"(a32Accum):);
    #elif defined(__GNUC__)
        __asm volatile(
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax unified \n"        /* Using unified asm syntax */
                        #endif
                        "sxth %0, %1 \n"                /* Takes fractional part */
                        "cmp %0, %1 \n"                 /* Compares a32Accum and f16Val */
                        "beq SatEnd%= \n"               /* If a32Accum != f16Val, then saturates output */
                        "movs %0, #0x80 \n"             /* f16Val = 0x80 */
                        "lsls %0, %0, #8 \n"            /* f16Val = 0x8000 */
                        "subs %0, #1 \n"                /* f16Val = 0x7FFF */
                        "asrs %1, %1, #31 \n"           /* a32Accum >> 31 */
                        "subs %0, %0, %1 \n"            /* f16Val = 0x7FFF - a32Accum */
                    "SatEnd%=:"
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        :"=&l"(f16Val), "+l"(a32Accum):);
    #else
        __asm volatile(
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax unified \n"        /* Using unified asm syntax */
                        #endif
                        "sxth %0, %1 \n"                /* Takes fractional part */
                        "cmp %0, %1 \n"                 /* Compares a32Accum and f16Val */
                        "beq SatEnd \n"                 /* If a32Accum != f16Val, then saturates output */
                        "movs %0, #0x80 \n"             /* f16Val = 0x80 */
                        "lsls %0, %0, #8 \n"            /* f16Val = 0x8000 */
                        "subs %0, #1 \n"                /* f16Val = 0x7FFF */
                        "asrs %1, %1, #31 \n"           /* a32Accum >> 31 */
                        "subs %0, %0, %1 \n"            /* f16Val = 0x7FFF - a32Accum */
                    "SatEnd:"
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        :"=&l"(f16Val), "+l"(a32Accum):);
    #endif

    return (frac16_t)f16Val;
}
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_RESTORE 

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_SAT_A32_ASM_H_ */
