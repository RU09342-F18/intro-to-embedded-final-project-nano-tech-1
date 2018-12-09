//Includes
#include <msp430.h>
#include <Setup.h>
//Functions
void MotionSensor();
void SoundSensor();


#define GREEN BIT6              // P1.6


int main(void){

  WDTCTL = WDTPW | WDTHOLD;			// stop watchdog timer

  BoardSetup();               // Setup the board

  UARTSetup();                  // Setup UART

  LEDSetup();                   // Setup for LEDs

  TimerSetup();                 // Setup Timers



  __bis_SR_register(GIE);       // Enable interrupts
  
  while(1){
      return(0);
  }
}


void MotionSensor(){
	//We have detected motion
}

void SoundSensor(){
	//We have detected sound
	
}



//--------------------Interrupts--------------------

//This should be a working interrupt for port 1.3
/*
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)

{
  P1OUT ^= BIT0;                            // P1.0 = toggle
  P1IFG &= ~BIT3;                           // P1.3 IFG cleared
  

  This interrupt should fire when the morion sensor sees something
  When the motion sensor sees something the buzzer should go off and the LED should blink

}
*/
#pragma vector=TIMER0_A2_VECTOR
__interrupt void Timer_A2 (void)
{//This is used to make the buzzer make noise


    P1OUT ^= BIT0;                            // P1.0 = toggle
    TA0CCR2 = TA0CCR2 + 5;                    //Roll the CCR value forward so it toggles again.

}


