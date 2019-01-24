/*
 * PhotoElectricSensorFunctionality.c
 *
 * Created: 18/04/2018 02:57:19 م
 *  Author: Khaled Mohamed Nasser
 */ 

#include "PhotoElectricSensorFunctionality.h"

static uint16_t right_sensor_ticks = 0;
static uint16_t left_sensor_ticks = 0;

void init_photoelectric_sensor(){
	// set up sensor output pin as an external input interrupt to microcontroller
	
	clear_bit(right_sensor_output_pin_dir,right_sensor_output_pin);  // define sensor output pin as input to microcontroller 
	clear_bit(left_sensor_output_pin_dir,left_sensor_output_pin);
	
	clear_bit(right_sensor_output_pin_port,right_sensor_output_pin);                  // no pull-up resistor needed
	clear_bit(left_sensor_output_pin_port,left_sensor_output_pin);

	set_bit(MCUCR,ISC01);     // set interrupt sense as falling edge generates an interrupt request
	set_bit(MCUCR,ISC11);
	
	set_bit(GICR,INT0);       // enable external interrupt request 0
	set_bit(GICR,INT1);		  // enable external interrupt request 1
	
	sei();                    // enable global interrupt
}

uint16_t get_right_sensor_ticks(){
	return right_sensor_ticks;
}

void clear_right_sensor_ticks(){
	right_sensor_ticks=0;
}

uint16_t get_left_sensor_ticks(){
	return left_sensor_ticks;
}

void clear_left_sensor_ticks(){
	left_sensor_ticks=0;
}


ISR(INT0_vect){
	right_sensor_ticks++;
}

ISR(INT1_vect){
	left_sensor_ticks++;
}