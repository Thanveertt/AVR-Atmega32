#define F_CPU 8000000UL
#include<avr/io.h>
void timer1();
int i;
void main()
{
	
	DDRD=0XFF;
	while(1)
	{
		PORTD=0XFF;
		timer1();
		PORTD=0X00;
		timer1();
	}

}
void timer1()
{
	for(i=0;i<100;i++)
	{
		TCCR1B=0X05;
		TCNT1H=0XFF;
		TCNT1L=0XB2;
		while((TIFR&0X04)==0);
		TIFR=4;
	}
	
}
