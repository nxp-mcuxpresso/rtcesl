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
* @brief  Reciprocal value
* 
*******************************************************************************/
#ifndef _MLIB_RCPHW1Q_A32_ASM_H_
#define _MLIB_RCPHW1Q_A32_ASM_H_

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
#define MLIB_RcpHw1Q1_A32s_Asmi(f16Denom) MLIB_RcpHw1Q_A32s_FAsmi(f16Denom)
#define MLIB_RcpHw1Q_A32s_Asmi(f16Denom)  MLIB_RcpHw1Q_A32s_FAsmi(f16Denom)

/*******************************************************************************
* @brief    16-bit input 32-output 16-bit precision one quadrant reciprocal 
*           function
*  
* @param    in      frac16_t f16Denom
*                     - Denominator in <0;1) in frac16_t
* @return   This function returns
*                   acc32_t value [1;65536.0)
*
* @remarks  This function calculates the multiplicative inverse value of
*           the fractional input:
*           result = FRAC16(1) / f16Denom. The function calculates
*           the result with 16-bit division precision.
*           If the denominator is 0, the output is 0x7FFF FFFF.
*
*******************************************************************************/
#if defined(__IAR_SYSTEMS_ICC__)           /* IAR compiler */
#pragma diag_suppress=Pe549                /* Suppresses the Pe549 warning for IAR compiler*/
#endif
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET
static inline acc32_t MLIB_RcpHw1Q_A32s_FAsmi(register frac16_t f16Denom)
{
  register acc32_t a32Result = 0x7FFFFFFF;
  register frac32_t f32BasePtr = (frac32_t)0xF0004000U;
  register frac32_t f32Num = 0x40000000;
  register frac32_t f32Temp1=0, f32Temp2=0;

    #if defined(__CC_ARM)                                        /* For ARM Compiler */
        __asm volatile{ sxth    f16Denom, f16Denom               /* Converts 16 input to 32-bit value */
                        cmp     f16Denom, #0                     /* Compares Denominator with 0 */
                        beq     RcpHw1Q_A32s_End                 /* If Denominator = 0, then goes to RcpHw1Q_A32s_End */
                        ldrh    f32Temp1, [&gu16CntMmdvsq]       /* f32Temp1 = gu16CntMmdvsq */
                    RcpHw1Q_A32s_Recount:    
                        adds    f32Temp2, f32Temp1, #1           /* f32Temp2 = gu16CntMmdvsq + 1 */
                        strh    f32Temp2, [&gu16CntMmdvsq]       /* gu16CntMmdvsq = f32Temp2 */
                        movs    f32Temp1, #0                     /* f32TestVal = 0 */
                        str     f32Temp1, [f32BasePtr, #8]       /* MMDVSQ_CSR = 0x00000000 */
                        str     f32Num, [f32BasePtr]             /* MMDVSQ_DEND = f32Num */
                        str     f16Denom, [f32BasePtr, #4]       /* MMDVSQ_DSOR = f16Denom */
                        ldr     a32Result, [f32BasePtr, #12]     /* a32Result = MMDVSQ_RES */
                        ldrh    f32Temp1, [&gu16CntMmdvsq]       /* f32Temp1 = gu16CntMmdvsq */
                        cmp     f32Temp1, f32Temp2               /* Compares f32Temp1 and f32Temp2 */
                        bne     RcpHw1Q_A32s_Recount             /* If f32Temp1 != f32Temp2, then goes to RcpHw1Q_A32s_Recount */
                    RcpHw1Q_A32s_End:  };  
    #elif defined(__GNUC__) && defined(__ARMCC_VERSION)   
        __asm volatile(  
                        "sxth    %0, %0 \n\t"                    /* Converts 16 input to 32-bit value */
                        "cmp     %0, #0 \n\t"                    /* Compares Denominator with 0 */
                        "beq     MLIB_RcpHw1Q_A32s_End%= \n\t"   /* If Denominator = 0, then goes to RcpHw1Q_A32s_End */
                        "ldrh    %2, [%4] \n\t"                  /* f32Temp1 = gu16CntMmdvsq */
                    "MLIB_RcpHw1Q_A32s_Recount%=: \n\t"  
                        "adds    %3, %2, #1 \n\t"                /* f32Temp2 = gu16CntMmdvsq + 1 */
                        "strh    %3, [%4] \n\t"                  /* gu16CntMmdvsq = f32Temp2 */
                        "movs    %2, #0 \n\t"                    /* f32TestVal = 0 */
                        "str     %2, [%5, #8] \n\t"              /* MMDVSQ_CSR = 0x00000000 */
                        "str     %6, [%5] \n\t"                  /* MMDVSQ_DEND = f32Num */
                        "str     %0, [%5, #4] \n\t"              /* MMDVSQ_DSOR = f16Denom */
                        "ldr     %1, [%5, #12] \n\t"             /* f16Result = MMDVSQ_RES */
                        "ldrh    %2, [%4] \n\t"                  /* f32Temp1 = gu16CntMmdvsq */
                        "cmp     %2, %3 \n\t"                    /* Compares f32Temp1 and f32Temp2 */
                        "bne     MLIB_RcpHw1Q_A32s_Recount%= \n\t" /* If f32Temp1 != f32Temp2, then goes to RcpHw1Q_A32s_Recount */
                    "MLIB_RcpHw1Q_A32s_End%=: \n\t"
                        : "+l"(f16Denom), "+l"(a32Result), "+l"(f32Temp1), "+l"(f32Temp2): "l"(&gu16CntMmdvsq), "l"(f32BasePtr), "l"(f32Num):);
    #elif defined(__GNUC__)
        __asm volatile(
                        #if defined(__GNUC__)                    /* For GCC compiler */
                            ".syntax unified \n"                 /* Using unified asm syntax */
                        #endif    
                        "sxth    %0, %0 \n"                      /* Converts 16 input to 32-bit value */
                        "cmp     %0, #0 \n"                      /* Compares Denominator with 0 */
                        "beq     MLIB_RcpHw1Q_A32s_FAsmi_End%= \n" /* If Denominator = 0, then goes to RcpHw1Q_A32s_End */
                        "ldrh    %2, [%4] \n"                    /* f32Temp1 = gu16CntMmdvsq */
                    "RcpHw1Q_A32s_Recount%=: \n"    
                        "adds    %3, %2, #1 \n"                  /* f32Temp2 = gu16CntMmdvsq + 1 */
                        "strh    %3, [%4] \n"                    /* gu16CntMmdvsq = f32Temp2 */
                        "movs    %2, #0 \n"                      /* f32TestVal = 0 */
                        "str     %2, [%5, #8] \n"                /* MMDVSQ_CSR = 0x00000000 */
                        "str     %6, [%5] \n"                    /* MMDVSQ_DEND = f32Num */
                        "str     %0, [%5, #4] \n"                /* MMDVSQ_DSOR = f16Denom */
                        "ldr     %1, [%5, #12] \n"               /* f16Result = MMDVSQ_RES */
                        "ldrh    %2, [%4] \n"                    /* f32Temp1 = gu16CntMmdvsq */
                        "cmp     %2, %3 \n"                      /* Compares f32Temp1 and f32Temp2 */
                        "bne     RcpHw1Q_A32s_Recount%= \n"      /* If f32Temp1 != f32Temp2, then goes to RcpHw1Q_A32s_Recount */
                    "MLIB_RcpHw1Q_A32s_FAsmi_End%=: \n"   
                        #if defined(__GNUC__)                    /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f16Denom), "+l"(a32Result), "+l"(f32Temp1), "+l"(f32Temp2): "l"(&gu16CntMmdvsq), "l"(f32BasePtr), "l"(f32Num):);
    #else
        __asm volatile(
                        #if defined(__GNUC__)                    /* For GCC compiler */
                            ".syntax unified \n"                 /* Using unified asm syntax */
                        #endif    
                        "sxth    %0, %0 \n"                      /* Converts 16 input to 32-bit value */
                        "cmp     %0, #0 \n"                      /* Compares Denominator with 0 */
                        "beq     MLIB_RcpHw1Q_A32s_FAsmi_End \n" /* If Denominator = 0, then goes to RcpHw1Q_A32s_End */
                        "ldrh    %2, [%4] \n"                    /* f32Temp1 = gu16CntMmdvsq */
                    "RcpHw1Q_A32s_Recount: \n"    
                        "adds    %3, %2, #1 \n"                  /* f32Temp2 = gu16CntMmdvsq + 1 */
                        "strh    %3, [%4] \n"                    /* gu16CntMmdvsq = f32Temp2 */
                        "movs    %2, #0 \n"                      /* f32TestVal = 0 */
                        "str     %2, [%5, #8] \n"                /* MMDVSQ_CSR = 0x00000000 */
                        "str     %6, [%5] \n"                    /* MMDVSQ_DEND = f32Num */
                        "str     %0, [%5, #4] \n"                /* MMDVSQ_DSOR = f16Denom */
                        "ldr     %1, [%5, #12] \n"               /* f16Result = MMDVSQ_RES */
                        "ldrh    %2, [%4] \n"                    /* f32Temp1 = gu16CntMmdvsq */
                        "cmp     %2, %3 \n"                      /* Compares f32Temp1 and f32Temp2 */
                        "bne     RcpHw1Q_A32s_Recount \n"        /* If f32Temp1 != f32Temp2, then goes to RcpHw1Q_A32s_Recount */
                    "MLIB_RcpHw1Q_A32s_FAsmi_End: \n"   
                        #if defined(__GNUC__)                    /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f16Denom), "+l"(a32Result), "+l"(f32Temp1), "+l"(f32Temp2): "l"(&gu16CntMmdvsq), "l"(f32BasePtr), "l"(f32Num):);
    #endif
    return a32Result;
}
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_RESTORE 

#if defined(__IAR_SYSTEMS_ICC__)           /* IAR compiler */
#pragma diag_default=Pe549
#endif

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_RCPHW1Q_A32_ASM_H_ */
