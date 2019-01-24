/*
 * PhotoElectricSensorFunctionality.h
 *
 * Created: 18/04/2018 02:56:59 م
 *  Author: Khaled Mohamed Nasser
 */ 


#ifndef PHOTOELECTRICSENSORFUNCTIONALITY_H_
#define PHOTOELECTRICSENSORFUNCTIONALITY_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "macros.h"
#include "PhotoElectricSensorConfig.h"

void init_photoelectric_sensor();
uint16_t get_right_sensor_ticks();
void clear_right_sensor_ticks();
uint16_t get_left_sensor_ticks();
void clear_left_sensor_ticks();


#endif /* PHOTOELECTRICSENSORFUNCTIONALITY_H_ */