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
  
	char PublishBuzzer(){
		unsigned int count = 0;
		//char Publish[10]={'$','S','e','c','u','r','i','t','y','\0'};
		while (!(IFG2&UCA0TXIFG) && count <= 8){	                // USCI_A0 TX buffer ready?
		UCA0TXBUF = Publish[count];
		count++;
  }
  count = 0;
	}
	
	char PublishMotion(){
		
	}
	
	char PublishSound(){
		
	}

	void ReceivedMessage(){
		
	}
	
	void Unsubscribe(){
		
	}
