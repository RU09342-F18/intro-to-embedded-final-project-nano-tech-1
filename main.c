//Includes
#include <msp430.h>
#include <Setup.h>
//Functions
void MotionSensor();	


int main(void){
 
 
 UARTSetup(); //Setup UART
 
 TimerSetup(); //Setup Timers
 
 BoardSetup(); //Setup the board
}


void MotionSensor(){
	
}



//--------------------Interupts--------------------

//This should be a working interupt for port 1.3
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)

{
  P1OUT ^= BIT0;                            // P1.0 = toggle
  P1IFG &= ~BIT3;                           // P1.3 IFG cleared
}
