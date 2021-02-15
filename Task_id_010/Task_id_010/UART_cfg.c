#include "UART_cfg.h"

#if OPERATION_MODE == NORMAL_MODE
#define BAUD_PRESCALE (((F_CPU / (UART_BUAD_RATE * 16UL))) - 1)
#elif OPERATION_MODE == DOUBLE_SPEED_MODE
#define BAUD_PRESCALE (((F_CPU / (UART_BUAD_RATE * 8UL))) - 1)
#else
#error UART operating speed mode is not configured
#endif

#define UART_notInitialized 0
#define UART_Initialized    1
#define NO_NEW_BYTE 0
#define NEW_BYTE_READY 1

/* variable for holding received byte */
uint8 UART_ReceivedByte;


/* flag to check if the UART module is initialized or not */
static uint8 UART_isInit = UART_notInitialized;

void UART_Init(void)
{
	/* config. UART operating speed mode */
	#if OPERATION_MODE == DOUBLE_SPEED_MODE
	SET_BIT(UCSRA, U2X);
	#endif
	/* enable Transmitting and Receiving data through UART */
	UCSRB |= (1<<RXEN) | (1<<TXEN);
	/* setting 8-bit data mode */
	UCSRC |= (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
	/* config. baud_rate */
	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH = BAUD_PRESCALE>>8;
	UBRRL = BAUD_PRESCALE;
	UART_ReceivedByte = 0;
	UART_isInit = UART_Initialized;
}

void UART_ReceiveByte(void)
{
	if (UART_isInit != UART_Initialized)
	{
		Det_ReportError();
	}
	else
	{
		while (!GET_BIT(UCSRA, RXC));
		UART_ReceivedByte = UDR;	
	}
}