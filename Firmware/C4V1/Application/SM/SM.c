/*
 * SM.c
 *
 *  Created on: Mar 24, 2023
 *      Author: M
 */
#include "main.h"

#include "SM.h"

#include "Buttons.h"
#include "Data.h"
#include "Fram_spi.h"
#include "GFX_Color.h"
#include "Led.h"
#include "Supp.h"
#include "USB_KeyboardKeyDescriptor.h"
#include "WS2812b.h"
#include "flash_spi.h"
#include "fonts/fonts.h"
#include "rng.h"
#include "spi.h"
#include "ssd1331.h"
#include "stdio.h"
#include "usb_device.h"
#include "usbd_hid.h"
void SM_InitializeFunction(void);
void SM_IdleFunction(void);
void SM_RunningFunction(void);
static void SM_ChangeState(void);
static void BUT_ButtonUpCallback(void);
static void BUT_ButtonRightCallback(void);
static void BUT_ButtonLeftCallback(void);
static void BUT_ButtonDownCallback(void);
static void BUT_ButtonOkCallback(void);
SMTransitionTable_TypeDef SMTransitionTable[] = { { SM_STATE_INITIALIZE, SM_STATE_IDLE, SM_EVENT_END_INIT },
                                                  { SM_STATE_IDLE, SM_STATE_RUNNING, SM_EVENT_NEW },
                                                  { SM_STATE_RUNNING, SM_STATE_IDLE, SM_EVENT_END_RUNNING } };
SMFunction_TypeDef SMFunctionsTable[]         = { { SM_InitializeFunction }, { SM_IdleFunction }, { SM_RunningFunction } };
flash_t Flash                                 = { 0 };
Fram_TypeDef Fram                             = { 0 };
extern USBD_HandleTypeDef hUsbDeviceFS;
extern uint8_t UsbHidKeyboardReportBuffer[8];
void SM_Handle(void)
{
   if(HAL_GetTick() - DATA_GetSmPtr()->LastTick > 10)
   {
      SM_ChangeState();
      DATA_GetSmPtr()->LastTick = HAL_GetTick();
      if(SMFunctionsTable[DATA_GetSmPtr()->State].SMFunction != NULL)
      {
         SMFunctionsTable[DATA_GetSmPtr()->State].SMFunction();
      }
   }
}
void SM_InitializeFunction(void)
{
   ssd1331_init(&hspi1);
   GFX_SetFont(font_8x5);
   ButtonsConfig();
   BUT_RegisterCallback(DATA_GetButPtr(BUTTON_UP), BUT_ButtonUpCallback);
   BUT_RegisterCallback(DATA_GetButPtr(BUTTON_RIGHT), BUT_ButtonRightCallback);
   BUT_RegisterCallback(DATA_GetButPtr(BUTTON_LEFT), BUT_ButtonLeftCallback);
   BUT_RegisterCallback(DATA_GetButPtr(BUTTON_DOWN), BUT_ButtonDownCallback);
   BUT_RegisterCallback(DATA_GetButPtr(BUTTON_OK), BUT_ButtonOkCallback);
   flash_Init(&Flash, &hspi1, FLASH_CS_GPIO_Port, FLASH_CS);
   ExtFram_Init(&Fram, &hspi1, NULL, FRAM_CS_GPIO_Port, NULL, 0, FRAM_CS_Pin, 0);
   SUPP_AES_Init();
   LED_BlinkPoll(10, 150, 15, 5, 100);
   DATA_GetSmPtr()->NewEvent = SM_EVENT_END_INIT;
}
void SM_IdleFunction(void)
{
   SUPP_ButtonOffFlagTask();
   for(int i = 0; i < BUTTONS_QUATITY; i++)
   {
      BUT_Handle(DATA_GetButPtr(i));
   }
}
void SM_RunningFunction(void)
{
}
static void SM_ChangeState(void)
{
   for(int i = 0; i < SM_TRANSITION_TABLE_SIZE; i++)
   {
      if(SMTransitionTable[i].Source == DATA_GetSmPtr()->State && SMTransitionTable[i].Event == DATA_GetSmPtr()->NewEvent)
      {
         DATA_GetSmPtr()->State    = SMTransitionTable[i].Destination;
         DATA_GetSmPtr()->NewEvent = SM_EVENT_NOTHING;
         return;
      }
   }
   DATA_GetSmPtr()->NewEvent = SM_EVENT_NOTHING;
}
static void BUT_ButtonUpCallback(void)
{
   WS2812_SetPixel(100, 100, 100);
   DATA_GetSmPtr()->Flags.FlagsBits.UpButtonFlag = SM_FLAG_SET;
   DATA_GetButPtr(BUTTON_UP)->OffFlagCnt         = 0;
}
static void BUT_ButtonRightCallback(void)
{
   WS2812_SetPixel(0, 0, 0);
   DATA_GetSmPtr()->Flags.FlagsBits.RightButtonFlag = SM_FLAG_SET;
   DATA_GetButPtr(BUTTON_RIGHT)->OffFlagCnt         = 0;
}
static void BUT_ButtonLeftCallback(void)
{
   DATA_GetSmPtr()->Flags.FlagsBits.LeftButtonFlag = SM_FLAG_SET;
   SUPP_ExtFramhMassErase();
   DATA_GetButPtr(BUTTON_LEFT)->OffFlagCnt = 0;
}
static void BUT_ButtonDownCallback(void)
{
   Password_TypeDef Pass;
   DATA_GetSmPtr()->Flags.FlagsBits.DownButtonFlag = SM_FLAG_SET;
   SUPP_ReadPassword(&Pass, 0);
   DATA_GetButPtr(BUTTON_DOWN)->OffFlagCnt = 0;
}
static void BUT_ButtonOkCallback(void)
{
   NewPasswordRules_TypeDef pass;
   pass.NameLength            = 0;
   uint8_t temp               = 0xff;
   pass.Name                  = &temp;
   pass.SpecialCharacter      = SM_FLAG_SET;
   pass.SpecialCharacterStart = SM_FLAG_SET;
   pass.PasswordLength        = 32;
   SUPP_GenerateNewPassword(pass);
   DATA_GetSmPtr()->Flags.FlagsBits.OkButtonFlag = SM_FLAG_SET;
   DATA_GetButPtr(BUTTON_OK)->OffFlagCnt         = 0;
}
