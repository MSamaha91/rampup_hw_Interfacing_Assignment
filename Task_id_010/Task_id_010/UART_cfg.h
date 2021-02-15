
#ifndef UART_CFG_H_
#define UART_CFG_H_
#include "micro_config.h"
#include "Det.h"

#define UART_BUAD_RATE 9600       /* UART baud_rate configuration */
#define NORMAL_MODE 1        /* UART normal speed mode */
#define DOUBLE_SPEED_MODE 2  /* UART double speed mode */

/* configure UART operation speed mode */
#define OPERATION_MODE DOUBLE_SPEED_MODE

#ifndef UART_BUAD_RATE
#error UART_BUAD_RATE is not defined
#elif ((UART_BUAD_RATE <= 0) || (UART_BUAD_RATE > 2500000))
#error UART_BUAD_RATE is out of range it must be 0 < UART_BUAD_RATE <= 2500000
#endif

void UART_Init(void);
void UART_ReceiveByte(void);

extern uint8 UART_ReceivedByte;

#endif /* UART_CFG_H_ */