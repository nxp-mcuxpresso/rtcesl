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
* @brief  Hardware Square root
* 
*******************************************************************************/
#ifndef _GFLIB_SQRTHW_F32_H_
#define _GFLIB_SQRTHW_F32_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "MLIB_MMDVSQ.h"

/*******************************************************************************
* Macros 
*******************************************************************************/ 
#define GFLIB_SqrtHw_F16l_C(f32Val) GFLIB_SqrtHw_F16l_FC(f32Val) 

/***************************************************************************//*!
* @brief        This function returns the square root of input value.
*
* @param[in]         f32Val      The input value.
*
* @return      The function returns the square root of the input value. The
*              return value is within the [0, 1) 16 bit fraction range.
*              If input is <= 0, then the function returns 0. 
*
*              The computations are made by hardware MMDVSQ
*
*
****************************************************************************/    
static inline frac16_t GFLIB_SqrtHw_F16l_FC(frac32_t f32Val)
{
    uint16_t    u16InternalCount;
    frac16_t    f16Out;
    frac32_t    f32Out;
  
    if (f32Val <= 0)
    {
        f16Out = 0;
    }
    else
    {
        do
        {
            u16InternalCount = gu16CntMmdvsq + 1U;
            gu16CntMmdvsq = u16InternalCount;
         
            RTCESL_MMDVSQ_CSR = 0x0U;
            RTCESL_MMDVSQ_RCND = (uint32_t)f32Val >> 1U;
            while (((RTCESL_MMDVSQ_CSR)>>31) == 1U)
            {
            };

            f32Out = (frac32_t)(RTCESL_MMDVSQ_RES);
        }
        while (u16InternalCount != gu16CntMmdvsq);
        
        f16Out = (frac16_t)f32Out;
    }
    return (f16Out);
}
#if defined(__cplusplus)
}
#endif

#endif /* _GFLIB_SQRTHW_F32_H_ */

