#include "msp430g2553.h"

void configureClocks();
volatile unsigned int i; // volatile to prevent optimization

void main(void)
{
WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
configureClocks();

// Configure LED on P1.0
P1DIR = BIT0; // P1.0 output
P1OUT |= BIT0;
//
//// Configure Switch on P1.2
P1REN |= BIT3; // P1.2 Enable Pullup/Pulldown
P1OUT |= BIT3; // P1.2 pullup
P1IES |= BIT3; // P1.2 Hi/lo edge
//P1IFG &= BIT3; // P1.2 IFG cleared just in case
P1IFG = 0
//_EINT();
while(1)
{
if(P1IFG & BIT3) // P1.2 IFG cleared
{
P1OUT ^= BIT0; // Toggle LED at P1.0
P1IFG &= ~BIT3; // P1.2 IFG cleared
}
}
}

void configureClocks()
{
// Set system DCO to 8MHz
BCSCTL1 = CALBC1_8MHZ;
DCOCTL = CALDCO_8MHZ;

// Set LFXT1 to the VLO @ 12kHz
BCSCTL3 |= LFXT1S_2;
}
