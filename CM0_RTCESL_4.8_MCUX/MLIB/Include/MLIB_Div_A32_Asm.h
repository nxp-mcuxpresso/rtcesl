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
* @brief  Division
* 
*******************************************************************************/
#ifndef _MLIB_DIV_A32_ASM_H_
#define _MLIB_DIV_A32_ASM_H_

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
#define MLIB_Div_A32ss_Asm(f16Num, f16Denom) MLIB_Div_A32ss_FAsm(f16Num, f16Denom)
#define MLIB_Div_A32ls_Asm(f32Num, f16Denom) MLIB_Div_A32ls_FAsm(f32Num, f16Denom)
#define MLIB_Div_A32ll_Asm(f32Num, f32Denom) MLIB_Div_A32ll_FAsm(f32Num, f32Denom)

/*******************************************************************************
* Exported function prototypes
*******************************************************************************/
extern acc32_t MLIB_Div_A32ll_FAsm(frac32_t f32Num, frac32_t f32Denom);
extern acc32_t MLIB_Div_A32ss_FAsm(frac16_t f16Num, frac16_t f16Denom);
extern acc32_t MLIB_Div_A32ls_FAsm(frac32_t f32Num, frac16_t f16Denom);

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_DIV_A32_H_ASM_ */
