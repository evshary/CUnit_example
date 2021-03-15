#include <stdio.h>
#include <CUnit/Basic.h>

extern CU_TestInfo testcases1[];
extern CU_TestInfo testcases2[];

int suite_init(void) { return 0; }
int suite_clean(void) { return 0; }
void suite_setup(void) { return; }
void suite_teardown(void) { return; }

CU_SuiteInfo suites[] = {
    {"MyTestSuite1", suite_init, suite_clean, suite_setup, suite_teardown, testcases1},
    {"MyTestSuite2", suite_init, suite_clean, suite_setup, suite_teardown, testcases2},
    CU_SUITE_INFO_NULL
};

int main(void)
{
    /* Test Registry */
    CU_initialize_registry();

    /* Register Suite */
    if (CUE_SUCCESS != CU_register_suites(suites)) {
        printf("Unable to register suites.\n");
        return -1;
    }

    /* Run basic test */
    CU_basic_run_tests();

    /* Clean Registry */
    CU_cleanup_registry();

    return 0;
}
