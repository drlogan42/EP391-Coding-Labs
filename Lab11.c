/*****A program that reads the voltage across a potentiometer, converting it to digital
* values. It then flips on or off LEDs based on the read in ADC value
********************/
#include <avr/io.h>
//Declare which pins the LEDs are connected to.
#define redLEDpin PD3
#define greenLEDpin PD2
int main()
{
	DDRD |= (1<<redLEDpin); // Set red LED as output
	DDRD |= (1<<greenLEDpin); // Set green LED as output
	// Set ADC prescalar to 8: Which is 125KHz sample rate @ 1MHz
	// Refer to page 244 to understand prescaling, and page 258 to see ADCSRA register
	ADCSRA |= (1<<ADPS1) | (1<<ADPS0);
	//Refer to page 256 to see how to set ADMUX register, and what each bit in the register means
	ADMUX |= (1<<REFS0); // This sets ADC reference to AVCC
	ADMUX |= (1<<ADLAR); // This left adjusts ADC result to allow easy 8 bit reading
	// No MUX values needed to be changed to use ADC0.
	// For more details refer to bottom of page 256 and Table 20-4 on page 257.
	// Next we enable the ADC
	ADCSRA |= (1<<ADEN); // Enable ADC
	// Our logic in the program will be as follows
	// Turn on and off the LED's as the value for ADCH is greater or less than 128.
	while(1){
		ADCSRA |= (1 << ADSC); // Start ADC Conversions
		// We now wait until the conversion is complete.
		// This will be signaled to us by the *re-setting* of ADSC bit within ADCSRA register.
		// Thus, we test if that bit is set. If it is ‘1’ then conversion is still being done. // Read page 258 of Datasheet. Read about Bit 6 ADSC.
		while ((1 << ADSC) & ADCSRA) {} // Wait until conversion is complete
		// The ADC results are stored in registers ADCH and ADCL.
		// But as we had set the ADLAR bit, we only need to read 8 bits.
		// Thus, the ADCH register will contain our ADC output data.
		if(ADCH < 128)
		{
			PORTD |= (1<<greenLEDpin); // Turn on green LED
			PORTD &= ~(1<<redLEDpin); // Turn off red LED
		}
		else
		{
			PORTD &= ~(1<<greenLEDpin); // Turn off green LED
			PORTD |= (1<<redLEDpin); // Turn on red LED
		}
	}
}
