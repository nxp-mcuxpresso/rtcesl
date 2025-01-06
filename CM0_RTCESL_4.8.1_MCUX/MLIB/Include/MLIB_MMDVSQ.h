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
* @brief  MLIB_MMDVSQ.h
* 
*******************************************************************************/
#ifndef _MLIB_MMDVSQ_H_
#define _MLIB_MMDVSQ_H_

#if defined(__cplusplus)
extern "C" {
#endif

/******************************************************************************
* Includes
******************************************************************************/   
#include "mlib_types.h"

/*******************************************************************************
* Macros
*******************************************************************************/    
/* Base address of Memory-Mapped Divide and Square Root peripheral module(MMDVSQ) */ 
#define RTCESL_MMDVSQ_BASE_PTR 0xF0004000U

/* MMDVSQ registers definitions
*  Absolute      Register name                        Width      Access Reset value
*  address (hex)                                      (in bits)
*  F000_4000     Dividend Register (MMDVSQ_DEND)      32         R/W    Undefined
*  F000_4004     Divisor Register (MMDVSQ_DSOR)       32         R/W    Undefined
*  F000_4008     Control/Status Register (MMDVSQ_CSR) 32         R/W    Some bits undefined
*  F000_400C     Result Register (MMDVSQ_RES)         32         R/W    Undefined
*  F000_4010     Radicand Register (MMDVSQ_RCND)      32         W      Undefined    */
    
#define RTCESL_MMDVSQ_DEND  *(volatile unsigned int*)(RTCESL_MMDVSQ_BASE_PTR + 0x0U)
#define RTCESL_MMDVSQ_DSOR  *(volatile unsigned int*)(RTCESL_MMDVSQ_BASE_PTR + 0x4U)
#define RTCESL_MMDVSQ_CSR   *(volatile unsigned int*)(RTCESL_MMDVSQ_BASE_PTR + 0x8U)
#define RTCESL_MMDVSQ_RES   *(volatile unsigned int*)(RTCESL_MMDVSQ_BASE_PTR + 0xCU)
#define RTCESL_MMDVSQ_RCND  *(volatile unsigned int*)(RTCESL_MMDVSQ_BASE_PTR + 0x10U)

/*******************************************************************************
* Variables
*******************************************************************************/    
/* Global variable which store actual MMDVSQ state to avoid register 
   rewriting during interrupt service routine handling */  
extern volatile uint16_t gu16CntMmdvsq;  

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_MMDVSQ_H_ */  


