/*
 * fsm_button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Christian
 */

#ifndef INC_FSM_BUTTON_H_
#define INC_FSM_BUTTON_H_

#include "input_reading.h"
#include "led7display.h"
#include "timer.h"

void System_init();
void fsm_simple_buttons_run();
void led_blinking();

#endif /* INC_FSM_BUTTON_H_ */
