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
* @brief  Ramp 
* 
*******************************************************************************/
#ifndef _GFLIB_RAMP_F16_H_
#define _GFLIB_RAMP_F16_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "gflib_types.h"
#include "mlib.h"
  
/*******************************************************************************
* Macros 
*******************************************************************************/  
#define GFLIB_RampInit_F16_Ci(f16InitVal, psParam)                             \
        GFLIB_RampInit_F16_FCi(f16InitVal, psParam)                            

/*******************************************************************************
* Types
*******************************************************************************/
typedef struct
{
    frac16_t f16RampUp;     /* Ramp-up increment */
    frac16_t f16RampDown;   /* Ramp-down increment */
    frac16_t f16State;      /* Previous ramp value */
} GFLIB_RAMP_T_F16;

/***************************************************************************//*!
* @brief  The function initializes the actual value of Ramp_F16.
*
* @param  ptr   GFLIB_RAMP_T_F16 *psParam
*                   - rampUp: Ramp-up increment
*                   - rampDown: Ramp-down increment
*                   - state: Actual state
*                 
* @param  in    frac16_t f16InitVal - Initial value
*******************************************************************************/
static inline void GFLIB_RampInit_F16_FCi(frac16_t f16InitVal, GFLIB_RAMP_T_F16 *psParam)
{
  psParam->f16State = f16InitVal;
}
#if defined(__cplusplus)
}
#endif

#endif /* _GFLIB_RAMP_F16_H_*/

