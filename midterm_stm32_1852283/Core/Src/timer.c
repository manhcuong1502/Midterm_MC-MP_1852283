/*
 * timer.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Christian
 */

#include "timer.h"

int timer_counter[N_TIMERS];
int timer_flag[N_TIMERS];
int TIMER_CYCLE = 10;

void Software_TIM_Init(){
	timer_setting(LED_BLINKING, 500);
	timer_setting(COUNTER_CHANGE, 0);
	timer_setting(SYSTEM_RUN, 10);
}

void timer_setting(int idx, int duration){
	timer_counter[idx] = duration/TIMER_CYCLE;
	timer_flag[idx] = 0;
}

int get_timer_flag(int idx){
	return timer_flag[idx];
}

void timer_run(){
	for (int i = 0; i < N_TIMERS; i++){
		if (timer_counter[i] > 0){
			timer_counter[i]--;
			if (timer_counter[i] == 0){
				timer_flag[i] = 1;
			}
		}
	}
}
