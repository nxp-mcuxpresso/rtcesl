/*******************************************************************************
*
* Copyright 2007-2016 Freescale Semiconductor, Inc.
*
* This software is owned or controlled by Freescale Semiconductor.
* Use of this software is governed by the Freescale License
* distributed with this Material.
* See the LICENSE file distributed for more details.
* 
*
****************************************************************************//*!
*
* @brief  Conversion functions
* 
*******************************************************************************/
#ifndef _MLIB_CONV_FLT_H_
#define _MLIB_CONV_FLT_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "mlib_types.h"  
#include "MLIB_Div_FLT.h"  

/*******************************************************************************
* Macros 
*******************************************************************************/
#define MLIB_Conv_F16f_Ci(fltVal) MLIB_Conv_F16f_FCi(fltVal)
#define MLIB_Conv_F32f_Ci(fltVal) MLIB_Conv_F32f_FCi(fltVal)  
   
#define MLIB_Conv_FLTs_Ci(f16Val) MLIB_Conv_FLTs_FCi(f16Val)
#define MLIB_Conv_FLTl_Ci(f32Val) MLIB_Conv_FLTl_FCi(f32Val)  

#define MLIB_Conv_A32f_Ci(fltVal) MLIB_Conv_A32f_FCi(fltVal)
#define MLIB_Conv_FLTa_Ci(a32Val) MLIB_Conv_FLTa_FCi(a32Val)

/***************************************************************************//*!
*
* @brief  This function converts the input value to different representation without scale.
*
* @param  in   Input value in 16-bit fractional format to be converted.     
*
* @return This function returns
*         - Converted input value in single precision floating point format.
*       
* @remarks  This inline function returns converted input value. 
*           The input value is considered as 16-bit fractional data type and 
*           output value is considered as single precision floating point data type.
*           The input value represents the values in unity model. The output
*           saturation is not implemented in this function.
*******************************************************************************/

static inline float_t MLIB_Conv_FLTs_FCi(register frac16_t f16Val)
{
    return(MLIB_Div_FLT_FCi((float_t)f16Val,((float_t)(INT16_MAX))+(float_t)1.0F));
}

/***************************************************************************//*!
*
* @brief  This function converts the input value to different representation without scale.
*
* @param  in   Input value in 32-bit fractional format to be converted.     
*
* @return This function returns
*         - Converted input value in single precision floating point format.
*       
* @remarks  This inline function returns converted input value. 
*           The input value is considered as 32-bit fractional data type and 
*           output value is considered as single precision floating point data type.
*           The input value represents the values in unity model. The output
*           saturation is not implemented in this function.
*******************************************************************************/

static inline float_t MLIB_Conv_FLTl_FCi(register frac32_t f32Val)
{
    return(MLIB_Div_FLT_FCi((float_t)f32Val,((float_t)(INT32_MAX))+(float_t)1.0F));
}

/***************************************************************************//*!
*
* @brief  This function converts the input value to different representation without scale.
*
* @param  in   fltVal     Input value in single precision floating point format to be converted.        
*
* @return This function returns
*         - Converted input value in 16-bit fractional format.
*       
* @remarks  This inline function returns converted input value. The input value is 
*           considered as single precision floating  point data type and output value 
*           is considered as 16-bit fractional data type. The output value  represents
*           the values in unity model. The output saturation is implemented in this function,
*           thus in case the input value is outside the (-1, 1) interval, the output 
*           value is limited to the boundary value.
*               
*******************************************************************************/

static inline frac16_t MLIB_Conv_F16f_FCi(register float_t fltVal)
{
    return((fltVal>=(float_t)1.0F) ? (frac16_t)INT16_MAX :
    ((fltVal<(float_t)-1.0F) ? (frac16_t)INT16_MIN :
    ((frac16_t)(fltVal * (((float_t)INT16_MAX)+(float_t)1.0F)))));
}

/***************************************************************************//*!
*
* @brief  This function converts the input value to different representation without scale.
*
* @param  in   fltVal     Input value in single precision floating point format to be converted.        
*
* @return This function returns
*         - Converted input value in 32-bit fractional format.
*       
* @remarks  This inline function returns converted input value. The input value is 
*           considered as single precision floating  point data type and output value 
*           is considered as 32-bit fractional data type. The output value  represents
*           the values in unity model. The output saturation is implemented in this function,
*           thus in case the input value is outside the (-1, 1) interval, the output 
*           value is limited to the boundary value.
*               
*******************************************************************************/

static inline frac32_t MLIB_Conv_F32f_FCi(register float_t fltVal)
{
    return((fltVal>=(float_t)1.0F) ? (frac32_t)INT32_MAX : 
    ((fltVal<(float_t)-1.0F) ? (frac32_t)INT32_MIN :
    ((frac32_t)(fltVal * (((float_t)INT32_MAX)+(float_t)1.0F)))));
}
         
/***************************************************************************//*!
*
* @brief  This function converts the input value to different representation without scale.
*
* @param  in   fltVal     Input value in single precision floating point format to be converted.        
*
* @return This function returns
*         - Converted input value in 32-bit accumulator format (-65536.0, 65536.0].
*       
* @remarks  This inline function returns converted input value. The input value is 
*           considered as single precision floating  point data type and output value 
*           is considered as 32-bit accumulator data type. The output value  represents
*           the values in unity model. The output saturation is implemented in this function,
*           thus in case the input value is outside the (-65536.0, 65536.0] interval, the output
*           value is limited to the boundary value.
*               
*******************************************************************************/

static inline acc32_t MLIB_Conv_A32f_FCi(register float_t fltVal)
{
    return((fltVal>=(float_t)65535.999969482421875F) ? (acc32_t)INT32_MAX :
    ((fltVal<(float_t)-65536.0F) ? (acc32_t)INT32_MIN :
    ((frac32_t)(fltVal * (((float_t)INT16_MAX)+(float_t)1.0F)))));
}          

/***************************************************************************//*!
*
* @brief  This function converts the input value to different representation without scale.
*
* @param  in   Input value in 32-bit accumulator format to be converted.     
*
* @return This function returns
*         - Converted input value in single precision floating point format.
*       
* @remarks  This inline function returns converted input value. 
*           The input value is considered as 32-bit accumulator data type and
*           output value is considered as single precision floating point data type.
*           The input value represents the values in unity model. The output
*           saturation is not implemented in this function.
*******************************************************************************/

static inline float_t MLIB_Conv_FLTa_FCi(register acc32_t a32Val)
{
    return(MLIB_Div_FLT_FCi((float_t)a32Val,((float_t)(INT16_MAX))+(float_t)1.0F));
}

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_CONV_FLT_H_ */

