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
* @brief  Subtraction of three input values from the first input
* 
*******************************************************************************/
#ifndef _MLIB_SUB4_F16_ASM_H_
#define _MLIB_SUB4_F16_ASM_H_

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
#define MLIB_Sub4_F16_Asmi(f16Min, f16Sub1, f16Sub2, f16Sub3)                   \
        MLIB_Sub4_F16_FAsmi(f16Min, f16Sub1, f16Sub2, f16Sub3)
#define MLIB_Sub4Sat_F16_Asmi(f16Min, f16Sub1, f16Sub2, f16Sub3)                \
        MLIB_Sub4Sat_F16_FAsmi(f16Min, f16Sub1, f16Sub2, f16Sub3)

/***************************************************************************//*!
*  Subtraction of three input values from the first input
*     f16Out = f16Min - f16Sub1 - f16Sub2 - f16Sub3
*  function is not saturated
*******************************************************************************/
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET 
RAM_FUNC_LIB 
RTCESL_INLINE static inline frac16_t MLIB_Sub4_F16_FAsmi(register frac16_t f16Min, register frac16_t f16Sub1,
                                           register frac16_t f16Sub2, register frac16_t f16Sub3)
{
    #if defined(__CC_ARM)                              /* For ARM Compiler */
        __asm volatile{sub f16Min, f16Min, f16Sub1     /* f16Min = f16Min - f16Sub1 */
                       sub f16Min, f16Min, f16Sub2     /* f16Min = f16Min - f16Sub2 */
                       sub f16Min, f16Min, f16Sub3};   /* f16Min = f16Min - f16Sub3 */
    #else
        __asm volatile( 
                        #if defined(__GNUC__) && !defined(__ARMCC_VERSION)  /* For GCC compiler */
                            ".syntax unified \n"           /* Using unified asm syntax */
                        #endif
                        "sub %0, %0, %1 \n"            /* f16Min = f16Min - f16Sub1 */
                        "sub %0, %0, %2 \n"            /* f16Min = f16Min - f16Sub2 */
                        "sub %0, %0, %3 \n"            /* f16Min = f16Min - f16Sub3 */
                        : "+l"(f16Min): "l"(f16Sub1), "l"(f16Sub2), "l"(f16Sub3));
    #endif

    return f16Min;
}
RTCESL_INLINE_OPTIM_RESTORE 

/***************************************************************************//*!
*  Subtraction of three input values from the first input
*     f16Out = f16Min - f16Sub1 - f16Sub2 - f16Sub3
*  function is saturated
*******************************************************************************/
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET 
RAM_FUNC_LIB 
RTCESL_INLINE static inline frac16_t MLIB_Sub4Sat_F16_FAsmi(register frac16_t f16Min, register frac16_t f16Sub1,
                                              register frac16_t f16Sub2, register frac16_t f16Sub3)
{        
    #if defined(__CC_ARM)                                   /* For ARM Compiler */
        __asm volatile{ sxth f16Min, f16Min                 /* Transforms 16-bit input f16Val to 32-bit */
                        sxth f16Sub1, f16Sub1               /* Transforms 16-bit input f16Val to 32-bit */
                        sxth f16Sub2, f16Sub2               /* Transforms 16-bit input f16Val to 32-bit */
                        sxth f16Sub3, f16Sub3               /* Transforms 16-bit input f16Val to 32-bit */
                        sub f16Min, f16Min, f16Sub2         /* f16Min - f16Sub2 */
                        add f16Sub1, f16Sub1, f16Sub3       /* f16Sub1 + f16Sub3 */
                        sub f16Min, f16Min, f16Sub1         /* f16Min - f16Sub2 - f16Sub1 - f16Sub3 */
                        ssat f16Min, #16, f16Min };         /* Saturation */
    #else
        __asm volatile( 
                        #if defined(__GNUC__) && !defined(__ARMCC_VERSION)   /* For GCC compiler */
                            ".syntax unified \n"            /* Using unified asm syntax */
                        #endif
                        "sxth %0, %0 \n"                    /* Transforms 16-bit input f16Val to 32-bit */
                        "sxth %1, %1 \n"                    /* Transforms 16-bit input f16Val to 32-bit */
                        "sxth %2, %2 \n"                    /* Transforms 16-bit input f16Val to 32-bit */
                        "sxth %3, %3 \n"                    /* Transforms 16-bit input f16Val to 32-bit */
                        "sub %0, %0, %2 \n"                 /* f16Min - f16Sub2 */
                        "add %1, %1, %3 \n"                 /* f16Sub1 + f16Sub3 */
                        "sub %0, %0, %1 \n"                 /* f16Min - f16Sub2 - f16Sub1 - f16Sub3 */
                        "ssat %0, #16, %0 \n"               /* Saturation */
                        #if defined(__GNUC__) && !defined(__ARMCC_VERSION)   /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f16Min), "+l"(f16Sub1), "+l"(f16Sub2), "+l"(f16Sub3):);
    #endif

    return f16Min;
}
RTCESL_INLINE_OPTIM_RESTORE 

#if defined(__cplusplus)
}
#endif /* _MLIB_SUB4_F16_ASM_H_ */

#endif 
