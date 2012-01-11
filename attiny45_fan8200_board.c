#include <avr/io.h>
#include "attiny45_fan8200_board.h"

void io_setup(void) {
 DDRB |= 1<<PB0 | 1<<PB1 | 1<<PB3 | 1<<PB4; //All ports output except PB2 (ADC1)
 PORTB &= ~(1<<PB2); //PB2 pullup off

//ADC stuff, 8-bit value readable from ADHC
 ADMUX |= 1<<MUX0 | 1<<ADLAR; //Use PB2, Left shift register results
 ADCSRA |= 1<<ADEN | 1<<ADPS2 | 1<<ADPS1 | 1<<ADSC; //ADC enable, Use 64 prescaler, start ADC
}

void stop(void) {
 PORTB &= ~(1<<PB0 | 1<<PB1 | 1<<PB3 | 1<<PB4); //Disable motors 1 & 2
}

void forward(void) {
 stop();
 PORTB |= 1<<PB0 | 1<<PB4; //Motors 1 & 2 on and forward
}

void reverse(void) {
 stop();
 PORTB |= 1<<PB1 | 1<<PB3; //Motors 1 & 2 on and backwards
}

void right(void) {
 stop();
 PORTB |= 1<<PB1 | 1<<PB4; //Left forward, right backwards, turns right.
}

void left(void) {
 stop();
 PORTB |= 1<<PB0 | 1<<PB3; // Right forward, left backwards, turns left.
}

