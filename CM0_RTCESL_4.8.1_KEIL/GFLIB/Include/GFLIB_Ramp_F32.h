/*******************************************************************************
*
* Copyright (c) 2013 - 2016, Freescale Semiconductor, Inc.
* Copyright 2016-2021, 2024 NXP
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
* @brief  Ramp 
* 
*******************************************************************************/
#ifndef _GFLIB_RAMP_F32_H_
#define _GFLIB_RAMP_F32_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/  
#include "mlib.h"
#include "gflib_types.h"
  
/*******************************************************************************
* Macros 
******************************************************************************/  
#define GFLIB_RampInit_F32_Ci(f32InitVal, psParam)                            \
        GFLIB_RampInit_F32_FCi(f32InitVal, psParam)                           

/*******************************************************************************
* Types
*******************************************************************************/
typedef struct
{
    frac32_t f32RampUp;    /* Ramp-up increment */
    frac32_t f32RampDown;  /* Ramp-down increment */
    frac32_t f32State;     /* Previous ramp value */
} GFLIB_RAMP_T_F32;

/***************************************************************************//*!
* @brief  The function initializes the actual value of Ramp_F32.
*
* @param  ptr   GFLIB_RAMP_T_F32 *psParam
*                     - rampUp: Ramp-up increment
*                     - rampDown: Ramp-down increment
*                     - state: Actual state
*                     
* @param  in    frac32_t f32InitVal - Initial value
*******************************************************************************/
static inline void GFLIB_RampInit_F32_FCi(frac32_t f32InitVal, GFLIB_RAMP_T_F32 *psParam)
{
    psParam->f32State = f32InitVal;
}
#if defined(__cplusplus)
}
#endif

#endif /* _GFLIB_RAMP_F32_H */

