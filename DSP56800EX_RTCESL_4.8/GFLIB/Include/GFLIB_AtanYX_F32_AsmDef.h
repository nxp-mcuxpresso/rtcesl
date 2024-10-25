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
* @brief  Definition file for arcus tangent function based on the provided x,y 
* 		  coordinates as arguments
* 
*******************************************************************************/
#ifndef _GFLIB_ATANYX_F32_ASMDEF_H_
#define _GFLIB_ATANYX_F32_ASMDEF_H_

#if defined(__cplusplus) 
extern "C" { 
#endif 
/******************************************************************************
* Includes
******************************************************************************/
#include "GFLIB_AtanYX_F32_Asm.h"

/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros 
******************************************************************************/
#define GFLIB_AtanYX_F16_Asm(f16Y, f16X, pbErrFlag) GFLIB_AtanYX_F16_FAsm(f16Y, f16X, &gsAtanCoef_F32, pbErrFlag)

/******************************************************************************
* Types
******************************************************************************/

/******************************************************************************
* Global variables
******************************************************************************/
extern GFLIB_CONST GFLIB_ATAN_T_F32 gsAtanCoef_F32;

/******************************************************************************
* Global functions
******************************************************************************/

/******************************************************************************
* Inline functions
******************************************************************************/
#if defined(__cplusplus) 
} 
#endif 

#endif /* _GFLIB_ATANYX_F32_ASMDEF_H_ */
