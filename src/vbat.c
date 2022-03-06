#include "vbat.h"

#include "led.h"
#include "adc.h"

#include <stdint.h>
#include <stdbool.h>

static int32_t below_cnt = 0;

void vbat_init(void)
{
    led_off();

    below_cnt = 0;
}

void vbat_check(void)
{
    adc_raw_t reading = adc_read();

    if (reading < VBAT_THRESHOLD_RAW)
    {
        below_cnt++;

        if (below_cnt >= VBAT_CNT_TO_ALARM)
        {
            led_on();
        }
    }
    else
    {
        below_cnt = 0;
    }
}