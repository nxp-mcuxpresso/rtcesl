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
****************************************************************************/
#ifndef _PCLIB_CTRLPID_F16_H_
#define _PCLIB_CTRLPID_F16_H_

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
#define PCLIB_CtrlPIDInit_F16_C(psParam)       PCLIB_CtrlPIDInit_F16_FC(psParam)
#define PCLIB_CtrlPID_F16_C(f16InErr, psParam) PCLIB_CtrlPID_F16_FC(f16InErr, psParam)

/*******************************************************************************
* Types
*******************************************************************************/
typedef struct
{
    frac16_t f16Ka;          /* Controller coefficient for present error. */ 
    frac16_t f16Kb;          /* Controller coefficient for past error. */
    frac16_t f16Kc;          /* Controller coefficient for past to past error. */
    frac16_t f16DelayX1;     /* Controller delay parameter, past error. */
    frac16_t f16DelayX2;     /* Controller delay parameter, past to past error. */
    frac16_t f16DelayY1;     /* Controller delay parameter, past result. */
    frac16_t f16UpperLimit;  /* Control Loop Output Upper Limit */
    frac16_t f16LowerLimit;  /* Control Loop Output Lower Limit */
} PCLIB_CTRL_PID_T_F16;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
extern void PCLIB_CtrlPIDInit_F16_FC(PCLIB_CTRL_PID_T_F16 *psParam);
extern frac16_t PCLIB_CtrlPID_F16_FC(frac16_t f16InErr, PCLIB_CTRL_PID_T_F16 *psParam);


#if defined(__cplusplus)
}
#endif

#endif /* _PCLIB_CTRLPID_F16_H_ */
