#include "app/output/output.h"

#define UNITY_OUTPUT_CHAR(a)    output_send(a)
#define UNITY_OUTPUT_START()    output_init()
#define UNITY_OUTPUT_FLUSH()    output_flush()
#define UNITY_OUTPUT_COMPLETE() output_close()