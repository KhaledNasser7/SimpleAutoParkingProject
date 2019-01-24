/*
 * HBridgeFunctionality.h
 *
 * Created: 12/04/2018 02:54:34 م
 *  Author: Khaled Mohamed Nasser
 */ 


#ifndef HBRIDGEFUNCTIONALITY_H_
#define HBRIDGEFUNCTIONALITY_H_

#include <avr/io.h>
#include "HBridgeWithPWMConfig.h"
#include <util/delay.h>
#include "macros.h"

void init_HBridge_PWM();
void init_HBridge_Backward_PWM();
void motorA_move_forward_PWM(uint8_t duty_cycle);
void motorA_move_backward_PWM(uint8_t duty_cycle);
void motorA_stop_PWM();
void motorB_move_forward_PWM(uint8_t duty_cycle);
void motorB_move_backward_PWM(uint8_t duty_cycle);
void motorB_stop_PWM();

#endif /* HBRIDGEFUNCTIONALITY_H_ */