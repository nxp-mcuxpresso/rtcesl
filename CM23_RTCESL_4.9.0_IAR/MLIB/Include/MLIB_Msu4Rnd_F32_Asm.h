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
#ifndef _MLIB_MSU4RND_F32_ASM_H_
#define _MLIB_MSU4RND_F32_ASM_H_

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
#define MLIB_Msu4Rnd_F32_Asm(f32MinMul1, f32MinMul2, f32SubMul1, f32SubMul2)    \
        MLIB_Msu4Rnd_F32_FAsm(f32MinMul1, f32MinMul2, f32SubMul1, f32SubMul2)
#define MLIB_Msu4RndSat_F32_Asm(f32MinMul1, f32MinMul2, f32SubMul1, f32SubMul2) \
        MLIB_Msu4RndSat_F32_FAsm(f32MinMul1, f32MinMul2, f32SubMul1, f32SubMul2)

/*******************************************************************************
* Exported function prototypes
*******************************************************************************/
extern frac32_t MLIB_Msu4Rnd_F32_FAsm(register frac32_t f32MinMul1, register frac32_t f32MinMul2, 
                                      register frac32_t f32SubMul1, register frac32_t f32SubMul2);
extern frac32_t MLIB_Msu4RndSat_F32_FAsm(register frac32_t f32MinMul1,register frac32_t f32MinMul2,
                                         register frac32_t f32SubMul1,register frac32_t f32SubMul2);

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_MSU4RND_F32_ASM_H_ */
