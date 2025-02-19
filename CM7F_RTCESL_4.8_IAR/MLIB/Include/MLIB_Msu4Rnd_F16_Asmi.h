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
* @brief  Multiply subtract of four inputs with rounding
* 
*******************************************************************************/
#ifndef _MLIB_MSU4RND_F16_ASM_H_
#define _MLIB_MSU4RND_F16_ASM_H_


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
#define MLIB_Msu4RndSat_F16_Asmi(f16MinMul1, f16MinMul2, f16SubMul1, f16SubMul2) \
        MLIB_Msu4RndSat_F16_FAsmi(f16MinMul1, f16MinMul2, f16SubMul1, f16SubMul2)
  
/***************************************************************************//*!
*
* f16Out = (f16MinMul1 * f16MinMul2) - (f16SubMul1 * f16SubMul2)
* With saturation
*******************************************************************************/
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET 
RAM_FUNC_LIB 
RTCESL_INLINE static inline frac16_t MLIB_Msu4RndSat_F16_FAsmi(register frac16_t f16MinMul1, register frac16_t f16MinMul2, 
                                                 register frac16_t f16SubMul1, register frac16_t f16SubMul2)
{
    #if defined(__CC_ARM)                                            /* For ARM Compiler */
        __asm volatile{ smulbb f16MinMul1, f16MinMul1, f16MinMul2    /* f16MinMul1 * f16MinMul2 */
                        smulbb f16SubMul1, f16SubMul1, f16SubMul2    /* f16SubMul1 * f16SubMul2 */
                        add f16MinMul1, f16MinMul1, #0x4000          /* Rounding */
                        qsub f16MinMul1, f16MinMul1, f16SubMul1      /* Addition with saturation */
                        ssat f16MinMul1, #16, f16MinMul1, asr #15 }; /* Result = Result * 2 */
    #else
        __asm volatile( 
                        #if defined(__GNUC__) && !defined(__ARMCC_VERSION)            /* For GCC compiler */
                            ".syntax unified \n"                     /* Using unified asm syntax */
                        #endif
                        "smulbb %0, %0, %2 \n"                       /* f16MinMul1 * f16MinMul2 */
                        "smulbb %1, %1, %3 \n"                       /* f16SubMul1 * f16SubMul2 */
                        "add %0, %0, #0x4000 \n"                     /* Rounding */
                        "qsub %0, %0, %1 \n"                         /* Addition with saturation */
                        "ssat %0, #16, %0, asr #15 \n"               /* Result = Result * 2 */
                        #if defined(__GNUC__) && !defined(__ARMCC_VERSION)            /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f16MinMul1), "+l"(f16SubMul1): "l"(f16MinMul2), "l"(f16SubMul2));
    #endif

    return f16MinMul1;
}
RTCESL_INLINE_OPTIM_RESTORE 

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_MSU4RND_F16_ASM_H_ */
