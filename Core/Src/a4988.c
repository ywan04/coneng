/*
 * a4988.c
 *
 *  Created on: Feb 18, 2024
 *      Author: ivan
 */

#include "a4988.h"

void a4988_init(a4988_t *driver, GPIO_TypeDef *dir_port, uint16_t dir_pin,
								 GPIO_TypeDef *step_port, uint16_t step_pin,
								 GPIO_TypeDef *ms1_port, uint16_t ms1_pin,
								 GPIO_TypeDef *ms2_port, uint16_t ms2_pin,
								 GPIO_TypeDef *ms3_port, uint16_t ms3_pin)
{
	driver->Dir_GPIO_Port  = dir_port;
	driver->Dir_Pin        = dir_pin;

	driver->Step_GPIO_Port = step_port;
	driver->Step_Pin       = step_pin;

	driver->Ms1_GPIO_Port  = ms1_port;
	driver->Ms1_Pin        = ms1_pin;

	driver->Ms2_GPIO_Port  = ms2_port;
	driver->Ms2_Pin        = ms2_pin;

	driver->Ms3_GPIO_Port  = ms3_port;
	driver->Ms3_Pin        = ms3_pin;

	driver->delay          = 20;
}

void a4988_do_step(a4988_t *driver)
{
	HAL_GPIO_WritePin(driver->Step_GPIO_Port, driver->Step_Pin, GPIO_PIN_SET);
	HAL_Delay(driver->delay);
	HAL_GPIO_WritePin(driver->Step_GPIO_Port, driver->Step_Pin, GPIO_PIN_RESET);
	HAL_Delay(driver->delay);
}

void a4988_move(a4988_t *driver, uint32_t steps)
{
	while (steps--) {
		a4988_do_step(driver);
	}
}


void a4988_set_dir(a4988_t *driver, uint8_t dir)
{
	HAL_GPIO_WritePin(driver->Dir_GPIO_Port, driver->Dir_Pin, dir);
}

void a4988_toggle_dir(a4988_t *driver)
{
	HAL_GPIO_TogglePin(driver->Dir_GPIO_Port, driver->Dir_Pin);
}

void a4988_set_step_size(a4988_t *driver, uint8_t divider)
{
	HAL_GPIO_WritePin(driver->Ms1_GPIO_Port, driver->Ms1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(driver->Ms2_GPIO_Port, driver->Ms2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(driver->Ms3_GPIO_Port, driver->Ms3_Pin, GPIO_PIN_RESET);

	switch (divider) {
	case 2:
		HAL_GPIO_WritePin(driver->Ms1_GPIO_Port, driver->Ms1_Pin, GPIO_PIN_SET);
		break;
	case 4:
		HAL_GPIO_WritePin(driver->Ms2_GPIO_Port, driver->Ms2_Pin, GPIO_PIN_SET);
		break;
	case 8:
		HAL_GPIO_WritePin(driver->Ms1_GPIO_Port, driver->Ms1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(driver->Ms2_GPIO_Port, driver->Ms2_Pin, GPIO_PIN_SET);
		break;
	case 16:
		HAL_GPIO_WritePin(driver->Ms1_GPIO_Port, driver->Ms1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(driver->Ms2_GPIO_Port, driver->Ms2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(driver->Ms3_GPIO_Port, driver->Ms3_Pin, GPIO_PIN_SET);
		break;
	}
}

void a4988_set_delay(a4988_t *driver, uint32_t delay)
{
	driver->delay = delay;
}
