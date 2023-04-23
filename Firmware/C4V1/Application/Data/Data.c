/*
 * Data.c
 *
 *  Created on: Mar 24, 2023
 *      Author: M
 */

#include "main.h"

#include "Data.h"

#include "Buttons.h"
#include "SM.h"
SM_TypeDef Sm                    = { 0 };
BUT_TypeDef But[BUTTONS_QUATITY] = { 0 };
SM_TypeDef *DATA_GetSmPtr(void)
{
   return &Sm;
}
BUT_TypeDef *DATA_GetButPtr(uint8_t ButtonNumber)
{
   return &But[ButtonNumber];
}
