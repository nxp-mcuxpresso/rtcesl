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
#ifndef _MLIB_MAC4RND_F16_H_
#define _MLIB_MAC4RND_F16_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "mlib_types.h"
#include "MLIB_Add_F32.h"
#include "MLIB_Add_F16.h"
#include "MLIB_MulRnd_F16.h" 

/*******************************************************************************
* Macros
*******************************************************************************/  
#define MLIB_Mac4Rnd_F16_Ci(f16Add1Mul1, f16Add1Mul2, f16Add2Mul1, f16Add2Mul2)    \
        MLIB_Mac4Rnd_F16_FCi(f16Add1Mul1, f16Add1Mul2, f16Add2Mul1, f16Add2Mul2) 
  
/***************************************************************************//*!
*
* f16Out = (f16Add1Mul1 * f16Add1Mul2) + (f16Add2Mul1 * f16Add2Mul2)
* Without saturation
*******************************************************************************/
static inline frac16_t MLIB_Mac4Rnd_F16_FCi(register frac16_t f16Add1Mul1, register frac16_t f16Add1Mul2, 
                                            register frac16_t f16Add2Mul1, register frac16_t f16Add2Mul2)
{
    return(frac16_t)MLIB_ShR_F32_Ci(((MLIB_Add_F32_Ci((int32_t)(f16Add1Mul1)*(int32_t)(f16Add1Mul2),
                                                      (int32_t)(f16Add2Mul1)*(int32_t)(f16Add2Mul2)))+0x4000), 15U);
}
#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_MAC4RND_F16_H_ */
