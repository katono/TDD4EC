#include <PCUnit/PCUnit.h>

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
	PCU_FAIL("Start here");
}


PCU_Suite *LedDriverTest_suite(void)
{
	static PCU_Test tests[] = {
		{ "test_LedsOffAfterCreate", test_LedsOffAfterCreate },
	};
	static PCU_Suite suite = { "LedDriverTest", tests, sizeof tests / sizeof tests[0], setup, teardown };
	return &suite;
}
