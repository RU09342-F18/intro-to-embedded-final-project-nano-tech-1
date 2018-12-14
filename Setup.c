#include "Setup.h"
#include <msp430.h>

#define RED BIT6              // P1.6

void UARTSetup()								              // Code from Lab 0 example code
{
  DCOCTL = 0;                            		  // Select lowest DCOx and MODx settings
  BCSCTL1 = CALBC1_1MHZ;                   	  // Set DCO
  DCOCTL = CALDCO_1MHZ;
  P1SEL |= BIT1 + BIT2 ;                     	// P1.1 = RXD, P1.2=TXD
  P1SEL2 |= BIT1 + BIT2 ;                    	// P1.1 = RXD, P1.2=TXD
  UCA0CTL1 |= UCSSEL_2;                     	// SMCLK
  UCA0BR0 = 104;                            	// 1MHz 9600
  UCA0BR1 = 0;                              	// 1MHz 9600
  UCA0MCTL = UCBRS0;                        	// Modulation UCBRSx = 1
  UCA0CTL1 &= ~UCSWRST;                     	// **Initialize USCI state machine**
  IE2 |= UCA0RXIE;                          	// Enable USCI_A0 RX interrupt
}

void TimerSetup()                       		  // Subject to change
{
  //RED LED and Buzzer
  TA0CTL |= TASSEL_2 + MC_1 + ID_3;           // Select clock source to SMCLK and to up mode
  TA0CCTL1 |= OUTMOD_7;
  TA0CCR0 = 60000;
  TA0CCR1 = 9000;
  //Buzzer
  TA0CCR2 = 5;

}

void BoardSetup(){
  WDTCTL = WDTPW + WDTHOLD;                   // Stop watchdog timer

  //Buzzer - P1.0 - Can be changed
	//From example
	/*P1DIR |= BIT0;                         	    // Set P1.0 to output direction
  P1SEL |= BIT0;
  */

  // GREEN LED toggles each time interrupt is fired
  P1DIR |= BIT0;                            // Set P1.0 to output direction
  P1IE |=  BIT3;                            // P1.3 interrupt enabled
  P1IES |= BIT3;                            // P1.3 Hi/lo edge
  P1REN |= BIT3;							              // Enable Pull Up
  P1IFG &= ~BIT3;                           // P1.3 IFG cleared

  // RED LED toggles each time interrupt is fired
  P2DIR |= BIT0;                            // Set P2.0 to output direction
  P1IE |=  BIT4;                            // P1.4 interrupt enabled
  P1IES |= BIT4;                            // P1.4 Hi/lo edge
  P1REN |= BIT4;							              // Enable Pull Up
  P1IFG &= ~BIT4;                           // P1.4 IFG cleared

   

	/*P1IE |=  BIT3;                         	    // P1.3 interrupt enabled
	P1IES |= BIT3;                         	    // P1.3 Hi/lo edge
	P1REN |= BIT3;								              // Enable Pull Up on SW2 (P1.3)
	P1IFG |= ~BIT3;                       	    // P1.3 IFG cleared
	
	//test code for multiple interrupts
  P1REN |= 0x10;                            // P1.4 pullup
  P1IE |= 0x10;                             // P1.4 interrupt enabled
  P1IES |= 0x10;                            // P1.4 Hi/lo edge
  P1IFG |= ~0x10;                           // P1.4 IFG cleared

  //BIT3 on Port 1 can be used as Switch2
  */
}

void LEDSetup(){

  //Blinking LED - P1.6 - Can not be changed
  P1DIR |= RED;
  P1SEL |= RED;

}



