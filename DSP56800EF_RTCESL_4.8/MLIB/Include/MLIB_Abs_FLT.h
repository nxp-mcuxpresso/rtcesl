/*******************************************************************************
*
* Copyright (c) 2013 - 2016, Freescale Semiconductor, Inc.
* Copyright 2016-2022, 2024 NXP
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
* @brief  Absolute Value
* 
*******************************************************************************/
#ifndef _MLIB_ABS_FLT_H_
#define _MLIB_ABS_FLT_H_

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
#define MLIB_Abs_FLT_Asmi(fltVal) MLIB_Abs_FLT_FAsmi(fltVal)
  
/***************************************************************************//*!
*  Absolute value      
*  fltOut = |fltIn|
*  The output saturation is not implemented.
*******************************************************************************/
static inline float_t MLIB_Abs_FLT_FAsmi(register float_t fltVal)
{
    return fabsf(fltVal);
}
 
#if defined(__cplusplus)
}
#endif

#endif  /* _MLIB_ABS_FLT_H_*/
