/*
servo.h
Author:Kirollos Gerges
*/
#ifndef SERVO_H
#define SERVO_H

void GPIO_init(void);
void TIM2_init(void);
void TIM4_ms_Delay(int delay);
void SERVO_INIT(void);
void SERVO (int DELAY1 ,int DELAY2);




#endif


