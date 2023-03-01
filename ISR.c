#include "Includes.h"


// Define PWM pin
#define PWM_Pin    GP0




void interruptISR(void)
{
	if(T0IF)  //If Timer0 Interrupt
	{
		if(PWM_Pin)	// if PWM_Pin is high
		{
			PWM_Pin = 0;
			TMR0 = PWM;
		}
		else	     // if PWM_Pin is low
		{
			PWM_Pin = 1;
			TMR0 = 255 - PWM;
		}

		T0IF = 0;   // Clear the interrupt
	}
}