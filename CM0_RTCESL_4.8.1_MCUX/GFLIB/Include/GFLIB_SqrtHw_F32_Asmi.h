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
* @brief  Hardware Square root
* 
*******************************************************************************/
#ifndef _GFLIB_SQRTHW_F32_ASMI_H_
#define _GFLIB_SQRTHW_F32_ASMI_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "MLIB_MMDVSQ.h"

/*******************************************************************************
* Macros 
*******************************************************************************/ 
#define GFLIB_SqrtHw_F16l_Asmi(f32Val) GFLIB_SqrtHw_F16l_FAsmi(f32Val)

/***************************************************************************//*!
* @brief        This function returns the square root of input value.
*
* @param[in]         f32Val      The input value.
*
* @return      The function returns the square root of the input value. The
*              return value is within the [0, 1) 16 bit fraction range.
*              If input is <= 0, then the function returns 0. 
*
*              The computations are made by hardware MMDVSQ
*
*
****************************************************************************/
#if defined(__IAR_SYSTEMS_ICC__)           /* IAR compiler */
#pragma diag_suppress=Pe549  /* Suppresses the Pe549 warning for IAR compiler*/
#endif
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET
static inline frac16_t GFLIB_SqrtHw_F16l_FAsmi(register frac32_t f32Val)
{
  register frac32_t f32BasePtr = (frac32_t)0xF0004000U;
  register frac16_t f16Result=0;
  register frac32_t f32Temp1=0, f32Temp2=0;

    #if defined(__CC_ARM)                                        /* For ARM Compiler */
        __asm volatile{ movs    f16Result, #0                    /* f16Result = 0 */
                        asrs    f32Val, f32Val, #1               /* f32Val >> 1 */
                        bmi     SqrtHw_F16l_End                  /* If f32Val < 0, then goes to SqrtHw_F16l_End */
                        ldrh    f32Temp1, [&gu16CntMmdvsq]       /* f32Temp1 = gu16CntMmdvsq */
                    SqrtHw_F16l_Recount:    
                        adds    f32Temp2, f32Temp1, #1           /* f32Temp2 = gu16CntMmdvsq + 1 */
                        strh    f32Temp2, [&gu16CntMmdvsq]       /* gu16CntMmdvsq = f32Temp2 */
                        movs    f32Temp1, #0                     /* f32TestVal = 0 */
                        str     f32Temp1, [f32BasePtr, #8]       /* MMDVSQ_CSR = 0x00000000 */
                        str     f32Val, [f32BasePtr, #16]        /* RTCESL_MMDVSQ_RCND = f32Val */
                    SqrtHw_F16l_Wait:    
                        ldr     f32Temp1, [f32BasePtr, #8]       /* f32Temp1 = MMDVSQ_CSR */
                        lsrs    f32Temp1, f32Temp1, #31          /* f32Temp1 >> 31*/
                        bne     SqrtHw_F16l_Wait                 /* If f32Temp1 != 0, then goes to SqrtHw_F16l_Wait */
                        ldr     f16Result, [f32BasePtr, #12]     /* f16Result = MMDVSQ_RES */
                        ldrh    f32Temp1, [&gu16CntMmdvsq]       /* f32Temp1 = gu16CntMmdvsq */
                        cmp     f32Temp1, f32Temp2               /* Compares f32Temp1 and f32Temp2 */
                        bne     SqrtHw_F16l_Recount              /* If f32Temp1 != f32Temp2, then goes to SqrtHw_F16l_Recount */
                    SqrtHw_F16l_End: };    
    #elif defined(__GNUC__) && defined(__ARMCC_VERSION) 
        __asm volatile( 
                        "movs    %1, #0 \n\t"                    /* f16Result = 0 */
                        "asrs    %0, %0, #1 \n\t"                /* f32Val >> 1 */
                        "bmi     GFLIB_SqrtHw_F16l_End%= \n\t"   /* If f32Val < 0, then goes to GFLIB_SqrtHw_F16l_End */
                        "ldrh    %2, [%4] \n\t"                  /* f32Temp1 = gu16CntMmdvsq */
                    "GFLIB_SqrtHw_F16l_Recount%=: \n\t"       
                        "adds    %3, %2, #1 \n\t"                /* f32Temp2 = gu16CntMmdvsq + 1 */
                        "strh    %3, [%4] \n\t"                  /* gu16CntMmdvsq = f32Temp2 */
                        "movs    %2, #0 \n\t"                    /* f32TestVal = 0 */
                        "str     %2, [%5, #8] \n\t"              /* MMDVSQ_CSR = 0x00000000 */
                        "str     %0, [%5, #16] \n\t"             /* RTCESL_MMDVSQ_RCND = f32Val */
                    "GFLIB_SqrtHw_F16l_Wait%=: \n\t"       
                        "ldr     %2, [%5, #8] \n\t"              /* f32Temp1 = MMDVSQ_CSR */
                        "lsrs    %2, %2, #31 \n\t"               /* f32Temp1 >> 31*/
                        "bne     GFLIB_SqrtHw_F16l_Wait%= \n\t"  /* If f32Temp1 != 0, then goes to GFLIB_SqrtHw_F16l_Wait */
                        "ldr     %1, [%5, #12] \n\t"             /* f16Result = MMDVSQ_RES */
                        "ldrh    %2, [%4] \n\t"                  /* f32Temp1 = gu16CntMmdvsq */
                        "cmp     %2, %3 \n\t"                    /* Compares f32Temp1 and f32Temp2 */
                        "bne     GFLIB_SqrtHw_F16l_Recount%= \n\t" /* If f32Temp1 != f32Temp2, then goes to GFLIB_SqrtHw_F16l_Recount */
                    "GFLIB_SqrtHw_F16l_End%=: \n\t"
                        : "+l"(f32Val), "+l"(f16Result), "+l"(f32Temp1), "+l"(f32Temp2): "l"(&gu16CntMmdvsq), "l"(f32BasePtr):);
    #elif defined(__GNUC__)
        __asm volatile(
                        #if defined(__GNUC__)                    /* For GCC compiler */
                            ".syntax unified \n"                 /* Using unified asm syntax */
                        #endif    
                        "movs    %1, #0 \n"                      /* f16Result = 0 */
                        "asrs    %0, %0, #1 \n"                  /* f32Val >> 1 */
                        "bmi     SqrtHw_F16l_End%= \n"           /* If f32Val < 0, then goes to SqrtHw_F16l_End */
                        "ldrh    %2, [%4] \n"                    /* f32Temp1 = gu16CntMmdvsq */
                    "SqrtHw_F16l_Recount%=: \n"    
                        "adds    %3, %2, #1 \n"                  /* f32Temp2 = gu16CntMmdvsq + 1 */
                        "strh    %3, [%4] \n"                    /* gu16CntMmdvsq = f32Temp2 */
                        "movs    %2, #0 \n"                      /* f32TestVal = 0 */
                        "str     %2, [%5, #8] \n"                /* MMDVSQ_CSR = 0x00000000 */
                        "str     %0, [%5, #16] \n"               /* RTCESL_MMDVSQ_RCND = f32Val */
                    "SqrtHw_F16l_Wait%=: \n"    
                        "ldr     %2, [%5, #8] \n"                /* f32Temp1 = MMDVSQ_CSR */
                        "lsrs    %2, %2, #31 \n"                 /* f32Temp1 >> 31*/
                        "bne     SqrtHw_F16l_Wait%= \n"          /* If f32Temp1 != 0, then goes to SqrtHw_F16l_Wait */
                        "ldr     %1, [%5, #12] \n"               /* f16Result = MMDVSQ_RES */
                        "ldrh    %2, [%4] \n"                    /* f32Temp1 = gu16CntMmdvsq */
                        "cmp     %2, %3 \n"                      /* Compares f32Temp1 and f32Temp2 */
                        "bne     SqrtHw_F16l_Recount%= \n"       /* If f32Temp1 != f32Temp2, then goes to SqrtHw_F16l_Recount */
                    "SqrtHw_F16l_End%=: \n"    
                        #if defined(__GNUC__)                    /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f32Val), "+l"(f16Result), "+l"(f32Temp1), "+l"(f32Temp2): "l"(&gu16CntMmdvsq), "l"(f32BasePtr):);
    #else
        __asm volatile(
                        #if defined(__GNUC__)                    /* For GCC compiler */
                            ".syntax unified \n"                 /* Using unified asm syntax */
                        #endif    
                        "movs    %1, #0 \n"                      /* f16Result = 0 */
                        "asrs    %0, %0, #1 \n"                  /* f32Val >> 1 */
                        "bmi     SqrtHw_F16l_End \n"             /* If f32Val < 0, then goes to SqrtHw_F16l_End */
                        "ldrh    %2, [%4] \n"                    /* f32Temp1 = gu16CntMmdvsq */
                    "SqrtHw_F16l_Recount: \n"    
                        "adds    %3, %2, #1 \n"                  /* f32Temp2 = gu16CntMmdvsq + 1 */
                        "strh    %3, [%4] \n"                    /* gu16CntMmdvsq = f32Temp2 */
                        "movs    %2, #0 \n"                      /* f32TestVal = 0 */
                        "str     %2, [%5, #8] \n"                /* MMDVSQ_CSR = 0x00000000 */
                        "str     %0, [%5, #16] \n"               /* RTCESL_MMDVSQ_RCND = f32Val */
                    "SqrtHw_F16l_Wait: \n"    
                        "ldr     %2, [%5, #8] \n"                /* f32Temp1 = MMDVSQ_CSR */
                        "lsrs    %2, %2, #31 \n"                 /* f32Temp1 >> 31*/
                        "bne     SqrtHw_F16l_Wait \n"            /* If f32Temp1 != 0, then goes to SqrtHw_F16l_Wait */
                        "ldr     %1, [%5, #12] \n"               /* f16Result = MMDVSQ_RES */
                        "ldrh    %2, [%4] \n"                    /* f32Temp1 = gu16CntMmdvsq */
                        "cmp     %2, %3 \n"                      /* Compares f32Temp1 and f32Temp2 */
                        "bne     SqrtHw_F16l_Recount \n"         /* If f32Temp1 != f32Temp2, then goes to SqrtHw_F16l_Recount */
                    "SqrtHw_F16l_End: \n"    
                        #if defined(__GNUC__)                    /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f32Val), "+l"(f16Result), "+l"(f32Temp1), "+l"(f32Temp2): "l"(&gu16CntMmdvsq), "l"(f32BasePtr):);
    #endif
    return f16Result;
}
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_RESTORE 

#if defined(__IAR_SYSTEMS_ICC__)           /* IAR compiler */
#pragma diag_default=Pe549
#endif

#if defined(__cplusplus)
}
#endif

#endif /* _GFLIB_SQRTHW_F32_ASMI_H_ */

