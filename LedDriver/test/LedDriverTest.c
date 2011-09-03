#include "PCUnit/PCUnit.h"
#include "LedDriver.h"
#include "RuntimeError.h"
#include "mocks/RuntimeErrorStub.h"

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

static void test_UpperAndLowerBounds(void)
{
	LedDriver_TurnOn(1);
	LedDriver_TurnOn(16);
	PCU_ASSERT_EQUAL((uint16_t) 0x8001, virtualLeds);
}

static void test_OutOfBoundsTurnOnDoesNoHarm(void)
{
	LedDriver_TurnOn(-1);
	LedDriver_TurnOn(0);
	LedDriver_TurnOn(17);
	LedDriver_TurnOn(3141);
	PCU_ASSERT_EQUAL((uint16_t) 0, virtualLeds);
}

static void test_OutOfBoundsTurnOffDoesNoHarm(void)
{
	LedDriver_TurnAllOn();

	LedDriver_TurnOff(-1);
	LedDriver_TurnOff(0);
	LedDriver_TurnOff(17);
	LedDriver_TurnOff(3141);
	PCU_ASSERT_EQUAL((uint16_t) 0xffff, virtualLeds);
}

static void test_OutOfBoundsProducesRuntimeError(void)
{
	LedDriver_TurnOn(-1);
	PCU_ASSERT_STRING_EQUAL("LED Driver: out-of-bounds LED",
			RuntimeErrorStub_GetLastError());
	PCU_ASSERT_EQUAL(-1, RuntimeErrorStub_GetLastParameter());
}

static void test_OutOfBoundsToDo(void)
{
	/* TODO */
}

static void test_IsOn(void)
{
	PCU_ASSERT_FALSE(LedDriver_IsOn(11));
	LedDriver_TurnOn(11);
	PCU_ASSERT_TRUE(LedDriver_IsOn(11));
}

static void test_OutOfBoundsLedsAreAlwaysOff(void)
{
	PCU_ASSERT_FALSE(LedDriver_IsOn(0));
	PCU_ASSERT_FALSE(LedDriver_IsOn(17));
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
		PCU_TEST(test_UpperAndLowerBounds),
		PCU_TEST(test_OutOfBoundsTurnOnDoesNoHarm),
		PCU_TEST(test_OutOfBoundsTurnOffDoesNoHarm),
		PCU_TEST(test_OutOfBoundsProducesRuntimeError),
		PCU_TEST_SKIPPED(test_OutOfBoundsToDo),
		PCU_TEST(test_IsOn),
		PCU_TEST(test_OutOfBoundsLedsAreAlwaysOff),
	};
	static PCU_Suite suite = { "LedDriverTest", tests, sizeof tests / sizeof tests[0], setup, teardown };
	return &suite;
}
