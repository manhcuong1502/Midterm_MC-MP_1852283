/*
 * input_reading.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Christian
 */

#include "input_reading.h"

static GPIO_PinState button_buffer [N_BUTTONS];
static uint8_t flag_for_3s_pressed [N_BUTTONS];

static GPIO_PinState debounce_button_1 [N_BUTTONS];
static GPIO_PinState debounce_button_2 [N_BUTTONS];
static uint16_t counter_for_3s_pressed [N_BUTTONS];

void button_reading(){
	for (int i = 0; i < N_BUTTONS; i++){
		debounce_button_2[i] = debounce_button_1[i];
		debounce_button_1[i] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6 << i);

		if (debounce_button_2[i] == debounce_button_1[i]){
			button_buffer[i] = debounce_button_1[i];
		}

		if (button_buffer[i] == BTN_PRESSED){
			if (counter_for_3s_pressed[i] < DURATION_3S_PRESSED){
				counter_for_3s_pressed[i]++;
			}
			else {
				flag_for_3s_pressed[i] = 1;
			}
		}
		else {
			counter_for_3s_pressed[i] = 0;
			flag_for_3s_pressed[i] = 0;
		}
	}
}

uint8_t is_pressed(uint8_t idx){
	return (button_buffer[idx] == BTN_PRESSED);
}

uint8_t is_pressed_3s(uint8_t idx){
	return (flag_for_3s_pressed[idx] == 1);
}
