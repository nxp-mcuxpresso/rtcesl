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
* @brief Arcus tangent function based on the provided x,y coordinates as arguments
* 		 using division and piece-wise polynomial approximation
* 
*******************************************************************************/
#ifndef _GFLIB_ATANCORDIC_F32_H_
#define _GFLIB_ATANCORDIC_F32_H_

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
#define GFLIB_AtanCORDIC_F16_Ci(f16Val) GFLIB_AtanCORDIC_F16_FCi(f16Val)

/****************************************************************************
* Inline functions 
****************************************************************************/ 

/***************************************************************************//*!
*
* @brief     The GFLIB_Atan function computes the Atan(f16X)
*            using piece-wise polynomial approximation.
*
* @param     ptr r2 - *pbErrFlag - The pointed variable is 1, if the inputs were 0, 0
*                              otherwise it is 0.
*
* @param     in  r0 - f16Y in the range of [-1,1).
*                r1 - f16X in the range of [-1,1).
*
* @return    The function returns
*                r0 - Atan(f16Y,f16X).The output data value
*            is in range [-0.25, 0.25), which corresponds to the angle
*            in the range of [-pi/4,pi/4).
*
* @remarks   The GFLIB_Atan function computes the atan(x)/pi
*            using CORDIC module.
*
*            In case of the inputs 0, 0 the error flag is set to 1 and the output
*            of the function is 0.
*******************************************************************************/

extern inline  frac16_t GFLIB_AtanCORDIC_F16_FCi(frac16_t f16Angle)
{
	register frac32_t i32Q27Val;
	register int32_t i32Q27Rslt;
	
	i32Q27Val = (frac32_t)f16Angle<<12U; /* convert to Q5.27 format */
	__crdpld_cx(RTCESL_CIR_VLENTH_ARCTAN_COEFF_Q27);
	__crdpld_cz(0);
	__crdpld_cy(MLIB_Mul_F32(RTCESL_CIR_VLENTH_ARCTAN_COEFF_Q31,i32Q27Val));
	__crdpld_cdc(24ul<<8 | 1ul<<13 | 0x1); // 24 iteration cycles and start, T=1(vector mode)
	
	i32Q27Rslt = __crdpst_cz();
		
	return (frac16_t)(i32Q27Rslt>>12U);
}


#if defined(__cplusplus)
}
#endif

#endif /* _GFLIB_ATANCORDIC_F32_H_ */

