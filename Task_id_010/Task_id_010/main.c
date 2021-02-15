
#include "micro_config.h"
#include "UART_cfg.h"



int main(void)
{
	uint8 data = 0;
	UART_Init();
    while (1) 
    {
		UART_ReceiveByte();
		data = UART_ReceivedByte;
		
    }
}


