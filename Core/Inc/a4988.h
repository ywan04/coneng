/*
 * a4988.h
 *
 *  Created on: Feb 18, 2024
 *      Author: ivan
 */

#ifndef INC_A4988_H_
#define INC_A4988_H_

#include "stm32f1xx_hal.h"

#define A4988_DIR_CW  (GPIO_PIN_SET)
#define A4988_DIR_CCW (GPIO_PIN_RESET)

typedef struct {
	GPIO_TypeDef *Dir_GPIO_Port;
	uint16_t Dir_Pin;
	GPIO_TypeDef *Step_GPIO_Port;
	uint16_t Step_Pin;
	GPIO_TypeDef *Ms1_GPIO_Port;
	uint16_t Ms1_Pin;
	GPIO_TypeDef *Ms2_GPIO_Port;
	uint16_t Ms2_Pin;
	GPIO_TypeDef *Ms3_GPIO_Port;
	uint16_t Ms3_Pin;
	uint32_t delay; // TODO: re-do using timers
} a4988_t;

void a4988_init(a4988_t *driver, GPIO_TypeDef *dir_port, uint16_t dir_pin,
								 GPIO_TypeDef *step_port, uint16_t step_pin,
								 GPIO_TypeDef *ms1_port, uint16_t ms1_pin,
								 GPIO_TypeDef *ms2_port, uint16_t ms2_pin,
								 GPIO_TypeDef *ms3_port, uint16_t ms3_pin);
void a4988_do_step(a4988_t *driver);
void a4988_move(a4988_t *driver, uint32_t steps);
void a4988_set_dir(a4988_t *driver, uint8_t dir);
void a4988_toggle_dir(a4988_t *driver);
void a4988_set_step_size(a4988_t *driver, uint8_t divider);
void a4988_set_delay(a4988_t *driver, uint32_t delay);

#endif /* INC_A4988_H_ */
