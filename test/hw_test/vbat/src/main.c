#include "unity/fixture/unity_fixture.h"

static void run_all_tests(void);

int main(void)
{
    int argc = 0;
    const char **argv = NULL;

    UnityMain(argc, argv, run_all_tests);

    while(1);

    return 0;
}

static void run_all_tests(void)
{
   RUN_TEST_GROUP(vbat);
}
