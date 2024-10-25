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
* @brief  RTCESL configuration file
* 
*******************************************************************************/
#ifndef _RTCESL_CFG_H_
#define _RTCESL_CFG_H_

#if defined(__cplusplus)
extern "C" {
#endif 
    
/*******************************************************************************
* RTCESL vesion 
*******************************************************************************/  
/* RTCESL version is 4.8 */  
#define RTCESL_VERSION 4.8

  
/*******************************************************************************
* Macros 
*******************************************************************************/  
#define RTCESL_ON 1
#define RTCESL_OFF 0    
    
/*******************************************************************************
* User Modified Macros 
*******************************************************************************/        
/* CORDIC RTCESL_ON/RTCESL_OFF configuration. CORDIC hardware accelerator 
*  for (fixed and floating point unit) CMSIS DSP functions with support of software 
*  API faster execution of ARM CMSIS instruction set. 
*  It is recommended to use PQ for LPC55S6x/LPC55S2x/LPC552x devices, 
*  because some function are quicker. */
    
/* The PQ can be enabled or disabled by the definition of the symbol in IDE
*  preprocessor setting.
*  To enable PQ module please define symbol: RTCESL_CORDIC_ON, to disable the PQ please
*  define RTCESL_CORDIC_OFF (All functions will be calculated by core).
*
*  If no symbol RTCESL_CORDIC_XXX is defined the RTCESL_CORDIC setting will be taken from 
*  this header file, see next paragraph. */
    
#if (defined (RTCESL_CORDIC_ON))   
    #define RTCESL_CORDIC RTCESL_ON
#elif (defined (RTCESL_CORDIC_OFF))
    #define RTCESL_CORDIC RTCESL_OFF
#else    
    /* User option to enable or disable PQ module when IDE preprocessor setting 
    *  was not used. Set the following define as RTCESL_ON or RTCESL_OFF to enable or  
    *  disable hardware PQ support. */  
    
    /* Next line can be modified by user */
    #define RTCESL_CORDIC RTCESL_OFF  
    
    /* Independent function call can be used as well, for example
    *  MLIB_Div_F16 ... depend on setting
    *  MLIB_DivCORDIC_F16_C always make calculation in PQ module
    *  MLIB_Div_F16_Ci always make calculation in core */ 
#endif     

/* Warning if RTCESL_CORDIC was not correctly defined */   
#ifndef RTCESL_CORDIC 
    #warning "RTCESL_CORDIC was not defined !" 
#endif    
/* Warning if RTCESL_CORDIC_ON and RTCESL_CORDIC_OFF are defined in IDE */       
#if defined(RTCESL_CORDIC_ON) && defined(RTCESL_CORDIC_OFF)
    #warning "RTCESL_CORDIC_ON and RTCESL_CORDIC_OFF are defined !" 
#endif       

#define RAM_FUNC_LIB                              /* function executed from ROM */
     
#if defined(__cplusplus)
}
#endif

#endif  /*_RTCESL_CFG_H_*/
