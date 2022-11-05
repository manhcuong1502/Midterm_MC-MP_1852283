/*
 * fsm_button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Christian
 */

#include "fsm_button.h"

typedef enum {
	NORMAL,
	PRESSED,
	LONG_PRESSED,
	WAITING_3s
} System_State;

System_State state;
int counter;
int button;

void System_init(){
	state = NORMAL;
	counter = 5;
	button = -1;
}

void fsm_simple_buttons_run() {
	switch(state){
	case NORMAL:
	{
		for (uint8_t i = 0; i < N_BUTTONS; i++){
			if (is_pressed(i)){
				button = i;
			}
		}
		if (button != -1){
			state = PRESSED;
		}
		else if (get_timer_flag(SYSTEM_RUN)){
			if (counter > 0) counter--;
			timer_setting(SYSTEM_RUN, 1000);
		}
		// update for normal state at step 3 later
		break;
	}
	case PRESSED:
	{
		switch(button){
		case RST:
		{
			counter = 0;
			break;
		}
		case INC:
		{
			counter++;
			if (counter > 9) counter = 0;
			break;
		}
		case DEC:
		{
			counter--;
			if (counter < 0) counter = 9;
			break;
		}
		}

		state = WAITING_3s;
		break;
	}
	case WAITING_3s:
	{
		if (!is_pressed(button)){
			state = NORMAL;
			timer_setting(SYSTEM_RUN, 10000);
			button = -1;
		}
		else if (is_pressed_3s(button)){
			state = LONG_PRESSED;
			timer_setting(COUNTER_CHANGE, 10);
		}
		break;
	}
	case LONG_PRESSED:
	{
		if (!is_pressed(button)){
			state = NORMAL;
			timer_setting(COUNTER_CHANGE, 0);
			timer_setting(SYSTEM_RUN, 10000);
			button = -1;
		}
		else if (get_timer_flag(COUNTER_CHANGE)){
			switch(button){
			case RST:
			{
				counter = 0;
				break;
			}
			case INC:
			{
				counter++;
				if (counter > 9) counter = 0;
				break;
			}
			case DEC:
			{
				counter--;
				if (counter < 0) counter = 9;
				break;
			}
			}
			timer_setting(COUNTER_CHANGE, 1000);
		}
		break;
	}
	}
	// SHOW COUNTER VALUE INTO 7SEG_LED
	led_7_seg_disp(counter);
}

void led_blinking(){
	if (get_timer_flag(LED_BLINKING)){
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		timer_setting(LED_BLINKING, 500);
	}
}

