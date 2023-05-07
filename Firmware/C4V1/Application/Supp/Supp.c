/*
 * Supp.c
 *
 *  Created on: Apr 8, 2023
 *      Author: M
 */
#include "main.h"

#include "Supp.h"

#include "Aes.h"
#include "Data.h"
#include "FramMemoryMap.h"
#include "Fram_spi.h"
#include "GFX_Color.h"
#include "Led.h"
#include "SM.h"
#include "crc.h"
#include "flash_spi.h"
#include "rng.h"
#include "ssd1331.h"
#include "stdio.h"
extern flash_t Flash;
extern Fram_TypeDef Fram;
uint8_t TempTable[SECTOR_SIZE] = { 0 };
uint8_t AesKey[16]             = { 0 };
AES_ctx Aes;
uint32_t map(uint32_t val, uint32_t in_min, uint32_t in_max, uint32_t out_min, uint32_t out_max)
{
   return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
const uint8_t SpecialCharacter[10] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')' };
void SUPP_ExtFlashMassErase(void)
{
   char Temp[50] = { 0 };
   ssd1331_clear();
   sprintf(Temp, "EXTERNAL FLASH");
   GFX_DrawString(0, 0, Temp, GREEN);
   sprintf(Temp, "MASS ERASE");
   GFX_DrawString(0, 10, Temp, GREEN);
   GFX_DrawRectangle(0, 20, 96, 5, GREEN);
   ssd1331_display(0);
   for(int i = 0; i < NUMBER_OF_SECTORS; i++)
   {
      flash_ClearSector(&Flash, i);
      GFX_DrawFillRectangle(0, 20, map(i, 0, 511, 0, 96), 5, GREEN);
      ssd1331_display(0);
   }
}
void SUPP_ExtFramhMassErase(void)
{
   char Temp[50] = { 0 };
   ssd1331_clear();
   sprintf(Temp, "EXTERNAL FRAM");
   GFX_DrawString(0, 0, Temp, GREEN);
   sprintf(Temp, "MASS ERASE");
   GFX_DrawString(0, 10, Temp, GREEN);
   GFX_DrawRectangle(0, 20, 96, 5, GREEN);
   ssd1331_display(0);
   for(int i = 0; i < 128; i++)
   {
      TempTable[i] = 0;
   }
   for(int i = 0; i < FRAM_NUMBER_OF_BYTES; i += 128)
   {
      ExtFram_WriteData(&Fram, i, TempTable, 128);
      GFX_DrawFillRectangle(0, 20, map(i, 0, FRAM_NUMBER_OF_BYTES - 1, 0, 96), 5, GREEN);
      ssd1331_display(0);
   }
}
void SUPP_ExtMemoryMassErase(void)
{
   char Temp[50] = { 0 };
   ssd1331_clear();
   sprintf(Temp, "EXTERNAL FLASH");
   GFX_DrawString(0, 0, Temp, GREEN);
   sprintf(Temp, "MASS ERASE");
   GFX_DrawString(0, 10, Temp, GREEN);
   GFX_DrawRectangle(0, 20, 96, 5, GREEN);
   ssd1331_display(0);
   for(int i = 0; i < NUMBER_OF_SECTORS; i++)
   {
      flash_ClearSector(&Flash, i);
      GFX_DrawFillRectangle(0, 20, map(i, 0, 511, 0, 96), 5, GREEN);
      ssd1331_display(0);
   }
   sprintf(Temp, "EXTERNAL FRAM");
   GFX_DrawString(0, 30, Temp, GREEN);
   sprintf(Temp, "MASS ERASE");
   GFX_DrawString(0, 40, Temp, GREEN);
   GFX_DrawRectangle(0, 50, 96, 5, GREEN);
   ssd1331_display(0);
   for(int i = 0; i < 128; i++)
   {
      TempTable[i] = 0;
   }
   for(int i = 0; i < FRAM_NUMBER_OF_BYTES; i += 128)
   {
      ExtFram_WriteData(&Fram, i, TempTable, 128);
      GFX_DrawFillRectangle(0, 50, map(i, 0, FRAM_NUMBER_OF_BYTES - 1, 0, 96), 5, GREEN);
      ssd1331_display(0);
   }
   sprintf(Temp, "SUCCESS");
   GFX_DrawString(0, 56, Temp, GREEN);
   ssd1331_display(0);
   HAL_Delay(1000);
   ssd1331_clear();
   ssd1331_display(0);
}
void SUPP_ExtFlashPageErase(uint32_t PageNumber)
{
   uint32_t SectorNumber      = PageNumber / 16;
   uint8_t PageInSectorNumber = PageNumber % 16;
   flash_ReadDataBytes(&Flash, SectorNumber * SECTOR_SIZE, TempTable, SECTOR_SIZE);
   flash_ClearSector(&Flash, SectorNumber);
   for(int i = (PageInSectorNumber * PAGE_SIZE); i < ((PageInSectorNumber + 1) * PAGE_SIZE); i++)
   {
      TempTable[i] = 0xFF;
   }
   for(int i = 0; i < PAGES_IN_SECTOR; i++)
   {
      flash_WritePage(&Flash, SectorNumber * PAGES_IN_SECTOR, &TempTable[i * PAGE_SIZE]);
   }
}
void SUPP_ButtonOffFlagTask(void)
{
   if(DATA_GetSmPtr()->Flags.FlagsBits.DownButtonFlag == SM_FLAG_SET)
   {
      DATA_GetButPtr(BUTTON_DOWN)->OffFlagCnt++;
      if(DATA_GetButPtr(BUTTON_DOWN)->OffFlagCnt >= BUTTON_OF_FLAG_TIME)
      {
         DATA_GetButPtr(BUTTON_DOWN)->OffFlagCnt         = 0;
         DATA_GetSmPtr()->Flags.FlagsBits.DownButtonFlag = SM_FLAG_RESET;
      }
   }
   if(DATA_GetSmPtr()->Flags.FlagsBits.UpButtonFlag == SM_FLAG_SET)
   {
      DATA_GetButPtr(BUTTON_UP)->OffFlagCnt++;
      if(DATA_GetButPtr(BUTTON_UP)->OffFlagCnt >= BUTTON_OF_FLAG_TIME)
      {
         DATA_GetButPtr(BUTTON_UP)->OffFlagCnt         = 0;
         DATA_GetSmPtr()->Flags.FlagsBits.UpButtonFlag = SM_FLAG_RESET;
      }
   }
   if(DATA_GetSmPtr()->Flags.FlagsBits.LeftButtonFlag == SM_FLAG_SET)
   {
      DATA_GetButPtr(BUTTON_LEFT)->OffFlagCnt++;
      if(DATA_GetButPtr(BUTTON_LEFT)->OffFlagCnt >= BUTTON_OF_FLAG_TIME)
      {
         DATA_GetButPtr(BUTTON_LEFT)->OffFlagCnt         = 0;
         DATA_GetSmPtr()->Flags.FlagsBits.LeftButtonFlag = SM_FLAG_RESET;
      }
   }
   if(DATA_GetSmPtr()->Flags.FlagsBits.RightButtonFlag == SM_FLAG_SET)
   {
      DATA_GetButPtr(BUTTON_RIGHT)->OffFlagCnt++;
      if(DATA_GetButPtr(BUTTON_RIGHT)->OffFlagCnt >= BUTTON_OF_FLAG_TIME)
      {
         DATA_GetButPtr(BUTTON_RIGHT)->OffFlagCnt         = 0;
         DATA_GetSmPtr()->Flags.FlagsBits.RightButtonFlag = SM_FLAG_RESET;
      }
   }
   if(DATA_GetSmPtr()->Flags.FlagsBits.OkButtonFlag == SM_FLAG_SET)
   {
      DATA_GetButPtr(BUTTON_OK)->OffFlagCnt++;
      if(DATA_GetButPtr(BUTTON_OK)->OffFlagCnt >= BUTTON_OF_FLAG_TIME)
      {
         DATA_GetButPtr(BUTTON_OK)->OffFlagCnt         = 0;
         DATA_GetSmPtr()->Flags.FlagsBits.OkButtonFlag = SM_FLAG_RESET;
      }
   }
}
void SUPP_GetChipID(uint32_t *Data)
{
   Data[0] = *((unsigned long *)UID_BASE);
   Data[1] = *((unsigned long *)UID_BASE + 1);
   Data[2] = *((unsigned long *)UID_BASE + 2);
   Data[3] = Crc(CRC_INITIAL_VALUE, 12, (uint8_t *)Data);
}

