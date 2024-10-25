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
* @brief  Square root 
* 
*******************************************************************************/

#ifndef _GFLIB_SQRT_FLT_H_
#define _GFLIB_SQRT_FLT_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "gflib_types.h"
#include "mlib_FP.h"

/*******************************************************************************
* Exported function prototypes
*******************************************************************************/
 extern float_t GFLIB_Sqrt_FLT_FC(float_t fltVal);

/*******************************************************************************
* Macros 
*******************************************************************************/
#define GFLIB_Sqrt_FLT_Asmi(fltVal) GFLIB_Sqrt_FLT_FAsmi(fltVal)

/***************************************************************************//*!
* @brief     This function returns the square root of input value.
*
* @param[in] fltVal      The input value.
*
* @return    The function returns the square root of the input value. The
*            return value is float range. If input is <= 0, then the function 
*            returns 0. 
*
****************************************************************************/  
static inline float_t GFLIB_Sqrt_FLT_FAsmi(float_t fltVal)
{
    return sqrtf(fltVal);
}

#if defined(__cplusplus)
}
#endif

#endif /* _GFLIB_SQRT_FLT_H_ */

