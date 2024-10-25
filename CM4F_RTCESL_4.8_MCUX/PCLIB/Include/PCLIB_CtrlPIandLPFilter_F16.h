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
#ifndef _PCLIB_CTRLPILP_F16_H_
#define _PCLIB_CTRLPILP_F16_H_

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
#define PCLIB_CtrlPIandLPInit_F16_C(psParam)       PCLIB_CtrlPIandLPInit_F16_FC(psParam)
#define PCLIB_CtrlPIandLP_F16_C(f16InErr, psParam) PCLIB_CtrlPIandLP_F16_FC(f16InErr, psParam)

/*******************************************************************************
* Types
*******************************************************************************/
typedef struct
{
    frac16_t f16CoeffB0;         /*!< Controller coefficient for present error. */
    frac16_t f16CoeffB1;         /*!< Controller coefficient for past error. */
    frac16_t f16CoeffB2;         /*!< Controller coefficient for past to past error. */
    frac16_t f16CoeffA1;         /*!< Controller coefficient for past result. */
    frac16_t f16CoeffA2;         /*!< Controller coefficient for past to past result. */
    frac16_t f16DelayX1;         /*!< Controller delay parameter, past error. */
    frac16_t f16DelayX2;         /*!< Controller delay parameter, past to past error. */
    frac16_t f16DelayY1;         /*!< Controller delay parameter, past result. */
    frac16_t f16DelayY2;         /*!< Controller delay parameter, past to past result. */
} PCLIB_CTRL_PI_LP_T_F16;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
extern void PCLIB_CtrlPIandLPInit_F16_FC(PCLIB_CTRL_PI_LP_T_F16 *psParam);
extern frac16_t PCLIB_CtrlPIandLP_F16_FC(frac16_t f16InErr, PCLIB_CTRL_PI_LP_T_F16 *psParam);


#if defined(__cplusplus)
}
#endif

#endif /* _PCLIB_CTRLPILP_F16_H_ */
