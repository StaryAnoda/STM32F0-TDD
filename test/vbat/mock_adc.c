#include "mock_adc.h"

static adc_raw_t adc_val = 0xFFFF;

adc_raw_t adc_read(void)
{
    return adc_val;
}

void mock_adc_init(void)
{
    adc_val = 0xFFFF;
}

void mock_adc_val_set(adc_raw_t val)
{
    adc_val = val;
}
