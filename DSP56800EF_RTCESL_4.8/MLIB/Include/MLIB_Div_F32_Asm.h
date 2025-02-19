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
* @brief  Division functions with 32-bit fractional input or output in assembler
* 
*******************************************************************************/
#ifndef _MLIB_DIV_F32_ASM_H_
#define _MLIB_DIV_F32_ASM_H_

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
/* Non-saturated division */
#define MLIB_Div_F16ls_Asmi(f32Num, f16Denom) MLIB_Div_F16ls_FAsmi(f32Num, f16Denom)
#define MLIB_Div_F16ll_Asm(f32Num, f32Denom) MLIB_Div_F16ll_FAsm(f32Num, f32Denom)
#define MLIB_Div_F32ls_Asmi(f32Num, f16Denom) MLIB_Div_F32ls_FAsmi(f32Num, f16Denom)
#define MLIB_Div_F32_Asm(f32Num, f32Denom) MLIB_Div_F32_FAsm(f32Num, f32Denom)

/* Saturated division */
#define MLIB_DivSat_F16ls_Asmi(f32Num, f16Denom) MLIB_DivSat_F16ls_FAsmi(f32Num, f16Denom)
#define MLIB_DivSat_F16ll_Asm(f32Num, f32Denom) MLIB_DivSat_F16ll_FAsm(f32Num, f32Denom)
#define MLIB_DivSat_F32ls_Asmi(f32Num, f16Denom) MLIB_DivSat_F32ls_FAsmi(f32Num, f16Denom)
#define MLIB_DivSat_F32_Asm(f32Num, f32Denom) MLIB_DivSat_F32_FAsm(f32Num, f32Denom)

/******************************************************************************
* Types
******************************************************************************/

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/
/* Non-saturated division */
extern frac16_t MLIB_Div_F16ll_FAsm(frac32_t f32Num, frac32_t f32Denom);
extern frac32_t MLIB_Div_F32_FAsm(frac32_t f32Num, frac32_t f32Denom);

/* Saturated division */
extern frac16_t MLIB_DivSat_F16ll_FAsm(frac32_t f32Num, frac32_t f32Denom);
extern frac32_t MLIB_DivSat_F32_FAsm(frac32_t f32Num, frac32_t f32Denom);

