#include "Setup.h"

void UARTSetup()								// Code from Lab 0 example code
{
    DCOCTL = 0;                            		// Select lowest DCOx and MODx settings
    BCSCTL1 = CALBC1_1MHZ;                   	// Set DCO
    DCOCTL = CALDCO_1MHZ;
    P1SEL = BIT1 + BIT2 ;                     	// P1.1 = RXD, P1.2=TXD
    P1SEL2 = BIT1 + BIT2 ;                    	// P1.1 = RXD, P1.2=TXD
    UCA0CTL1 |= UCSSEL_2;                     	// SMCLK
    UCA0BR0 = 104;                            	// 1MHz 9600
    UCA0BR1 = 0;                              	// 1MHz 9600
    UCA0MCTL = UCBRS0;                        	// Modulation UCBRSx = 1
    UCA0CTL1 &= ~UCSWRST;                     	// **Initialize USCI state machine**
    IE2 |= UCA0RXIE;                          	// Enable USCI_A0 RX interrupt
}

void TimerSetup()                       		// Subject to change
{
    //CCTL0 = CCIE;
    TA0CTL = TASSEL_2 + MC_1 + ID_0;            // SMCLK divided by 1, Up
    TA0CCR0  = 255;                         	// Sets CCR0 to 255
    TA0CCTL1 = OUTMOD_7;                        // Reset or Set behavior
    TA1CTL = TASSEL_2 + MC_1 + ID_0;            // SMCLK divided by 1, Up
    TA1CCR0  = 0x00FF;                          // Sets CCR0 to 255
    TA1CCTL1 = OUTMOD_7;                        // Reset or Set behavior
    TA1CCTL2 = OUTMOD_7;                        // Reset or Set behavior

    TA0CCR1 = 0x00FF;
    TA1CCR1 = 0x00FF;
    TA1CCR2 = 0x00FF;
}

/*void LEDSetup()
{
    P1DIR |= RedLED;                            // P1.6 to output
    P1SEL |= RedLED;                            // P1.6 to TA0.1
    P1SEL2 |= ~RedLED;
    P2DIR |= GreenLED;                          // P2.1 to output
    P2SEL |= GreenLED;                          // P2.1 to TA0.2
    P2SEL2 &= ~GreenLED;
    P2SEL2 &= ~BlueLED;
    P2DIR |= BlueLED;                           // P2.4 to output
    P2SEL |= BlueLED;                           // P2.4 to TA0.3
}
*/


