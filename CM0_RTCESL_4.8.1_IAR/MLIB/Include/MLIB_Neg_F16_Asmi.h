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
* @brief  Negation
* 
*******************************************************************************/
#ifndef _MLIB_NEG_F16_ASM_H_
#define _MLIB_NEG_F16_ASM_H_

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
#define MLIB_NegSat_F16_Asmi(f16Val) MLIB_NegSat_F16_FAsmi(f16Val)

/***************************************************************************//*!
*
* Output = -f16Val
* With saturation
*******************************************************************************/
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET
static inline frac16_t MLIB_NegSat_F16_FAsmi(register frac16_t f16Val)
{
    register frac32_t f32SatVal = 0x8000;
    #if defined(__CC_ARM)                                 /* For ARM Compiler */
        __asm volatile{ sxth f16Val, f16Val               /* Transforms 16-bit input f16Val to 32-bit */
                        rsbs f16Val, f16Val, #0           /* f16Val = - f16Val */
                        cmp f16Val, f32SatVal             /* Compares f16Val with 0x00008000 */
                        bne SatEnd                        /* If f32Val != 0x8000, then goes to SatEnd */
                        subs f16Val, f16Val, #1           /* Compares f16Val with 0x00008000 */
        SatEnd: };
    #elif defined(__GNUC__) && defined(__ARMCC_VERSION) 
        __asm volatile(
                        "sxth %0, %0 \n\t"                /* Transforms 16-bit input f16Val to 32-bit */
                        "rsbs %0, %0, #0 \n\t"            /* f16Val = - f16Val */
                        "cmp %0, %1 \n\t"                 /* Compares f16Val with 0x00008000 */
                        "bne MLIB_NegSat_F16_SatEnd%= \n\t" /* If f32Val != 0x8000, then jumps through next command */
                        "subs %0, %0, #1 \n\t"            /* Compares f16Val with 0x00008000 */
                    "MLIB_NegSat_F16_SatEnd%=: \n\t"    
                        : "+l"(f16Val): "l"(f32SatVal));
    #else
        __asm volatile(
                        #if defined(__GNUC__)             /* For GCC compiler */
                            ".syntax unified \n"          /* Using unified asm syntax */
                        #endif  
                        "sxth %0, %0 \n"                  /* Transforms 16-bit input f16Val to 32-bit */
                        "rsbs %0, %0, #0 \n"              /* f16Val = - f16Val */
                        "cmp %0, %1 \n"                   /* Compares f16Val with 0x00008000 */
                        "bne .+4 \n"                      /* If f32Val != 0x8000, then jumps through next command */
                        "subs %0, %0, #1 \n"              /* Compares f16Val with 0x00008000 */
                        #if defined(__GNUC__)             /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f16Val): "l"(f32SatVal));
    #endif

    return f16Val;
}
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_RESTORE 

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_NEG_F16_ASM_H_ */
