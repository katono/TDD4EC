#include <PCUnit/PCUnit.h>
#include "LedDriver.h"

static int setup(void)
{
	return 0;
}

static int teardown(void)
{
	return 0;
}


static void test_LedsOffAfterCreate(void)
{
	uint16_t virtualLeds = 0xffff;
	LedDriver_Create(&virtualLeds);
	PCU_ASSERT_EQUAL((uint16_t) 0, virtualLeds);
}

static void test_TurnOnLedOne(void)
{
	uint16_t virtualLeds;
	LedDriver_Create(&virtualLeds);
	LedDriver_TurnOn(1);
	PCU_ASSERT_EQUAL((uint16_t) 1, virtualLeds);
}

static void test_TurnOffLedOne(void)
{
	uint16_t virtualLeds;
	LedDriver_Create(&virtualLeds);
	LedDriver_TurnOn(1);
	LedDriver_TurnOff(1);
	PCU_ASSERT_EQUAL((uint16_t) 0, virtualLeds);
}


PCU_Suite *LedDriverTest_suite(void)
{
	static PCU_Test tests[] = {
		{ "test_LedsOffAfterCreate", test_LedsOffAfterCreate },
		{ "test_TurnOnLedOne", test_TurnOnLedOne },
		{ "test_TurnOffLedOne", test_TurnOffLedOne },
	};
	static PCU_Suite suite = { "LedDriverTest", tests, sizeof tests / sizeof tests[0], setup, teardown };
	return &suite;
}
