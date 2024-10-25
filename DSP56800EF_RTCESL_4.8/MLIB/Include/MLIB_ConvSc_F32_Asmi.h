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
* @brief  Convert functions with scale factor and with 64-bit fractional 
* 		  input or output in assembler for V3
* 
*******************************************************************************/
#ifndef _MLIB_CONVSC_F32_ASMI_H_
#define _MLIB_CONVSC_F32_ASMI_H_

#if defined(__cplusplus) 
extern "C" { 
#endif 
/******************************************************************************
* Includes
******************************************************************************/
#include "mlib_types.h"

/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros 
******************************************************************************/

/******************************************************************************
* Types
******************************************************************************/

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/


/******************************************************************************
* Inline functions
******************************************************************************/

/***************************************************************************//*!
*
* @brief  32-bit fractional to 16-bit fractional convert function
*
* @param  ptr			
* 
* @param  in    		frac32_t f32Val
*                         - Argument in [-1;1] in frac32_t
*    					frac32_t f32Sc
*                         - Argument in [-1;1] in frac32_t                        
*
* @return This function returns
*    - frac16_t value [-1;1]
*		
* @remarks 	This function converts the 32-bit fractional value to 16-bit fractional 
* 			value with a scale. The second value represents the scale factor and is 
* 			considered as 32-bit fractional data type. The sign of the second value 
* 			represents the scale mechanism. In case the second value is positive the 
* 			first input value is multiplied with the second one and converted to the 
* 			output format. In case the second value is negative, the first input 
* 			value is divided by absolute value of second input value and converted 
* 			to the output format. 
* 			The output saturation is not implemented in this function, thus in case 
* 			the input value is outside the (-1, 1) interval, the output value will 
* 			overflow without any detection.
*
*			SATURATION INDEPENDENT!
*
****************************************************************************/
extern inline frac16_t MLIB_ConvSc_F16ll_FAsmi(register frac32_t f32Val, register frac32_t f32Sc)
{
	register frac16_t f16Out;
	
	asm(.optimize_iasm on);	
	
	asm(cmp.l #0, f32Sc);			/* Tests f32Sc */
	
	asm(bge CONVF16F32MUL);		
	
	asm(abs f32Sc);					/* If f32Sc<0 then f16Out=f32Val/(-f32Sc) */
	
	return ((int16_t)((MLIB_DivSat_F32_FAsm(f32Val, f32Sc))>>16));
	
	asm(CONVF16F32MUL:);			/* If f32Sc>0 then f16Out=f32Val*f32Sc */

	asm(mpy64 f32Val,f32Sc,f32Val);	/* f32Val = f32Val * f32Sc */

	asm(nop);

	asm(sat f32Val, f16Out);		/* Saturation */

	return f16Out;		
}

#if defined(__cplusplus) 
} 
#endif 

#endif /* _MLIB_CONVSC_F32_ASMI_H_ */
