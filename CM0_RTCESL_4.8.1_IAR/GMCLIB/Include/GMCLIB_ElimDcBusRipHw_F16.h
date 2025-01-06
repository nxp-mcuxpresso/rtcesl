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
* @brief  Elimination of the DC-Bus voltage ripple for FOC
* 
*******************************************************************************/
#ifndef _GMCLIB_ELIMDCBUSRIPHW_F16_H_
#define _GMCLIB_ELIMDCBUSRIPHW_F16_H_

#if defined(__cplusplus) 
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/  
#include "mlib.h"
#include "gmclib_types.h"  

/*******************************************************************************
* Macros 
*******************************************************************************/     
#define GMCLIB_ElimDcBusRipFOCHw_F16_C(f16UDCBus, psUAlBe, psUAlBeComp)                    \
        GMCLIB_ElimDcBusRipFOCHw_F16_FC(f16UDCBus, psUAlBe, psUAlBeComp)                                         
#define GMCLIB_ElimDcBusRipFOCHw_F16_Asm(f16UDCBus, psUAlBe, psUAlBeComp)                  \
        GMCLIB_ElimDcBusRipFOCHw_F16_FAsm(f16UDCBus, psUAlBe, psUAlBeComp, &gu16CntMmdvsq)
/*******************************************************************************
* Exported function prototypes
*******************************************************************************/
extern void GMCLIB_ElimDcBusRipFOCHw_F16_FC(frac16_t f16UDCBus,
                                            const GMCLIB_2COOR_ALBE_T_F16 *psUAlBe,
                                            GMCLIB_2COOR_ALBE_T_F16 *psUAlBeComp);
extern void GMCLIB_ElimDcBusRipFOCHw_F16_FAsm(frac16_t f16UDCBus,
                                            const GMCLIB_2COOR_ALBE_T_F16 *psUAlBe,
                                            GMCLIB_2COOR_ALBE_T_F16 *psUAlBeComp,
                                            const volatile uint16_t *pVal);

#if defined(__cplusplus) 
}
#endif

#endif  /* _GMCLIB_ELIMDCBUSRIPHW_F16_H_ */
