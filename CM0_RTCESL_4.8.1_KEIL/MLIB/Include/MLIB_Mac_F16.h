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
* @brief  Multiply accumulate
* 
*******************************************************************************/
#ifndef _MLIB_MAC_F16_H_
#define _MLIB_MAC_F16_H_

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
#define MLIB_Mac_F16_Ci( f16Accum, f16Mult1, f16Mult2)                        \
        MLIB_Mac_F16_FCi( f16Accum, f16Mult1, f16Mult2)                               
  
/***************************************************************************//*!
*
* f16Out = f16Accum + ( f16Mult1 * f16Mult2)
* Without saturation
*******************************************************************************/
static inline frac16_t MLIB_Mac_F16_FCi(register frac16_t f16Accum, 
                                        register frac16_t f16Mult1, register frac16_t f16Mult2)
{
    register acc32_t a32Temp;
    
    a32Temp = ((int32_t)f16Mult1 * (int32_t)f16Mult2);
    a32Temp = MLIB_ShR_F32_Ci(a32Temp, 15U);
    a32Temp = (acc32_t)f16Accum + a32Temp;
    return((frac16_t)a32Temp);  
}
#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_MAC_F16_H_ */
