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
* @brief  Multiply 
* 
*******************************************************************************/
#ifndef _MLIB_MUL_F32_ASM_H_
#define _MLIB_MUL_F32_ASM_H_

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
#define MLIB_MulSat_F32ss_Asmi(f32Mult1, f32Mult2) MLIB_MulSat_F32ss_FAsmi(f32Mult1, f32Mult2)

/***************************************************************************//*!
*
* f32Out = f16Mult1 * f16Mult2
* With saturation
*******************************************************************************/
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET
static inline frac32_t MLIB_MulSat_F32ss_FAsmi(register frac16_t f16Mult1, register frac16_t f16Mult2)
{
    register frac32_t f32Out=0;
    #if defined(__CC_ARM)                                     /* For ARM Compiler */
        __asm volatile{ sxth f16Mult1, f16Mult1               /* Converts 16-bit input to 32-bit */
                        sxth f16Mult2, f16Mult2               /* Converts 16-bit input to 32-bit */
                        muls f32Out, f16Mult1, f16Mult2       /* f32Out = f16Mult1 * f16Mult2 */
                        lsls f32Out, f32Out, #1               /* f32Out << 1 (fractional multiplication) */
                        movs f16Mult2, #128                   /* f16Mult2 = 0x80 */
                        rev f16Mult2, f16Mult2                /* f16Mult2 = 0x80000000 */
                        cmp f32Out, f16Mult2                  /* Compares f32Out with 0x80000000*/
                        bne NotSat                            /* If f32Out <> 0x80000000, then jumps through next command */
                        subs f32Out, f32Out, #1               /* If f32Out = 0x80000000, then f32Out = 0x7FFFFFFF */
                    NotSat: };
    #elif defined(__GNUC__) && defined(__ARMCC_VERSION) 
        __asm volatile(
                        "sxth %2, %2 \n\t"                    /* Converts 16-bit input to 32-bit */
                        "sxth %1, %1 \n\t"                    /* Converts 16-bit input to 32-bit */
                        "muls %2, %2, %1 \n\t"                /* f16Mult2 = f16Mult1 * f16Mult2 */
                        "lsls %0, %2, #1 \n\t"                /* f32Out = f16Mult2 << 1 (fractional multiplication) */
                        "movs %1, #128 \n\t"                  /* f16Mult1 = 0x80 */
                        "rev %1, %1 \n\t"                     /* f16Mult1 = 0x80000000 */
                        "cmp %0, %1 \n\t"                     /* Compares f32Out with 0x80000000*/
                        "bne MLIB_MulSat_F32ss_NotSat%= \n\t"   /* If f32Out <> 0x80000000, then jumps through next command */
                        "subs %0, %0, #1 \n\t"                /* If f32Out = 0x80000000, then f16Mult1 = 0x7FFFFFFF */
					"MLIB_MulSat_F32ss_NotSat%=: \n\t"
                        : "=&l"(f32Out), "+l"(f16Mult1), "+l"(f16Mult2):);
    #else
        __asm volatile(
                        #if defined(__GNUC__)                 /* For GCC compiler */
                            ".syntax unified \n"              /* Using unified asm syntax */
                        #endif  
                        "sxth %2, %2 \n"                      /* Converts 16-bit input to 32-bit */
                        "sxth %1, %1 \n"                      /* Converts 16-bit input to 32-bit */
                        "muls %2, %2, %1 \n"                  /* f16Mult2 = f16Mult1 * f16Mult2 */
                        "lsls %0, %2, #1 \n"                  /* f32Out = f16Mult2 << 1 (fractional multiplication) */
                        "movs %1, #128 \n"                    /* f16Mult1 = 0x80 */
                        "rev %1, %1 \n"                       /* f16Mult1 = 0x80000000 */
                        "cmp %0, %1 \n"                       /* Compares f32Out with 0x80000000*/
                        "bne .+4 \n"                          /* If f32Out <> 0x80000000, then jumps through next command */
                        "subs %0, %0, #1 \n"                  /* If f32Out = 0x80000000, then f16Mult1 = 0x7FFFFFFF */
                        #if defined(__GNUC__)                 /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "=&l"(f32Out), "+l"(f16Mult1), "+l"(f16Mult2):);
    #endif

    return f32Out;
}
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_RESTORE 

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_MUL_F32_ASM_H_ */
