/*
 * ultrasonic.c
 *
 *  Created on: Oct 15, 2022
 *      Author: Ziad
 */
#include "ultrasonic.h"
#include <util/delay.h>

uint16 highEdgeTime = 0; // timer for high edge of echo signal
uint8 edgeCount = 0;     // counter to count calling call back function

/*
 * Initialization funciton of Ultrasonic sensor
 */
void Ultrasonic_init(void)
{
    Icu_ConfigType configType;
    configType.edge = RISING;
    configType.clock = F_CPU_8;
    Icu_init(&configType);
    Icu_setCallBack(Ultrasonic_edgeProcessing);
    GPIO_setupPinDirection(PORTB_ID, PIN5_ID, PIN_OUTPUT);
}
void Ultrasonic_Trigger(void)
{
    GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_HIGH);
    _delay_us(10);
    GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_LOW);
}
uint16 Ultrasonic_readDistance(void)
{
    
   
     Ultrasonic_Trigger(); /* Calling trigger function*/

    /*17000 x (TIMER value) x 1 x 10^-6 cm
     = 0.017 x (TIMER value) cm
    = (TIMER value) / 58.8 cm
    */
   return ((uint16)((float)highEdgeTime)/(58.8));
}
void Ultrasonic_edgeProcessing(void)
{
    edgeCount++;
    if(edgeCount==1){
        Icu_clearTimerValue(); // clear timer register
        Icu_setEdgeDetectionType(FALLING); // measuring time till falling edge
    }
    else if(edgeCount==2){
        highEdgeTime=Icu_getInputCaptureValue();
        Icu_clearTimerValue();
        Icu_setEdgeDetectionType(RISING);
        edgeCount=0;
    }
}
