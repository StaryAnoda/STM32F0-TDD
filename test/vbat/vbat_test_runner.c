#include "unity/fixture/unity_fixture.h"

TEST_GROUP_RUNNER(vbat)
{
   /* Test cases to run */
   RUN_TEST_CASE(vbat, LedOffAfterInit);
   RUN_TEST_CASE(vbat, LedOffAfterAdcBelowThreshold4TimesInARow);
   RUN_TEST_CASE(vbat, LedOnAfterAdcBelowThreshold5TimesInARow);
   RUN_TEST_CASE(vbat, LedOffAfterAdcAboveThreshold5TimesInARow);
   RUN_TEST_CASE(vbat, LedOffAfterAdcBelowThreshold5TimesNotInARow);
   RUN_TEST_CASE(vbat, LedOffAfterAdcBelowThreshold4TimesThenAboveThen4TimesBelow);
   RUN_TEST_CASE(vbat, LedOnAfterAdcBelowThreshold4TimesThenAboveThen5TimesBelow);
   RUN_TEST_CASE(vbat, LedOnWhen5TimesBelowThenAbove);
}
