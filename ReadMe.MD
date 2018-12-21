# Security System
### Final Project for Introduction to Embedded Systems
### Team Members: Tyler McLemore, Helen Pan

## Description
The Security System project is a simple implication of  a home security system, where the device have the capabilities of sensing motions, sounds, and send an alert to the owner through an app on their phone. By utilizing a sounds sensor and infrared motion sensor, the Mixed Signal Processor (MSP) is able to take in the signals from the sensors and analyze this data to understand its surroundings. The data the MSP takes in is processed and used to determine whether or not the device should trip the alarm and signal the user.

## Circuit Diagram
<img src="https://github.com/RU09342-F18/intro-to-embedded-final-project-nano-tech-1/blob/master/Documents/block%20diagram.png" height="400" width="550">

## Wireless Communication with MQTT DASH
Users can download a free app named, "MQTT DASH", for their phone in order to receive  alerts regarding intruder(s) is detected.

## Software
### main.c
The "main.c" file is required for the MSP430 micro-controller. By utilizing Code Composer Studio, the "main.c" file is complied to the micro-controller, which will than process all the inputs and outs of each sensors: PIR Motion Sensor and the Microphone Sound Sensor. 

Before heading in, some important libraries are required in order to run the code:
~~~~
#include <msp430.h>
#include <Setup.h>
~~~~

The code is divided into several functions:
~~~~
void UARTSetup();
void TimerSetup(); 
void BoardSetup();
void LEDSetup();
void ADC_Setup();
void MQTTSetup();
void SoundSensor();
void Polling();
~~~~

The UARTSetup() function is the setup for the serial UART communication that sends data to the ESP8266 chip, which sends the alert to the user's phone. 'TimerSetup()' is setting up two timers: one for the flashing of the red LED on the MSP430 and the frequency of the buzzer, and one is used to poll the sound every 1000ms. 'BoardSetup()' is setting up the inputs and outputs of the different pins that will be used. 'LEDSetup()' is pretty much self explanatory as it is setting up the outputs for the LEDs. 'ADC_Setup()' is set up for continuous conversion of the analog inputs from the sound sensor. 'MQTTSetup()' is setting up the wireless communication to send alerts to the user when the device detects auditory and visual cues. The 'SoundSensor()' function turns the buzzer alarm on when sound is detected from the sensor. The 'Polling()' function is for polling the sound sensor to check for noise. 

One interrupt vector is used for the motion sensor for when the sensor detects motion and sends signal to toggle the LED. In the event of when both or either the motion sensor and the sound sensor detects changes, the buzzer alarm will set on, the flashing of the red LED will be enable, and a message will be sent through the ESP to the user. 

### ESP8266_Code.c
The ESP8266 file is an arduino file authored by Russell Trafford, which is complied to the ESP Wifi Module. The file enables the ESP to communicate over the Rowan_IoT network.

## Circuit Design
### MSP-EXP430G2553 Micro-controller
The MSP430 micro-controller is crucial as it is the main processing unit for the Security System. It uses the high signals received from the PIR motion sensor and the analog signal from the Microphone Sound sensor to set off the buzzer and the LED in real time.

### Passive Infrared (PIR) Motion Sensor


### KY-037 Microphone Sensor Module (High Sensitivity)


### Electromagnetic Active Buzzer PB-1226PEAQ
In the event of motion and or sound detected around the Security System device, the MSP430 will send a PWM signal to the buzzer to create a frequency of an alarm. The power source pin of the buzzer is connected to the P2.5 pin on the MSP in order to control the frequency and the GND pin is connected to the GND pin on the MSP as well.

## Components List
- 1 MSP-EXP430G2553 Micro-controller
- 1 Passive Infrared (PIR) Motion Sensor
- 1 KY-037 Microphone Sensor Module (High Sensitivity)
- 1 Electromagnetic Active Buzzer PB-1226PEAQ
- 1 ESP-01 Serial Wifi Module (ESP8266 Module)
- 1 Green LED
- 1 Solderless Breadboard