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
* @brief   Flux weakening controller 
* 
*******************************************************************************/
#ifndef _AMCLIB_CTRL_FLUX_WKNG_FLT_H_
#define _AMCLIB_CTRL_FLUX_WKNG_FLT_H_

#if defined(__cplusplus) 
extern "C" { 
#endif 
/******************************************************************************
* Includes
******************************************************************************/
#include "mlib_FP.h"      
#include "gflib_FP.h"     
#include "gdflib_FP.h"    

/******************************************************************************
* Macros 
******************************************************************************/
#define AMCLIB_CtrlFluxWkng_FLT_C(fltIQErr, fltUQReq, fltUQLim, psCtrl)       \
        AMCLIB_CtrlFluxWkng_FLT_FC(fltIQErr, fltUQReq, fltUQLim, psCtrl)                        
#define AMCLIB_CtrlFluxWkngInit_FLT_Ci(fltInitVal, psCtrl)                    \
        AMCLIB_CtrlFluxWkngInit_FLT_FCi(fltInitVal, psCtrl)   

/******************************************************************************
* Types
******************************************************************************/
typedef struct
{
    /* function parameters */
    GFLIB_CTRL_PI_P_AW_T_FLT sFWPiParam;      /* PIp controller structure for FW controller */ 
    GDFLIB_FILTER_IIR1_T_FLT sIqErrIIR1Param; /* Iq error IIR filter structure for Iq measured */ 
    
    /* function parameters */
    float_t fltIqErrIIR1;     /* Iq filtered by IIR - calculated by algorithm */
    float_t fltUFWErr;        /* Required voltage error - calculated by algorithm */
    float_t fltFWErr;         /* Flux weakening error - calculated by algorithm */
    float_t fltIGainUgain;    /* Gain for proper float scaling: fltIGainUgain = IGain / Ugain, fltIGainUgain > 0 */
    bool_t  *pbStopIntegFlag; /* Flux weakening controller stop integration input flag 
                                 Set from application when saturation occurs */
} AMCLIB_CTRL_FLUX_WKNG_T_FLT;
   
/******************************************************************************
* Exported function prototypes
******************************************************************************/
extern float_t AMCLIB_CtrlFluxWkng_FLT_FC(float_t fltIQErr, float_t fltUQReq, float_t fltUQLim,
                                          AMCLIB_CTRL_FLUX_WKNG_T_FLT *psCtrl);

/***************************************************************************//*!
*
* @brief  Initialization for the Flux weakening control function
*
* @param  ptr AMCLIB_CTRL_FLUX_WKNG_T_FLT *psCtrl - Pointer to controller structure 
* @param  in  float_t fltInitVal - Initial state value for CtrlPIpAW integrating part            
*
* @return none
*
* @remarks  The function initializes Flux weakening control function by following:
*
*  - PI controller with anti-wind-up protection initialization. 
*  - Iq IIR filter initialization
*
****************************************************************************/
static inline void AMCLIB_CtrlFluxWkngInit_FLT_FCi(float_t fltInitVal,
                                                   AMCLIB_CTRL_FLUX_WKNG_T_FLT *psCtrl)
{
    GFLIB_CtrlPIpAWInit_FLT(fltInitVal, &psCtrl->sFWPiParam);
    GDFLIB_FilterIIR1Init_FLT (&psCtrl->sIqErrIIR1Param);             
}


#if defined(__cplusplus) 
} 
#endif 

#endif /* _AMCLIB_CTRL_FLUX_WKNG_FLT_H_ */
