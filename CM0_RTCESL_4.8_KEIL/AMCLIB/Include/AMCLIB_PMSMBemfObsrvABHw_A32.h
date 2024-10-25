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
* @brief  Algorithm of PMSM Back Electromotive Force observer in stationary 
*         reference frame
* 
*******************************************************************************/
#ifndef _AMCLIB_PMSM_BEMF_OBSRVHW_A32_AB_H_
#define _AMCLIB_PMSM_BEMF_OBSRVHW_A32_AB_H_

#if defined(__cplusplus) 
extern "C" { 
#endif 
/******************************************************************************
* Includes
******************************************************************************/
#include "gflib.h"
#include "gmclib.h"
#include "AMCLIB_PMSMBemfObsrvAB_A32.h"
    
/******************************************************************************
* Macros 
******************************************************************************/
#define AMCLIB_PMSMBemfObsrvABHw_F16_C(psIAlBe, psUAlBe, f16Speed, psCtrl)     \
        AMCLIB_PMSMBemfObsrvABHw_F16_FC(psIAlBe, psUAlBe, f16Speed, psCtrl)
/******************************************************************************
* Types
******************************************************************************/

   
/******************************************************************************
* Exported function prototypes
******************************************************************************/
extern void AMCLIB_PMSMBemfObsrvABHw_F16_FC(const GMCLIB_2COOR_ALBE_T_F16 *psIAlBe,
                                            const GMCLIB_2COOR_ALBE_T_F16 *psUAlBe,
                                            frac16_t f16Speed,
                                            AMCLIB_BEMF_OBSRV_AB_T_A32 *psCtrl);

/******************************************************************************
* Inline functions
******************************************************************************/

 
#if defined(__cplusplus) 
} 
#endif 

#endif /* _AMCLIB_PMSM_BEMF_OBSRVHW_A32_AB_H_ */    
