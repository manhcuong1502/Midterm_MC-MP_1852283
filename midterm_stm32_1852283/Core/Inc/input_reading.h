/*
 * input_reading.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Christian
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"
#define N_BUTTONS 3
#define RST 0
#define INC 1
#define DEC 2

#define BTN_PRESSED GPIO_PIN_RESET
#define BTN_RELEASED GPIO_PIN_SET
#define DURATION_3S_PRESSED 300

void button_reading();
uint8_t is_pressed(uint8_t);
uint8_t is_pressed_3s(uint8_t);

#endif /* INC_INPUT_READING_H_ */
