/*
 * SensorFunctionality.c
 *
 * Created: 11/04/2018 01:59:02 م
 *  Author: Khaled Mohamed Nasser
 */ 

#include "SensorFunctionality.h"

static inline void trig_pulse();

static volatile uint8_t echo_sense = 0;
static volatile uint16_t echo_pulse_time = 0;

void init_sensor(){
	// set trig pin initialization
	set_bit(sensor_trig_pin_dir,sensor_trig_pin);       // trig pin is output
	clear_bit(sensor_trig_pin_port,sensor_trig_pin);    // trig pin is initialized 0
	
	// set echo pin initialization
	clear_bit(sensor_echo_pin_dir,sensor_echo_pin);       // echo pin is input
	clear_bit(sensor_echo_pin_port,sensor_echo_pin);    // echo pin is initialized 0
	//set_bit(MCUCR,ISC00);
	//clear_bit(MCUCR,ISC01);                            // sense control 01 -> any logical change generates an interrupt
	//set_bit(GICR,INT0);                                // enable int0
	set_bit(TCCR1B,ICNC1);            //noise canceler on
	set_bit(TCCR1B,ICES1);           // interrupt on rising edge
	set_bit(TIMSK,TICIE1);            // enable icp interrupt
	
	
	TCNT1 = 0;                                         // timer1 is initialized 0
}

uint8_t read_distance(){
	trig_pulse();                                // send trig pulse
	_delay_ms(16);                               // delay till counter stops (MAX pulse - 16000 us) -> datasheet
	uint8_t distance = (echo_pulse_time*(0.01145));  // distance = (T/29.1)/2 = T/58.2 or distance = T*0,0343/2 -> datasheet 
	                                                  //but since our clock is 12 MHz and we chose an 8 prescalar we need to add these factors
													 // to the equation .. so it becomes : distance = (T/58.2)*(prescalar/clk in MHz) 
													 // = (T/58.2)*(8/12) = T/(8/(58.2*12)) = T * 0.01145
	return distance;
}


static inline void trig_pulse(){
	set_bit(sensor_trig_pin_port,sensor_trig_pin);
	_delay_us(10);
	clear_bit(sensor_trig_pin_port,sensor_trig_pin);
}

ISR(TIMER1_CAPT_vect){
	if(echo_sense == 0){        // if echo pulse logic changes from 0 to 1
		//set_bit(TCCR1B,CS10);   // set timer clock to internal clock source with no prescaling to start counting
		set_bit(TCCR1B,CS11);   // set timer clock to internal clock source with 1/8 prescaling to start counting
		clear_bit(TCCR1B,ICES1); // interrupt on falling edge
		echo_sense = 1;         // echo pulse logic now is 1
	}
	else{
	if(echo_sense == 1){         // if echo pulse logic changes from 1 to 0 
		//clear_bit(TCCR1B,CS10); // set timer clock to no clock source to stop timer
		clear_bit(TCCR1B,CS11); // set timer clock to no clock source to stop timer
		//echo_pulse_time = TCNT1;                 // get echo pulse time in us
		echo_pulse_time = ICR1   ;  // get echo pulse time in us for any frequency + prescaling 1/8
		TCNT1 = 0;              // reset counter for further interrupts usage
		echo_sense = 0;         // echo pulse logic now is 0
		set_bit(TCCR1B,ICES1);  // interrupt on rising edge
	}
	}
}