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
* @brief  Arcus tangent function based on the provided x,y coordinates as arguments
*        using division and piece-wise polynomial approximation
* 
*******************************************************************************/
#ifndef _GFLIB_ATANYXHW_F32_H_
#define _GFLIB_ATANYXHW_F32_H_

#if defined(__cplusplus)
extern "C" {
#endif

/******************************************************************************
* Includes
******************************************************************************/
#include "mlib.h"
#include "GFLIB_Atan_F32.h"
#include "gflib_types.h"

/******************************************************************************
* Macros 
******************************************************************************/
#define GFLIB_AtanYXHw_F16_Asm(f16Y, f16X, pbErrFlag) GFLIB_AtanYXHw_F16_FAsm(f16Y, f16X, pbErrFlag)

/****************************************************************************
* Exported function prototypes
****************************************************************************/
extern frac16_t GFLIB_AtanYXHw_F16_FAsm(frac16_t f16Y, frac16_t f16X, bool_t *pbErrFlag);

/*******************************************************************************
* Global variables
*******************************************************************************/

#if defined(__cplusplus)
}
#endif
#endif /* _GFLIB_ATANYXHW_F32_H_ */
