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
* @brief  Sign
* 
*******************************************************************************/
#ifndef _MLIB_SIGN_F16_ASM_H_
#define _MLIB_SIGN_F16_ASM_H_

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
#define MLIB_Sign_F16_Asmi(f16Val) MLIB_Sign_F16_FAsmi(f16Val)

/***************************************************************************//*!
*   This function returns the sign of the argument:
*           f16Val = 0: returns 0
*           f16Val > 0: returns 32767 (fractional 1.0)
*           f16Val < 0: returns -32768 (fractional -1.0)
*
*******************************************************************************/
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET
static inline frac16_t MLIB_Sign_F16_FAsmi(register frac16_t f16Val)
{
    register frac16_t f16SigVal = (frac16_t)0x8000U;
    #if defined(__CC_ARM)                                 /* For ARM Compiler */
        __asm volatile{ lsls f16Val, f16Val, #16          /* f16Val << 16 */
                        bpl Next                          /* If f16Val >= 0, then goes to Next */
                        sxth f16Val, f16SigVal            /* If f16Val < 0, then f16Val = 0xFFFF8000 */
                        b SignEnd                         /* Goes to SignEnd */
                    Next:  
                        beq SignEnd                       /* If f16Val = 0, then goes to SignEnd */
                        subs f16Val, f16SigVal, #1        /* If f16Val > 0, then f16Val = 0x00007FFF */
                    SignEnd: };
    #elif defined(__GNUC__) && defined(__ARMCC_VERSION) 
        __asm volatile(
                        "lsls %0, %0, #16 \n\t"          /* f16Val << 16 */
                        "bpl MLIB_Sign_F16_Next%= \n\t"    /* If f16Val >= 0, then jumps through two commands */
                        "sxth %0, %1 \n\t"               /* If f16Val < 0, then f16Val = 0xFFFF8000 */
                        "b MLIB_Sign_F16_SignEnd%= \n\t"   /* Jumps to the end of function */
                    "MLIB_Sign_F16_Next%=: \n\t"  
						"beq MLIB_Sign_F16_SignEnd%= \n\t" /* If f16Val = 0, then jumps through next command */
                        "subs %0, %1, #1 \n\t"           /* If f16Val > 0, then f16Val = 0x00007FFF */
					"MLIB_Sign_F16_SignEnd%=: \n\t"
                        : "+l"(f16Val): "l"(f16SigVal));
    #else
        __asm volatile(
                        #if defined(__GNUC__)            /* For GCC compiler */
                            ".syntax unified \n"         /* Using unified asm syntax */
                        #endif 
                        "lsls %0, %0, #16 \n"            /* f16Val << 16 */
                        "bpl .+6 \n"                     /* If f16Val >= 0, then jumps through two commands */
                        "sxth %0, %1 \n"                 /* If f16Val < 0, then f16Val = 0xFFFF8000 */
                        "b .+6 \n"                       /* Jumps to the end of function */
                        "beq .+4 \n"                     /* If f16Val = 0, then jumps through next command */
                        "subs %0, %1, #1 \n"             /* If f16Val > 0, then f16Val = 0x00007FFF */
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f16Val): "l"(f16SigVal));
    #endif

    return f16Val;
}
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_RESTORE 

#if defined(__cplusplus)
}
#endif

#endif  /* _MLIB_SIGN_F16_ASM_H_ */
