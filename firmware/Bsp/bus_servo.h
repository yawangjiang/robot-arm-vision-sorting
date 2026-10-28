#ifndef _BUS_SERVO_H_
#define _BUS_SERVO_H_
#include "main.h"

void bus_servo_control(uint8_t id, uint16_t value, uint16_t time);
void bus_servo_set_id(uint8_t id);
void bus_servo_read(uint8_t id);
uint16_t bus_servo_get_value(void);
void bus_servo_uart_recv(uint8_t Rx_Temp);
uint8_t get_Rx_state(void);


void bus_servo_Unloading(uint8_t id,uint8_t value);

void Uart3Rx_Handler(char *pdata, uint16_t len);//»Øµ÷º¯Êý

#endif /* _BUS_SERVO_H_ */
