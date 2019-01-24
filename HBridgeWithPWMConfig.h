/*
 * HBridgeConfig.h
 *
 * Created: 11/04/2018 01:17:21 م
 *  Author: Khaled Mohamed Nasser
 */ 


#ifndef HBRIDGECONFIG_H_
#define HBRIDGECONFIG_H_

#define F_CPU 12000000ul

#define motorA_pinA 3           // oc0 pin
#define motorA_pinA_port PORTB
#define motorA_pinA_dir DDRB

#define motorA_pinB 4           // oc1B
#define motorA_pinB_port PORTD
#define motorA_pinB_dir DDRD

#define motorB_pinA 7            // oc2 pin
#define motorB_pinA_port PORTD
#define motorB_pinA_dir DDRD

#define motorB_pinB 5			// oc1A
#define motorB_pinB_port PORTD
#define motorB_pinB_dir DDRD





#endif /* HBRIDGECONFIG_H_ */