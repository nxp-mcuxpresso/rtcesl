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
* @brief  Square root functions
* 
*******************************************************************************/

#ifndef _GFLIB_SQRTCORDIC_F16_H_
#define _GFLIB_SQRTCORDIC_F16_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "mlib.h"

/*******************************************************************************
* Macros 
*******************************************************************************/
#define GFLIB_SqrtCORDIC_F16_Ci(f16Val)  GFLIB_SqrtCORDIC_F16_FCi(f16Val)

/****************************************************************************
* Inline functions 
****************************************************************************/ 

/***************************************************************************//*!
*
* @brief  Calculates the square root of the argument.
*
* @param  in    		frac16_t f16Val
*                         - Argument in [0;1] in frac16_t
*
* @return This function returns
*     - frac16_t value [0;1]
*		
* @remarks 	This function calculates square root. The argument must be in the
*			range [0;1]. The algorithm calculates the raw result using a polynom
*			of the 4th order using 3 intervals. Then the raw result is iterated
*			in 3 steps to get a more precise result.
*			If the value is negative, it is negated and then calculated as it was
*			positive. But the result keeps positive.
*
*			SATURATION INDEPENDENT!
* 
****************************************************************************/
extern inline frac16_t GFLIB_SqrtCORDIC_F16_FCi(frac16_t f16Val)
{
    register int32_t i32Q27X,i32Q27Y,f32Val;
    register int32_t i32Q27Rslt;
    register int32_t i32Q27Tmp;	
	
    f32Val = (frac32_t)f16Val << 11U; /* transfer to sfq5.27 (4 ShR) + 1 ShR to prepare val for X and Y CORDIC reg */
    i32Q27X = f32Val + ACC32_Q27(0.5);
    i32Q27Y = f32Val - ACC32_Q27(0.5);
    __crdpld_cx(i32Q27X);
    __crdpld_cz(0);
    __crdpld_cy(i32Q27Y);
    __crdpld_cdc(24ul<<8 | 1ul<<14 | 1ul<<13 | 0x1); // 24 iteration cycles and start, MIU = 1(hyperbolic coordinate), T = 1(vector mode)
		
    /*---------------- WORKAROUND ----------------*/
    asm(crdpst cx, i32Q27Tmp); 
    i32Q27Rslt = MLIB_Mul_F32(i32Q27Tmp, HYP_VLENTH_SQRT_COEFF_Q31)>>11;
    /*--------------------------------------------*/
		
    return (frac16_t)i32Q27Rslt;
}


#if defined(__cplusplus)
}
#endif

#endif /* _GFLIB_SQRTCORDIC_F16_H_ */

