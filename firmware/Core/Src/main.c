/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

	int flag,color;

void grab_all_up(int direction){//初始位置，全2048
	for(int i=0;i<3;i++){
	bus_servo_control(0,direction,3000);
	bus_servo_control(1,2000,3000);
	bus_servo_control(2,2048,3000);
	bus_servo_control(3,2048,3000);
	}
	
}

void grab_all_down_first(int direction){//抓取中间态1
	for(int i=0;i<3;i++){
		bus_servo_control(0,direction,6000);
		bus_servo_control(1,2000,6000);
		bus_servo_control(2,2548,6000);
		bus_servo_control(3,2050,6000);
	}
	
	
}

void grab_all_down(int direction){//抓取中间态结束
	for(int i=0;i<3;i++){
		bus_servo_control(0,direction,6000);
		bus_servo_control(1,300,6000);
		bus_servo_control(2,2548,6000);
		bus_servo_control(3,1048,6000);
	}
	
	
}

void put_all_first(int direction){	//一级放
	for(int i=0;i<3;i++){
	bus_servo_control(0,direction,2000);
	bus_servo_control(1,2048,2000);
	bus_servo_control(2,3200,2000);
	bus_servo_control(3,2700,2000);
	}
}

void put_all_second(int direction){	//抓取时状态
	for(int i=0;i<3;i++){
	bus_servo_control(0,direction,2000);
	bus_servo_control(1,3050,2000);
	bus_servo_control(2,2050,2000);
	bus_servo_control(3,2700,2000);
	}
}

void put_all_third(int direction){	//放置最终态
	for(int i=0;i<3;i++){
	bus_servo_control(0,direction,4000);
	bus_servo_control(1,2550,4000);
	bus_servo_control(2,2200,4000);
	bus_servo_control(3,2850,4000);
	}
}


void catch_all(){
	grab_all_up(850); 
	delay_ms(2000);
	bus_servo_control(4,2048,2000);
	delay_ms(2000);
	put_all_first(850);
	delay_ms(2000);
	
	put_all_second(850);
	delay_ms(2000);
	flag = Openmv.m;
	bus_servo_control(4,3025,2000);//夹爪力度
	delay_ms(2000);
	grab_all_down(850);
	delay_ms(5000);

}

void put_three(int i){
	int direction;
	switch(i){
		case 1:direction = 2900;break;//红位置
		case 0:direction = 3300;break;//绿
		case 2:direction = 3700;break;//蓝
	}
	grab_all_down(direction);
	delay_ms(2000);
	put_all_third(direction);
	delay_ms(4000);
	bus_servo_control(4,2048,2000);
	delay_ms(2000);
	put_all_first(direction);
	delay_ms(2000);
	grab_all_up(direction);
	delay_ms(6000);
	
	
}
	
/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART1_UART_Init();
  MX_USART3_UART_Init();
  MX_UART4_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
	delay_init(168);
	OpenmvInit();

	//flag = 1;
/* USER CODE END 2 */
	for(int i=0;i<3;i++){
		delay_ms(2000);
		catch_all();

		switch(flag){
			case 1:put_three(0);break;
			case 0:put_three(2);break;
			case 2:put_three(1);break;
		}
	}
	/*
	grab_all_up(850);
	delay_ms(2000);
	grab_all_down(850);
*/
//	grab_all_up(3300);
//	delay_ms(2000);
//	put_all_third(3300);
	
	//put_all_second(850);
	//bus_servo_control(4,2525,2000);
	//delay_ms(2000);
 
 
 
//	grab_all_up(850);
//	delay_ms(2000);
//	put_all_first(850);
//	delay_ms(2000);
//	put_all_second(850);
//	delay_ms(2000);

	//grab_all(2800);
	//put_all_first(850);
	//bus_servo_control(4,3048,2000);
  /* USER CODE BEGIN WHILE */
  
  while (1)
  {
    /* USER CODE END WHILE */
		

	  delay_ms(10);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
