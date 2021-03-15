#include <CUnit/CUnit.h>
/* Used by CU_console_run_tests */
//#include <CUnit/Console.h>
/* Used by CU_automated_run_tests */
//#include <CUnit/Automated.h>
/* Used by CU_basic_run_tests */
#include <CUnit/Basic.h>

static int TestInit(void) { return 0; }
static int TestClean(void) { return 0; }

void testAssertTrue(void)
{
    // Pass
    CU_ASSERT_TRUE(CU_TRUE);
    // Pass
    CU_ASSERT_TRUE(!CU_FALSE);
    // Pass
    CU_ASSERT_EQUAL(strlen("abc"), 3);
    // Fail
    CU_ASSERT_TRUE(3 > 5);
}

/*
 * Level relationship: Test Registry -> Suite -> Test
 */
int main(void)
{
    CU_pSuite pSuite;

    /* Test Registry */
    CU_initialize_registry();
    /* Suite */
    pSuite = CU_add_suite("MyTestSuite", TestInit, TestClean);
    /* Test */
    CU_add_test(pSuite, "testAssertTrue", testAssertTrue);

    /* Run test with interactive console */
    //CU_console_run_tests();
    /* Run test and generate XML automatically */
    //CU_automated_run_tests();
    /* Run basic test */
    CU_basic_run_tests();

    CU_cleanup_registry();

    return 0;
}
