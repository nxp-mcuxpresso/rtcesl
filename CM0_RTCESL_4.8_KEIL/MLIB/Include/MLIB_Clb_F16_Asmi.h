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
* @brief  Count of leading bits
* 
*******************************************************************************/
#ifndef _MLIB_CLB_F16_ASM_H_
#define _MLIB_CLB_F16_ASM_H_

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
#define MLIB_Clb_U16s_Asmi(f16Val) MLIB_Clb_U16s_FAsmi(f16Val)
  
/***************************************************************************//*!
* Count of leading bits
*  - first, if input < 0, the Bitwise NOT of the input is calculated
*  - then the amount of zero bits before the first non-zero bits is counted (sign bit is not included)
****************************************************************************/
/* inline function without any optimization (compilation issue) */              
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET       
static inline uint16_t MLIB_Clb_U16s_FAsmi(register frac16_t f16Val)
{
    register frac16_t f16Clb = 0;                        /* Initialization of f16Clb */

    #if defined(__CC_ARM)                                /* For ARM Compiler */
        __asm volatile{ sxth f16Val, f16Val              /* Transforms 16-bit input to 32-bit */
                        cmp f16Val, #0                   /* Compares f16Val with 0 */
                        bgt NotNeg                       /* If f16Val > 0, then goes to NotNeg */
                        mvns f16Val, f16Val              /* If f16Val <= 0, then Bitwise NOT of f16Val */
                        bne NotNeg                       /* If f16Val <> 0, then go to NotNeg */
                        subs f16Val, f16Val, #1          /* f16Val = f16Val - 1 */
                    NotNeg:
                        cmp f16Val, #0xFF                /* Compares f16Val with 0xFF */
                        ble Cmp1                         /* If f16Val <= 0xFF, then goes to Cmp1 */
                        movs f16Clb, #8                  /* f16Clb = 8 */
                        lsrs f16Val, f16Val, #8          /* f16Val >> 8 */
                    Cmp1:
                        cmp f16Val, #0xF                 /* Compares f16Val with 0xF */
                        ble Cmp2                         /* If f16Val <= 0xF, then goes to Cmp2 */
                        adds f16Clb, #4                  /* f16Clb = f16Clb + 4 */
                        lsrs f16Val, f16Val, #4          /* f16Val >> 4 */
                    Cmp2:
                        cmp f16Val, #0x3                 /* Compares f16Val with 0x3 */
                        ble Cmp3                         /* If f16Val <= 0x3, then goes to Cmp3 */
                        adds f16Clb, #2                  /* f16Clb = f16Clb + 2 */
                        lsrs f16Val, f16Val, #2          /* f16Val >> 2 */
                    Cmp3:
                        lsrs f16Val, f16Val, #1          /* f16Val >> 1 */
                        orrs f16Clb, f16Clb, f16Val      /* f16Clb = f16Clb |= f16Val */
                        movs f16Val, #14                 /* f16Val = 14 */
                        subs f16Val, f16Val, f16Clb};    /* f16Val = 14 - f16Clb */
    #elif defined(__GNUC__) && defined(__ARMCC_VERSION) 
        __asm volatile(
                        "sxth %0, %0 \n\t"               /* Transforms 16-bit input to 32-bit */
                        "cmp %0,#0 \n\t"                 /* Compares f16Val with 0 */
                        "bgt MLIB_Clb_U16s_NotNeg%= \n\t"  /* If f16Val > 0, then jumps through three commands */
                        "mvns %0, %0 \n\t"               /* If f16Val <= 0, then Bitwise NOT of f16Val */
                        "bne MLIB_Clb_U16s_NotNeg%= \n\t"  /* If f16Val <> 0, then jumps through the next command */
                        "subs %0, %0, #1 \n\t"           /* f16Val = f16Val - 1 */
					"MLIB_Clb_U16s_NotNeg%=: \n\t"
                        "cmp %0, #0xFF \n\t"             /* Compares f16Val with 0xFF */
                        "ble MLIB_Clb_U16s_Cmp1%= \n\t"    /* If f16Val <= 0xFF, then jumps through two commands */
                        "movs %1, #8 \n\t"               /* f16Clb = f16Clb + 8 */
                        "lsrs %0, %0, #8 \n\t"           /* f16Val >> 8 */
					"MLIB_Clb_U16s_Cmp1%=: \n\t"
                        "cmp %0, #0xF \n\t"              /* Compares f16Val with 0xF */
                        "ble MLIB_Clb_U16s_Cmp2%= \n\t"    /* If f16Val <= 0xF, then jumps through two commands */
                        "adds %1, #4 \n\t"               /* f16Clb = f16Clb + 4 */
                        "lsrs %0, %0, #4 \n\t"           /* f16Val >> 4 */
					"MLIB_Clb_U16s_Cmp2%=: \n\t"
                        "cmp %0, #0x3 \n\t"              /* Compares f16Val with 0x3 */
                        "ble MLIB_Clb_U16s_Cmp3%= \n\t"    /* If f16Val <= 0x3, then jumps through two commands */
                        "adds %1, #2 \n\t"               /* f16Clb = f16Clb + 2 */
                        "lsrs %0, %0, #2 \n\t"           /* f16Val >> 2 */
					"MLIB_Clb_U16s_Cmp3%=: \n\t"
                        "lsrs %0, %0, #1 \n\t"           /* f16Val >> 1 */
                        "orrs %1, %1, %0 \n\t"           /* f16Clb = f16Clb | f16Val */
                        "movs %0, #14 \n\t"              /* f16Val = 14 */
                        "subs %0, %0, %1 \n\t"           /* f16Val = 14 - f16Clb */

                        : "+l"(f16Val), "+l"(f16Clb):);
    #else
        __asm volatile(
                        #if defined(__GNUC__)            /* For GCC compiler */
                            ".syntax unified \n"         /* Using unified asm syntax */
                        #endif  
                        "sxth %0, %0 \n"                 /* Transforms 16-bit input to 32-bit */
                        "cmp %0,#0 \n"                   /* Compares f16Val with 0 */
                        "bgt .+8 \n"                     /* If f16Val > 0, then jumps through three commands */
                        "mvns %0, %0 \n"                 /* If f16Val <= 0, then Bitwise NOT of f16Val */
                        "bne .+4 \n"                     /* If f16Val <> 0, then jumps through the next command */
                        "subs %0, %0, #1 \n"             /* f16Val = f16Val - 1 */
  
                        "cmp %0, #0xFF \n"               /* Compares f16Val with 0xFF */
                        "ble .+6 \n"                     /* If f16Val <= 0xFF, then jumps through two commands */
                        "movs %1, #8 \n"                 /* f16Clb = f16Clb + 8 */
                        "lsrs %0, %0, #8 \n"             /* f16Val >> 8 */
  
                        "cmp %0, #0xF \n"                /* Compares f16Val with 0xF */
                        "ble .+6 \n"                     /* If f16Val <= 0xF, then jumps through two commands */
                        "adds %1, #4 \n"                 /* f16Clb = f16Clb + 4 */
                        "lsrs %0, %0, #4 \n"             /* f16Val >> 4 */
  
                        "cmp %0, #0x3 \n"                /* Compares f16Val with 0x3 */
                        "ble .+6 \n"                     /* If f16Val <= 0x3, then jumps through two commands */
                        "adds %1, #2 \n"                 /* f16Clb = f16Clb + 2 */
                        "lsrs %0, %0, #2 \n"             /* f16Val >> 2 */
  
                        "lsrs %0, %0, #1 \n"             /* f16Val >> 1 */
                        "orrs %1, %1, %0 \n"             /* f16Clb = f16Clb | f16Val */
  
                        "movs %0, #14 \n"                /* f16Val = 14 */
                        "subs %0, %0, %1 \n"             /* f16Val = 14 - f16Clb */
                        #if defined(__GNUC__)            /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f16Val), "+l"(f16Clb):);
    #endif

    return (uint16_t)f16Val;
}
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_RESTORE     

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_CLB_F16_ASM_H_ */
