#include "control.h"h

void arm_go_to_mid(void)
{
	bus_servo_control(254, 2048, 1000);
}
/*
void arm_reset(void)
{
    bus_servo_control(1, 2048, 2000); //1000:开  2048：合
    bus_servo_control(2, 2260, 2000);
    bus_servo_control(3, 2048, 2000);	
    bus_servo_control(4, 2100, 2000); //302  
    bus_servo_control(5, 2048, 2000);
    bus_servo_control(6, 2048, 2000);
}
//抓取色块
void arm_A_detect_pos(void)
{
    bus_servo_control(6, 3250, 1500);             // 定义在bus_servo.c  
    bus_servo_control(4, 3000, 1500);
    bus_servo_control(1, 1000, 1500);
    delay_ms(1000);  
	
	bus_servo_control(3, 2600, 1500);
	bus_servo_control(4, 3000, 1500);
    bus_servo_control(5, 2600, 1500);
    delay_ms(500);
	
    bus_servo_control(3,1500 , 1500);
 	bus_servo_control(4, 2800, 1500);
    bus_servo_control(5, 3000, 1500); 
    delay_ms(1000);    
} 


//放置绿色色块
void put_green(void) 
{
    bus_servo_control(1, 2048, 1500);
    delay_ms(1500);  
	
    bus_servo_control(3,3100 , 1500);
    bus_servo_control(4, 1600, 2000);
    bus_servo_control(5, 2500, 2000);   
    delay_ms(1000);
	
    bus_servo_control(1, 2048, 1000);
    delay_ms(1000); 
	

    bus_servo_control(6,1025 , 3000);
    delay_ms(1000);
	
    bus_servo_control(3,1500 , 2000);
 	bus_servo_control(4, 2800, 2000);
    bus_servo_control(5, 3000, 2000); 
    delay_ms(1500);
	
    bus_servo_control(1, 1000, 1000);
    delay_ms(1000);  
	
	bus_servo_control(3,1300 , 1000);    
    bus_servo_control(4, 2900, 1000);
    bus_servo_control(5, 2048, 1000);
    delay_ms(200);  
}
//放置蓝色色块
void put_bule(void)
{
    bus_servo_control(1, 2048, 1500);
    delay_ms(1500);  
    bus_servo_control(3,3100 , 1500);
    bus_servo_control(4, 1600, 2000);
    bus_servo_control(5, 2500, 2000);   

    delay_ms(1000);
    bus_servo_control(1, 2048, 1000);
    delay_ms(1000); 
	
    bus_servo_control(6,1380 , 3000);
    delay_ms(1500);
    bus_servo_control(3,1500 , 2000);
 	bus_servo_control(4, 2800, 2000);
    bus_servo_control(5, 3000, 2000); 
    delay_ms(1500);
    bus_servo_control(1, 1000, 1000);
    delay_ms(1000);  
    bus_servo_control(3,1300 , 1000);    
    bus_servo_control(4, 2900, 1000);
    bus_servo_control(5, 2048, 1000);
    delay_ms(200); 
}
//放置红色色块
void put_red(void)
{
    bus_servo_control(1, 2048, 1500);
    delay_ms(1500);  
    bus_servo_control(3,3100 , 1500);
    bus_servo_control(4, 1600, 2000);
    bus_servo_control(5, 2500, 2000);   

    delay_ms(1000);
    bus_servo_control(1, 2048, 1000);
    delay_ms(1000); 

    bus_servo_control(6,640 , 3000);
    delay_ms(1500);
    bus_servo_control(3,1500 , 2000);
 	bus_servo_control(4, 2800, 2000);
    bus_servo_control(5, 3000, 2000); 
    delay_ms(1500);
    bus_servo_control(1, 1000, 1000);
    delay_ms(1000);  
   bus_servo_control(3,1300 , 1000);    
    bus_servo_control(4, 2900, 1000);
    bus_servo_control(5, 2048, 1000);
    delay_ms(200);   
}

void arm_put_action(uint8_t color)
{
	if (color == 1)// 红色
	{
        put_red();
	}
	else if (color == 2)
	{
        put_bule();
	}
	else if (color == 4)
	{
		put_green();
	}
}

uint8_t flag = 0;

void servo_control(void)
{
	
	uint8_t id; 
	uint16_t value; 
	uint16_t time;
	uint8_t color=0;
	static uint8_t count = 0;
	if (flag == 0)
	{
		arm_reset();//机械臂复位
		delay_ms(1000);
		flag = 1;
        count++;
        if(count==4)
        {
            flag=2;//结束
        }
	}
	else if (flag == 1)
	{
        arm_A_detect_pos();//机械臂抓取色块
        Openmv.m = 0;
        delay_ms(1000);
        color = Openmv.m;
//        delay_ms(1000);
        if(color)
        {   
            
//    		printf("color:%d\r\n", Openmv.m);
            arm_put_action(color);
            delay_ms(1000);           
            Openmv.m = 0;
            flag = 0;
        }
	}
	delay_ms(500);
}
*/