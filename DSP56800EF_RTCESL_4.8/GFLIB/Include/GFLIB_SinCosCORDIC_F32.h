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
* @brief  Sine, Cosine
* 
*******************************************************************************/
#ifndef _GFLIB_SINCOSCORDIC_FLT_H_
#define _GFLIB_SINCOSCORDIC_FLT_H_

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
#define GFLIB_SinCORDIC_F16_Ci(f16Angle) GFLIB_SinCORDIC_F16_FCi(f16Angle) 
#define GFLIB_CosCORDIC_F16_Ci(f16Angle) GFLIB_CosCORDIC_F16_FCi(f16Angle)
/****************************************************************************
* Inline functions 
****************************************************************************/ 

/***************************************************************************//*!
* @brief  Calculates the sine of the given argument using PowerQuad hardware accelerator.
*
* @param  in   frac16_t f16Angle - Argument in frac16_t range 
*
* @return This function returns - frac16_t value 
*       
* @remarks  
*   This function calculates sin(x) using CORDIC hardware module:
*
*******************************************************************************/
extern inline frac16_t GFLIB_SinCORDIC_F16_FCi(frac16_t f16Angle)
{
	register int32_t f32temp;
    
	if(f16Angle > FRAC16(90.0/180.0)) /* input > 90 degree */
	{
		f16Angle = FRAC16(1) - f16Angle; /* theta = 180 - theta */
	}
	else if(f16Angle < FRAC16(-90.0/180.0)) /* input < -90 degree */
	{
		f16Angle = FRAC16(-1) - f16Angle; /* theta = -180 - theta */
	}	
    f32temp = (frac32_t)f16Angle<<12U;	

	__crdpld_cx(RTCESL_CIR_VLENTH_COEFF_Q27);
	__crdpld_cz(f32temp);
	__crdpld_cy(0);
	__crdpld_cdc(24ul<<8 | 0x1); /* 24 iteration cycles and start */
    
	f32temp = __crdpst_cy();
    f32temp = f32temp>>12U;
	if (f32temp > 32767)
	{
		f32temp = 32767;		
	}
	else if (f32temp < -32768)
	{
		f32temp = -32768;		
	}		
    return (frac16_t)f32temp;
}

/***************************************************************************//*!
* @brief  Calculates the cosine of the given argument using PowerQuad hardware accelerator.
*
* @param  in   float_t frac16_t - Argument in frac16_t range 
*
* @return This function returns - frac16_t value 
*       
* @remarks  
*   This function calculates cos(x) using CORDIC hardware module:
*
*******************************************************************************/ 
extern inline frac16_t GFLIB_CosCORDIC_F16_FCi(register frac16_t f16Angle)
{
	register int32_t f32temp;
    register bool_t bAngleChanged;
    bAngleChanged = 0;

	f32temp = (frac32_t)f16Angle<<12U;		
	if(f32temp > ACC32_Q27(90.0/180.0)) /* input > 90 degree */
	{
		f32temp = ACC32_Q27(1) - f32temp; /* theta = 180 - theta */
		bAngleChanged = 1;
	}
	else if(f32temp < ACC32_Q27(-90.0/180.0)) /* input < -90 degree */
	{
		f32temp = ACC32_Q27(-1) - f32temp; /* theta = -180 - theta */
		bAngleChanged = 1;
	}

	__crdpld_cx(RTCESL_CIR_VLENTH_COEFF_Q27);
	__crdpld_cz(f32temp);
	__crdpld_cy(0);
	__crdpld_cdc(24ul<<8 | 0x1); /* 24 iteration cycles and start */
    
	f32temp = __crdpst_cx();
	if(bAngleChanged)
	{
		f32temp = -f32temp;
	}
	f32temp = f32temp>>12U;	
	if (f32temp > 32767)
	{
		f32temp = 32767;		
	}
    return (frac16_t)f32temp;
}

#if defined(__cplusplus)
}
#endif

#endif /* _GFLIB_SINCOSCORDIC_A32_H_ */

