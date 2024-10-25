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
* @brief  Dynamic flex ramp functions with 16-bit fractional output 
* 
*******************************************************************************/
#ifndef _GFLIB_DFLEXRAMP_A32_H_
#define _GFLIB_DFLEXRAMP_A32_H_

#if defined(__cplusplus) 
extern "C" { 
#endif 
/******************************************************************************
* Includes
******************************************************************************/
#include "mlib.h"
    
/******************************************************************************
* Macros 
******************************************************************************/
#define GFLIB_DFlexRampInit_F16_C(f16InitVal, psParam)                                                    \
        GFLIB_DFlexRampInit_F16_FC(f16InitVal, psParam)                                                   
#define GFLIB_DFlexRampCalcIncr_F16_C(f16Target, a32Duration, f32IncrSatMot, f32IncrSatGen, psParam)      \
        GFLIB_DFlexRampCalcIncr_F16_FC(f16Target, a32Duration, f32IncrSatMot, f32IncrSatGen, psParam)     
#define GFLIB_DFlexRamp_F16_C(f16Instant, pbStopFlagMot, pbStopFlagGen, psParam)                          \
        GFLIB_DFlexRamp_F16_FC(f16Instant, pbStopFlagMot, pbStopFlagGen, psParam)
#define GFLIB_DFlexRampCalcIncr_F16_CRam(f16Target, a32Duration, f32IncrSatMot, f32IncrSatGen, psParam)   \
        GFLIB_DFlexRampCalcIncr_F16_FCRam(f16Target, a32Duration, f32IncrSatMot, f32IncrSatGen, psParam)
#define GFLIB_DFlexRamp_F16_CRam(f16Instant, pbStopFlagMot, pbStopFlagGen, psParam)                       \
        GFLIB_DFlexRamp_F16_FCRam(f16Instant, pbStopFlagMot, pbStopFlagGen, psParam)

/******************************************************************************
* Types
******************************************************************************/
/* Flex dynamic ramp structure */
typedef struct
{
    frac32_t f32State; 
    frac32_t f32Incr; 
    frac32_t f32IncrSatMot;
    frac32_t f32IncrSatGen;
    frac32_t f32Target; 
    frac32_t f32Ts;
    frac32_t f32IncrMax; 
    bool_t bReachFlag; 
} GFLIB_DFLEXRAMP_T_F32;

/******************************************************************************
* Exported function prototypes
******************************************************************************/
extern void GFLIB_DFlexRampCalcIncr_F16_FC(frac16_t f16Target,
                                           acc32_t a32Duration,
                                           frac32_t f32IncrSatMot,
                                           frac32_t f32IncrSatGen,
                                           GFLIB_DFLEXRAMP_T_F32 *psParam);
RAM_FUNC_LIB 
extern void GFLIB_DFlexRampCalcIncr_F16_FCRam(frac16_t f16Target,
                                              acc32_t a32Duration,
                                              frac32_t f32IncrSatMot,
                                              frac32_t f32IncrSatGen,
                                              GFLIB_DFLEXRAMP_T_F32 *psParam);
										   
extern frac16_t GFLIB_DFlexRamp_F16_FC(frac16_t f16Instant,
                                       const bool_t *pbStopFlagMot,
                                       const bool_t *pbStopFlagGen,
                                       GFLIB_DFLEXRAMP_T_F32 *psParam);										   
RAM_FUNC_LIB 
extern frac16_t GFLIB_DFlexRamp_F16_FCRam(frac16_t f16Instant,
                                          const bool_t *pbStopFlagMot,
                                          const bool_t *pbStopFlagGen,
                                          GFLIB_DFLEXRAMP_T_F32 *psParam);


/******************************************************************************
* Inline functions
******************************************************************************/

/***************************************************************************//*!
*
* @brief   Dynamic flex ramp initialization
*
* @param   in   frac16_t f16InitVal - Measured instant value in <-1;1) in frac16_t
*
* @param   ptr  GFLIB_FLEXRAMP_T_F32 *psParam
*                 - f32State: State variable keeping the last state, assigned by GFLIB_DFlexRampInit_F16
*                 - f32Incr: Increment - calculated by GFLIB_DFlexRampCalcIncr_F16 function
*                 - f32IncrSatMot: Motor mode saturation mode increment - assigned by user(positive value), 
*                                  sign can be changed by GFLIB_DFlexRampCalcIncr_F16
*                 - f32IncrSatGen: Generator mode saturation mode increment - assigned by user(positive value),
*                                  sign can be changed by GFLIB_DFlexRampCalcIncr_F16
*                 - f32Target: Target value - assigned by GFLIB_DFlexRampCalcIncr_F16 function
*                 - f32Ts: Sample time [s] - assigned by user(positive value)
*                 - f32IncrMax: Maximum increment - assigned by user(positive value)
*                 - bReachFlag: Flag is set to TRUE if the desired value is achieved
*
* @return  void
*       
* @remarks The initialization value is stored into the f32State variable and the bReachFlag flag is cleared.
*
****************************************************************************/
RAM_FUNC_LIB 
RTCESL_INLINE static inline void GFLIB_DFlexRampInit_F16_FC(register frac16_t f16InitVal,
                                              register GFLIB_DFLEXRAMP_T_F32 *psParam)
{
    psParam -> f32State = MLIB_Conv_F32s(f16InitVal);
    psParam -> bReachFlag = FALSE;   
}
 
#if defined(__cplusplus) 
} 
#endif 

#endif /* _GFLIB_DFLEXRAMP_A32_H_ */