/******************************************************************************
* Inline functions
******************************************************************************/
/***************************************************************************//*!
*
* @brief  32-bit numerator, 16-bit denominator inputs 16-output 4-quadrant
* 		  division function
*
* @param  ptr			
* 
* @param  in    		frac32_t f32Num
*                         - Numerator in [-1;1] in frac32_t
*						frac16_t f16Denom
*                         - Denominator in [-1;1] in frac16_t
*                       
*
* @return This function returns
*     - frac16_t value [-1;1]
*		
* @remarks 	This function divides two fractional inputs:
* 			result = f32Num / f16Denom.
* 			The function normalises the inputs to get higher precision of
* 			division.
* 			The function does not saturate the output.
* 			If the denominator is 0, the output is 0x7FFF or 0x8000
* 			depending on the numerator's sign. For the both are 0, the output 
* 			is 0x7FFF.
* 			
*			SATURATION INDEPENDENT!
*
****************************************************************************/
extern inline frac16_t MLIB_Div_F16ls_FAsmi(register frac32_t f32Num, register frac16_t f16Denom)
{
	register int16_t w16ClbNum, w16ClbDenom;
	register frac32_t f32Result;
	register frac16_t f16Result;
	register frac32_t f32NumTemp, f32Copy;
		
	asm(.optimize_iasm on);

	asm(tfr f32Num,f32NumTemp);

	asm(clb f32NumTemp,w16ClbNum);		/* w16ClbNum = number of leading bits of f32Num */
	asm(sub.w #1,w16ClbNum);			/* w16ClbNum = w16ClbNum - 1 because we need to have f16Num 0.25 to 0.5 */
	asm(asll.l w16ClbNum,f32NumTemp);	/* Normalisation of f16Num to the range 0.25 to 0.5 */	
	asm(clb f16Denom,w16ClbDenom);		/* w16ClbDenom = number of leading bits of f16Denom */
	
	asm(abs f32NumTemp);				/* Absolute value of the numerator */
		
	asm(asll.l w16ClbDenom,f16Denom);	/* Normalisation of f16Denom to 0.5 to 1.0 */
	asm(sub w16ClbNum,w16ClbDenom);		/* w16ClbDenom = shifts of f16Denom - shifts of w16ClbNum */
	
	asm(tst f32NumTemp);				/* Clears the C flag */
	asm(rep 8);							/* Repeat 8 times */
	asm(div f16Denom,f32NumTemp);		/* f32NumTemp = f32NumTemp / f16Denom */
	asm(rep 8);							/* Repeat 8 times */
	asm(div f16Denom,f32NumTemp);		/* f32NumTemp = f32NumTemp / f16Denom */
	
	asm(move.w f32NumTemp.0,f32NumTemp);/* f32NumTemp = f32NumTemp << 16 */	
	asm(tfr f32NumTemp,f32Copy);		/* Copy of the result */			

	asm(neg	f32NumTemp);				/* Negates the result */
	asm(eor.w f16Denom,f32Num);			/* Save sign bit of quotient in N bit of SR */
	asm(nop);
	asm(tlt	f32NumTemp,f32Copy);		/* f32Copy = -f32NumTemp if different signs */

	asm(tfr f32Copy,f32Result);			/* f32Result = f32Copy */
	asm(asll.l w16ClbDenom,f32Result);	/* f16Result = f16Result << w16ClbDenom (arithmetically) */
		
	asm(bfchg #0x8000,f32Copy.1);		/* Changes the MSB of the result */
		
	asm(tst.w f16Denom);				/* Leading bits of denominator, comparison to 15 */
	asm(teq f32Copy,f32Result);			/* In case of 0, uses the maximum output */

	asm(move.w f32Result,f16Result);	/* f16Result = f32Result with saturation */
		
	asm(.optimize_iasm off);

	return f16Result;
}

/***************************************************************************//*!
*
* @brief  32-bit numerator, 16-bit denominator inputs 16-output 4-quadrant
* 		  division function
*
* @param  ptr			
* 
* @param  in    		frac32_t f32Num
*                         - Numerator in [-1;1] in frac32_t
*						frac16_t f16Denom
*                         - Denominator in [-1;1] in frac16_t
*                       
*
* @return This function returns
*     - frac16_t value [0;1]
*		
* @remarks 	This function divides two fractional inputs:
* 			result = f32Num / f16Denom.
* 			The function normalises the inputs to get higher precision of
* 			division.
* 			The function saturates the output if |f32Num| > |f16Denom|
* 			to 0x7FFF or 0x8000 depending on the signs. 

*
*			SATURATION INDEPENDENT!
*
****************************************************************************/
extern inline frac16_t MLIB_DivSat_F16ls_FAsmi(register frac32_t f32Num, register frac16_t f16Denom)
{
	register int16_t w16ClbNum, w16ClbDenom, w16ClbResult;
	register frac16_t f16Out;
	register frac32_t f32NumTemp, f32Copy;	
		
	asm(.optimize_iasm on);

	asm(tfr f32Num,f32NumTemp);

	asm(clb f32NumTemp,w16ClbNum);		/* w16ClbNum = number of leading bits of f32Num */
	asm(sub.w #1,w16ClbNum);			/* w16ClbNum = w16ClbNum - 1 because we need to have f16Num 0.25 to 0.5 */
	asm(asll.l w16ClbNum,f32NumTemp);	/* Normalisation of f16Num to the range 0.25 to 0.5 */	
	asm(clb f16Denom,w16ClbDenom);		/* w16ClbDenom = number of leading bits of f16Denom */
	
	asm(abs f32NumTemp);				/* Absolute value of the numerator */
		
	asm(asll.l w16ClbDenom,f16Denom);	/* Normalisation of f16Denom to 0.5 to 1.0 */
	asm(sub w16ClbNum,w16ClbDenom);		/* w16ClbDenom = shifts of f16Denom - shifts of w16ClbNum */
	
	asm(tst a);							/* Clears the C flag */
	asm(rep 8);							/* Repeat 8 times */
	asm(div f16Denom,f32NumTemp);		/* f32NumTemp = f32NumTemp / f16Denom */
	asm(rep 8);							/* Repeat 8 times */
	asm(div f16Denom,f32NumTemp);		/* f32NumTemp = f32NumTemp / f16Denom */
	
	asm(move.w f32NumTemp.0,f32NumTemp);/* f32NumTemp = f32NumTemp << 16 */	
	asm(tfr f32NumTemp,f32Copy);		/* Copy of the result */			

	asm(neg	f32NumTemp);				/* Negates the result */
	asm(eor.w f16Denom,f32Num);			/* Save sign bit of quotient in N bit of SR */
	asm(nop);
	asm(tlt	f32NumTemp,f32Copy);		/* f32Copy = -f32NumTemp if different signs */

	asm(clb f32Copy,w16ClbResult);		/* Leading bits of the result */
	asm(tfr f32Copy,f32NumTemp);		/* Copy of the result */
		
	asm(asll.l w16ClbDenom,f32Copy);	/* f32Copy = f32Copy << w16ClbDenom (arithmetically) */

	asm(bfchg #0x8000,f32NumTemp.1);	/* Changes the MSB of the result */		

	asm(cmp.w w16ClbDenom,w16ClbResult);/* Leading bits comparison */

	asm(tlt f32NumTemp,f32Copy);		/* In case of result's overflow, uses the maximum output */
		
	asm(move.w f32Copy,f16Out);			/* Saturation */
		
	asm(.optimize_iasm off);
		
	return f16Out;
}

/***************************************************************************//*!
*
* @brief  32-bit numerator, 16-bit denominator inputs 32-output four quadrant
* 		  division function
*
* @param  ptr			
* 
* @param  in    		frac32_t f32Num
*                         - Numerator in [-1;1] in frac32_t
*						frac16_t f16Denom
*                         - Denominator in [-1;1] in frac16_t
*                       
*
* @return This function returns
*     - frac16_t value [-1;1]
*		
* @remarks 	This function divides two fractional inputs:
* 			result = f32Num / f16Denom.
* 			The function does not saturate the output.
* 			If the denominator is 0, the output is 0x7FFF or 0x8000
* 			depending on the numerator's sign. For the both are 0, the output 
* 			is 0x7FFF.
* 			
*			SATURATION INDEPENDENT!
*
****************************************************************************/
extern inline frac32_t MLIB_Div_F32ls_FAsmi(register frac32_t f32Num, register frac16_t f16Denom)
{
	register frac32_t f32Result;
	register int16_t w16ClbNum, w16ClbDenom;
	register frac16_t f16Out;
	register frac32_t f32NumTemp, f32Copy;
	
	asm(.optimize_iasm on);

	asm(tfr f32Num,f32NumTemp);
		
	asm(clb f32NumTemp,w16ClbNum);				/* w16ClbNum = number of leading bits of f16Num */
		
	asm(sub.w #1,w16ClbNum);			/* w16ClbNum = w16ClbNum - 1 because we need to have f16Num 0.25 to 0.5 */
	asm(asll.l w16ClbNum,f32NumTemp);			/* Normalisation of f32Num to the range 0.25 to 0.5 */	

	asm(clb f16Denom,w16ClbDenom);		/* w16ClbDenom = number of leading bits of f16Denom */
		
	asm(abs f32NumTemp);							/* Absolute value of the numerator */
		
	asm(asll.l w16ClbDenom,f16Denom);	/* Normalisation of f16Denom to 0.5 to 1.0 */

	asm(sub w16ClbNum,w16ClbDenom);		/* w16ClbDenom = shifts of f16Denom - shifts of w16ClbNum */

	asm(tst f32NumTemp);							/* Clears the C flag */
	asm(rep 8);							/* Repeat 8 times */
	asm(div f16Denom,f32NumTemp);				/* A = A / f16Denom */
	asm(rep 8);							/* Repeat 8 times */
	asm(div f16Denom,f32NumTemp);				/* A = A / f16Denom */

	asm(move.w f32NumTemp.0,f32Copy);					/* Upper 16 bits of the result */ 
		
	asm(rep 8);							/* Repeat 8 times */
	asm(div f16Denom,f32NumTemp);				/* A = A / f16Denom */
	asm(rep 8);							/* Repeat 8 times */
	asm(div f16Denom,f32NumTemp);				/* A = A / f16Denom */

	asm(move.w f32NumTemp.0,f32Copy.0);					/* Lower 16 bits of the result */

	asm(tfr f32Copy,f32NumTemp);						/* Copy of the result */			

	asm(neg	f32NumTemp);							/* Negates the result */
	asm(eor.w f16Denom,f32Num);			/* Save sign bit of quotient in N bit of SR */
	asm(nop);
	asm(tlt	f32NumTemp,f32Copy);						/* B = -B if different signs */
		
	asm(tfr f32Copy,f32Result);				/* Copy of the result */

	asm(asll.l w16ClbDenom,f32Result);	/* A = A << w16ClbDenom (arithmetically) */
		
	asm(bfchg #0x8000,f32Copy.1);				/* Changes the MSB of the result */
		
	asm(sat f32Copy);						
		
	asm(tst.w f16Denom);				/* Leading bits of denominator, comparison to 15 */
		
	asm(teq f32Copy,f32Result);				/* In case of 0, uses the maximum output */
		
	asm(.optimize_iasm off);
		
	return f32Result;
}

/***************************************************************************//*!
*
* @brief  32-bit numerator, 16-bit denominator inputs 32-output four quadrant
* 		  division function
*
* @param  ptr			
* 
* @param  in    		frac32_t f32Num
*                         - Numerator in [-1;1] in frac32_t
*						frac16_t f16Denom
*                         - Denominator in [-1;1] in frac16_t
*                       
*
* @return This function returns
*     - frac16_t value [-1;1]
*		
* @remarks 	This function divides two fractional inputs:
* 			result = f32Num / f16Denom.
* 			The function normalises the inputs to get higher precision of
* 			division.
* 			The function saturates the output if |f32Num| > |f16Denom|
* 			to 0x7FFF FFFF or 0x8000 0000 depending on the signs. 
*
*			SATURATION INDEPENDENT!
*
****************************************************************************/
extern inline frac32_t MLIB_DivSat_F32ls_FAsmi(register frac32_t f32Num, register frac16_t f16Denom)
{
	register frac32_t f32Result;
	register int16_t w16ClbNum, w16ClbDenom, w16ClbResult;
	register frac16_t f16Out;
	register frac32_t f32NumTemp, f32Copy;	
		
	asm(.optimize_iasm on);

	asm(tfr f32Num,f32NumTemp);
		
	asm(clb f32NumTemp,w16ClbNum);				/* w16ClbNum = number of leading bits of f16Num */
		
	asm(sub.w #1,w16ClbNum);			/* w16ClbNum = w16ClbNum - 1 because we need to have f16Num 0.25 to 0.5 */
	asm(asll.l w16ClbNum,f32NumTemp);			/* Normalisation of f32Num to the range 0.25 to 0.5 */	

	asm(clb f16Denom,w16ClbDenom);		/* w16ClbDenom = number of leading bits of f16Denom */
		
	asm(abs f32NumTemp);							/* Absolute value of the numerator */
		
	asm(asll.l w16ClbDenom,f16Denom);	/* Normalisation of f16Denom to 0.5 to 1.0 */

	asm(sub w16ClbNum,w16ClbDenom);		/* w16ClbDenom = shifts of f16Denom - shifts of w16ClbNum */

	asm(tst f32NumTemp);							/* Clears the C flag */
	asm(rep 8);							/* Repeat 8 times */
	asm(div f16Denom,f32NumTemp);				/* A = A / f16Denom */
	asm(rep 8);							/* Repeat 8 times */
	asm(div f16Denom,f32NumTemp);				/* A = A / f16Denom */

	asm(move.w f32NumTemp.0,f32Copy);					/* Upper 16 bits of the result */ 
		
	asm(rep 8);							/* Repeat 8 times */
	asm(div f16Denom,f32NumTemp);				/* A = A / f16Denom */
	asm(rep 8);							/* Repeat 8 times */
	asm(div f16Denom,f32NumTemp);				/* A = A / f16Denom */

	asm(move.w f32NumTemp.0,f32Copy.0);					/* Lower 16 bits of the result */

	asm(tfr f32Copy,f32NumTemp);						/* Copy of the result */			

	asm(neg	f32NumTemp);							/* Negates the result */
	asm(eor.w f16Denom,f32Num);			/* Save sign bit of quotient in N bit of SR */
	asm(nop);
	asm(tlt	f32NumTemp,f32Copy);						/* B = -B if different signs */
		
	asm(clb f32Copy,w16ClbResult);			/* Leading bits of the result */

	asm(tfr f32Copy,f32NumTemp);						/* Copy of the result */

	asm(asll.l w16ClbDenom,f32NumTemp);			/* A = A << w16ClbDenom (arithmetically) */
		
	asm(bfchg #0x8000,f32Copy.1);				/* Changes the MSB of the result */
		
	asm(cmp.w w16ClbDenom,w16ClbResult);/* Leading bits comparison */
		
	asm(tlt f32Copy,f32NumTemp);						/* In case of result's overflow, uses the maximum output */
		
	asm(sat f32NumTemp,f32Result);				/* Saturation */
		
	asm(.optimize_iasm off);
		
	return f32Result;
}

#if defined(__cplusplus) 
} 
#endif 

#endif /* _MLIB_DIV_F32_ASM_H_ */
