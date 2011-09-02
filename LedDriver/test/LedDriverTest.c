#include "PCUnit/PCUnit.h"
#include "LedDriver.h"

static uint16_t virtualLeds;

static int setup(void)
{
	LedDriver_Create(&virtualLeds);
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
	LedDriver_TurnOn(1);
	PCU_ASSERT_EQUAL((uint16_t) 1, virtualLeds);
}

static void test_TurnOffLedOne(void)
{
	LedDriver_TurnOn(1);
	LedDriver_TurnOff(1);
	PCU_ASSERT_EQUAL((uint16_t) 0, virtualLeds);
}

static void test_TurnOnMultipleLeds(void)
{
	LedDriver_TurnOn(9);
	LedDriver_TurnOn(8);
	PCU_ASSERT_EQUAL((uint16_t) 0x180, virtualLeds);
}

static void test_TurnOffAnyLed(void)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnOff(8);
	PCU_ASSERT_EQUAL((uint16_t) 0xff7f, virtualLeds);
}

static void test_AllOn(void)
{
	LedDriver_TurnAllOn();
	PCU_ASSERT_EQUAL((uint16_t) 0xffff, virtualLeds);
}

static void test_LedMemoryIsNotReadable(void)
{
	virtualLeds = 0xffff;
	LedDriver_TurnOn(8);
	PCU_ASSERT_EQUAL((uint16_t) 0x80, virtualLeds);
}


PCU_Suite *LedDriverTest_suite(void)
{
	static PCU_Test tests[] = {
		PCU_TEST(test_LedsOffAfterCreate),
		PCU_TEST(test_TurnOnLedOne),
		PCU_TEST(test_TurnOffLedOne),
		PCU_TEST(test_TurnOnMultipleLeds),
		PCU_TEST(test_TurnOffAnyLed),
		PCU_TEST(test_AllOn),
		PCU_TEST(test_LedMemoryIsNotReadable),
	};
	static PCU_Suite suite = { "LedDriverTest", tests, sizeof tests / sizeof tests[0], setup, teardown };
	return &suite;
}
