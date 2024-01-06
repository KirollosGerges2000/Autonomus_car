/*
US_sensor.c
Author:Kirollos Gerges
*/
#include "US_sensor.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"

// initialization sensor
void ADC_init(void)
{
	RCC->AHB1ENR |= (1<<0); // Enable clock source for PORT A
	GPIOA->MODER |= (3<<0); // Pa0 pin as an Analog
	RCC->APB2ENR |= (1<<8);  // Enable clock source for ADC1
	ADC1->CR1 |= (1<<24);  //  set 10 bit ADC
	ADC1->CR2 &= ~(1<<0);  //  ADC disable
	ADC1->SQR3 |= 0; // Enable ADC 0th Channel
	ADC1->CR2 |=  (1<<0);  // ADC ON
	
}

//ADC conversion
void ADC_conversion(void)
{
	ADC1->CR2 |= (1<<30); // Start  ADC conversion
	
}

float ADC_read(void)
{
	ADC_conversion();
	while(!(ADC1->SR & (1<<1))) {} // wait for conversion to be complete
		return (ADC1-> DR);
		
}


