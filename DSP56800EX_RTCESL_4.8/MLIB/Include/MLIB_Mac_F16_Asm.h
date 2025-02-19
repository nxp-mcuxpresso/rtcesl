/*******************************************************************************
*
* Copyright (c) 2013 - 2016, Freescale Semiconductor, Inc.
* Copyright 2016-2019, 2024 NXP
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
* @brief  Multiply accumulate functions with 16-bit fractional output in assembler
* 
*******************************************************************************/
#ifndef _MLIB_MAC_F16_ASM_H_
#define _MLIB_MAC_F16_ASM_H_

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
#define MLIB_Mac_F16_Asmi(f16Accum, f16Mult1, f16Mult2) MLIB_Mac_F16_FAsmi(f16Accum, f16Mult1, f16Mult2)
#define MLIB_MacSat_F16_Asmi(f16Accum, f16Mult1, f16Mult2) MLIB_MacSat_F16_FAsmi(f16Accum, f16Mult1, f16Mult2)

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
* @brief  16-bit inputs 16-output multiply accumulate function
*
* @param  ptr			
* 
* @param  in    		frac16_t f16Accum
*                         - Argument in [-1;1] in frac16_t, accumulator
*                       frac16_t f16Mult1
*                         - Argument in [-1;1] in frac16_t
*						frac16_t f16Mult2
*                         - Argument in [-1;1] in frac16_t
*                       
*
* @return This function returns
*     - frac16_t value [-1;1]
*		
* @remarks 	This function multiplies two fractional inputs and adds them to
* 			the accumulator:
* 			result = f16Accum + f16Mult1 * f16Mult2.
* 			The function does not saturate the output if the saturation mode
* 			is turned off.
*
*			SATURATION required if saturation desirable!
*
****************************************************************************/
extern inline frac16_t MLIB_Mac_F16_FAsmi(register frac16_t f16Accum, register frac16_t f16Mult1, register frac16_t f16Mult2)
{
	register frac32_t f32Acc;
	register frac16_t f16Out;
		
	asm(.optimize_iasm on);
		
	asm(move.w f16Accum,f32Acc);
				
	asm(mac f16Mult1,f16Mult2,f32Acc);		/* f32Acc = f16Accum + f16Mult1 * f16Mult2 */
		
	asm(move.w f32Acc.1,f16Out);
		
	asm(.optimize_iasm off);
		
	return f16Out;
}

/***************************************************************************//*!
*
* @brief  16-bit inputs 16-output multiply accumulate saturated function
*
* @param  ptr			
* 
* @param  in    		frac16_t f16Accum
*                         - Argument in [-1;1] in frac16_t, accumulator
*                       frac16_t f16Mult1
*                         - Argument in [-1;1] in frac16_t
*						frac16_t f16Mult2
*                         - Argument in [-1;1] in frac16_t
*                       
*
* @return This function returns
*     - frac16_t value [-1;1]
*		
* @remarks 	This function multiplies two fractional inputs and adds them to
* 			the accumulator:
* 			result = f16Accum + f16Mult1 * f16Mult2.
* 			The function saturates the output.
*
*			SATURATION INDEPENDENT!
*
****************************************************************************/
extern inline frac16_t MLIB_MacSat_F16_FAsmi(register frac16_t f16Accum, register frac16_t f16Mult1, register frac16_t f16Mult2)
{
	register frac32_t f32Acc;
	register frac16_t f16Out;
	
	asm(.optimize_iasm on);
		
	asm(move.w f16Accum,f32Acc);	
		
	asm(mac f16Mult1,f16Mult2,f32Acc);		/* f32Acc = f16Accum + f16Mult1 * f16Mult2 */

	asm(sat f32Acc,f16Out);					/* Saturation */
		
	asm(.optimize_iasm off);
		
	return f16Out;
}

#if defined(__cplusplus) 
} 
#endif 

#endif /* _MLIB_MAC_F16_ASM_H_ */
