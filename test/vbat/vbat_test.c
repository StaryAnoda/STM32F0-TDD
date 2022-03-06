#include "unity/fixture/unity_fixture.h"

#include "mock_led.h"
#include "mock_adc.h"

#include "vbat.h"

TEST_GROUP(vbat);

void below_threshold(void)
{
    mock_adc_val_set(VBAT_THRESHOLD_RAW - 1);
}

void above_threshold(void)
{
    mock_adc_val_set(VBAT_THRESHOLD_RAW);
}

void check_vbat_n_times(int n)
{
    for (int i = 0; i < n; i++)
    {
        vbat_check();
    }
}

TEST_SETUP(vbat)
{
    /* Init before every test */
    mock_led_init();
    mock_adc_init();

    vbat_init();
}

TEST_TEAR_DOWN(vbat)
{
    /* Cleanup after every test */
}

TEST(vbat, LedOffAfterInit)
{
    vbat_init();

    TEST_ASSERT_EQUAL(LED_OFF, mock_led_state_get());
}

TEST(vbat, LedOffAfterAdcBelowThreshold4TimesInARow)
{
    below_threshold();
    check_vbat_n_times(VBAT_CNT_TO_ALARM - 1);
    
    TEST_ASSERT_EQUAL(LED_OFF, mock_led_state_get());
}

TEST(vbat, LedOnAfterAdcBelowThreshold5TimesInARow)
{
    below_threshold();
    check_vbat_n_times(VBAT_CNT_TO_ALARM);
    
    TEST_ASSERT_EQUAL(LED_ON, mock_led_state_get());
}


TEST(vbat, LedOffAfterAdcAboveThreshold5TimesInARow)
{
    above_threshold();
    check_vbat_n_times(VBAT_CNT_TO_ALARM);
    
    TEST_ASSERT_EQUAL(LED_OFF, mock_led_state_get());
}

TEST(vbat, LedOffAfterAdcBelowThreshold5TimesNotInARow)
{
    below_threshold();
    check_vbat_n_times(VBAT_CNT_TO_ALARM - 1);

    above_threshold();
    vbat_check();

    below_threshold();
    vbat_check();
    
    TEST_ASSERT_EQUAL(LED_OFF, mock_led_state_get());
}

TEST(vbat, LedOffAfterAdcBelowThreshold4TimesThenAboveThen4TimesBelow)
{
    below_threshold();
    check_vbat_n_times(VBAT_CNT_TO_ALARM - 1);

    above_threshold();
    vbat_check();

    below_threshold();
    check_vbat_n_times(VBAT_CNT_TO_ALARM - 1);
    
    TEST_ASSERT_EQUAL(LED_OFF, mock_led_state_get());
}

TEST(vbat, LedOnAfterAdcBelowThreshold4TimesThenAboveThen5TimesBelow)
{
    below_threshold();
    check_vbat_n_times(VBAT_CNT_TO_ALARM - 1);

    above_threshold();
    vbat_check();

    below_threshold();
    check_vbat_n_times(VBAT_CNT_TO_ALARM);
    
    TEST_ASSERT_EQUAL(LED_ON, mock_led_state_get());
}

TEST(vbat, LedOnWhen5TimesBelowThenAbove)
{
    below_threshold();
    check_vbat_n_times(VBAT_CNT_TO_ALARM);

    above_threshold();
    vbat_check();
    
    TEST_ASSERT_EQUAL(LED_ON, mock_led_state_get());
}
