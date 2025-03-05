//This is a hardware version of the "hello world" program. This turns on/off an LED on PortD-2 [pin 4] for 1,000 ms
#define F_CPU 1000000UL //declaring the microcontroller frequency of 1MHz
//the following lines include the header files for AVR-specific C code
#include <avr/io.h> //input and output
#include <util/delay.h> //delay utilities
int main()
{
	DDRD |= (1<<DDD2); // Set Data Direction Register of PortD-2 to be output by left-shifting a 1 into that position
	while(1) // Do an infinite loop
	{
		PORTD |= (1<<PORTD2); // Turn on the LED on PortD-2 by left-shifting a 1 into that position
		_delay_ms(1000); // Keep LED on for 1,000 ms or 1 second
		PORTD &= ~(1<<PORTD2); // Turn off the LED on PortD-2 by left-shifting a 0 into that position
		_delay_ms(1000); // Keep LED off for 1,000 ms or 1 second
	}
	return 0;
}
