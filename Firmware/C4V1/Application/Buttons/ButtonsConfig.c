/*
 * ButtonsConfig.c
 *
 *  Created on: Mar 24, 2023
 *      Author: M
 */
#include "main.h"

#include "Buttons.h"

#include "Data.h"
#include "stdio.h"

void ButtonsConfig(void)
{
   DATA_GetButPtr(BUTTON_UP)->ButtonCallback = NULL;
   DATA_GetButPtr(BUTTON_UP)->Cnt            = 0;
   DATA_GetButPtr(BUTTON_UP)->GPIO           = BUTTON_UP_GPIO_Port;
   DATA_GetButPtr(BUTTON_UP)->NewEvent       = BUT_EVENT_NOTHING;
   DATA_GetButPtr(BUTTON_UP)->Pin            = BUTTON_UP_Pin;
   DATA_GetButPtr(BUTTON_UP)->State          = BUT_STATE_IDLE;

   DATA_GetButPtr(BUTTON_LEFT)->ButtonCallback = NULL;
   DATA_GetButPtr(BUTTON_LEFT)->Cnt            = 0;
   DATA_GetButPtr(BUTTON_LEFT)->GPIO           = BUTTON_LEFT_GPIO_Port;
   DATA_GetButPtr(BUTTON_LEFT)->NewEvent       = BUT_EVENT_NOTHING;
   DATA_GetButPtr(BUTTON_LEFT)->Pin            = BUTTON_LEFT_Pin;
   DATA_GetButPtr(BUTTON_LEFT)->State          = BUT_STATE_IDLE;

   DATA_GetButPtr(BUTTON_RIGHT)->ButtonCallback = NULL;
   DATA_GetButPtr(BUTTON_RIGHT)->Cnt            = 0;
   DATA_GetButPtr(BUTTON_RIGHT)->GPIO           = BUTTON_RIGHT_GPIO_Port;
   DATA_GetButPtr(BUTTON_RIGHT)->NewEvent       = BUT_EVENT_NOTHING;
   DATA_GetButPtr(BUTTON_RIGHT)->Pin            = BUTTON_RIGHT_Pin;
   DATA_GetButPtr(BUTTON_RIGHT)->State          = BUT_STATE_IDLE;

   DATA_GetButPtr(BUTTON_DOWN)->ButtonCallback = NULL;
   DATA_GetButPtr(BUTTON_DOWN)->Cnt            = 0;
   DATA_GetButPtr(BUTTON_DOWN)->GPIO           = BUTTON_DOWN_GPIO_Port;
   DATA_GetButPtr(BUTTON_DOWN)->NewEvent       = BUT_EVENT_NOTHING;
   DATA_GetButPtr(BUTTON_DOWN)->Pin            = BUTTON_DOWN_Pin;
   DATA_GetButPtr(BUTTON_DOWN)->State          = BUT_STATE_IDLE;

   DATA_GetButPtr(BUTTON_OK)->ButtonCallback = NULL;
   DATA_GetButPtr(BUTTON_OK)->Cnt            = 0;
   DATA_GetButPtr(BUTTON_OK)->GPIO           = BUTTON_OK_GPIO_Port;
   DATA_GetButPtr(BUTTON_OK)->NewEvent       = BUT_EVENT_NOTHING;
   DATA_GetButPtr(BUTTON_OK)->Pin            = BUTTON_OK_Pin;
   DATA_GetButPtr(BUTTON_OK)->State          = BUT_STATE_IDLE;
}
