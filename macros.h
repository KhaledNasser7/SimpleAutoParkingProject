/*
 * macros.h
 *
 * Created: 03/04/2018 03:16:44 ص
 *  Author: Peter
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#define clear_bit(var, bit) var &= (~(1u<<bit))

#define set_bit(var, bit) var |= (1u<<bit)

#define toggle_bit(var, bit) var ^= (1u<<bit)

#define read_bit(var, bit) (1u&(var>>bit))




#endif /* MACROS_H_ */