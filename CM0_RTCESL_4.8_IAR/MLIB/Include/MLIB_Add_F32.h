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
* @brief  Addition
* 
*******************************************************************************/
#ifndef _MLIB_ADD_F32_H_
#define _MLIB_ADD_F32_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "mlib_types.h"

/*******************************************************************************
* Macros 
*******************************************************************************/  
#define MLIB_Add_F32_Ci(f32Add1, f32Add2)    MLIB_Add_F32_FCi(f32Add1, f32Add2) 
#define MLIB_AddSat_F32_Ci(f32Add1, f32Add2) MLIB_AddSat_F32_FCi(f32Add1, f32Add2)   

/***************************************************************************//*!
*  Addition        
*  f32Out = f32Add1 + f32Add2
*  function is not saturated
*******************************************************************************/ 
static inline frac32_t MLIB_Add_F32_FCi(register frac32_t f32Add1, register frac32_t f32Add2)
{
    return((frac32_t)(f32Add1 + f32Add2));
}
/***************************************************************************//*!
*  Saturated Addition      
*  f32Out = f32Add1 + f32Add2
*******************************************************************************/
static inline frac32_t MLIB_AddSat_F32_FCi(register frac32_t f32Add1, register frac32_t f32Add2)
{
    register int32_t i32z;
    register uint32_t u32SatMin;
    register uint32_t u32SatMax;
 
    i32z = f32Add1 + f32Add2;                              /* Addition without saturation to find saturation max. and min. */
    u32SatMax = ~((uint32_t)f32Add1 | (uint32_t)f32Add2);  /* Saturation max. from addends and addition without sat. */
    u32SatMax = u32SatMax & (uint32_t)i32z;  
    u32SatMin = ((uint32_t)f32Add1 & (uint32_t)f32Add2);   /* Saturation min. from addends and addition without sat. */
    u32SatMin = u32SatMin & (~(uint32_t)i32z);   
	
    i32z = ((int32_t)u32SatMin < 0) ? (int32_t)0x80000000U : i32z; /* Low limit restriction */
    i32z = ((int32_t)u32SatMax < 0) ? (int32_t)0x7FFFFFFF  : i32z; /* Hight limit restriction */
    return(i32z);       
}
#if defined(__cplusplus)
}
#endif

#endif  /* _MLIB_ADD_F32_H_ */
