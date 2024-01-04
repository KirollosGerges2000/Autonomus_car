/*
motors.h
Author:Kirollos Gerges
*/

#ifndef MOTORS

#define MOTORS
//Prototypes
void init_motors (void);
void forward (void);
void backward (void);
void leftward (void);
void rightward (void);
void stop (void);
void TIM2_Init(void);
void control_speed (int value);

#endif
