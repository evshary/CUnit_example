#include <stdio.h>
#include <CUnit/Basic.h>
#include "myfunc.h"

void testNormal(void)
{
    CU_ASSERT_TRUE(myfunc(1) == 1);
    CU_ASSERT_TRUE(myfunc(100) == 10000);
}

CU_TestInfo testcases1[] = {
    {"Normal", testNormal},
    CU_TEST_INFO_NULL
};

void testTooLarge(void)
{
    CU_ASSERT_TRUE(myfunc(10000) == -1);
    CU_ASSERT_TRUE(myfunc(101) == -1);
}

void testNegative(void)
{
    CU_ASSERT_TRUE(myfunc(-1) == -1);
    CU_ASSERT_TRUE(myfunc(-100) == -1);
}

void testZero(void)
{
    CU_ASSERT_TRUE(myfunc(0) == -1);
}

CU_TestInfo testcases2[] = {
    {"Too large number", testTooLarge},
    {"Negative number", testNegative},
    {"Zero", testZero},
    CU_TEST_INFO_NULL
};

int suite_init(void) { return 0; }
int suite_clean(void) { return 0; }
int suite_setup(void) { return 0; }
int suite_teardown(void) { return 0; }

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
