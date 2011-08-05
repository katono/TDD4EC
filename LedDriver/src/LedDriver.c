#include "LedDriver.h"

static uint16_t *ledsAddress;

void LedDriver_Create(uint16_t *address)
{
	ledsAddress = address;
	*address = 0;
}

void LedDriver_TurnOn(int ledNumber)
{
	*ledsAddress = 1;
}

void LedDriver_TurnOff(int ledNumber)
{
}

