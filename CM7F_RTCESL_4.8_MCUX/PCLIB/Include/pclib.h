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
* @brief  Main PCLIB header file for devices without FPU.
* 
*******************************************************************************/

#ifndef _PCLIB_H_
#define _PCLIB_H_

#if defined(__cplusplus)
extern "C" {
#endif

/******************************************************************************
* Includes
******************************************************************************/
#include "PCLIB_Ctrl2P2Z_F16.h"
#include "PCLIB_Ctrl3P3Z_F16.h"
#include "PCLIB_CtrlPID_F16.h"
#include "PCLIB_CtrlPI_F16.h"
#include "PCLIB_CtrlPIandLPFilter_F16.h"

/*******************************************************************************
* Macros
*******************************************************************************/
#if ( defined(RAM_RELOCATION))

#define PCLIB_Ctrl2P2ZInit_F16(psParam)          PCLIB_Ctrl2P2ZInit_F16_CRam(psParam)
#define PCLIB_Ctrl2P2Z_F16(f16InErr, psParam)    PCLIB_Ctrl2P2Z_F16_CRam(f16InErr, psParam)
#define PCLIB_Ctrl3P3ZInit_F16(psParam)          PCLIB_Ctrl3P3ZInit_F16_CRam(psParam)
#define PCLIB_Ctrl3P3Z_F16(f16InErr, psParam)    PCLIB_Ctrl3P3Z_F16_CRam(f16InErr, psParam)
#define PCLIB_CtrlPIInit_F16(psParam)            PCLIB_CtrlPIInit_F16_CRam(psParam)
#define PCLIB_CtrlPI_F16(f16InErr, psParam)      PCLIB_CtrlPI_F16_CRam(f16InErr, psParam)
#define PCLIB_CtrlPIandLPInit_F16(psParam)       PCLIB_CtrlPIandLPInit_F16_CRam(psParam)
#define PCLIB_CtrlPIandLP_F16(f16InErr, psParam) PCLIB_CtrlPIandLP_F16_CRam(f16InErr, psParam)
#define PCLIB_CtrlPIDInit_F16(psParam)           PCLIB_CtrlPIDInit_F16_CRam(psParam)
#define PCLIB_CtrlPID_F16(f16InErr, psParam)     PCLIB_CtrlPID_F16_CRam(f16InErr, psParam)

#else
	
#define PCLIB_Ctrl2P2ZInit_F16(psParam)          PCLIB_Ctrl2P2ZInit_F16_C(psParam)
#define PCLIB_Ctrl2P2Z_F16(f16InErr, psParam)    PCLIB_Ctrl2P2Z_F16_C(f16InErr, psParam)
#define PCLIB_Ctrl3P3ZInit_F16(psParam)          PCLIB_Ctrl3P3ZInit_F16_C(psParam)
#define PCLIB_Ctrl3P3Z_F16(f16InErr, psParam)    PCLIB_Ctrl3P3Z_F16_C(f16InErr, psParam)
#define PCLIB_CtrlPIInit_F16(psParam)            PCLIB_CtrlPIInit_F16_C(psParam)
#define PCLIB_CtrlPI_F16(f16InErr, psParam)      PCLIB_CtrlPI_F16_C(f16InErr, psParam)
#define PCLIB_CtrlPIandLPInit_F16(psParam)       PCLIB_CtrlPIandLPInit_F16_C(psParam)
#define PCLIB_CtrlPIandLP_F16(f16InErr, psParam) PCLIB_CtrlPIandLP_F16_C(f16InErr, psParam)
#define PCLIB_CtrlPIDInit_F16(psParam)           PCLIB_CtrlPIDInit_F16_C(psParam)
#define PCLIB_CtrlPID_F16(f16InErr, psParam)     PCLIB_CtrlPID_F16_C(f16InErr, psParam)

#endif /* defined(RAM_RELOCATION) */

#if defined(__cplusplus)
}
#endif  
  
#endif /* _PCLIB_H_ */
