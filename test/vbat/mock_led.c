#include "mock_led.h"
#include "led.h"

static enum led_state led = LED_STATE_UNKNOWN;

void led_off(void)
{
    led = LED_OFF;
}

void led_on(void)
{
    led = LED_ON;
}

void mock_led_init(void)
{
    led = LED_STATE_UNKNOWN;
}

enum led_state mock_led_state_get(void)
{
    return led;
}
