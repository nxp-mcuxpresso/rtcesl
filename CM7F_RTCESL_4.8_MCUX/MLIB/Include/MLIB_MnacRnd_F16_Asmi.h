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
#ifndef _MLIB_MNACRND_F16_ASM_H_
#define _MLIB_MNACRND_F16_ASM_H_

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
#define MLIB_MnacRnd_F16_Asmi( f16Accum, f16Mult1, f16Mult2)                   \
        MLIB_MnacRnd_F16_FAsmi( f16Accum, f16Mult1, f16Mult2)
#define MLIB_MnacRndSat_F16_Asmi( f16Accum, f16Mult1, f16Mult2)                \
        MLIB_MnacRndSat_F16_FAsmi( f16Accum, f16Mult1, f16Mult2)

/***************************************************************************//*!
*
* f16Out = - f16Accum + ( f16Mult1 * f16Mult2)
* Without saturation
*******************************************************************************/
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET 
RAM_FUNC_LIB 
RTCESL_INLINE static inline frac16_t MLIB_MnacRnd_F16_FAsmi(register frac16_t f16Accum, 
                                              register frac16_t f16Mult1, register frac16_t f16Mult2)
{
    #if defined(__CC_ARM)                                             /* For ARM Compiler */
        __asm volatile{ sxth f16Accum, f16Accum                       /* Transforms 16-bit input f16Val to 32-bit */
                        smulbb f16Mult1, f16Mult1, f16Mult2           /* f16Mult1 * f16Mult2 */
                        add f16Mult1, f16Mult1, #0x4000               /* Rounding */
                        asr f16Mult1, f16Mult1, #15                   /* f16Mult1 * f16Mult2 >> 15 */ 
                        sub f16Accum, f16Mult1, f16Accum };           /* f16Accum = f16Accum + f16Mult1 * f16Mult2 */
    #else
        __asm volatile( 
                        #if defined(__GNUC__) && !defined(__ARMCC_VERSION)  /* For GCC compiler */
                            ".syntax unified \n"           /* Using unified asm syntax */
                        #endif
                        "sxth %0, %0 \n"                              /* Transforms 16-bit input f16Val to 32-bit */
                        "smulbb %1, %1, %2 \n"                        /* f16Mult1 * f16Mult2 */
                        "add %1, %1, #0x4000 \n"                      /* Rounding */
                        "asr %1, %1, #15 \n"                          /* f16Mult1 * f16Mult2 >> 15 */                           
                        "sub %0, %1, %0 \n"                           /* f16Accum = f16Mult1 * f16Mult2 - f16Accum*/
                        : "+l"(f16Accum), "+l"(f16Mult1): "l"(f16Mult2));
    #endif

    return f16Accum;
}
RTCESL_INLINE_OPTIM_RESTORE 

/***************************************************************************//*!
*
* f16Out = - f16Accum + ( f16Mult1 * f16Mult2)
* With saturation
*******************************************************************************/
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET 
RAM_FUNC_LIB 
RTCESL_INLINE static inline frac16_t MLIB_MnacRndSat_F16_FAsmi(register frac16_t f16Accum,
                                                 register frac16_t f16Mult1, register frac16_t f16Mult2)
{
    #if defined(__CC_ARM)                                         /* For ARM Compiler */
        __asm volatile{ sxth f16Accum, f16Accum                   /* Transforms 16-bit input f16Val to 32-bit */
                        smulbb f16Mult1, f16Mult1, f16Mult2       /* f16Mult1 * f16Mult2 */
                        add f16Mult1, f16Mult1, #0x4000           /* Rounding */
                        asr f16Mult1, f16Mult1, #15               /* f16Mult1 * f16Mult2 >> 15 */ 
                        sub f16Accum, f16Mult1, f16Accum          /* f16Accum = f16Accum + f16Mult1 * f16Mult2 */
                        ssat f16Accum, #16, f16Accum };           /* Saturation */
    #else
        __asm volatile( 
                        #if defined(__GNUC__) && !defined(__ARMCC_VERSION)         /* For GCC compiler */
                            ".syntax unified \n"                  /* Using unified asm syntax */
                        #endif
                        "sxth %0, %0 \n"                          /* Transforms 16-bit input f16Val to 32-bit */
                        "smulbb %1, %1, %2 \n"                    /* f16Mult1 * f16Mult2 */
                        "add %1, %1, #0x4000 \n"                  /* Rounding */
                        "asr %1, %1, #15 \n"                      /* f16Mult1 * f16Mult2 >> 15 */                           
                        "sub %0, %1, %0 \n"                       /* f16Accum = f16Mult1 * f16Mult2 - f16Accum*/
                        "ssat %0, #16, %0 \n"                     /* Saturation */
                        #if defined(__GNUC__) && !defined(__ARMCC_VERSION)         /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f16Accum), "+l"(f16Mult1): "l"(f16Mult2));
    #endif

    return f16Accum;
}
RTCESL_INLINE_OPTIM_RESTORE 

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_MNACRND_F16_ASM_H_ */  
