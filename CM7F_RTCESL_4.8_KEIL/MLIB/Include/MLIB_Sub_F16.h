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
* @brief  Subtraction
* 
*******************************************************************************/
#ifndef _MLIB_SUB_F16_H_
#define _MLIB_SUB_F16_H_

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
#define MLIB_Sub_F16_Ci(f16Min, f16Sub)    MLIB_Sub_F16_FCi(f16Min, f16Sub) 

/***************************************************************************//*!
*
* f16Out = f16Min - f16Sub
* Without saturation
*******************************************************************************/
RAM_FUNC_LIB 
RTCESL_INLINE static inline frac16_t MLIB_Sub_F16_FCi(register frac16_t f16Min, register frac16_t f16Sub)
{
    return(f16Min - f16Sub);
}
 
#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_SUB_F16_H_ */
