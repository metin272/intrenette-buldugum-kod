#include "Includes.h"

// Define PWM variable, It can have a value 
// from 0 (0% duty cycle) to 255 (100% duty cycle)
unsigned char PWM = 0;



void InitPWM(void)
{

    OPTION_REGbits.T0CS = 0; // Dahili saat kayna?? kullan?lacak
    OPTION_REGbits.PSA = 0;  // Önölçekleyici kullan?lacak
    OPTION_REGbits.PS2 = 0;  // Önölçekleyici oran? 1:2
    OPTION_REGbits.PS1 = 1;
    OPTION_REGbits.PS0 = 0;
    // Enable global interrupts
    
	
	T0IE = 1;				// Enable Timer0 interrupt
	GIE = 1;	

}