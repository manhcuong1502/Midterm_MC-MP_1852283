/*
 * timer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Christian
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define N_TIMERS 3
#define LED_BLINKING 0
#define COUNTER_CHANGE 1
#define SYSTEM_RUN 2

void Software_TIM_Init();
void timer_setting(int, int);
void timer_run();
int get_timer_flag(int);

#endif /* INC_TIMER_H_ */
