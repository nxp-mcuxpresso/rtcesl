/*******************************************************************************
*
* Copyright 2013-2016 Freescale Semiconductor, Inc.
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
* @brief  MLIB_CORDIC.h
* 
*******************************************************************************/

#ifndef MLIB_CORDIC_H_
#define MLIB_CORDIC_H_
#include <stdint.h>
#include "intrinsics_56800EF.h"

#define ACC32_Q27(x) ((int32_t)((x) < 16 ? ((x) >= -16 ? (x)*0x8000000 : 0x80000000) : 0x7FFFFFFF))

#define RTCESL_CIR_VLENTH_COEFF_Q27 ACC32_Q27(0.607252935009) // circular coordinate vector length compensation coefficient
#define RTCESL_CIR_VLENTH_ARCTAN_COEFF_Q27 ACC32_Q27(0.4)
#define RTCESL_CIR_VLENTH_ARCTAN_COEFF_Q31 FRAC32(0.4)

#define HYP_VLENTH_COEFF_Q27 ACC32_Q27(1.2074970677631) // hyperbolic coordinate vector length compensation coefficient
#define HYP_VLENTH_ARCTAN_COEFF_Q27 ACC32_Q27(0.4)
#define HYP_VLENTH_SQRT_COEFF_Q31 FRAC32(1.2074970677631/2.0)


#endif /* MLIB_CORDIC_H_ */
