/*
 * Buttons.c
 *
 *  Created on: Mar 24, 2023
 *      Author: M
 */
#include "main.h"

#include "Buttons.h"

#include "Data.h"
#include "stdio.h"
static void BUT_IdleFunction(BUT_TypeDef *Button);
static void BUT_DebounceFunction(BUT_TypeDef *Button);
static void BUT_PressFunction(BUT_TypeDef *Button);
static void BUT_ChangeState(BUT_TypeDef *Button);
BUTTransitionTable_TypeDef BUTTransitionTable[] = { { BUT_STATE_IDLE, BUT_STATE_DEBOUNCE, BUT_EVENT_DEBOUNCE },
                                                    { BUT_STATE_DEBOUNCE, BUT_STATE_PRESS, BUT_EVENT_PRESS },
                                                    { BUT_STATE_PRESS, BUT_STATE_IDLE, BUT_EVENT_END_PRESS },
                                                    { BUT_STATE_DEBOUNCE, BUT_STATE_IDLE, BUT_EVENT_ERROR } };
BUTFunction_TypeDef BUTFunctionsTable[]         = { { BUT_IdleFunction }, { BUT_DebounceFunction }, { BUT_PressFunction } };

void BUT_Handle(BUT_TypeDef *Button)
{
   BUT_ChangeState(Button);
   if(BUTFunctionsTable[Button->State].BUTFunction != NULL)
   {
      BUTFunctionsTable[Button->State].BUTFunction(Button);
   }
}
void BUT_RegisterCallback(BUT_TypeDef *Button, void *Callback)
{
   if(Callback != NULL)
   {
      Button->ButtonCallback = Callback;
   }
}
static void BUT_IdleFunction(BUT_TypeDef *Button)
{
   if(HAL_GPIO_ReadPin(Button->GPIO, Button->Pin) == GPIO_PIN_RESET)
   {
      Button->Cnt      = 0;
      Button->NewEvent = BUT_EVENT_DEBOUNCE;
   }
}
static void BUT_DebounceFunction(BUT_TypeDef *Button)
{
   Button->Cnt++;
   if(Button->Cnt > BUTTON_DEBOUNCE_TIME)
   {
      if(HAL_GPIO_ReadPin(Button->GPIO, Button->Pin) == GPIO_PIN_RESET)
      {
         Button->NewEvent = BUT_EVENT_PRESS;
      }
      else
      {
         Button->NewEvent = BUT_EVENT_ERROR;
      }
   }
}
static void BUT_PressFunction(BUT_TypeDef *Button)
{
   if(HAL_GPIO_ReadPin(Button->GPIO, Button->Pin) == GPIO_PIN_SET)
   {
      if(Button->ButtonCallback != NULL)
      {
         Button->ButtonCallback();
      }
      Button->NewEvent = BUT_EVENT_END_PRESS;
   }
}
static void BUT_ChangeState(BUT_TypeDef *Button)
{
   for(int i = 0; i < BUT_TRANSITION_TABLE_SIZE; i++)
   {
      if(BUTTransitionTable[i].Source == Button->State && BUTTransitionTable[i].Event == Button->NewEvent)
      {
         Button->State    = BUTTransitionTable[i].Destination;
         Button->NewEvent = BUT_EVENT_NOTHING;
         return;
      }
   }
   Button->NewEvent = BUT_EVENT_NOTHING;
}
