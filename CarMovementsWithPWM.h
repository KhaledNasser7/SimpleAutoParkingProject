/*
 * CarMovementsWithPWM.h
 *
 * Created: 18/04/2018 04:39:44 م
 *  Author: Khaled Mohamed Nasser
 */ 


#ifndef CARMOVEMENTSWITHPWM_H_
#define CARMOVEMENTSWITHPWM_H_

#include "HBridgeWithPWMFunctionality.h"
#include "PhotoElectricSensorFunctionality.h"

void init_car_movements();
void move_car_forward(uint8_t duty_cycle_left, uint8_t duty_cycle_right);
void move_car_backward(uint8_t duty_cycle_left, uint8_t duty_cycle_right);
void turn_right45_forward(uint8_t duty_cycle);
void turn_right90_forward(uint8_t duty_cycle);
void turn_right45_backward(uint8_t duty_cycle);
void turn_right90_backward(uint8_t duty_cycle);
void turn_left45_forward(uint8_t duty_cycle);
void turn_left90_forward(uint8_t duty_cycle);
void turn_left45_backward(uint8_t duty_cycle);
void turn_left90_backward(uint8_t duty_cycle);
void stop_car();




#endif /* CARMOVEMENTSWITHPWM_H_ */