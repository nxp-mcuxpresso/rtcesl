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
* @brief  Multiply accumulate of four inputs with rounding
*
*******************************************************************************/
#ifndef _MLIB_MAC4RND_F32_ASM_H_
#define _MLIB_MAC4RND_F32_ASM_H_

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
#define MLIB_Mac4Rnd_F32_Asm(f32Add1Mul1, f32Add1Mul2, f32Add2Mul1, f32Add2Mul2)    \
        MLIB_Mac4Rnd_F32_FAsm(f32Add1Mul1, f32Add1Mul2, f32Add2Mul1, f32Add2Mul2)
#define MLIB_Mac4RndSat_F32_Asm(f32Add1Mul1, f32Add1Mul2, f32Add2Mul1, f32Add2Mul2) \
        MLIB_Mac4RndSat_F32_FAsm(f32Add1Mul1, f32Add1Mul2, f32Add2Mul1, f32Add2Mul2)

/*******************************************************************************
* Exported function prototypes
*******************************************************************************/
extern frac16_t MLIB_Mac4Rnd_F32_FAsm(frac32_t f32Add1Mul1, frac32_t f32Add1Mul2, 
                                      frac32_t f32Add2Mul1, frac32_t f32Add2Mul2);
extern frac16_t MLIB_Mac4RndSat_F32_FAsm(frac32_t f32Add1Mul1, frac32_t f32Add1Mul2, 
                                         frac32_t f32Add2Mul1, frac32_t f32Add2Mul2);

#if defined(__cplusplus)
}
#endif

#endif  /* _MLIB_MAC4RND_F32_ASM_H_ */
