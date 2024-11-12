/*******************************************************************************
*
* Copyright 2013-2016 Freescale Semiconductor, Inc.
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
