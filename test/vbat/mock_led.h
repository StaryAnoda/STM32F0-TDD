enum led_state
{
    LED_STATE_UNKNOWN = -1,
    LED_OFF = 0,
    LED_ON = 1,
};

void mock_led_init(void);
enum led_state mock_led_state_get(void);