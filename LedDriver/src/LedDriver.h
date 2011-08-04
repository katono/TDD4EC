#ifndef LED_DRIVER_H_INCLUDED
#define LED_DRIVER_H_INCLUDED

#include <stdint.h>

void LedDriver_Create(uint16_t *address);
void LedDriver_TurnOn(int ledNumber);


#endif /* LED_DRIVER_H_INCLUDED */
