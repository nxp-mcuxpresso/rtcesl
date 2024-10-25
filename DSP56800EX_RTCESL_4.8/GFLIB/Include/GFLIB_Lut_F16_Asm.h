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
* @brief  Look-up table algorithm implemented in assembler 
* 
*******************************************************************************/
#ifndef _GFLIB_LUT_F16_ASM_H_
#define _GFLIB_LUT_F16_ASM_H_

#if defined(__cplusplus) 
extern "C" { 
#endif 
/******************************************************************************
* Includes
******************************************************************************/
#include "mlib.h"

/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros 
******************************************************************************/
#define GFLIB_Lut1D_F16_Asm(f16X, pf16Table, u16TableSize) GFLIB_Lut1D_F16_FAsm(f16X, pf16Table, u16TableSize)
#define GFLIB_Lut2D_F16_Asm(f16X, f16Y, psParam) GFLIB_Lut2D_F16_FAsm(f16X, f16Y, psParam)

/******************************************************************************
* Types
******************************************************************************/
typedef struct
{
	uint16_t  u16ShamOffset1;
	uint16_t  u16ShamOffset2;
	frac16_t *pf16Table;
} GFLIB_LUT2D_T_F16;

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/

extern asm frac16_t GFLIB_Lut1D_F16_FAsm(frac16_t f16X, const frac16_t *pf16Table, uint16_t u16TableSize);

extern asm frac16_t GFLIB_Lut2D_F16_FAsm(frac16_t f16X, frac16_t f16Y, const GFLIB_LUT2D_T_F16 *psParam);

/******************************************************************************
* Inline functions
******************************************************************************/
#if defined(__cplusplus) 
} 
#endif 

#endif /* _GFLIB_LUT_F16_ASM_H_ */
