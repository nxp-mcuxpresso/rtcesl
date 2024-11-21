/*******************************************************************************
*
* Copyright 2007-2016 Freescale Semiconductor, Inc.
*
* This software is owned or controlled by Freescale Semiconductor.
* Use of this software is governed by the Freescale License
* distributed with this Material.
* See the LICENSE file distributed for more details.
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

