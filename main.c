//Includes
#include <msp430.h>
#include <Setup.h>
//Functions
void MotionSensor();


int main(void){


 UARTSetup(); //Setup UART

 TimerSetup(); //Setup Timers

 BoardSetup(); //Setup the board

 __bis_SR_register(GIE); //Enable interrupts
 while(1){
     return(0);
 }
}


void MotionSensor(){

}



//--------------------Interrupts--------------------

//This should be a working interupt for port 1.3

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)

{
  P1OUT ^= BIT0;                            // P1.0 = toggle
  P1IFG &= ~BIT3;                           // P1.3 IFG cleared
  
  /*
  This interrupt should fire when the morion sensor sees something
  When the motion sensor sees something the buzzer should go off and the LED should blink
  */
}
