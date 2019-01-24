/*
 * AutoParkingProject.h
 *
 * Created: 21/04/2018 02:25:55 م
 *  Author: Khaled Mohamed Nasser
 */ 


#ifndef AUTOPARKINGPROJECT_H_
#define AUTOPARKINGPROJECT_H_

#include "CarMovementsWithPWM.h"
#include "SensorFunctionality.h"

typedef enum {
	NOT_SUITABLE, SUITABLE
	}space_status_t;


void init_modules();							 // initialize all modules
void detect_possible_parking_space();			 // move car till the sensor detects a width suitable for car dimensions
space_status_t check_parking_space_length();     // measure the distance (length) of the free space using encoder
void parking_algorithm_on();					 // park the car


#endif /* AUTOPARKINGPROJECT_H_ */