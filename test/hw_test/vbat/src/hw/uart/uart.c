#include "uart.h"
#include "stm32f030x6.h"

#define UART_BAUDRATE 115200

void USART1_GPIO_Config(void)
{
	RCC -> AHBENR |= RCC_AHBENR_GPIOAEN;

	GPIOA -> MODER |= GPIO_MODER_MODER9_1 | GPIO_MODER_MODER10_1;
	GPIOA -> AFR[1] |= (1 << (1 * 4)) | (1 << (2 * 4));
}

void USART1_Config(void)
{
	RCC -> APB2ENR |= RCC_APB2ENR_USART1EN;

	USART1 -> BRR = SystemCoreClock / UART_BAUDRATE;
	USART1 -> CR1 = USART_CR1_TE | USART_CR1_UE;
}

void USART1_Send_Char(const char c)
{
	USART1 -> TDR = c;
	while(!(USART1 -> ISR & USART_ISR_TC));
}

void USART1_Send_String(const char * string)
{
	while(*string)
	{
		USART1_Send_Char(*string++);
	}
}