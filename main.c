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
void ADC_Setup();

//Global Variables
bool BuzzerOn = false;

volatile unsigned int i = 0;                //This will not be optimized and removed by the compiler

int main(void){              	
//Setup the board
	BoardSetup();                             // Setup the board
	UARTSetup();                              // Setup UART
	LEDSetup();                               // Setup for LEDs
	TimerSetup();                             // Setup Timers
  ADC_Setup();                              // Setup for ADC
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
    P1OUT ^= BIT0;                            // P1.0 = toggle
    TA0CCR2 = TA0CCR2 + 5;                    //Roll the CCR value forward so it toggles again.
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
  P2OUT ^= BIT0;                            // P2.0 = toggle
  P1IFG &= ~BIT4;                           // P1.4 IFG cleared
}//end interrupt vector



