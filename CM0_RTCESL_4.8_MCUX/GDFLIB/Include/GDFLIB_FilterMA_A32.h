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
* @brief  Moving average filter 
* 
*******************************************************************************/
#ifndef _GDFLIB_FILTERMA_A32_H_
#define _GDFLIB_FILTERMA_A32_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "gdflib_types.h"
#include "mlib.h"

/*******************************************************************************
* Macros 
*******************************************************************************/
#define GDFLIB_FilterMAInit_F16_Ci(f16InitVal, psParam)                       \
        GDFLIB_FilterMAInit_F16_FCi(f16InitVal, psParam)                      

/*******************************************************************************
* Types
*******************************************************************************/
typedef struct{
    acc32_t  a32Acc;   /* Filter accumulator. */
    uint16_t u16Sh;    /* Number of samples for averaging, filter sample window [0,15].*/
}GDFLIB_FILTER_MA_T_A32;


/***************************************************************************//*!
* @brief  The function initializes the actual values of FilterMA_F16.
*
* @param  in  frac16_t f16InitVal  - Initial value
*         ptr  GDFLIB_FILTER_MA_T_A32 *psParam - pointer to filter structure 
*
*******************************************************************************/
static inline void GDFLIB_FilterMAInit_F16_FCi(frac16_t f16InitVal,
                                               GDFLIB_FILTER_MA_T_A32 *psParam)
{
    psParam->a32Acc = (acc32_t)MLIB_ShLSat_F32(f16InitVal, psParam->u16Sh) - (acc32_t)f16InitVal; 
}
#if defined(__cplusplus)
}
#endif

#endif /* _GDFLIB_FILTERMA_A32_H_ */
