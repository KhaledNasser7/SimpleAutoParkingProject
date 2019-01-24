/*
 * main.c
 *
 * Created: 21/04/2018 02:17:22 م
 *  Author: Khaled Mohamed Nasser
 */ 


#include <avr/io.h>
#include "AutoParkingProject.h"

int main(void)
{
	init_modules();
    while(1)
    {
		//move_car_forward(90,90);
        //TODO:: Please write your application code
		detect_possible_parking_space();
		_delay_ms(1000);
		if(check_parking_space_length() == SUITABLE){
			_delay_ms(1000);
			parking_algorithm_on();
			break;
		}
		stop_car();
		//_delay_ms(1000);
    }
}