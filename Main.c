#pragma config FOSC = INTRCIO  // Oscillator Selection bits (RC oscillator: CLKOUT function on GP4/OSC2/CLKOUT pin, RC on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = ON      // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // GP3/MCLR pin function select (GP3/MCLR pin function is digital I/O, MCLR internally tied to VDD)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.



#include "Includes.h"


// Config word
//__CONFIG(FOSC_INTRCIO & WDTE_OFF & PWRTE_ON & MCLRE_ & BOREN_OFF & CP_OFF & CPD_OFF);


// Define CPU Frequency
// This must be defined, if __delay_ms() or 
// __delay_us() functions are used in the code
#define _XTAL_FREQ   4000000    


// Main function
void main()
{	
	ANSEL  = 0x00;       // Set ports as digital I/O, not analog input
	ADCON0 = 0x00;		 // Shut off the A/D Converter
	CMCON  = 0x07;		 // Shut off the Comparator
	VRCON  = 0x00;	     // Shut off the Voltage Reference
	TRISIO = 0x08;       // GP3 input, rest all output
	GPIO   = 0x00;       // Make all pins 0
    
    
	
	InitPWM();	
    interruptISR();// Initialize PWM

	// PWM=0 means 0% duty cycle and 
	// PWM=255 means 100% duty cycle
	PWM = 127;			 // 50% duty cycle 
	
	while(1)
	{
	}
}
