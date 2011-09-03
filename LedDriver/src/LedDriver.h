#ifndef LED_DRIVER_H_INCLUDED
#define LED_DRIVER_H_INCLUDED

#include <stdint.h>

void LedDriver_Create(uint16_t *address);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_TurnAllOn(void);
int LedDriver_IsOn(int ledNumber);


#endif /* LED_DRIVER_H_INCLUDED */
