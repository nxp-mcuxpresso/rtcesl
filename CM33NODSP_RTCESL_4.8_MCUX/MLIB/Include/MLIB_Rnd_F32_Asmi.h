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
* @brief  Rounding
* 
*******************************************************************************/
#ifndef _MLIB_RND_F32_ASM_H_
#define _MLIB_RND_F32_ASM_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "mlib_types.h"
#include "MLIB_Add_F32.h"

/*******************************************************************************
* Macros
*******************************************************************************/
#define MLIB_RndSat_F16l_Asmi(f32Val) MLIB_RndSat_F16l_FAsmi(f32Val)

/***************************************************************************//*!
*
* Converts 32-bit number into 16-bit with rounding
* With saturation
*******************************************************************************/  
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET
static inline frac16_t MLIB_RndSat_F16l_FAsmi(register frac32_t f32Val)
{
    register frac32_t f32Rnd = 0x80;
    #if defined(__CC_ARM)                                   /* For ARM Compiler */
        __asm volatile{ asrs f32Val, f32Val, #8             /* f32Val >> 8 */
                        adds f32Val, f32Val, f32Rnd         /* f32Val = f32Val + 0x80 */
                        lsls f32Rnd, f32Rnd, #8             /* f32Rnd = 0x00008000 */
                        asrs f32Val, f32Val, #8             /* f32Val >> 8 */
    
                        cmp f32Val, f32Rnd                  /* Compares f32Val with 0x00008000 */
                        bge NegTest                         /* If f32Val <= 0x8000, then goes to NegTest */
                        subs f32Rnd, f32Val, #1             /* If f32Val > 0x8000, then f32Val = 0x7FFF */
                        b SatEnd                            /* Go to SatEnd */
                    NegTest:    
                        mvns f32Val, f32Val                 /* f32Rnd = 0xFFFF7FFF */
                        cmp f32Val, f32Rnd                  /* Compares f32Val with 0xFFFF7FFF */
                        ble SatEnd                          /* If f32Val >= 0xFFFF7FFF, then goes to SatEnd */
                        adds f32Rnd, f32Val, #1             /* If f32Val < 0xFFFF7FFF, then f32Val = 0xFFFF8000 */
                    SatEnd: }
    #elif defined(__GNUC__) && defined(__ARMCC_VERSION) 
        __asm volatile(
                        "asrs %0,%0, #8 \n\t"               /* f32Val >> 8 */
                        "adds %0, %0, %1 \n\t"              /* f32Val = f32Val + 0x80 */
                        "lsls %1, %1, #8 \n\t"              /* f32Rnd = 0x00008000 */
                        "asrs %0, %0, #8 \n\t"              /* f32Val >> 8 */
  
                        "cmp %0, %1 \n\t"                   /* Compares f32Val with 0x00008000 */
                        "bge MLIB_RndSat_F16l_NegTest%= \n\t" /* If f32Val <= 0x8000, then jumps through two commands */
                        "subs %1, %0, #1 \n\t"              /* If f32Val > 0x8000, then f32Val = 0x7FFF */
                        "b MLIB_RndSat_F16l_SatEnd%= \n\t"    /* Jumps through four commands */
                    "MLIB_RndSat_F16l_NegTest%=: \n\t"     
						"mvns %0, %0 \n\t"                  /* f32Rnd = 0xFFFF7FFF */
                        "cmp %0, %1 \n\t"                   /* Compares f32Val with 0xFFFF7FFF */
                        "ble MLIB_RndSat_F16l_SatEnd%= \n\t"  /* If f32Val >= 0xFFFF7FFF, then jumps through next commands */
                        "adds %1, %0, #1 \n\t"              /* If f32Val < 0xFFFF7FFF, then f32Val = 0xFFFF8000 */
					"MLIB_RndSat_F16l_SatEnd%=: \n\t"
                        : "+l"(f32Val), "+l"(f32Rnd):);
    #else
        __asm volatile(
                        #if defined(__GNUC__)              /* For GCC compiler */
                            ".syntax unified \n"           /* Using unified asm syntax */
                        #endif   
                        "asrs %0,%0, #8 \n"                /* f32Val >> 8 */
                        "adds %0, %0, %1 \n"               /* f32Val = f32Val + 0x80 */
                        "lsls %1, %1, #8 \n"               /* f32Rnd = 0x00008000 */
                        "asrs %0, %0, #8 \n"               /* f32Val >> 8 */
   
                        "cmp %0, %1 \n"                    /* Compares f32Val with 0x00008000 */
                        "bge .+6 \n"                       /* If f32Val <= 0x8000, then jumps through two commands */
                        "subs %1, %0, #1 \n"               /* If f32Val > 0x8000, then f32Val = 0x7FFF */
                        "b .+10 \n"                        /* Jumps through four commands */
                        "mvns %0, %0 \n"                   /* f32Rnd = 0xFFFF7FFF */
                        "cmp %0, %1 \n"                    /* Compares f32Val with 0xFFFF7FFF */
                        "ble .+4 \n"                       /* If f32Val >= 0xFFFF7FFF, then jumps through next commands */
                        "adds %1, %0, #1 \n"               /* If f32Val < 0xFFFF7FFF, then f32Val = 0xFFFF8000 */
   
                        #if defined(__GNUC__)              /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f32Val), "+l"(f32Rnd):);
    #endif

    return (frac16_t)f32Val;
}
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_RESTORE 

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_RND_F32_ASM_H_ */
