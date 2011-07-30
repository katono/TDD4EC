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


PCU_Suite *LedDriverTest_suite(void)
{
	static PCU_Test tests[] = {
		{ "test_LedsOffAfterCreate", test_LedsOffAfterCreate },
	};
	static PCU_Suite suite = { "LedDriverTest", tests, sizeof tests / sizeof tests[0], setup, teardown };
	return &suite;
}
