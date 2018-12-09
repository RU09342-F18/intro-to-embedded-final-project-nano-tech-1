#include "Setup.h"
#include <msp430.h>
#define GREEN BIT6              // P1.6
void UARTSetup()								              // Code from Lab 0 example code
{
  DCOCTL = 0;                            		  // Select lowest DCOx and MODx settings
  BCSCTL1 = CALBC1_1MHZ;                   	  // Set DCO
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

void TimerSetup()                       		  // Subject to change
{
  TA0CTL |= TASSEL_2 + MC_1 + ID_3;                  // Select clock source to SMCLK and to up mode
  
  // Set capture/compare 1 to 128
  TA0CCR0 = 60000;
  TA0CCR1 = 30000;

  TA0CCTL1 |= OUTMOD_7;

  TA1CTL = TASSEL_1 + MC_1 + ID_0;            // SMCLK divided by 1, Up
  TA1CCR0  = 0x00FF;                          // Sets CCR0 to 255
  TA1CCTL1 = OUTMOD_7;                        // Reset or Set behavior
  TA1CCTL2 = OUTMOD_7;                        // Reset or Set behavior

  TA1CCR1 = 0x00FF;
  TA1CCR2 = 0x00FF;
}

void BoardSetup(){
  WDTCTL = WDTPW + WDTHOLD;                   // Stop watchdog timer

	//From example
	P1DIR |= BIT0;                         	    // Set P1.0 to output direction
	P1IE |=  BIT3;                         	    // P1.3 interrupt enabled
	P1IES |= BIT3;                         	    // P1.3 Hi/lo edge
	P1REN |= BIT3;								              // Enable Pull Up on SW2 (P1.3)
	P1IFG &= ~BIT3;                       	    // P1.3 IFG cleared
	
  //BIT3 on Port 1 can be used as Switch2
	
}

void LEDSetup(){
  /*P1DIR |= RedLED;                            // P1.6 to output
  P1SEL |= RedLED;                            // P1.6 to TA0.1
  P1SEL2 |= ~RedLED;
  P2DIR |= GreenLED;                          // P2.1 to output
  P2SEL |= GreenLED;                          // P2.1 to TA0.2
  P2SEL2 &= ~GreenLED;
  P2SEL2 &= ~BlueLED;
  */
  P1DIR |= GREEN;
  P1SEL |= GREEN;
}



