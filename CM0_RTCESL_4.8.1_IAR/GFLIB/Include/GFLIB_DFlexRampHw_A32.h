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
* @brief  Dynamic flex ramp functions with 16-bit fractional output 
* 
*******************************************************************************/
#ifndef _GFLIB_DFLEXRAMPHW_A32_H_
#define _GFLIB_DFLEXRAMPHW_A32_H_

#if defined(__cplusplus) 
extern "C" { 
#endif 
/******************************************************************************
* Includes
******************************************************************************/
#include "mlib.h"
#include "GFLIB_DFlexRamp_A32.h"  
    
/******************************************************************************
* Macros 
******************************************************************************/
#define GFLIB_DFlexRampCalcIncrHw_F16_C(f16Target, a32Duration, f32IncrSatMot, f32IncrSatGen, psParam) \
        GFLIB_DFlexRampCalcIncrHw_F16_FC(f16Target, a32Duration, f32IncrSatMot, f32IncrSatGen, psParam)

/******************************************************************************
* Exported function prototypes
******************************************************************************/
extern void GFLIB_DFlexRampCalcIncrHw_F16_FC(frac16_t f16Target,
                                             acc32_t a32Duration,
                                             frac32_t f32IncrSatMot,
                                             frac32_t f32IncrSatGen,
                                             GFLIB_DFLEXRAMP_T_F32 *psParam);

#if defined(__cplusplus) 
} 
#endif 

#endif /* _GFLIB_DFLEXRAMPHW_A32_H_ */
