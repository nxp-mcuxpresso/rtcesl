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
* @brief  Basic types for RTCESL
* 
*******************************************************************************/
#ifndef _MLIB_TYPES_H_
#define _MLIB_TYPES_H_

#ifdef SUPPORT_64BIT_DATA_TYPE
#pragma slld on
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/******************************************************************************
* Includes
******************************************************************************/
#include <stdint.h>                        /* stdint.h include for data types */

/*******************************************************************************
* Macros
*******************************************************************************/  
#define MLIB_CONST const 

/*******************************************************************************
* Types
*******************************************************************************/
/* Boolean data types */
typedef unsigned short bool_t;
#ifndef FALSE
#define FALSE    ((bool_t)0)                       
#endif

#ifndef TRUE
#define TRUE     ((bool_t)1)                        
#endif

/* Unsigned integer data types */
#if !defined(__MSL_BUILD__)
#if !defined( __STDINT_DECLS)
/* Signed and Unsigned integer data types */

/* 8 bits */
#if !defined( __int8_t_defined)
#if !defined(__INT8_T_TYPE__)
typedef signed char             int8_t;
#endif /* __INT8_T_TYPE__ */
#if !defined(__INT8_T_TYPE__)
typedef unsigned char           uint8_t;
#endif /* __INT8_T_TYPE__ */
#define __int8_t_defined        1
#endif /* __int8_t_defined */

/* 16 bits */
#if !defined( __int16_t_defined)
#if !defined(__INT16_T_TYPE__)
typedef signed short            int16_t;
#endif /* __INT16_T_TYPE__ */
#if !defined(__INT16_T_TYPE__)
typedef unsigned short          uint16_t;
#endif /* __INT16_T_TYPE__ */
#define __int16_t_defined       1
#endif /* __int16_t_defined */

/* 32 bits */
#if !defined( __int32_t_defined)
#if !defined(__STDINT_H_INCLUDED)
#if !defined(__INT32_T_TYPE__)
typedef signed long             int32_t;
#endif /* __INT32_T_TYPE__ */
#if !defined(__INT32_T_TYPE__)
typedef unsigned long           uint32_t;
#endif /* __INT32_T_TYPE__ */
#define __int32_t_defined       1
#endif /* __STDINT_H_INCLUDED */
#endif /* __int32_t_defined */

/* 64 bits */
#if !defined( __int64_t_defined)
#if !defined(__INT64_T_TYPE__)
typedef signed long long        int64_t;
#endif /* __INT64_T_TYPE__ */
#if !defined(__INT64_T_TYPE__)
typedef unsigned long long      uint64_t;
#endif /* __INT64_T_TYPE__ */
#define __int64_t_defined       1
#endif /* __int64_t_defined */

#endif /* __STDINT_DECLS */
#endif /* __MSL_BUILD__ */

/* Fractional data types */
typedef signed char             frac8_t; 
typedef signed long long frac64_t;
typedef signed long frac32_t;
typedef signed short frac16_t;

/* Accumulator data types */
typedef signed long long acc64_t;
typedef signed long acc32_t;
typedef signed short acc16_t;

/* Fractional conversion macros */
#if !defined(FRAC16)
#define FRAC16(x) ((frac16_t)((x) < 0.999969482421875 ? ((x) >= -1 ? (x)*0x8000 : 0x8000) : 0x7FFF))
#endif /*FRAC16 */

#if !defined(FRAC32)
#define FRAC32(x) ((frac32_t)((x) < 1 ? ((x) >= -1 ? (x)*0x80000000 : 0x80000000) : 0x7FFFFFFF))
#endif /*FRAC32*/

#if !defined(FRAC64)
#define FRAC64(x) ((frac64_t)((x) < 1 ? ((x) >= -1 ? (x)*0x8000000000000000 : 0x8000000000000000) : 0x7FFFFFFFFFFFFFFF))
#endif /*FRAC64*/

/* Accumulator conversion macros */
#if !defined(ACC16)
#define ACC16(x) ((acc16_t)((x) < 255.9921875 ? ((x) >= -256 ? (x)*0x80 : 0x8000) : 0x7FFF))
#endif /*ACC16*/

#if !defined(ACC32)
#define ACC32(x) ((acc32_t)((x) < 65535.999969482421875 ? ((x) >= -65536 ? (x)*0x8000 : 0x80000000) : 0x7FFFFFFF))
#endif /*ACC32*/

#if !defined(ACC64)
#define ACC64(x) ((acc64_t)((x) < 4294967295.9999999995343387126923 ? ((x) >= -4294967296 ? (x)*0x80000000 : 0x8000000000000000) : 0x7FFFFFFFFFFFFFFF))
#endif /*ACC64*/

#if defined(__cplusplus)
}
#endif

#endif  /*_MLIB_TYPES_H_*/
