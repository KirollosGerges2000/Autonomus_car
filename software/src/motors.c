/*
motors.c
Author:Kirollos Gerges
*/
#include "motors.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"



void init_motors (void)
{
//config the outputs clock
	 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);





    RCC->AHB1ENR |= 1; //Enable GPIOA clock
       GPIOA->AFR[0] |= 0x00100000; // Select the PA5 pin in alternate function mode
       GPIOA->MODER |= 0x00000800; //Set the PA5 pin alternate function
        RCC->CFGR |= 0<<10; // set APB1 = 16 MHz

//config the outputs pins
	 GPIO_InitTypeDef GPIO_InitDef_E;
	     GPIO_InitDef_E.GPIO_Pin = GPIO_Pin_All;
	     GPIO_InitDef_E.GPIO_Mode = GPIO_Mode_OUT;
	     GPIO_InitDef_E.GPIO_OType = GPIO_OType_PP;
	     GPIO_InitDef_E.GPIO_PuPd = GPIO_PuPd_NOPULL;
	     GPIO_InitDef_E.GPIO_Speed = GPIO_Speed_2MHz;


	     GPIO_Init(GPIOE, &GPIO_InitDef_E);
//make it initialization as low
	    GPIO_ResetBits(GPIOE,GPIO_Pin_0);
           GPIO_ResetBits(GPIOE,GPIO_Pin_3);
           GPIO_ResetBits(GPIOE,GPIO_Pin_4);
            GPIO_ResetBits(GPIOE,GPIO_Pin_5);

            TIM2_Init();
            TIM2->CR1 |= 1;
}


void forward (void)
{
    //instruct motor to be forward
    GPIO_SetBits(GPIOE,GPIO_Pin_0);
         GPIO_ResetBits(GPIOE,GPIO_Pin_1);
           GPIO_SetBits(GPIOE,GPIO_Pin_4);
            GPIO_ResetBits(GPIOE,GPIO_Pin_5);
            control_speed (10000);
}

void backward (void)

{
 //instruct motor to be backward
 GPIO_ResetBits(GPIOE,GPIO_Pin_0);
         GPIO_SetBits(GPIOE,GPIO_Pin_1);
           GPIO_ResetBits(GPIOE,GPIO_Pin_4);
            GPIO_SetBits(GPIOE,GPIO_Pin_5);
            control_speed (10000);


}

void leftward (void)
{
 //instruct motor to be rightward
GPIO_ResetBits(GPIOE,GPIO_Pin_0);
         GPIO_SetBits(GPIOE,GPIO_Pin_1);
           GPIO_SetBits(GPIOE,GPIO_Pin_4);
            GPIO_ResetBits(GPIOE,GPIO_Pin_5);
            control_speed (10000);

}

void rightward (void)
{
 //instruct motor to be fleftward
GPIO_SetBits(GPIOE,GPIO_Pin_0);
         GPIO_ResetBits(GPIOE,GPIO_Pin_1);
           GPIO_ResetBits(GPIOE,GPIO_Pin_4);
            GPIO_SetBits(GPIOE,GPIO_Pin_5);
            control_speed (10000);
    
}
void stop (void)
{
 //instruct motor to be stop
  GPIO_SetBits(GPIOE,GPIO_Pin_0);
         GPIO_SetBits(GPIOE,GPIO_Pin_1);
           GPIO_SetBits(GPIOE,GPIO_Pin_4);
            GPIO_SetBits(GPIOE,GPIO_Pin_5);
            control_speed (0);
}



void TIM2_Init(void)
{
//Steps
//	Set clock Enable
	// set prescaler frequency
	//set Total period of cycle
//	Set the PWM mode
	//Enable your channel "channel 1"
	// initialize the first duty cycle
	 RCC->APB1ENR |=1;
	    TIM2->PSC = 16-1; //Setting the clock frequency to 1MHz.
	    TIM2->ARR = 20000; // Total period of the timer
	    TIM2->CNT = 0;
	    TIM2->CCMR1 = 0x0060; //PWM mode for the timer
	    TIM2->CCER |= 1; //Enable channel 1 as output
	    TIM2->CCR1 = 500; // Pulse width for PWM
}

void control_speed (int value)
{
 TIM2->CCR1 = value;  //Make the developer control it voltage

}

