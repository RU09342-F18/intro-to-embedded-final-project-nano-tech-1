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
  if (ADC10MEM >= 500){
    SoundSensor();
  }else{
    BuzzerOn = false;
  }// End else statement
}// End Polling Function

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
  switch(TA0IV){
    case  2:
      break;                                // CCR1
    case  4:                                // CCR2
      TA0CCR2 += 5;
      break;
    case 10:
      P1OUT ^= 0x01;                        // Overflow
      break;
  }
}

//Interrupt for Motion Sensor, LED will toggle when it recieves a signal from the Motion Sensor
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
}//End interrupt vector



