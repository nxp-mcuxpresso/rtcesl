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
* @brief  Reciprocal value
* 
*******************************************************************************/
#ifndef _MLIB_RCP_A32_ASM_H_
#define _MLIB_RCP_A32_ASM_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "mlib_types.h"

/*******************************************************************************
* Macros
*******************************************************************************/  
#define MLIB_Rcp1_A32s_Asm(f16Denom) MLIB_Rcp1_A32s_FAsm(f16Denom)
#define MLIB_Rcp_A32s_Asm(f16Denom)  MLIB_Rcp_A32s_FAsm(f16Denom)

/*******************************************************************************
* Exported function prototypes
*******************************************************************************/
extern acc32_t MLIB_Rcp1_A32s_FAsm(register frac16_t f16Denom);
extern acc32_t MLIB_Rcp_A32s_FAsm(register frac16_t f16Denom);

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_RCP_A32_ASM_H_ */
