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
****************************************************************************/
#ifndef _PCLIB_CTRLPI_F16_H_
#define _PCLIB_CTRLPI_F16_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "mlib.h"
#include "pclib_types.h"

/*******************************************************************************
* Macros 
*******************************************************************************/  
#define PCLIB_CtrlPIInit_F16_C(psParam)       PCLIB_CtrlPIInit_F16_FC(psParam)
#define PCLIB_CtrlPIInit_F16_CRam(psParam)       PCLIB_CtrlPIInit_F16_FCRam(psParam)
#define PCLIB_CtrlPI_F16_C(f16InErr, psParam) PCLIB_CtrlPI_F16_FC(f16InErr, psParam) 
#define PCLIB_CtrlPI_F16_CRam(f16InErr, psParam) PCLIB_CtrlPI_F16_FCRam(f16InErr, psParam) 

/*******************************************************************************
* Types
*******************************************************************************/
typedef struct
{
    frac16_t f16Kp;                     /* Proportional Gain. */  
    frac16_t f16Ki;                     /* Integral Gain. */
    frac16_t f16IntegralUpperLimit;     /* Integral Upper limit */
    frac16_t f16IntegralLowerLimit;     /* Integral Lower limit */
    frac16_t f16PreviousIntegralOutput; /* Previous Integral output (n-1) */ 
    frac16_t f16UpperLimit;             /* Control Loop Output Upper Limit */
    frac16_t f16LowerLimit;             /* Control Loop Output Lower Limit */
} PCLIB_CTRL_PI_T_F16;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
RAM_FUNC_LIB
extern void PCLIB_CtrlPIInit_F16_FCRam(PCLIB_CTRL_PI_T_F16 *psParam);

extern void PCLIB_CtrlPIInit_F16_FC(PCLIB_CTRL_PI_T_F16 *psParam);

RAM_FUNC_LIB
extern frac16_t PCLIB_CtrlPI_F16_FCRam(frac16_t f16InErr, PCLIB_CTRL_PI_T_F16 *psParam);

extern frac16_t PCLIB_CtrlPI_F16_FC(frac16_t f16InErr, PCLIB_CTRL_PI_T_F16 *psParam);

#if defined(__cplusplus)
}
#endif

#endif /* _PCLIB_CTRLPI_F16_H_ */
