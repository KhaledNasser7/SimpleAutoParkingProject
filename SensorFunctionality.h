/*
 * SensorFunctionality.h
 *
 * Created: 11/04/2018 01:58:11 م
 *  Author: Khaled Mohamed Nasser
 */ 


#ifndef SENSORFUNCTIONS_H_
#define SENSORFUNCTIONS_H_

#include <avr/interrupt.h>
#include "UltrasonicSensorConfig.h"
#include <util/delay.h>
#include "macros.h"


void init_sensor();
uint8_t read_distance();





#endif /* SENSORFUNCTIONS_H_ */