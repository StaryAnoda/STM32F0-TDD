#include "output.h"

#include "../../../src/hw/uart/uart.h"

void output_init(void)
{
    USART1_GPIO_Config();
    USART1_Config();
}

int output_send(int c)
{
     USART1_Send_Char((char)c);
}

void output_flush(void)
{

}

void output_close(void)
{

}