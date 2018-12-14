/*
 * MQTT.c
 *
 *  Created on: Dec 14, 2018
 *      Author: Tyler
 */

#include "MQTT.h"

/*
	  Commands:
  $Subscribe        SYNTAX: "$Topic\n"
  #Publish          SYNTAX: "#Topic Payload\n"
  !ReceivedMessage  SYNTAX: "!Topic: Message\n"
  ~Unsubscribe      SYNTAX: "~Topic\n"
  */
  
	char PublishBuzzer(unsigned char value){
		char Buzzer [12] = {'#','S','e','c','u','r','i','t','y','B','x','\n'}
		int count = 0;
		Buzzer [10] = value;
		while (!(IFG2&UCA0TXIFG) && count <= 11){	                // USCI_A0 TX buffer ready?
		UCA0TXBUF = Buzzer[count];
		count++;
		}
  }

	
	char PublishMotion(unsigned char value){
		char Motion [11] = {'#','S','e','c','u','r','i','t','y','M','x','\n'}
		int count = 0;
		Motion [10] = value;
		while (!(IFG2&UCA0TXIFG) && count <= 11){	                // USCI_A0 TX buffer ready?
		UCA0TXBUF = Motion[count];
		count++;
		}
	}
	
	char PublishSound(unsigned char value){
		char Sound [11] = {'#','S','e','c','u','r','i','t','y','S','x','\n'}
		int count = 0;
		Sound [10] = value;
		while (!(IFG2&UCA0TXIFG) && count <= 11){	                // USCI_A0 TX buffer ready?
		UCA0TXBUF = Sound[count];
		count++;
		}
	}

	void ReceivedMessage(){
		
	}
	
	void Unsubscribe(){
		
	}
