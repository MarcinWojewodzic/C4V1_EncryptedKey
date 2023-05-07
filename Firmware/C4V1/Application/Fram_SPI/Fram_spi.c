/*
 * Fram_spi.c
 *
 *  Created on: 3 maj 2023
 *      Author: M
 */
#include "Fram_spi.h"
#include "crc.h"
#include "main.h"
#include "stdio.h"
static const FramDensity_TypeDef FramDensity[] = { { FRAM_DENSITY_16K, 2048 },   { FRAM_DENSITY_64K, 8192 },   { FRAM_DENSITY_128K, 16384 },
                                                   { FRAM_DENSITY_256K, 32768 }, { FRAM_DENSITY_512K, 65536 }, { FRAM_DENSITY_1M, 131072 },
                                                   { FRAM_DENSITY_2M, 262144 },  { FRAM_DENSITY_4M, 524288 },  { FRAM_DENSITY_8M, 1048576 } };
__weak FramStatus_TypeDef ExtFram_CsLow(Fram_TypeDef *Fram)
{
   HAL_GPIO_WritePin(Fram->CsPort, Fram->CsPin, 0);
   return FRAM_OK;
}
__weak FramStatus_TypeDef ExtFram_CsHigh(Fram_TypeDef *Fram)
{
   HAL_GPIO_WritePin(Fram->CsPort, Fram->CsPin, 1);
   return FRAM_OK;
}
__weak FramStatus_TypeDef ExtFram_Write(Fram_TypeDef *Fram, uint8_t *Data, uint32_t Size)
{
   if(HAL_SPI_Transmit(Fram->FramSpi, Data, Size, FRAM_MAX_TIMEOUT) == HAL_OK)
   {
      return FRAM_OK;
   }
   else
   {
      return FRAM_ERROR;
   }
}
__weak FramStatus_TypeDef ExtFram_Read(Fram_TypeDef *Fram, uint8_t *Data, uint32_t Size)
{
   if(HAL_SPI_Receive(Fram->FramSpi, Data, Size, FRAM_MAX_TIMEOUT) == HAL_OK)
   {
      return FRAM_OK;
   }
   else
   {
      return FRAM_ERROR;
   }
}
static FramStatus_TypeDef ExtFram_FindDensity(Fram_TypeDef *Fram)
{
   FramStatus_TypeDef Status = FRAM_ERROR;
   for(int i = 0; i < FRAM_DENSITY_TABLE_SIZE; i++)
   {
      if(Fram->FramID.FramIDBit.Density == FramDensity[i].FramDensityCode)
      {
         Fram->FramSize = FramDensity[i].FramDensity;
         Status         = FRAM_OK;
      }
   }
   return Status;
}
static FramStatus_TypeDef ExtFram_ReadID(Fram_TypeDef *Fram)
{
   uint8_t Com, ID[4];
   Com = FRAM_RDID;
   if(ExtFram_CsLow(Fram) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_Write(Fram, &Com, 1) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_Read(Fram, ID, 4) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_CsHigh(Fram) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   Fram->FramID.FramIDWord = ((ID[0] << 24) | (ID[1] << 16) | (ID[2] << 8) | ID[3]);
   if(Fram->FramID.FramIDWord == 0 || Fram->FramID.FramIDWord == 0xFFFFFFFF)
   {
      return FRAM_ERROR;
   }
   else
   {
      return FRAM_OK;
   }
}
static FramStatus_TypeDef ExtFram_SetWELBit(Fram_TypeDef *Fram)
{
   uint8_t Com = FRAM_WREN;
   if(ExtFram_CsLow(Fram) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_Write(Fram, &Com, 1) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_CsHigh(Fram) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   HAL_Delay(1);
   return FRAM_OK;
}
FramStatus_TypeDef ExtFram_SetProtectedBlocs(Fram_TypeDef *Fram, uint8_t Blocs)
{
   if(Blocs > 3)
   {
      Blocs = 3;
   }
   uint8_t Data[2];
   Data[0] = FRAM_WRSR;
   Data[1] = (Blocs << 2);
   if(ExtFram_SetWELBit(Fram) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_CsLow(Fram) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_Write(Fram, Data, 2) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_CsHigh(Fram) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   return FRAM_OK;
}
static FramStatus_TypeDef ExtFram_ReadSreg(Fram_TypeDef *Fram)
{
   uint8_t Com = FRAM_RDSR;
   if(ExtFram_CsLow(Fram) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_Write(Fram, &Com, 1) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_Read(Fram, &Fram->Sreg.FramSregWord, 1) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_CsHigh(Fram) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else
   {
      return FRAM_OK;
   }
}
FramStatus_TypeDef ExtFram_WriteData(Fram_TypeDef *Fram, uint32_t Addr, uint8_t *Data, uint32_t Size)
{
   uint8_t Com[4]         = { 0 };
   static uint8_t SizeCom = 0;
   if(Fram->FramSize < (Addr + Size))
   {
      return FRAM_ERROR;
   }
   else if(Fram->FramSize > FRAM_ADDRES_SIZE_16B)
   {
      Com[0]  = FRAM_WRITE;
      Com[1]  = (Addr & 0xFF) >> 16;
      Com[2]  = (Addr & 0xFF) >> 8;
      Com[3]  = (Addr & 0xFF) >> 0;
      SizeCom = 4;
   }
   else
   {
      Com[0]  = FRAM_WRITE;
      Com[1]  = (Addr & 0xFF) >> 8;
      Com[2]  = (Addr & 0xFF) >> 0;
      SizeCom = 3;
   }
   if(ExtFram_SetWELBit(Fram) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_CsLow(Fram) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_Write(Fram, Com, SizeCom) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_Write(Fram, Data, Size) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_CsHigh(Fram) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else
   {
      return FRAM_OK;
   }
}
FramStatus_TypeDef ExtFram_ReadData(Fram_TypeDef *Fram, uint32_t Addr, uint8_t *Data, uint32_t Size)
{
   uint8_t Com[4]         = { 0 };
   static uint8_t SizeCom = 0;
   if(Fram->FramSize < (Addr + Size))
   {
      return FRAM_ERROR;
   }
   else if(Fram->FramSize > FRAM_ADDRES_SIZE_16B)
   {
      Com[0]  = FRAM_READ;
      Com[1]  = (Addr & 0xFF) >> 16;
      Com[2]  = (Addr & 0xFF) >> 8;
      Com[3]  = (Addr & 0xFF) >> 0;
      SizeCom = 4;
   }
   else
   {
      Com[0]  = FRAM_READ;
      Com[1]  = (Addr & 0xFF) >> 8;
      Com[2]  = (Addr & 0xFF) >> 0;
      SizeCom = 3;
   }
   if(ExtFram_SetWELBit(Fram) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_CsLow(Fram) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_Write(Fram, Com, SizeCom) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_Read(Fram, Data, Size) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_CsHigh(Fram) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else
   {
      return FRAM_OK;
   }
}
FramStatus_TypeDef ExtFram_Write32(Fram_TypeDef *Fram, uint16_t Addr, uint32_t Data)
{
   uint8_t Temp[4];
   Temp[0] = ((Data >> 24) & 0xff);
   Temp[1] = ((Data >> 16) & 0xff);
   Temp[2] = ((Data >> 8) & 0xff);
   Temp[3] = ((Data >> 0) & 0xff);
   return ExtFram_WriteData(Fram, Addr, Temp, 4);
}
FramStatus_TypeDef ExtFram_Read32(Fram_TypeDef *Fram, uint16_t Addr, uint32_t *Data)
{
   uint8_t Temp[4];
   if(ExtFram_ReadData(Fram, Addr, Temp, 4) == FRAM_OK)
   {
      *Data = ((Temp[0] << 24) | (Temp[1] << 16) | (Temp[2] << 8) | Temp[3]);
      return FRAM_OK;
   }
   return FRAM_ERROR;
}
FramStatus_TypeDef ExtFram_Increment32(Fram_TypeDef *Fram, uint32_t Addr)
{
   uint32_t Temp = 0, Confirm = 0;
   if(ExtFram_Read32(Fram, Addr, &Temp) == FRAM_OK)
   {
      Temp++;
      if(ExtFram_Write32(Fram, Addr, Temp) == FRAM_OK)
      {
         if(ExtFram_Read32(Fram, Addr, &Confirm) == FRAM_OK)
         {
            if(Temp == Confirm)
            {
               return FRAM_OK;
            }
            else
            {
               return FRAM_ERROR;
            }
         }
         else
         {
            return FRAM_ERROR;
         }
      }
      else
      {
         return FRAM_ERROR;
      }
   }
   else
   {
      return FRAM_ERROR;
   }
}
FramStatus_TypeDef ExtFram_Decrement32(Fram_TypeDef *Fram, uint32_t Addr)
{
   uint32_t Temp = 0, Confirm = 0;
   if(ExtFram_Read32(Fram, Addr, &Temp) == FRAM_OK)
   {
      Temp--;
      if(ExtFram_Write32(Fram, Addr, Temp) == FRAM_OK)
      {
         if(ExtFram_Read32(Fram, Addr, &Confirm) == FRAM_OK)
         {
            if(Temp == Confirm)
            {
               return FRAM_OK;
            }
            else
            {
               return FRAM_ERROR;
            }
         }
         else
         {
            return FRAM_ERROR;
         }
      }
      else
      {
         return FRAM_ERROR;
      }
   }
   else
   {
      return FRAM_ERROR;
   }
}
FramStatus_TypeDef ExtFram_ChipErase(Fram_TypeDef *Fram)
{
   uint8_t Temp = 0;
   for(int i = 0; i < Fram->FramSize; i++)
   {
      if(ExtFram_WriteData(Fram, i, &Temp, 1) != FRAM_OK)
      {
         return FRAM_ERROR;
      }
   }
   return FRAM_OK;
}
FramStatus_TypeDef ExtFram_Init(Fram_TypeDef *Fram, SPI_HandleTypeDef *Spi, GPIO_TypeDef *HoldPort, GPIO_TypeDef *CsPort, GPIO_TypeDef *WpPort,
                                uint16_t HoldPin, uint16_t CsPin, uint16_t WpPin)
{
   Fram->FramInitStatus = FRAM_ERROR;
   Fram->FramSpi        = Spi;
   Fram->HoldPort       = HoldPort;
   Fram->HoldPin        = HoldPin;
   Fram->CsPort         = CsPort;
   Fram->CsPin          = CsPin;
   Fram->WpPort         = WpPort;
   Fram->WpPin          = WpPin;
   if(Fram->HoldPort != NULL)
   {
      HAL_GPIO_WritePin(Fram->HoldPort, Fram->HoldPin, 1);
   }
   if(Fram->WpPort != NULL)
   {
      HAL_GPIO_WritePin(Fram->WpPort, Fram->WpPin, 1);
   }
   if(ExtFram_SetProtectedBlocs(Fram, 0) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_ReadSreg(Fram) != FRAM_OK)
   {
      return FRAM_OK;
   }
   else if(ExtFram_ReadID(Fram) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else if(ExtFram_FindDensity(Fram) != FRAM_OK)
   {
      return FRAM_ERROR;
   }
   else
   {
      Fram->FramInitStatus = FRAM_OK;
      return FRAM_OK;
   }
}
