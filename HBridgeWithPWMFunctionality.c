/*
 * HBridgeFunctionality.c
 *
 * Created: 12/04/2018 02:55:03 م
 *  Author: Khaled Mohamed Nasser
 */ 

#include "HBridgeWithPWMFunctionality.h"

static uint8_t duty_cycle_analogous_value = 0;

void init_HBridge_PWM(){
	// set micro-controller pins to HBridge as outputs
	set_bit(motorA_pinA_dir,motorA_pinA); 
	set_bit(motorA_pinB_dir,motorA_pinB); 
	set_bit(motorB_pinA_dir,motorB_pinA); 
	set_bit(motorB_pinB_dir,motorB_pinB);
	
	// set PWM mode
	// timer0
	set_bit(TCCR0,WGM00);
	set_bit(TCCR0,WGM01);  // set timer/counter0 on Fast PWM mode
	TCNT0 = 0;             // initialize timer0 by 0
	// timer2
	set_bit(TCCR2,WGM20);
	set_bit(TCCR2,WGM21);  // set timer/counter2 on Fast PWM mode
	TCNT2 = 0;             // initialize timer2 by 0
	
	
	// initialize pins with zero
	clear_bit(motorA_pinA_port,motorA_pinA); 
	clear_bit(motorA_pinB_port,motorA_pinB); 
	clear_bit(motorB_pinA_port,motorB_pinA); 
	clear_bit(motorB_pinB_port,motorB_pinB); 
}


void init_HBridge_Backward_PWM(){
	// disable input capture settings of ultrasonic
	clear_bit(TIMSK,TICIE1);            // disable icp interrupt
	// timer1
	set_bit(TCCR1A,WGM10);
	set_bit(TCCR1B,WGM12);  // set timer/counter1 on Fast PWM mode
	TCNT1 = 0;             // initialize timer2 by 0
}


void motorA_move_forward_PWM(uint8_t duty_cycle){
	// make sure that the function argument is between 0 - 100
	if(duty_cycle < 0){
		duty_cycle = 0;
	}else{if(duty_cycle > 100){
		duty_cycle = 100;
	}
	}
	duty_cycle_analogous_value = (uint8_t)(duty_cycle*2.55);    // duty_cycle*255/100;
	set_bit(TCCR0,COM01);                                       // connect OC0 to pin and select non-inverting mode (clear OC0 on compare match)
	OCR0 = duty_cycle_analogous_value;                          // load the analogous value, to duty cycle, to OCR0
	set_bit(TCCR0,CS00);                                       // start timer with no pre-scalar
}


void motorA_move_backward_PWM(uint8_t duty_cycle){
	// make sure that the function argument is between 0 - 100
	if(duty_cycle < 0){
		duty_cycle = 0;
		}else{if(duty_cycle > 100){
		duty_cycle = 100;
	}
}
duty_cycle_analogous_value = (uint8_t)(duty_cycle*2.55);    // duty_cycle*255/100;
set_bit(TCCR1A,COM1B1);                                     // connect OC1B to pin and select non-inverting mode (clear OC1B on compare match)
OCR1B = duty_cycle_analogous_value;                          // load the analogous value, to duty cycle, to OCR1A/B
set_bit(TCCR1B,CS10);                                       // start timer with no pre-scalar
}


void motorA_stop_PWM(){
	clear_bit(TCCR0,CS00);						 //  stop timer 0
	clear_bit(TCCR1B,CS10);                     // stop timer 1
	clear_bit(TCCR0,COM01);						 // disconnect OC0 from pin
	clear_bit(TCCR1A,COM1B1);                   // disconnect OC1B from pin
	clear_bit(motorA_pinA_port,motorA_pinA);
	clear_bit(motorA_pinB_port,motorA_pinB);
	TCNT0 = 0;             // initialize timer0 by 0
	TCNT1 = 0;             // initialize timer1 by 0
}


void motorB_move_forward_PWM(uint8_t duty_cycle){
	// make sure that the function argument is between 0 - 100
	if(duty_cycle < 0){
		duty_cycle = 0;
		}else{if(duty_cycle > 100){
		duty_cycle = 100;
	}
}
duty_cycle_analogous_value = (uint8_t) (duty_cycle*2.55);    //duty_cycle*255/100;
set_bit(TCCR2,COM21);										// connect OC2 pin and select non-inverting mode (clear OC2 on compare match)
OCR2 = duty_cycle_analogous_value;                          // load the analogous value, to duty cycle, to OCR2
set_bit(TCCR2,CS20);                                       // start timer with no pre-scalar
}


void motorB_move_backward_PWM(uint8_t duty_cycle){
	// make sure that the function argument is between 0 - 100
	if(duty_cycle < 0){
		duty_cycle = 0;
		}else{if(duty_cycle > 100){
		duty_cycle = 100;
	}
}
duty_cycle_analogous_value = (uint8_t)(duty_cycle*2.55);    // duty_cycle*255/100;
set_bit(TCCR1A,COM1A1);										// connect OC1A to pin and select non-inverting mode (clear OC1A on compare match)
OCR1A = duty_cycle_analogous_value;								// load the analogous value, to duty cycle, to OCR1A
set_bit(TCCR1B,CS10);                                       // start timer with no pre-scalar
}


void motorB_stop_PWM(){
	clear_bit(TCCR2,CS20);						 //  stop timer
	clear_bit(TCCR1B,CS10);                     // stop timer 1
	clear_bit(TCCR2,COM21);						// disconnect OC2 pin
	clear_bit(TCCR1A,COM1A1);                   // disconnect OC1A from pin
	clear_bit(motorB_pinA_port,motorB_pinA);
	clear_bit(motorB_pinB_port,motorB_pinB);
	TCNT2 = 0;             // initialize timer2 by 0
	TCNT1 = 0;             // initialize timer1 by 0
}