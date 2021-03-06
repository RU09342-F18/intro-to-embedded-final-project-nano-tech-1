// Includes
#include <msp430.h>
#include <Setup.h>

// Definition
typedef int bool;
#define true 1                          // Defining 1 as true
#define false 0                         // Defining 0 as false
#define RED BIT6                        // Defining BIT6 as RED

// Functions
void MotionSensor();
void SoundSensor();
void ADC_Setup();
void Polling();

// Global Variables
bool BuzzerOn = false;
bool AllowBuzzer = true;

volatile unsigned int i = 0;            // This will not be optimized and removed by the compiler

int main(void){              	
  // Setting up the board
  BoardSetup();                         // Setup the board
  UARTSetup();                          // Setup UART
  LEDSetup();                           // Setup for LEDs
  TimerSetup();                         // Setup Timers
  ADC_Setup();                          // Setup for ADC

  // Setup MQTT
  MQTTSetup();
  
  // Prepare for normal operation
  __bis_SR_register(GIE);               // Enter LPM4 with interrupt
  
  while(1){
      return(0);
  }// End While Loop
}

void Polling(){                         // Polls the sound sensor to check for noise

  if (ADC10MEM >= 500 && BuzzerOn == false){
    AllowBuzzer = true;                     //The mic sees something! We should turn on the buzzer

    SoundSensor();
  }else{
      P1SEL &= ~BIT0;
    BuzzerOn = false;
  }// End else statement
}// End Polling Function

void MotionSensor(){
	//We have detected motion
}

void SoundSensor(){
	//We have detected sound
    BuzzerOn = true;
    P1SEL |= BIT0;
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
  case  2:                                  // CCR1

           break;
  case 4:                                 //CCR2 Buzzer control
      if(AllowBuzzer == true){
      TA0CCR2 += 40;
      P2OUT ^= BIT5;                       //This is SUPPOSE to make the buzzer actually buzz
      P2SEL |= BIT5;                        //Turn on P2.5
      TA1R = 1;                             //Reset this timer to 1, so we have a timer to turn off the buzzer!
      AllowBuzzer = false;
      }
      break;
  case 10:

      break;                           // overflow not used

 }
}
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER1_A1_VECTOR
__interrupt void Timer1_A(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER0_A1_VECTOR))) Timer_A (void)
#else
#error Compiler not supported!
#endif
{
  switch( TA1IV )
  {
  case  2:                                  // CCR1 Used to poll sound every 1000ms
      P1OUT ^= BIT0;                            // P1.0 = toggle test code
      TA1CCR1 = TA1CCR1 + 1000;                //Off set timer for next 100 ms
      Polling();                                //Check the ADC

           break;
  case  4:
      P2SEL &= ~BIT5;
      AllowBuzzer = true;

      break;                           // CCR2 not used
  case 10: break;                           // overflow not used

 }
}



//Interrupt for Motion Sensor, LED will toggle when it receives a signal from the Motion Sensor
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(PORT1_VECTOR))) Port_1 (void)
#else
#error Compiler not supported!
#endif
{
    if(AllowBuzzer == true){
       MotionSensor() ;
    }
  P2OUT ^= BIT0;                            // P2.0 = toggle
  P1IFG &= ~BIT4;                           // P1.4 IFG cleared
}//End interrupt vector



6v
