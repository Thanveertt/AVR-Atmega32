#define F_CPU 8000000UL
#include<util/delay.h>
#include<avr/io.h>
int main()
{
	DDRA=0XFF;
	DDRB=0XFF;
	while(1)
	{
		int i;
		for(i=0;i<9;i++)
		{
			PORTA=0X01<<i;
			_delay_ms(100);
		}
		for(i=0;i<9;i++)
		{
			PORTB=0X01<<i;
			_delay_ms(100);
		}
		for(i=0;i<9;i++)
		{
			PORTB=0X80>>i;
			_delay_ms(100);
		}
		for(i=0;i<9;i++)
		{
			PORTA=0X80>>i;
			_delay_ms(100);
		}
	}
}