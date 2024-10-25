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
* @brief  Summation of four inputs
* 
*******************************************************************************/
#ifndef _MLIB_ADD4_F16_H_
#define _MLIB_ADD4_F16_H_

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
#define MLIB_Add4_F16_Ci(f16Add1, f16Add2, f16Add3, f16Add4)                   \
        MLIB_Add4_F16_FCi(f16Add1, f16Add2, f16Add3, f16Add4)                  

/***************************************************************************//*!
*  Summation of four inputs        
*  f16Out = f16Add1 + f16Add2 + f16Add3 + f16Add4
*  function is not saturated
*******************************************************************************/
static inline frac16_t MLIB_Add4_F16_FCi(register frac16_t f16Add1, register frac16_t f16Add2, 
                                         register frac16_t f16Add3, register frac16_t f16Add4)
{
    return((frac16_t)(f16Add1 + f16Add2 + f16Add3 + f16Add4)); 
}
#if defined(__cplusplus)
}
#endif

#endif  /* _MLIB_ADD4_F16_H_ */
