#include <CUnit/Basic.h>
#include "myfunc.h"

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
