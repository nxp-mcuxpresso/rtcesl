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
* @brief  Addition
* 
*******************************************************************************/
#ifndef _MLIB_ADD_A32_ASM_H_
#define _MLIB_ADD_A32_ASM_H_

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
#define MLIB_Add_A32ss_Asmi(f16Add1, f16Add2) MLIB_Add_A32ss_FAsmi(f16Add1, f16Add2)
#define MLIB_Add_A32as_Asmi(a32Accum, f16Add) MLIB_Add_A32as_FAsmi(a32Accum, f16Add)

/***************************************************************************//*!
*  Addition        
*  Output = f16Add1 + f16Add2
*  Result can overflow through fractional range and is stored in accumulator type
*******************************************************************************/
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET
static inline acc32_t MLIB_Add_A32ss_FAsmi(register frac16_t f16Add1, register frac16_t f16Add2)
{ 
    register acc32_t a32Val=0;
    #if defined(__CC_ARM)                               /* For ARM Compiler */
        __asm volatile{ sxth f16Add1, f16Add1           /* Transforms 16-bit input f16Add2 to 32-bit */
                        sxth f16Add2, f16Add2           /* Transforms 16-bit input f16Add2 to 32-bit */
                        adds a32Val, f16Add1, f16Add2}; /* f16Add1 = f16Add1 + f16Add2 */
    #elif defined(__GNUC__) && defined(__ARMCC_VERSION) 
        __asm volatile(
                        "sxth %1, %1 \n\t"              /* Transforms 16-bit input f16Add2 to 32-bit */
                        "sxth %2, %2 \n\t"              /* Transforms 16-bit input f16Add2 to 32-bit */
                        "adds %0, %1, %2 \n\t"          /* f16Add1 = f16Add1 + f16Add2 */
                        : "=l"(a32Val), "+l"(f16Add1), "+l"(f16Add2):);
    #else
        __asm volatile(
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax unified \n"        /* Using unified asm syntax */
                        #endif
                        "sxth %1, %1 \n"                /* Transforms 16-bit input f16Add2 to 32-bit */
                        "sxth %2, %2 \n"                /* Transforms 16-bit input f16Add2 to 32-bit */
                        "adds %0, %1, %2 \n"            /* f16Add1 = f16Add1 + f16Add2 */
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "=l"(a32Val), "+l"(f16Add1), "+l"(f16Add2):);
    #endif

    return a32Val;
}
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_RESTORE 

/***************************************************************************//*!
*  Addition        
*  Output = a32Accum + f16Add
*  Result can overflow through fractional range and is stored in accumulator type
*******************************************************************************/
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET
static inline acc32_t MLIB_Add_A32as_FAsmi(register acc32_t a32Accum, register frac16_t f16Add)
{ 
    #if defined(__CC_ARM)                                 /* For ARM Compiler */
        __asm volatile{ sxth f16Add, f16Add               /* Transforms 16-bit input f16Add2 to 32-bit */
                        adds a32Accum, a32Accum, f16Add}; /* f16Add1 = f16Add1 + f16Add2 */
    #elif defined(__GNUC__) && defined(__ARMCC_VERSION) 
        __asm volatile(
                        "sxth %1, %1 \n\t"                /* Transforms 16-bit input f16Add2 to 32-bit */
                        "adds %0, %0, %1 \n\t"            /* a32Accum = a32Accum + f16Add2 */
                        : "+l"(a32Accum), "+l"(f16Add):);
    #else
        __asm volatile(
                        #if defined(__GNUC__)             /* For GCC compiler */
                            ".syntax unified \n"          /* Using unified asm syntax */
                        #endif
                        "sxth %1, %1 \n"                  /* Transforms 16-bit input f16Add2 to 32-bit */
                        "adds %0, %0, %1 \n"              /* a32Accum = a32Accum + f16Add2 */
                        #if defined(__GNUC__)             /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(a32Accum), "+l"(f16Add):);
    #endif

    return a32Accum;
}
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_RESTORE 

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_ADD_A32_ASM_H_*/
