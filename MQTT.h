/*
 * MQTT.h
 *
 *  Created on: Dec 14, 2018
 *      Author: Tyler
 */

#ifndef MQTT_H_
#define MQTT_H_

char PublishBuzzer(unsigned char value);
char PublishMotion(unsigned char value);
char PublishSound(unsigned char value);
void ReceivedMessage();
void Unsubscribe(char topic);



#endif /* MQTT_H_ */
