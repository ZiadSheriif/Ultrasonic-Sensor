/*
 * ultrasonic.h
 *
 *  Created on: Oct 15, 2022
 *      Author: Ziad
 */

#ifndef SRC_ULTRASONIC_H_
#define SRC_ULTRASONIC_H_

#include "std_types.h"
#include"icu.h"
#include"gpio.h"

void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);

#endif /* SRC_ULTRASONIC_H_ */
