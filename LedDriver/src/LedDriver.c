#include "LedDriver.h"

static uint16_t *ledsAddress;

enum {
	ALL_LEDS_ON = ~0,
	ALL_LEDS_OFF = ~ALL_LEDS_ON
};

void LedDriver_Create(uint16_t *address)
{
	ledsAddress = address;
	*address = ALL_LEDS_OFF;
}

static uint16_t convertLedNumberToBit(int ledNumber)
{
	return 1 << (ledNumber - 1);
}

void LedDriver_TurnOn(int ledNumber)
{
	*ledsAddress |= convertLedNumberToBit(ledNumber);
}

void LedDriver_TurnOff(int ledNumber)
{
	*ledsAddress = 0;
}

void LedDriver_TurnAllOn(void)
{
	*ledsAddress = ALL_LEDS_ON;
}

