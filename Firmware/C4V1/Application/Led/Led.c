/*
 * Led.c
 *
 *  Created on: Apr 9, 2023
 *      Author: M
 */
#include "main.h"

#include "Led.h"

#include "Data.h"
#include "tim.h"
#include "Supp.h"
#include "SM.h"
#include "WS2812b.h"
void LED_BlinkPoll(uint8_t R, uint8_t G, uint8_t B, uint32_t Quatity, uint32_t Delay)
{
	for(int i=0;i<Quatity;i++)
	{
		WS2812_SetPixel(R, G, B);
		HAL_Delay(Delay);
		WS2812_SetPixel(0, 0, 0);
		HAL_Delay(Delay);
	}
}
