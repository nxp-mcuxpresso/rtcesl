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
* @brief  Shift
* 
*******************************************************************************/
#ifndef _MLIB_SHIFT_F16_ASM_H_
#define _MLIB_SHIFT_F16_ASM_H_

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
#define MLIB_Sh1LSat_F16_Asmi(f16Val)       MLIB_Sh1LSat_F16_FAsmi(f16Val)
#define MLIB_ShLSat_F16_Asmi(f16Val, u16Sh) MLIB_ShLSat_F16_FAsmi(f16Val, u16Sh)

/***************************************************************************//*!
*
* This function returns the f16Val input shifted by 1 to the left. 
*              The function saturates the output.
*
*******************************************************************************/
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET 
RAM_FUNC_LIB 
RTCESL_INLINE static inline frac16_t MLIB_Sh1LSat_F16_FAsmi(register frac16_t f16Val)
{
    #if defined(__CC_ARM)                                /* For ARM Compiler */
        __asm volatile{ qadd16 f16Val, f16Val, f16Val }; /* Addition with saturation */
    #else
        __asm volatile(
                        #if defined(__GNUC__) && !defined(__ARMCC_VERSION)    /* For GCC compiler */
                            ".syntax unified \n"             /* Using unified asm syntax */
                        #endif
        		        "qadd16 %0, %0, %0 \n"               /* Addition with saturation */
                        #if defined(__GNUC__) && !defined(__ARMCC_VERSION)    /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f16Val):);
    #endif

    return f16Val;
}
RTCESL_INLINE_OPTIM_RESTORE 

/***************************************************************************//*!
*
* This function returns the f16Val input shifted by the number of u16Sh to the left. 
*          The function saturates the output.
*
*******************************************************************************/ 
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET 
RAM_FUNC_LIB 
RTCESL_INLINE static inline frac16_t MLIB_ShLSat_F16_FAsmi(register frac16_t f16Val, register uint16_t u16Sh)
{
    #if defined(__CC_ARM)                              /* For ARM Compiler */
        __asm volatile{ sxth f16Val, f16Val            /* Transforms 16-bit input f16Val to 32-bit */
                        usat u16Sh, #4, u16Sh          /* Saturates to 4-bit value */
                        lsl f16Val, f16Val, u16Sh      /* f16Val << u16Sh */
                        ssat f16Val, #16, f16Val };    /* Saturates to 16-bit value */
    #else
        __asm volatile( 
                        #if defined(__GNUC__) && !defined(__ARMCC_VERSION)        /* For GCC compiler */
                            ".syntax unified \n"       /* Using unified asm syntax */
                        #endif
                        "sxth %0, %0 \n"               /* Transforms 16-bit input f16Val to 32-bit */
                        "usat %1, #4, %1 \n"           /* Saturates to 4-bit value */
                        "lsl %0, %0, %1 \n"            /* f16Val << u16Sh */
                        "ssat %0, #16, %0 \n"          /* Saturates to 16-bit value */
                        #if defined(__GNUC__) && !defined(__ARMCC_VERSION)        /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f16Val), "+l"(u16Sh):);
    #endif

    return f16Val;
}
RTCESL_INLINE_OPTIM_RESTORE 

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_SHIFT_F16_ASM_H_ */
