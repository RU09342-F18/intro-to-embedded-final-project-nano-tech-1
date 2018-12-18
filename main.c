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
void Polling();

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

void Polling(){
   if (ADC10MEM >= 500){
       SoundSensor();
   }else{
       BuzzerOn = false;
   }

}

void MotionSensor(){
	//We have detected motion
}

void SoundSensor(){
	//We have detected sound
	
}



//--------------------Interrupts--------------------
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER0_A1_VECTOR
__interrupt void Timer_A(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER0_A1_VECTOR))) Timer_A (void)
#else
#error Compiler not supported!
#endif
{
 switch( TA0IV )
 {
   case  2: break;                          // CCR1
   case  4:                                 //CCR2
       TA0CCR2 += 5;
       P2OUT ^= BIT5;
       break;
   case 10:                                 // overflow
            break;
 }
}
/*
#pragma vector=TIMER1_A1_VECTOR
__interrupt void Timer1_A1 (void){ //This timer interrupt is to poll the mic.It currently does not work correctly
        P1OUT ^= BIT0;                            // P1.0 = toggle
    TA1CCR1 = TA1CCR1 + 10000;
    Polling();
}
*/
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
  
  /*if (P1IFG == BIT4){
    P2OUT ^= BIT0;                            // P2.0 = toggle
    P1IFG &= ~BIT4;                           // P1.4 IFG cleared
  }
  else if (P1IFG == BIT3){
    P1OUT ^= BIT5;                            // P2.0 = toggle
    P1IFG &= ~BIT3;                           // P1.4 IFG cleared
  }*/
}//end interrupt vector



