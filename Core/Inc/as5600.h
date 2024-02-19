/*
 * as5600.h
 *
 *  Created on: Feb 19, 2024
 *      Author: ivan
 */

#ifndef INC_AS5600_H_
#define INC_AS5600_H_

#include "stm32f1xx_hal.h"

typedef struct {
	I2C_HandleTypeDef *hi2c;
} as5600_t;

#endif /* INC_AS5600_H_ */
