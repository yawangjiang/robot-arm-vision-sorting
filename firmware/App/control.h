#ifndef __CONTROL_H_
#define __CONTROL_H_

#include "main.h"
#include "dma.h"
#include "usart.h"
#include "gpio.h"
#include "control.h"

void arm_go_to_mid(void);
void arm_reset(void);
void arm_A_detect_pos(void);
void put_red(void); 
void put_green(void);
void put_blue(void);
void arm_put_action(uint8_t color);
void servo_control(void);
#endif
