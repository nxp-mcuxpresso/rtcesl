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
* @brief  Multiply subtract with rounding
* 
*******************************************************************************/
#ifndef _MLIB_MSURND_F32_H_
#define _MLIB_MSURND_F32_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "mlib_types.h"
#include "MLIB_Add_F32.h"
#include "MLIB_MulRnd_F32.h"
#include "MLIB_Mul_F32.h"  

/*******************************************************************************
* Macros
*******************************************************************************/                    
#define MLIB_MsuRnd_F32lls_Ci( f32Accum, f32Mult1, f16Mult2)                  \
        MLIB_MsuRnd_F32lls_FCi( f32Accum, f32Mult1, f16Mult2)                 
  
/***************************************************************************//*!
*
* f32Out = f32Accum - ( f32Mult1 * f16Mult2)
* Without saturation
*******************************************************************************/
static inline frac32_t MLIB_MsuRnd_F32lls_FCi(register frac32_t f32Accum,
                                              register frac32_t f32Mult1,register frac16_t f16Mult2)
{
    return(MLIB_Add_F32_Ci(f32Accum, MLIB_MulNegRnd_F32ls_Ci(f32Mult1,f16Mult2)));  
}
#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_MSURND_F32_H_ */
