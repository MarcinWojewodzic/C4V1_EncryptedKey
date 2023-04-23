/*
 * SM.h
 *
 *  Created on: Mar 24, 2023
 *      Author: M
 */

#ifndef SM_SM_H_
#define SM_SM_H_
#define SM_TRANSITION_TABLE_SIZE sizeof(SMTransitionTable) / sizeof(SMTransitionTable_TypeDef)
#undef FLASH_CS
#define FLASH_CS GPIO_PIN_9
#undef FLASH_CS_GPIO_Port
#define FLASH_CS_GPIO_Port GPIOA
typedef enum
{
   SM_STATE_INITIALIZE,
   SM_STATE_IDLE,
   SM_STATE_RUNNING
} SMState_TypeDef;
typedef enum
{
   SM_EVENT_NOTHING,
   SM_EVENT_END_INIT,
   SM_EVENT_NEW,
   SM_EVENT_END_RUNNING
} SMEvent_TypeDef;
typedef enum
{
   SM_FLAG_RESET = 0x00,
   SM_FLAG_SET   = !SM_FLAG_RESET
} SMFlag_TypeDef;
typedef union
{
   struct
   {
      uint32_t UpButtonFlag    : 1;
      uint32_t DownButtonFlag  : 1;
      uint32_t LeftButtonFlag  : 1;
      uint32_t RightButtonFlag : 1;
      uint32_t OkButtonFlag    : 1;
      uint32_t Res             : 27;
   } FlagsBits;
   uint32_t FlagsWord;
} Flags_TypeDef;
typedef struct
{
   SMState_TypeDef Source;
   SMState_TypeDef Destination;
   SMEvent_TypeDef Event;
} SMTransitionTable_TypeDef;
typedef struct
{
   void (*SMFunction)(void);
} SMFunction_TypeDef;
typedef struct
{
   SMState_TypeDef State;
   SMEvent_TypeDef NewEvent;
   Flags_TypeDef Flags;
   uint32_t LastTick;
} SM_TypeDef;
void SM_Handle(void);
#endif /* SM_SM_H_ */