void SUPP_AES_Init(void)
{
   uint32_t Key[4];
   SUPP_GetChipID(Key);
   AesKey[0] = ((Key[0] >> 24) & 0xff);
   AesKey[1] = ((Key[0] >> 16) & 0xff);
   AesKey[2] = ((Key[0] >> 8) & 0xff);
   AesKey[3] = ((Key[0] >> 0) & 0xff);

   AesKey[4] = ((Key[1] >> 24) & 0xff);
   AesKey[5] = ((Key[1] >> 16) & 0xff);
   AesKey[6] = ((Key[1] >> 8) & 0xff);
   AesKey[7] = ((Key[1] >> 0) & 0xff);

   AesKey[8]  = ((Key[2] >> 24) & 0xff);
   AesKey[9]  = ((Key[2] >> 16) & 0xff);
   AesKey[10] = ((Key[2] >> 8) & 0xff);
   AesKey[11] = ((Key[2] >> 0) & 0xff);

   AesKey[12] = ((Key[3] >> 24) & 0xff);
   AesKey[13] = ((Key[3] >> 16) & 0xff);
   AesKey[14] = ((Key[3] >> 8) & 0xff);
   AesKey[15] = ((Key[3] >> 0) & 0xff);
   AES_init_ctx(&Aes, AesKey);
}
void SUPP_AES_EncryptBuffer(uint32_t *Buff, uint32_t Size)
{
   for(int i = 0; i < Size; i += 4)
   {
      AES_ECB_encrypt(&Aes, (uint8_t *)(&Buff[i]));
   }
}
void SUPP_AES_DecryptBuffer(uint32_t *Buff, uint32_t Size)
{
   for(int i = 0; i < Size; i += 4)
   {
      AES_ECB_decrypt(&Aes, (uint8_t *)(&Buff[i]));
   }
}
void SUPP_ReadPassword(Password_TypeDef *Pass, uint32_t Number)
{
   uint32_t TempCrc = Crc(CRC_INITIAL_VALUE, PASSWORD_SIZE - CRC_LENGTH, (uint8_t *)Pass->PasswordTable);
   while(TempCrc != Pass->PasswordStruct.Crc)
   {
      ExtFram_ReadData(&Fram, Number * PASSWORD_SIZE + PASSWORD_START_ADDRESS, (uint8_t *)Pass->PasswordTable, PASSWORD_SIZE);
      SUPP_AES_DecryptBuffer(Pass->PasswordTable, PASSWORD_SIZE / sizeof(uint32_t));
      TempCrc = Crc(CRC_INITIAL_VALUE, PASSWORD_SIZE - CRC_LENGTH, (uint8_t *)Pass->PasswordTable);
      if(TempCrc == Pass->PasswordStruct.Crc)
      {
         LED_BlinkPoll(0, 100, 100, 10, 15);
      }
      else
      {
         LED_BlinkPoll(100, 10, 56, 10, 15);
      }
   }
}

