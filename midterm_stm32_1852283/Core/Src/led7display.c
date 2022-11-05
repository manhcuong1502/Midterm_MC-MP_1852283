/*
 * led7display.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Christian
 */

#include "led7display.h"
uint16_t LED7SEG_ON [] = {0x003F, 0x0006, 0x005B, 0x004F, 0x0066,
							0x006D,	0x007D, 0x0007, 0x007F, 0x006F};
uint16_t LED7SEG_OFF [] = {0x0040, 0X0079, 0x0024, 0x0030, 0x0019,
							0x0012, 0x0002, 0x0078, 0x0000, 0x0010};
void led_7_seg_disp(int num)
{
	HAL_GPIO_WritePin(GPIOB, LED7SEG_ON[num], RESET);
	if (num != 8)
		HAL_GPIO_WritePin(GPIOB, LED7SEG_OFF[num], SET);
}
