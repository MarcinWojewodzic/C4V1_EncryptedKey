/*
 * Buttons.h
 *
 *  Created on: Mar 24, 2023
 *      Author: M
 */

#ifndef BUTTONS_BUTTONS_H_
#define BUTTONS_BUTTONS_H_
#define BUT_TRANSITION_TABLE_SIZE sizeof(BUTTransitionTable) / sizeof(BUTTransitionTable_TypeDef)
#define BUTTONS_QUATITY           5
#define BUTTON_DEBOUNCE_TIME      5
typedef enum
{
   BUTTON_UP,
   BUTTON_LEFT,
   BUTTON_RIGHT,
   BUTTON_DOWN,
   BUTTON_OK
} ButtonsNames_TypeDef;
typedef enum
{
   BUT_STATE_IDLE,
   BUT_STATE_DEBOUNCE,
   BUT_STATE_PRESS
} BUTState_TypeDef;
typedef enum
{
   BUT_EVENT_NOTHING,
   BUT_EVENT_DEBOUNCE,
   BUT_EVENT_PRESS,
   BUT_EVENT_END_PRESS,
   BUT_EVENT_ERROR
} BUTEvent_TypeDef;
typedef enum
{
   BUT_FLAG_RESET = 0x00,
   BUT_FLAG_SET   = !BUT_FLAG_RESET
} BUTFlag_TypeDef;
typedef struct
{
   BUTState_TypeDef Source;
   BUTState_TypeDef Destination;
   BUTEvent_TypeDef Event;
} BUTTransitionTable_TypeDef;
typedef struct
{
   BUTState_TypeDef State;
   BUTEvent_TypeDef NewEvent;
   uint32_t Cnt;
   GPIO_TypeDef *GPIO;
   uint16_t Pin;
   uint32_t OffFlagCnt;
   void (*ButtonCallback)(void);
} BUT_TypeDef;
typedef struct
{
   void (*BUTFunction)(BUT_TypeDef *Button);
} BUTFunction_TypeDef;
void BUT_Handle(BUT_TypeDef *Button);
void BUT_RegisterCallback(BUT_TypeDef *Button, void *Callback);
void ButtonsConfig(void);
#endif /* BUTTONS_BUTTONS_H_ */
