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
* @brief  Algorithm of PMSM Back Electromotive Force observer in rotating 
*         reference frame     
* 
*******************************************************************************/
#ifndef _AMCLIB_PMSM_BEMF_OBSRVHW_A32_DQ_H_
#define _AMCLIB_PMSM_BEMF_OBSRVHW_A32_DQ_H_

#if defined(__cplusplus) 
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "gflib.h"
#include "AMCLIB_PMSMBemfObsrvDQ_A32.h"   
#include "GFLIB_AtanYXHw_F32.h"
    
/*******************************************************************************
* Macros 
*******************************************************************************/    
#define AMCLIB_PMSMBemfObsrvDQHw_F16_C(psIDQ, psUDQ, f16Speed, psCtrl)       \
        AMCLIB_PMSMBemfObsrvDQHw_F16_FC(psIDQ, psUDQ, f16Speed, psCtrl)
#define AMCLIB_PMSMBemfObsrvDQHw_F16_Asm(psIDQ, psUDQ, f16Speed, psCtrl)     \
        AMCLIB_PMSMBemfObsrvDQHw_F16_FAsm(psIDQ, psUDQ, f16Speed, psCtrl)

/*******************************************************************************
* Types
*******************************************************************************/

   
/*******************************************************************************
* Exported function prototypes
*******************************************************************************/
extern frac16_t AMCLIB_PMSMBemfObsrvDQHw_F16_FC(const GMCLIB_2COOR_DQ_T_F16 *psIDQ,
                                                const GMCLIB_2COOR_DQ_T_F16 *psUDQ,
                                                frac16_t f16Speed, 
                                                AMCLIB_BEMF_OBSRV_DQ_T_A32 *psCtrl);

extern frac16_t AMCLIB_PMSMBemfObsrvDQHw_F16_FAsm(const GMCLIB_2COOR_DQ_T_F16 *psIDQ,
                                                  const GMCLIB_2COOR_DQ_T_F16 *psUDQ,
                                                  frac16_t f16Speed,
                                                  AMCLIB_BEMF_OBSRV_DQ_T_A32 *psCtrl);
#if defined(__cplusplus) 
}
#endif

#endif /* _AMCLIB_PMSM_BEMF_OBSRVHW_A32_DQ_H_ */       
