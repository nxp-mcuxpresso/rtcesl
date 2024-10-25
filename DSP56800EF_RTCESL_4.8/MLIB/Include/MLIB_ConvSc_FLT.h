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
* @brief  Conversion functions
* 
*******************************************************************************/
#ifndef _MLIB_CONVSC_FLT_H_
#define _MLIB_CONVSC_FLT_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "mlib_types.h"  
#include "MLIB_Div_FLT.h"
#include "MLIB_Mul_FLT.h"

/*******************************************************************************
* Macros 
*******************************************************************************/
#define MLIB_ConvSc_FLTsf_Ci(f16Val, fltSc) MLIB_ConvSc_FLTsf_FCi(f16Val, fltSc)
#define MLIB_ConvSc_FLTlf_Ci(f32Val, fltSc) MLIB_ConvSc_FLTlf_FCi(f32Val, fltSc) 
     
#define MLIB_ConvSc_F16ff_Ci(fltVal, fltSc) MLIB_ConvSc_F16ff_FCi(fltVal, fltSc)
#define MLIB_ConvSc_F32ff_Ci(fltVal, fltSc) MLIB_ConvSc_F32ff_FCi(fltVal, fltSc)
    
#define MLIB_ConvSc_A32ff_Ci(fltVal, fltSc) MLIB_ConvSc_A32ff_FCi(fltVal, fltSc)
#define MLIB_ConvSc_FLTaf_Ci(a32Val, fltSc) MLIB_ConvSc_FLTaf_FCi(a32Val, fltSc) 	
	
/***************************************************************************//*!
*  16-bit fractional to float convert function   
*    
* @param  in:   float_t f16Val - Argument in frac16_t <-1;1)
*               float_t fltSc  - Argument in float_t                         
*
* @return This function returns - float_t value 
*       
* @remarks This inline function returns converted input value. The input value 
* is considered as 16-bit fractional and float data types and output value is  
* considered as single precision floating point data type. The input value  
* represents the values in unity model. The second value represents the scale  
* factor and is considered as single precision float data type and determine the
* scale conversion   
*           
*******************************************************************************/

static inline float_t MLIB_ConvSc_FLTsf_FCi(register frac16_t f16Val, register float_t  fltSc)
{
    return ((float_t)(MLIB_Mul_FLT_FCi(MLIB_Div_FLT_FCi((float_t)f16Val,
                                                       ((float_t)INT16_MAX+(float_t)1.0F)),
                                      (float_t)fltSc)));    
}                                                               

/***************************************************************************//*!
*  32-bit fractional to float convert function   
*    
* @param  in:   float_t f32Val - Argument in frac32_t <-1;1)
*               float_t fltSc  - Argument in float_t                          
*
* @return This function returns - float_t value 
*       
* @remarks This inline function returns converted input value. The input value 
* is considered as 32-bit fractional and float data types and output value is  
* considered as single precision floating point data type. The input value  
* represents the values in unity model. The second value represents the scale  
* factor and is considered as single precision float data type and determine the
* scale conversion   
*           
*******************************************************************************/

static inline float_t MLIB_ConvSc_FLTlf_FCi(register frac32_t f32Val, register float_t fltSc)
{        
    return ((float_t)(MLIB_Mul_FLT_FCi(MLIB_Div_FLT_FCi((float_t)f32Val,
                                                       ((float_t)INT32_MAX+(float_t)1.0F)),
                                      (float_t)fltSc)));
}

/***************************************************************************//*!
*  float to 16-bit fractional  convert function  
*    
* @param  in:  fltVal   Input value in single precision floating point format
*                       to be converted.
*              fltSc    Scale factor in single precision floating point format.                         
*                
* @return This function returns - 16-bit fractional value 
*       
* @remarks This inline function returns converted input value. The input value
* is considered as single precision floating point data type and output value 
* is considered as 16-bit fractional data type. The second value represents the
* scale factor and is considered as single precision floating point data type.
* The output value represents the values in unity model. The output saturation 
* is implemented in this function, thus in case the input value is outside
* the <-1, 1) interval, the output value is limited to the boundary value.
*           
*******************************************************************************/

