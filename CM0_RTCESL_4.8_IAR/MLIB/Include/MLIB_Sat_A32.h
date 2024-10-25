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
* @brief  Saturation
* 
*******************************************************************************/
#ifndef _MLIB_SAT_A32_H_
#define _MLIB_SAT_A32_H_

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
#define MLIB_Sat_F16a_Ci(a32Accum) MLIB_Sat_F16a_FCi(a32Accum) 
  
/***************************************************************************//*!
*
* Takes the fractional part from number in accumulator format and
* saturate if the original number is greater than 1. 
* 
*******************************************************************************/ 
static inline frac16_t MLIB_Sat_F16a_FCi(register acc32_t a32Accum)
{
    register int32_t i32z;
    i32z = (int32_t)(a32Accum);
  
    i32z = (i32z > ((int32_t)(INT16_MAX))) ? ((int32_t)(INT16_MAX)) : i32z;
    i32z = (i32z < ((int32_t)(INT16_MIN))) ? ((int32_t)(INT16_MIN)) : i32z;
    return ((frac16_t)(i32z));
}
#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_SAT_A32_H_ */
