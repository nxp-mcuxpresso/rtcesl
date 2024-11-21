/*******************************************************************************
*
* Copyright (c) 2013 - 2016, Freescale Semiconductor, Inc.
* Copyright 2016-2019, 2024 NXP
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
* @brief  Multiply functions with 32-bit accumulator input in assembler
* 
*******************************************************************************/
#ifndef _MLIB_MUL_A32_ASM_H_
#define _MLIB_MUL_A32_ASM_H_

#if defined(__cplusplus) 
extern "C" { 
#endif 
/******************************************************************************
* Includes
******************************************************************************/
#include "mlib_types.h"
#include "MLIB_Mul_A32_Asmi.h"

/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros 
******************************************************************************/
#define MLIB_Mul_F16as_Asmi(a32Accum, f16Mult) MLIB_Mul_F16as_FAsmi(a32Accum, f16Mult)
#define MLIB_MulSat_F16as_Asmi(a32Accum, f16Mult) MLIB_MulSat_F16as_FAsmi(a32Accum, f16Mult)
#define MLIB_MulNeg_F16as_Asmi(a32Accum, f16Mult) MLIB_MulNeg_F16as_FAsmi(a32Accum, f16Mult)
#define MLIB_MulNegSat_F16as_Asmi(a32Accum, f16Mult) MLIB_MulNegSat_F16as_FAsmi(a32Accum, f16Mult)

#define MLIB_Mul_A32_Asmi(a32Mult1, a32Mult2) MLIB_Mul_A32_FAsmi(a32Mult1, a32Mult2)
#define MLIB_MulSat_A32_Asmi(a32Mult1, a32Mult2) MLIB_MulSat_A32_FAsmi(a32Mult1, a32Mult2)
#define MLIB_MulNeg_A32_Asmi(a32Mult1, a32Mult2) MLIB_MulNeg_A32_FAsmi(a32Mult1, a32Mult2)
#define MLIB_MulNegSat_A32_Asmi(a32Mult1, a32Mult2) MLIB_MulNegSat_A32_FAsmi(a32Mult1, a32Mult2)



/******************************************************************************
* Types
******************************************************************************/

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/

/******************************************************************************
* Inline functions
******************************************************************************/
#if defined(__cplusplus) 
} 
#endif 

#endif /* _MLIB_MUL_A32_ASM_H_ */
