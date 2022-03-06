/*
 * After init led is off.
 * VBat reads value from ADC in every vbat check iteration.
 * If value is below threshold for 5 consecutive readings - led is turned on.
 * If value is above threshold again then - led is still on.
 */ 

#define VBAT_THRESHOLD_RAW  2850
#define VBAT_CNT_TO_ALARM   5

void vbat_init(void);
void vbat_check(void);