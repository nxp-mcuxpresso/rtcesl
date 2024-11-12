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
* @brief  Addition
* 
*******************************************************************************/
#ifndef _MLIB_ADD_F16_H_
#define _MLIB_ADD_F16_H_

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
#define MLIB_Add_F16_Ci(f16Add1, f16Add2)    MLIB_Add_F16_FCi(f16Add1, f16Add2) 
#define MLIB_AddSat_F16_Ci(f16Add1, f16Add2) MLIB_AddSat_F16_FCi(f16Add1, f16Add2)  
  
/***************************************************************************//*!
*  Addition        
*  f16Out = f16Add1 + f16Add2
*  function is not saturated
*******************************************************************************/
static inline frac16_t MLIB_Add_F16_FCi(register frac16_t f16Add1, register frac16_t f16Add2)
{
    return((frac16_t)(f16Add1 + f16Add2));
}

/***************************************************************************//*!
*  Saturated Addition      
*  f16Out = f16Add1 + f16Add2
*******************************************************************************/
static inline frac16_t MLIB_AddSat_F16_FCi(register frac16_t f16Add1, register frac16_t f16Add2)
{
    register int32_t i32z;
    
    i32z = (int32_t)((frac32_t)f16Add1 + (frac32_t)f16Add2); 
    i32z = i32z > (int32_t)0x00007FFF  ? (int32_t)0x00007FFF : i32z;
    i32z = i32z < (int32_t)0xFFFF8000U ? (int32_t)0xFFFF8000U : i32z;
    return((frac16_t)(i32z)); 
}

#if defined(__cplusplus)
}
#endif

#endif  /*_MLIB_ADD_F16_H_*/
