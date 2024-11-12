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
* @brief  Elimination of the DC-Bus voltage ripple with index
* 
*******************************************************************************/
#ifndef _GMCLIB_ELIMDCBUSRIP_A32_H_
#define _GMCLIB_ELIMDCBUSRIP_A32_H_

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
#define GMCLIB_ElimDcBusRip_F16sas_C(f16UDCBus, a32IdxMod, psUAlBe, psUAlBeComp)    \
        GMCLIB_ElimDcBusRip_F16sas_FC(f16UDCBus, a32IdxMod, psUAlBe, psUAlBeComp)   
#define GMCLIB_ElimDcBusRip_F16sas_Asm(f16UDCBus, a32IdxMod, psUAlBe, psUAlBeComp)  \
        GMCLIB_ElimDcBusRip_F16sas_FAsm(f16UDCBus, a32IdxMod, psUAlBe, psUAlBeComp)
/*******************************************************************************
* Exported function prototypes
*******************************************************************************/
extern void GMCLIB_ElimDcBusRip_F16sas_FC(frac16_t f16UDCBus,
                                          acc32_t a32IdxMod, 
                                          const GMCLIB_2COOR_ALBE_T_F16 *psUAlBe,
                                          GMCLIB_2COOR_ALBE_T_F16 *psUAlBeComp);
extern void GMCLIB_ElimDcBusRip_F16sas_FAsm(frac16_t f16UDCBus,
                                            acc32_t a32IdxMod,
                                            const GMCLIB_2COOR_ALBE_T_F16 *psUAlBe,
                                            GMCLIB_2COOR_ALBE_T_F16 *psUAlBeComp);
#if defined(__cplusplus) 
}
#endif

#endif  /* _GMCLIB_ELIMDCBUSRIP_A32_H_ */
