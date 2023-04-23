/*
 * CORDIC_Def.h
 *
 *  Created on: Mar 18, 2023
 *      Author: M
 */

#ifndef INC_CORDIC_DEF_H_
#define INC_CORDIC_DEF_H_
typedef enum
{
   CORDIC_DATA_NOT_READY,
   CODIC_DATA_READY
} CORDIC_ReadyFlag;
typedef enum
{
   CORDIC_ARG_32B_SIZE,
   CORDIC_ARG_16B_SIZE
} CORDIC_ArgumentInputSize;
typedef enum
{
   CORDIC_RES_32B_SIZE,
   CORDIC_RES_16B_SIZE
} CORDIC_ArgumentOutputSize;
typedef enum
{
   CORDIC_ONE_DATA_INPUT,
   CORDIC_TWO_DATA_INPUT
} CORDIC_NumberOfArgumentInput;
typedef enum
{
   CORDIC_ONE_DATA_OUTPUT,
   CORDIC_TWO_DATA_OUTPUT
} CORDIC_NumberOfArgumentOutput;
typedef enum
{
   CORDIC_DMA_WRITE_DISABLE,
   CORDIC_TWO_DATA_ENABLE
} CORDIC_DMAWrite;
typedef enum
{
   CORDIC_DMA_READ_DISABLE,
   CORDIC_DMA_WRITE_ENABLE
} CORDIC_DMARead;
typedef enum
{
   CORDIC_INT_DISABLE,
   CORDIC_INT_ENABLE
} CORDIC_Interrupt;
typedef enum
{
   CORDIC_1_CYSCLE,
   CORDIC_2_CYSCLE,
   CORDIC_3_CYSCLE,
   CORDIC_4_CYSCLE,
   CORDIC_5_CYSCLE,
   CORDIC_6_CYSCLE
} CORDIC_Precision;
typedef enum
{
   CORDIC_COS,
   CORDIC_SIN,
   CORDIC_PHASE,
   CORDIC_MODULE,
   CORDIC_ATAN,
   CORDIC_HCOS,
   CORDIC_HSIN,
   CORDIC_ATANH,
   CORDIC_NLOG,
   CORDIC_SQRT
} CORDIC_Function;
//#define CORDIC ((CORDIC_TypeDef *)CORDIC_BASE)
//typedef union
//{
//   struct
//   {
//      __IO uint32_t FUNC      : 4;
//      __IO uint32_t PRECISION : 4;
//      __IO uint32_t SCALE     : 3;
//      __IO uint32_t RES2      : 5;
//      __IO uint32_t IEN       : 1;
//      __IO uint32_t DMAREN    : 1;
//      __IO uint32_t DMAWEN    : 1;
//      __IO uint32_t NRES      : 1;
//      __IO uint32_t NARGS     : 1;
//      __IO uint32_t RESSIZE   : 1;
//      __IO uint32_t ARGSIZE   : 1;
//      __IO uint32_t RES1      : 8;
//      __IO uint32_t RRDY      : 1;
//   } __IO CSR_Bit;
//   __IO uint32_t CSR_Word;
//} CORDIC_CSR;
//
//typedef struct
//{
//   __IO CORDIC_CSR *CSR;
//   __IO uint32_t WDATA;
//   __IO uint32_t RDATA;
//} CORDIC_TypeDef;


#endif /* INC_CORDIC_DEF_H_ */
