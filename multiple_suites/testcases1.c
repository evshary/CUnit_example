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
