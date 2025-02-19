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
* @brief  Function is used for elimination of the DC-Bus voltage ripple
* 
*******************************************************************************/
#ifndef _GMCLIB_ELIMDCBUSRIP_F16_ASM_H_
#define _GMCLIB_ELIMDCBUSRIP_F16_ASM_H_

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
#define GMCLIB_ElimDcBusRip_F16sas_Asm(f16UDCBus, a32IdxMod, psUAlBe, psUAlBeComp) \
			GMCLIB_ElimDcBusRip_F16sas_FAsm(f16UDCBus, a32IdxMod, psUAlBe, psUAlBeComp)

#define GMCLIB_ElimDcBusRipFOC_F16_Asm(f16UDCBus, psUAlBe, psUAlBeComp) \
			GMCLIB_ElimDcBusRipFOC_F16_FAsm(f16UDCBus, psUAlBe, psUAlBeComp)

/******************************************************************************
* Types
******************************************************************************/

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/

extern asm void GMCLIB_ElimDcBusRip_F16sas_FAsm(frac16_t f16UDCBus,
							    	   	   	 acc32_t a32IdxMod, 
							    	   	   	 const GMCLIB_2COOR_ALBE_T_F16 *psUAlBe,
							    	   	   	 GMCLIB_2COOR_ALBE_T_F16 *psUAlBeComp);

extern asm void GMCLIB_ElimDcBusRipFOC_F16_FAsm(frac16_t f16UDCBus, 
                        		   	      	  	const GMCLIB_2COOR_ALBE_T_F16 *psUAlBe,
                        		   	      	  	GMCLIB_2COOR_ALBE_T_F16 *psUAlBeComp);

/******************************************************************************
* Inline functions
******************************************************************************/
#if defined(__cplusplus) 
} 
#endif 

#endif /* _GMCLIB_ELIMDCBUSRIP_F16_ASM_H_ */
