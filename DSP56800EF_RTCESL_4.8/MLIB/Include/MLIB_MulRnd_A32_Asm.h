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
* @brief  Multiply functions with 32-bit accumulator input and result rounding 
* 		  in assembler
* 
*******************************************************************************/
#ifndef _MLIB_MULRND_A32_ASM_H_
#define _MLIB_MULRND_A32_ASM_H_

#if defined(__cplusplus) 
extern "C" { 
#endif 
/******************************************************************************
* Includes
******************************************************************************/
#include "mlib_types.h"
#include "MLIB_MulRnd_A32_Asmi.h"

/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros 
******************************************************************************/
#define MLIB_MulRnd_F16as_Asmi(a32Accum, f16Mult) MLIB_MulRnd_F16as_FAsmi(a32Accum, f16Mult)
#define MLIB_MulRndSat_F16as_Asmi(a32Accum, f16Mult) MLIB_MulRndSat_F16as_FAsmi(a32Accum, f16Mult)
#define MLIB_MulNegRnd_F16as_Asmi(a32Accum, f16Mult) MLIB_MulNegRnd_F16as_FAsmi(a32Accum, f16Mult)
#define MLIB_MulNegRndSat_F16as_Asmi(a32Accum, f16Mult) MLIB_MulNegRndSat_F16as_FAsmi(a32Accum, f16Mult)

#define MLIB_MulRnd_A32_Asmi(a32Mult1, a32Mult2) MLIB_MulRnd_A32_FAsmi(a32Mult1, a32Mult2)
#define MLIB_MulRndSat_A32_Asmi(a32Mult1, a32Mult2) MLIB_MulRndSat_A32_FAsmi(a32Mult1, a32Mult2)
#define MLIB_MulNegRnd_A32_Asmi(a32Mult1, a32Mult2) MLIB_MulNegRnd_A32_FAsmi(a32Mult1, a32Mult2)
#define MLIB_MulNegRndSat_A32_Asmi(a32Mult1, a32Mult2) MLIB_MulNegRndSat_A32_FAsmi(a32Mult1, a32Mult2)

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

#endif /* _MLIB_MULRND_A32_ASM_H_ */
