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

  //Sound poller
  TA1CCTL1 = CCIE;
  TA1CTL = TASSEL_2 + MC_1 + ID_3 + TAIE + TACLR; // SMCLK/4, Up
  TA1CCR0 = 65535;
  TA1CCR1 = 10000;


}

void BoardSetup(){
  WDTCTL = WDTPW + WDTHOLD;                   // Stop watchdog timer

  //Buzzer - P1.0 - Can be changed
	//From example
	/*P1DIR |= BIT0;                         	    // Set P1.0 to output direction
  P1SEL |= BIT0;
  */

  // RED LED toggles each time interrupt is fired
  P2DIR |= BIT0;                            // Set P2.0 to output direction
  P1IE |=  BIT4;                            // P1.4 interrupt enabled
  P1IES |= BIT4;                            // P1.4 Hi/lo edge
  P1REN |= BIT4;                            // Enable Pull Up
  //P1IFG &= ~BIT4;                           // P1.4 IFG cleared

  /*
  // GREEN LED toggles each time interrupt is fired
  P1DIR |= BIT5;                            // Set P1.0 to output direction
  P1IE |=  BIT3;                            // P1.3 interrupt enabled
  P1IES |= BIT3;                            // P1.3 Hi/lo edge
  //P1REN |= BIT3;							              // Enable Pull Up
  //P1IFG &= ~BIT3;                           // P1.3 IFG cleared
  */
}

void LEDSetup(){
  //Blinking LED - P1.6 - Can not be changed
  P1DIR |= RED;
  P1SEL |= RED;
}

void ADC_Setup(){
  //Setting up ADC
  ADC10CTL1 = CONSEQ_2 + INCH_3;            // Repeat single channel
  ADC10CTL0 = MSC + ADC10ON;
  ADC10DTC1 = 0x20;                         // 32 conversions
  ADC10AE0 |= BIT3;                         // P1.3 ADC option select
  P1DIR |= BIT5;                            // Set P1.0 output

  //for (;;){
    ADC10CTL0 &= ~ENC;
    while (ADC10CTL1 & ADC10BUSY);          // Wait if ADC10 core is active
    ADC10SA = 0x200;                        // Data buffer start
    P1OUT |= BIT5;                          // Set P1.0 LED on
    ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
    P1OUT &= ~BIT5;                         // Clear P1.0 LED off
  //}
}

void MQTTSetup(){
		/*
	  Commands:
  $Subscribe        SYNTAX: "$Topic\n"
  #Publish          SYNTAX: "#Topic Payload\n"
  !ReceivedMessage  SYNTAX: "!Topic: Message\n"
  ~Unsubscribe      SYNTAX: "~Topic\n"
  */
  unsigned int count = 0;
  char Subscribe[10]={'$','S','e','c','u','r','i','t','y','\0'};
  while (!(IFG2&UCA0TXIFG) && count <= 8){	                // USCI_A0 TX buffer ready?
	UCA0TXBUF = Subscribe[count];
	count++;
  }
  count = 0;
}



