//Includes
#include <msp430.h>
#include <Setup.h>
//Definition
typedef int bool;
#define true 1
#define false 0
#define RED BIT6              // P1.6
//Functions
void MotionSensor();
void SoundSensor();
//Global Variables
bool BuzzerOn = false;

volatile unsigned int i = 0;                //This will not be optimized and removed by the compiler

int main(void){              	
//Setup the board
	BoardSetup();                             // Setup the board
	UARTSetup();                              // Setup UART
	LEDSetup();                               // Setup for LEDs
	TimerSetup();                             // Setup Timers
//Setup MQTT
	MQTTSetup();
  
//Prepare for normal operation

  __bis_SR_register(GIE);       // Enter LPM4 w/interrupt
  
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

#pragma vector=TIMER0_A2_VECTOR
__interrupt void Timer_A2 (void){   
    //This is used to make the buzzer make noise
    P1OUT ^= BIT6;                            // P1.0 = toggle
    TA0CCR2 = TA0CCR2 + 5;                    //Roll the CCR value forward so it toggles again.
}

#pragma vector=TIMER1_B1_VECTOR
__interrupt void Timer_B1 (void){
    //This is used to make the buzzer make noise
    P1OUT ^= BIT0;                            // P1.0 = toggle
    TA1CCR1 =TA1CCR1 + 10000;
}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(PORT1_VECTOR))) Port_1 (void)
#else
#error Compiler not supported!
#endif
{
  /*if (P1IFG == BIT3){
    P1OUT ^= BIT0;                            // P1.0 = toggle
    P1IFG &= ~BIT3;                           // P1.3 IFG cleared
  }
  if (P1IFG == BIT4){
    P2OUT ^= BIT0;                            // P2.0 = toggle
    P1IFG &= ~BIT4;                           // P1.4 IFG cleared
  }
  */
  
  
  //while(1){                             //Infinite while loop
  //i++;
  switch(P1IFG){
    case 0x08:
      P1OUT ^= BIT0;                            // P1.0 = toggle
      P1IFG &= ~BIT3;                           // P1.3 IFG cleared
      break;
    case 0x10:
      P2OUT ^= BIT0;                            // P2.0 = toggle
      P1IFG &= ~BIT4;                           // P1.4 IFG cleared
      break;
    default:
      //this should never run
      break;
  }

}//end interrupt vector


