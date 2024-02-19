/*
 * as5600.c
 *
 *  Created on: Feb 19, 2024
 *      Author: ivan
 */

#include "as5600.h"

void as5600_init(as5600_t *encoder, I2C_HandleTypeDef *hi2c)
{
	encoder->hi2c = hi2c;
}

void as5600_read_angle(as5600_t *encoder)
{
	uint8_t reg = 0x0D;

	HAL_I2C_Master_Transmit(encoder->hi2c, 0x36, &reg, 1, 1000);
}
