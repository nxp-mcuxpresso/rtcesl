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
* @brief  Vector limit functions with 16-bit and 32-bit fractional output
* 
*******************************************************************************/
#ifndef _GFLIB_VECTORLIMIT1HW_F16_H_
#define _GFLIB_VECTORLIMIT1HW_F16_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "mlib.h" 
#include "GFLIB_SqrtHw_F32.h"
#include "GFLIB_VectorLimit1_F16.h"
    
/*******************************************************************************
* Macros 
*******************************************************************************/  
#define GFLIB_VectorLimit1Hw_F16_C(psVectorIn, f16Lim, psVectorOut)              \
        GFLIB_VectorLimit1Hw_F16_FC(psVectorIn, f16Lim, psVectorOut)
/*******************************************************************************
* Types
*******************************************************************************/  


/*******************************************************************************
* Exported function prototypes
*******************************************************************************/
extern bool_t GFLIB_VectorLimit1Hw_F16_FC(const GFLIB_VECTORLIMIT_T_F16 *psVectorIn, 
                                          frac16_t f16Lim, 
                                          GFLIB_VECTORLIMIT_T_F16 *psVectorOut);

#if defined(__cplusplus)
}
#endif

#endif /* _GFLIB_VECTORLIMIT1HW_F16_H_ */
