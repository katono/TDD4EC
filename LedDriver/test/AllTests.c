#include <PCUnit/PCUnit.h>


PCU_Suite *LedDriverTest_suite(void);

int main(void)
{
	const PCU_SuiteMethod suites[] = {
		LedDriverTest_suite,
	};
	PCU_run(suites, sizeof suites / sizeof suites[0]);
	return 0;
}
