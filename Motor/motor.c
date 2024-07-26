#define F_CPU 8000000UL
#include<util/delay.h>
#include<avr/io.h>
void main()
{
	DDRB=0XFF;
	DDRA=0X00;
	while(1)
	{
		
		if((PINA&0X01)==0)
		{
			PORTB=0X1D;
			_delay_ms(1000);
		}
		if((PINA&0X02)==0)
		{
			PORTB=0X2E;
			_delay_ms(1000);
		}
	}
}
