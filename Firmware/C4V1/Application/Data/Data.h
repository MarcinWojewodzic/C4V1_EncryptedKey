/*
 * Data.h
 *
 *  Created on: Mar 24, 2023
 *      Author: M
 */

#ifndef DATA_DATA_H_
#define DATA_DATA_H_
#include "Buttons.h"
#include "SM.h"
#include "main.h"
SM_TypeDef *DATA_GetSmPtr(void);
BUT_TypeDef *DATA_GetButPtr(uint8_t ButtonNumber);
#endif /* DATA_DATA_H_ */
