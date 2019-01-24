/*
 * CarMovementsWithPWM.c
 *
 * Created: 18/04/2018 04:40:05 م
 *  Author: Khaled Mohamed Nasser
 */ 

#include "CarMovementsWithPWM.h"

uint8_t ticks_per_turn45 = 11;
uint8_t ticks_per_turn90 = 17;


void init_car_movements(){
	init_HBridge_PWM();
	init_photoelectric_sensor();
}


void move_car_forward(uint8_t duty_cycle_left, uint8_t duty_cycle_right){
	motorA_move_forward_PWM(duty_cycle_right);
	motorB_move_forward_PWM(duty_cycle_left);
}


void move_car_backward(uint8_t duty_cycle_left, uint8_t duty_cycle_right){
	motorA_move_backward_PWM(duty_cycle_right);
	motorB_move_backward_PWM(duty_cycle_left);
}

// let motorA is the right motor & motorB is the left motor -- as viewed from the rear of the car

void turn_right45_forward(uint8_t duty_cycle){
	clear_left_sensor_ticks();
	motorB_move_forward_PWM(duty_cycle);
	while(get_left_sensor_ticks() < ticks_per_turn45);
	motorB_stop_PWM();
}


void turn_right90_forward(uint8_t duty_cycle){
	clear_left_sensor_ticks();
	motorB_move_forward_PWM(duty_cycle);
	while(get_left_sensor_ticks() < ticks_per_turn90);
	motorB_stop_PWM();
}


void turn_right45_backward(uint8_t duty_cycle){
	clear_right_sensor_ticks();
	motorA_move_backward_PWM(duty_cycle);
	while(get_right_sensor_ticks() < ticks_per_turn45);
	motorA_stop_PWM();
}


void turn_right90_backward(uint8_t duty_cycle){
	clear_right_sensor_ticks();
	motorA_move_backward_PWM(duty_cycle);
	while(get_right_sensor_ticks() < ticks_per_turn90);
	motorA_stop_PWM();
}


void turn_left45_forward(uint8_t duty_cycle){
	clear_right_sensor_ticks();
	motorA_move_forward_PWM(duty_cycle);
	while(get_right_sensor_ticks() < ticks_per_turn45);
	motorA_stop_PWM();
}


void turn_left90_forward(uint8_t duty_cycle){
	clear_right_sensor_ticks();
	motorA_move_forward_PWM(duty_cycle);
	while(get_right_sensor_ticks() < ticks_per_turn90);
	motorA_stop_PWM();
}


void turn_left45_backward(uint8_t duty_cycle){
	clear_left_sensor_ticks();
	motorB_move_backward_PWM(duty_cycle);
	while(get_left_sensor_ticks() < ticks_per_turn45);
	motorB_stop_PWM();
}


void turn_left90_backward(uint8_t duty_cycle){
	clear_left_sensor_ticks();           
	motorB_move_backward_PWM(duty_cycle);
	while(get_left_sensor_ticks() < ticks_per_turn90);
	motorB_stop_PWM();
}


void stop_car(){
	motorA_stop_PWM();
	motorB_stop_PWM();
}