/*
 * Supp.h
 *
 *  Created on: Apr 8, 2023
 *      Author: M
 */

#ifndef SUPP_SUPP_H_
#define SUPP_SUPP_H_
#include "SM.h"
#define PACK __attribute__((packed))
// #define UID_BASE 0x1FFF7590
#define BUTTON_OF_FLAG_TIME 50
typedef struct
{
   uint32_t Number;
   uint8_t Password[32];
   uint8_t PasswordLenght;
   SMFlag_TypeDef ExistScreenShoot;
   uint32_t ScreenShootCrc;
   uint8_t PasswordName[10];
   uint8_t PasswordNameLength;
   uint8_t Res[7];
   uint32_t Crc;
} PACK PasswordStruct_TypeDef;
typedef union
{
   PasswordStruct_TypeDef PasswordStruct;
   uint32_t PasswordTable[16];
} Password_TypeDef;
typedef struct
{
   SMFlag_TypeDef SpecialCharacter;
   SMFlag_TypeDef SpecialCharacterStart;
   uint8_t PasswordLength;
   uint8_t *Name;
   uint8_t NameLength;
} NewPasswordRules_TypeDef;
void SUPP_ExtFlashMassErase(void);
void SUPP_ExtFramhMassErase(void);
void SUPP_ExtMemoryMassErase(void);
void SUPP_ExtFlashPageErase(uint32_t PageNumber);
void SUPP_ButtonOffFlagTask(void);
void SUPP_GenerateNewPassword(NewPasswordRules_TypeDef NewPassword);
void SUPP_ReadPassword(Password_TypeDef *Pass, uint32_t Number);
void SUPP_AES_Init(void);
#endif /* SUPP_SUPP_H_ */
