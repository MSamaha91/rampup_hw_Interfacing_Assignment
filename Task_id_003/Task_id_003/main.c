
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Std_macros.h"
#include "Std_types.h"

void setupTimer1_ctc(void);

volatile uint8 t_flag = 0;

ISR(TIMER1_COMPA_vect)
{
	t_flag = 1;
}

int main(void)
{
    /* Initialize IO pins */
	ASSIGN_REG_VALUE(DDRB, 7);  /* PortB as output */
	ASSIGN_REG_VALUE(PORTB, 0); /* PortB output 0 */
	
	/* Initialize Timer1 and start the timer */
	setupTimer1_ctc();
	
    while (1) 
    {
		if (t_flag == 1)
		{
			TOGGLE_BIT(PORTB, PB0);
			TOGGLE_BIT(PORTB, PB1);
			TOGGLE_BIT(PORTB, PB2);
			t_flag = 0;	
		}
    }
}

void setupTimer1_ctc(void)
{
	/* disable global interrupt */
	cli();
	/* reset Timer1 register TCNT1 value to 0 */
	TCNT1 = 0;
	/* set OCR1A value to 15625 to let the timer trigger the interrupt every 1 second */
	OCR1A = 15625;           
	/* set output compare a match interrupt enable (OCIE1A) to enable interrupt when compare match happen */
	TIMSK |= (1<<OCIE1A);
	/* enable global interrupt */
	sei();
	/* configure timer1 to CTC mode with prescaler clk/64 */ 
	TCCR1A = (1<<FOC1A);
	TCCR1B = (1<<WGM12) | (1<<CS10) | (1<<CS11); 
	
}

