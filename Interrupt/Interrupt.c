#define F_CPU 8000000UL
#include<util/delay.h>
#include<avr/interrupt.h>
#include<avr/io.h>
void main()
{
	
	DDRD=0X00;
	DDRC=0XFF;
	PORTC=0XFF;
	DDRA=0XFF;
	PORTA=0X00;
	GICR=1<<INT0;
	MCUCR|=1<<ISC01|1<<ISC00;
	GICR|=1<<7;//1<<7  1000 0000 
	MCUCR|=1<<ISC11|1<<ISC10;
	GICR|=1<<INT2;
	MCUCSR=0x00;
	sei();
	while(1);
	

}
ISR(INT0_vect)
{
	PORTC=~PORTC;
	_delay_ms(100);
}
ISR(INT1_vect)
{
	PORTA=0X0F;
	_delay_ms(1000);
}
ISR(INT2_vect)
{
	PORTA=0XF0;
	_delay_ms(1000);
}