void SUPP_GenerateNewPassword(NewPasswordRules_TypeDef NewPassword)
{
   Password_TypeDef Pass = { 0 };
   uint32_t Temp         = sizeof(Password_TypeDef);
   ExtFram_Read32(&Fram, COUNTER_PASSWORD_ADDRESS, &Temp);
   Pass.PasswordStruct.Number = Temp;
   ExtFram_Increment32(&Fram, COUNTER_PASSWORD_ADDRESS);
   Pass.PasswordStruct.PasswordLenght     = NewPassword.PasswordLength;
   Pass.PasswordStruct.PasswordNameLength = NewPassword.NameLength;
   for(int i = 0; i < NewPassword.NameLength; i++)
   {
      Pass.PasswordStruct.PasswordName[i] = NewPassword.Name[i];
   }
   if(NewPassword.SpecialCharacter == SM_FLAG_SET)
   {
      if(NewPassword.SpecialCharacterStart == SM_FLAG_SET)
      {
         uint32_t Temp;
         HAL_RNG_GenerateRandomNumber(&hrng, &Temp);
         if(Temp % 2 == 0)
         {
            Pass.PasswordStruct.Password[0] = '*';
         }
         else
         {
            Pass.PasswordStruct.Password[0] = '!';
         }
         NewPassword.PasswordLength--;
      }
   }
   for(int i = 0; i < NewPassword.PasswordLength; i++)
   {
      uint32_t Temp;
      HAL_RNG_GenerateRandomNumber(&hrng, &Temp);
      if(Temp % 3 == 0)
      {
         HAL_RNG_GenerateRandomNumber(&hrng, &Temp);
         Temp = (Temp % 26) + 65;
         if(NewPassword.SpecialCharacterStart == SM_FLAG_SET)
         {
            Pass.PasswordStruct.Password[i + 1] = Temp;
         }
         else
         {
            Pass.PasswordStruct.Password[i] = Temp;
         }
      }
      else if(Temp % 3 == 1)
      {
         HAL_RNG_GenerateRandomNumber(&hrng, &Temp);
         Temp = (Temp % 26) + 97;
         if(NewPassword.SpecialCharacterStart == SM_FLAG_SET)
         {
            Pass.PasswordStruct.Password[i + 1] = Temp;
         }
         else
         {
            Pass.PasswordStruct.Password[i] = Temp;
         }
      }
      else if(NewPassword.SpecialCharacter == SM_FLAG_SET)
      {
         HAL_RNG_GenerateRandomNumber(&hrng, &Temp);
         Temp = (Temp % 10);
         if(NewPassword.SpecialCharacterStart == SM_FLAG_SET)
         {
            Pass.PasswordStruct.Password[i + 1] = SpecialCharacter[Temp];
         }
         else
         {
            Pass.PasswordStruct.Password[i] = SpecialCharacter[Temp];
         }
      }
      else
      {
         i--;
      }
   }
   Pass.PasswordStruct.Crc = Crc(CRC_INITIAL_VALUE, PASSWORD_SIZE - CRC_LENGTH, (uint8_t *)Pass.PasswordTable);
   uint32_t TempAddr       = Pass.PasswordStruct.Number * PASSWORD_SIZE + PASSWORD_START_ADDRESS;
   SUPP_AES_EncryptBuffer(Pass.PasswordTable, PASSWORD_SIZE / sizeof(uint32_t));
   ExtFram_WriteData(&Fram, TempAddr, (uint8_t *)Pass.PasswordTable, PASSWORD_SIZE);
}
