#ifndef ATTINY45_FAN8200_BOARD_H_INCLUDED
#define ATTINY45_FAN8200_BOARD_H_INCLUDED

//Call io_setup() at the beginning of your program,
//Infrared sensor values can be read from register ADHC

void io_setup(void); //Sets up communication to FAN8200 and ADC for infrared sensor input
void stop(void); //Halts motors
void forward(void); //Forward
void reverse(void); //Backwards
void right(void); //Turn right
void left(void); //Turn left

#endif
