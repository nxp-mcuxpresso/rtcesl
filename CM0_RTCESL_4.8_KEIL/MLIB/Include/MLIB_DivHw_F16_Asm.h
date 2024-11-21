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
* @brief  Division
* 
*******************************************************************************/
#ifndef _MLIB_DIVHW_F16_ASM_H_
#define _MLIB_DIVHW_F16_ASM_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "MLIB_MMDVSQ.h"

/*******************************************************************************
* Macros 
*******************************************************************************/  
#define MLIB_DivHw_F16_Asm(f16Num, f16Denom)    MLIB_DivHw_F16_FAsm(f16Num, f16Denom, &gu16CntMmdvsq)
#define MLIB_DivHwSat_F16_Asm(f16Num, f16Denom) MLIB_DivHwSat_F16_FAsm(f16Num, f16Denom, &gu16CntMmdvsq)

/*******************************************************************************
* Exported function prototypes
*******************************************************************************/
extern frac16_t MLIB_DivHw_F16_FAsm(frac16_t f16Num, frac16_t f16Denom, const volatile uint16_t *pVal);
extern frac16_t MLIB_DivHwSat_F16_FAsm(frac16_t f16Num, frac16_t f16Denom, const volatile uint16_t *pVal);

#if defined(__cplusplus)
}
#endif

#endif  /* _MLIB_DIVHW_F16_ASM_H_ */
