/******************************************************************************
 *
 * www.payitforward.edu.vn
 *
 ******************************************************************************/

/******************************************************************************
 *
 * CHICKEN BOARD - HAPPY CODING
 *
 ******************************************************************************/

/******************************************************************************
 *
 *    Module       : main.C
 *    Description  : This demonstration use the MSP430G2xxx to generate tones
 *    				using PWM
 *
 *  Tool           : CCS 5.4
 *  Chip           : MSP430G2xxx
 *  History        : 23-04-2014
 *  Version        : 1.1
 *
 *  Author         : PIFers, Pay It Forward Club
 *  Notes          :
 *
******************************************************************************/

 /****************************************************************************
 * IMPORT
******************************************************************************/
#include <msp430.h>
#include "sound.h"

/****************************************************************************
* DEFINITIONS
******************************************************************************/
#define Song 	FurElise
#define speed	500

/****************************************************************************
* FUNCTIONS
******************************************************************************/
//*****************************************************************************
// Clocks Configurations
//*****************************************************************************
void ConfigClocks(void)
{
	BCSCTL1 = CALBC1_1MHZ;		// Set range
	DCOCTL = CALDCO_1MHZ;		// Set DCO step + modulation
	BCSCTL3 |= LFXT1S_2;		// LFXT1 = VLO
	IFG1 &= ~OFIFG;				// Clear OSCFault flag
	BCSCTL2 |= SELM_0 + DIVM_3;	//MCLK = DCO/8, SMCLK = DCO/8
}

//*****************************************************************************
// Configure Timer1
//*****************************************************************************
void ConfigTimer(void)
{
	TA1CTL = TASSEL_2 + MC_1 + TAIE;// SMCLK, up mode
	TA1CCR0 = 2500;					// PWM Period=50HZ
	TA1CCTL1 = OUTMOD_7;			// CCR1 reset/set
	TA1CCR1 = 0;					// PWM duty cycle
	TA1CCTL2 = OUTMOD_7;			// CCR1 reset/set
	TA1CCR2 = 0;					// PWM duty cycle
	P2DIR |=  BIT2 + BIT4;			// P2.2 & P2.4 output
	P2SEL |=  BIT2 + BIT4;			// P2.2 TA1.1
									// P2.4 TA1.2
}

//*****************************************************************************
// Main Routine
//*****************************************************************************
void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;		//Stop Watchdog Timer

	ConfigClocks();
	ConfigTimer();

	_bis_SR_register(GIE + LPM1_bits);		// Turn on interrupts, Enter LPM1
}

//*****************************************************************************
// Timer1 interrupt service routine
//*****************************************************************************
#pragma vector = TIMER1_A1_VECTOR
__interrupt void Timer1_ISR(void)
{
	static unsigned long time = 0;
	static unsigned int count = 0;
	time++;
	if (time >= speed * Song[count*2])
	{
		time = 0;
		count++;
		if (Song[count*2] == 0xffff)
		{
			count = 0;
		}
		TA1CCR0 = 20 * Song[count*2 + 1];
		TA1CCR1 = TA1CCR0 / 2;
		TA1CCR2 = TA1CCR0 / 2;
	}
}
/******************************************************************************
 * END OF main.C
*******************************************************************************/
