/*
 * MQTT.h
 *
 *  Created on: Dec 14, 2018
 *      Author: Tyler
 */

#ifndef MQTT_H_
#define MQTT_H_

void PublishBuzzer(unsigned char value);
void PublishMotion(unsigned char value);
void PublishSound(unsigned char value);
void ReceivedMessage();
void Unsubscribe(char topic);



#endif /* MQTT_H_ */
