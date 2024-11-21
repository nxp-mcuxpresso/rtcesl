/*******************************************************************************
*
* Copyright (c) 2013 - 2016, Freescale Semiconductor, Inc.
* Copyright 2016-2019, 2024 NXP
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
* @brief  Space vector modulation functions in assembler
* 
*******************************************************************************/
#ifndef _GMCLIB_SVM_F16_ASM_H_
#define _GMCLIB_SVM_F16_ASM_H_

#if defined(__cplusplus) 
extern "C" { 
#endif 
/******************************************************************************
* Includes
******************************************************************************/
#include "mlib.h"
#include "gmclib_types.h"

/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros 
******************************************************************************/
#define	GMCLIB_SvmStd_F16_Asm(psIn, psOut) GMCLIB_SvmStd_F16_FAsm(psIn, psOut)
#define	GMCLIB_SvmIct_F16_Asm(psIn, psOut) GMCLIB_SvmIct_F16_FAsm(psIn, psOut)
#define	GMCLIB_SvmU0n_F16_Asm(psIn, psOut) GMCLIB_SvmU0n_F16_FAsm(psIn, psOut)
#define	GMCLIB_SvmU7n_F16_Asm(psIn, psOut) GMCLIB_SvmU7n_F16_FAsm(psIn, psOut)

/******************************************************************************
* Types
******************************************************************************/

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/

extern asm uint16_t GMCLIB_SvmStd_F16_FAsm(const GMCLIB_2COOR_ALBE_T_F16 *psIn, GMCLIB_3COOR_T_F16 *psOut);
    
extern asm uint16_t GMCLIB_SvmIct_F16_FAsm(const GMCLIB_2COOR_ALBE_T_F16 *psIn, GMCLIB_3COOR_T_F16 *psOut);                            

extern asm uint16_t GMCLIB_SvmU0n_F16_FAsm(const GMCLIB_2COOR_ALBE_T_F16 *psIn, GMCLIB_3COOR_T_F16 *psOut);                            

extern asm uint16_t GMCLIB_SvmU7n_F16_FAsm(const GMCLIB_2COOR_ALBE_T_F16 *psIn, GMCLIB_3COOR_T_F16 *psOut);                            


/******************************************************************************
* Inline functions
******************************************************************************/
#if defined(__cplusplus) 
} 
#endif 

#endif /* _GMCLIB_SVM_F16_ASM_H_ */

