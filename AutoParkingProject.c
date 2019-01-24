/*
 * AutoParkingProject.c
 *
 * Created: 21/04/2018 02:26:14 م
 *  Author: Khaled Mohamed Nasser
 */ 

#include "AutoParkingProject.h"

void init_modules(){
	init_car_movements();  // initialize HBridge + photoelectric sensor
	init_sensor();		   // initialize ultrasonic sensor
}


void detect_possible_parking_space(){					// move car till the sensor detects a width suitable for car dimensions
	move_car_forward(85,87);
	while(read_distance() < 20);
	stop_car();
}


space_status_t check_parking_space_length(){						// measure the distance (length) of the free space using encoder
	space_status_t space_status = NOT_SUITABLE;  //  0 -> not suitable .. 1 -> suitable
	clear_right_sensor_ticks();
	move_car_forward(85,87);
	while( (read_distance() > 20) && (get_right_sensor_ticks() < 150) );  // 16 ticks analogous to 20.5 cm
	if(get_right_sensor_ticks() > 39){ // suitable space for parking
		stop_car();
		space_status = SUITABLE;
	}
	return space_status;
}


void parking_algorithm_on(){							 // park the car
	init_HBridge_Backward_PWM();
	turn_left45_forward(100);
	_delay_ms(1000);
	clear_right_sensor_ticks();
	move_car_backward(85,87);
	while(get_right_sensor_ticks() < 150);
	stop_car();
	_delay_ms(1000);
	turn_right45_backward(100);
}