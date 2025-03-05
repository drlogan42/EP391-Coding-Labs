//This is Lab Assignment for Lab 10, it will turn red LED on if nothing is in PD4, and will turn green LED on when GND supplied to PD4.

#define F_CPU 1000000UL //declaring the micro controller frequency of 1MHz

//The following lines include the header files for AVR-specific C code
#include <avr/io.h> //input and output
#include <util/delay.h> //delay utilities

int main(void)
{
	DDRD |= (1<<DDD2); //Set Data Direction Register of PortD-2 to be output by left-shifting a 1 into that position

	DDRD |= (1<<DDD3); //Set Data Direction Register of PortD-3 to be output by left-shifting a 1 into that position
	
	DDRD &= ~(1<<DDD4); //Set Data Direction Register of PortD-4 to be input by left-shifting a 0 into that position
	
	PORTD |= (1 << PD4); // Enable pull-up resistor on PD4

	
	while(1) //	Do an infinite loop
	{
		if (PIND & (1 << PD4)) {
			// PD4 is HIGH, turn red LED ON, green LED OFF
			PORTD |= (1<<PD3); //Red ON
			PORTD &= ~(1<<PD2); //Green OFF

			} else {
			// PD4 is LOW, turn green LED ON, red LED OFF
			PORTD &= ~(1<<PD3); //Red OFF
			PORTD |= (1<<PD2); //Green ON
		}
		
	}
	return 0;
}
