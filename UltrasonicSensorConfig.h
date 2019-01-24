/*
 * UltrasonicSensorConfig.h
 *
 There is a constraint in our micro-controller that we have only one input capture pin. It was dealt with by doing the following:
 The two ultrasonic sensors used in the project do not work simultaneously, so an advantage was taken of this condition 
 by connecting both sensors echo pin to the same pin (ICP), we can also connect their trigger pin to a common pin .. however, we have to
 switch on only one sensor at a time, to avoid overlapping of the waves .. so the Vcc pin of each sensor is connected to a pin 
 on the micro-controller 
 * Created: 11/04/2018 11:59:33 ص
 *  Author: Khaled Mohamed Nasser
 */ 


#ifndef ULTRASONICSENSORCONFIG_H_
#define ULTRASONICSENSORCONFIG_H_

#include <avr/io.h>
#ifndef F_CPU
#define F_CPU 12000000
#endif


#define sensor_trig_pin      0
#define sensor_trig_pin_port PORTC
#define sensor_trig_pin_dir  DDRC

#define sensor_echo_pin      6
#define sensor_echo_pin_port PORTD
#define sensor_echo_pin_dir  DDRD

// two 



#endif /* ULTRASONICSENSORCONFIG_H_ */