static inline frac16_t MLIB_ConvSc_F16ff_FCi(register float_t fltVal, register float_t fltSc)
{
  register float_t fltInScaled;

  fltInScaled = MLIB_Div_FLT_FCi(fltVal, fltSc);
  
  return((fltInScaled>=(float_t)1.0F) ? (frac16_t)INT16_MAX :
  ((fltInScaled<(float_t)-1.0F) ? (frac16_t)INT16_MIN :
  (frac16_t)MLIB_Mul_FLT_FCi(fltInScaled,((float_t)INT16_MAX) + (float_t)1.0F)));
}

/***************************************************************************//*!
*  float to 32-bit fractional  convert function  
*    
* @param  in:  fltVal   Input value in single precision floating point format 
*                       to be converted.
*              fltSc    Scale factor in single precision floating point format.                         
*                
* @return This function returns - 32-bit fractional value 
*       
* @remarks This inline function returns converted input value. The input value
* is considered as single precision floating point data type and output value 
* is considered as 32-bit fractional data type. The second value represents the
* scale factor and is considered as single precision floating point data type.
* The output value represents the values in unity model. The output saturation 
* is implemented in this function, thus in case the input value is outside
* the <-1, 1) interval, the output value is limited to the boundary value.
*           
*******************************************************************************/

static inline frac32_t MLIB_ConvSc_F32ff_FCi(register float_t fltVal, register float_t fltSc)
{      
    register float_t fltInScaled;
    
    fltInScaled = MLIB_Div_FLT_FCi(fltVal, fltSc);
    
    return((fltInScaled>=(float_t)1.0F) ? (frac32_t)INT32_MAX :
    ((fltInScaled<(float_t)-1.0F) ? (frac32_t)INT32_MIN :
    (frac32_t)MLIB_Mul_FLT_FCi(fltInScaled,((float_t)INT32_MAX) + (float_t)1.0F)));
}


/***************************************************************************//*!
*  float to 32-bit accumulator convert function  
*    
* @param  in:  fltVal   Input value in single precision floating point format 
*                       to be converted.
*              fltSc    Scale factor in single precision floating point format.                         
*                
* @return This function returns - 32-bit accumulator value (-65536.0, 65536.0]
*       
* @remarks This inline function returns converted input value. The input value
* is considered as single precision floating point data type and output value 
* is considered as 32-bit accumulator data type. The second value represents the
* scale factor and is considered as single precision floating point data type.
* The output value represents the values in unity model. The output saturation 
* is implemented in this function, thus in case the input value is outside
* the (-65536.0, 65536.0] interval, the output value is limited to the boundary value.
*           
*******************************************************************************/
static inline acc32_t MLIB_ConvSc_A32ff_FCi(register float_t fltVal, register float_t fltSc)
{      
    register float_t fltInScaled;
    
    fltInScaled = MLIB_Div_FLT_FCi(fltVal,fltSc);
    
    return((fltInScaled>=(float_t)65535.999969482421875F) ? (acc32_t)INT32_MAX :
    ((fltInScaled<(float_t)-65536.0F) ? (acc32_t)INT32_MIN :
    (acc32_t)MLIB_Mul_FLT_FCi(fltInScaled,((float_t)32768))));
}
 
/***************************************************************************//*!
*  32-bit accumulator to float convert function   
*    
* @param  in:   float_t f32Acc - Argument in acc32_t (-65536.0, 65536.0]
*               float_t fltSc  - Argument in float_t                          
*
* @return This function returns - float_t value 
*       
* @remarks This inline function returns converted input value. The input value 
* is considered as 32-bit accumulator and float data types and output value is  
* considered as single precision floating point data type. The input value  
* represents the values in unity model. The second value represents the scale  
* factor and is considered as single precision float data type and determine the
* scale conversion.    
*           
*******************************************************************************/
static inline float_t MLIB_ConvSc_FLTaf_FCi(register acc32_t a32Val, register float_t fltSc)
{        
    return ((float_t)(MLIB_Mul_FLT_FCi(MLIB_Mul_FLT_FCi((float_t)a32Val,
                                                       ((float_t)1.0f/32768.0f)),
                                      (float_t)fltSc)));
}

#if defined(__cplusplus)
}
#endif

#endif  /* _MLIB_CONVSC_FLT_H_ */
