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
* @brief  Accumulator subtraction from product functions with 32-bit rounded fractional 
* 		  output in assembler
* 
*******************************************************************************/
#ifndef _MLIB_MNACRND_F32_ASM_H_
#define _MLIB_MNACRND_F32_ASM_H_

#if defined(__cplusplus) 
extern "C" { 
#endif 
/******************************************************************************
* Includes
******************************************************************************/
#include "mlib_types.h"
#include "MLIB_MnacRnd_F32_Asmi.h"

/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros 
******************************************************************************/
#define MLIB_MnacRnd_F32lls_Asmi(f32Accum, f32Mult1, f16Mult2) MLIB_MnacRnd_F32lls_FAsmi(f32Accum, f32Mult1, f16Mult2)
#define MLIB_MnacRndSat_F32lls_Asmi(f32Accum, f32Mult1, f16Mult2) MLIB_MnacRndSat_F32lls_FAsmi(f32Accum, f32Mult1, f16Mult2)

#define MLIB_MnacRnd_F32_Asmi(f32Accum, f32Mult1, f32Mult2) MLIB_MnacRnd_F32_FAsmi(f32Accum, f32Mult1, f32Mult2)
#define MLIB_MnacRndSat_F32_Asmi(f32Accum, f32Mult1, f32Mult2) MLIB_MnacRndSat_F32_FAsmi(f32Accum, f32Mult1, f32Mult2)

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

#endif /* MLIB_MNACRND_F32_ASM_H_ */
