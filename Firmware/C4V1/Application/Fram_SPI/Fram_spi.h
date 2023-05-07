/*
 * Fram_spi.h
 *
 *  Created on: 3 maj 2023
 *      Author: M
 */

#ifndef FRAM_SPI_FRAM_SPI_H_
#define FRAM_SPI_FRAM_SPI_H_
#include "main.h"
#define FRAM_DENSITY_TABLE_SIZE sizeof(FramDensity) / sizeof(FramDensity_TypeDef)
#define FRAM_MAX_TIMEOUT        1000
#define FRAM_RDSR               0x05
#define FRAM_WREN               0x06
#define FRAM_RDID               0x9f
#define FRAM_WRITE              0x02
#define FRAM_READ               0x03
#define FRAM_WRSR               0x01
#define FRAM_NUMBER_OF_BYTES    (32 * 1024)
#define FRAM_ADDRES_SIZE_16B    65536
typedef enum
{
   FRAM_ERROR,
   FRAM_OK
} FramStatus_TypeDef;
typedef union
{
   struct
   {
      uint32_t ProprietaryUse1 : 8;
      uint32_t Density         : 5;
      uint32_t ProprietaryUse2 : 3;
      uint32_t ManufacturedID  : 16;
   } FramIDBit;
   uint32_t FramIDWord;
} FramID_TypeDef;
typedef enum
{
   FRAM_DENSITY_16K  = 0b00001,
   FRAM_DENSITY_64K  = 0b00011,
   FRAM_DENSITY_128K = 0b00100,
   FRAM_DENSITY_256K = 0b00101,
   FRAM_DENSITY_512K = 0b00110,
   FRAM_DENSITY_1M   = 0b00111,
   FRAM_DENSITY_2M   = 0b01000,
   FRAM_DENSITY_4M   = 0b01001,
   FRAM_DENSITY_8M   = 0b01010
} FramDensityCode_TypeDef;
typedef struct
{
   FramDensityCode_TypeDef FramDensityCode;
   uint32_t FramDensity;
} FramDensity_TypeDef;
typedef union
{
   struct
   {
      uint8_t Res1 : 1;
      uint8_t Wel  : 1;
      uint8_t BP0  : 1;
      uint8_t BP1  : 1;
      uint8_t Res2 : 3;
      uint8_t Wpen : 1;
   } FramSregBit;
   uint8_t FramSregWord;
} FramSreg_TypeDef;
typedef struct
{
   SPI_HandleTypeDef *FramSpi;
   GPIO_TypeDef *HoldPort, *CsPort, *WpPort;
   uint16_t HoldPin, CsPin, WpPin;
   FramSreg_TypeDef Sreg;
   FramID_TypeDef FramID;
   FramStatus_TypeDef FramInitStatus;
   uint32_t FramSize;
} Fram_TypeDef;
FramStatus_TypeDef ExtFram_Init(Fram_TypeDef *Fram, SPI_HandleTypeDef *Spi, GPIO_TypeDef *HoldPort, GPIO_TypeDef *CsPort, GPIO_TypeDef *WpPort,
                                uint16_t HoldPin, uint16_t CsPin, uint16_t WpPin);
FramStatus_TypeDef ExtFram_WriteData(Fram_TypeDef *Fram, uint32_t Addr, uint8_t *Data, uint32_t Size);
FramStatus_TypeDef ExtFram_ReadData(Fram_TypeDef *Fram, uint32_t Addr, uint8_t *Data, uint32_t Size);
FramStatus_TypeDef ExtFram_Read32(Fram_TypeDef *Fram, uint16_t Addr, uint32_t *Data);
FramStatus_TypeDef ExtFram_Write32(Fram_TypeDef *Fram, uint16_t Addr, uint32_t Data);
FramStatus_TypeDef ExtFram_Increment32(Fram_TypeDef *Fram, uint32_t Addr);
FramStatus_TypeDef ExtFram_Decrement32(Fram_TypeDef *Fram, uint32_t Addr);
FramStatus_TypeDef ExtFram_ChipErase(Fram_TypeDef *Fram);
FramStatus_TypeDef ExtFram_SetProtectedBlocs(Fram_TypeDef *fram, uint8_t Blocs);
#endif /* FRAM_SPI_FRAM_SPI_H_ */
