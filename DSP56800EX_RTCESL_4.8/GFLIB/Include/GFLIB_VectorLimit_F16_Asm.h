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
* @brief  Vector limit functions with 16-bit fractional output in assembler
* 
*******************************************************************************/
#ifndef _GFLIB_VECTORLIMIT_F16_ASM_H_
#define _GFLIB_VECTORLIMIT_F16_ASM_H_

#if defined(__cplusplus) 
extern "C" { 
#endif 
/******************************************************************************
* Includes
******************************************************************************/
#include "mlib.h"
#include "GFLIB_Sqrt_F32_AsmDef.h"

/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros 
******************************************************************************/
#define GFLIB_VectorLimit_F16_Asm(psVectorIn, f16Lim, psVectorOut) GFLIB_VectorLimit_F16_FAsm(psVectorIn, f16Lim, psVectorOut)
#define GFLIB_VectorLimit1_F16_Asm(psVectorIn, f16Lim, psVectorOut) GFLIB_VectorLimit1_F16_FAsm(psVectorIn, f16Lim, psVectorOut)

/******************************************************************************
* Types
******************************************************************************/
typedef struct
{
	frac16_t f16A;
	frac16_t f16B;
} GFLIB_VECTORLIMIT_T_F16;

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/
extern asm bool_t GFLIB_VectorLimit_F16_FAsm(const GFLIB_VECTORLIMIT_T_F16 *psVectorIn, frac16_t f16Lim, GFLIB_VECTORLIMIT_T_F16 *psVectorOut);
extern asm bool_t GFLIB_VectorLimit1_F16_FAsm(const GFLIB_VECTORLIMIT_T_F16 *psVectorIn, frac16_t f16Lim, GFLIB_VECTORLIMIT_T_F16 *psVectorOut);
/******************************************************************************
* Inline functions
******************************************************************************/
#if defined(__cplusplus) 
} 
#endif 

#endif /* _GFLIB_VECTORLIMIT_F16_ASM_H_ */

