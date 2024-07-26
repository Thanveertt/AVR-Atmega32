#define F_CPU 8000000UL
#include<util/delay.h>
#include<avr/io.h>
int main()
{
	DDRA=0X00;
	DDRB=0XFF;
	while(1)
	{
		if((PINA&0X01)==0)
		{
			PORTB=0XFF;
			_delay_ms(1000);
			PORTB=0X00;
			_delay_ms(1000);
		}
		if((PINA&2)==0)
		{
			int b;
			for(b=0;b<9;b++)
			{
				PORTB=0X80>>b;
				_delay_ms(100);
			}
		}
		if((PINA&4)==0)
		{
			int m;
			for(m=0;m<9;m++)
			{
				PORTB=0X01<<m;
				_delay_ms(100);
			}
		}
		
	}
}
