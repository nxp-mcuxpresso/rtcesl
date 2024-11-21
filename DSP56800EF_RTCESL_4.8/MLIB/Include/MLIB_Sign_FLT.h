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
* @brief  Sign
* 
*******************************************************************************/
#ifndef _MLIB_SIGN_FLT_H_
#define _MLIB_SIGN_FLT_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "mlib_types.h"

/*******************************************************************************
* Macros
*******************************************************************************/  
#define MLIB_Sign_FLT_Ci(fltVal) MLIB_Sign_FLT_FCi(fltVal)  

/***************************************************************************//*! 
*  This function returns the sign of the argument:
*  fltVal = 0: returns  0.0F
*  fltVal > 0: returns  1.0F 
*  fltVal < 0: returns -1.0F
*
*******************************************************************************/

static inline float_t MLIB_Sign_FLT_FCi(register float_t fltVal)
{
    return((fltVal < 0.0F) ? -1.0F : ((fltVal == 0.0F) ? 0.0F : 1.0F));
}

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_SIGN_FLT_H_ */
