/*
 * MQTT.h
 *
 *  Created on: Dec 14, 2018
 *      Author: Tyler
 */

#ifndef MQTT_H_
#define MQTT_H_

char PublishBuzzer(unsigned int value);
char PublishMotion(unsigned int value);
char PublishSound(unsigned int value);
void ReceivedMessage();
void Unsubscribe();



#endif /* MQTT_H_ */
