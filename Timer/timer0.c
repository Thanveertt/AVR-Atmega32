#define F_CPU 8000000UL
#include<avr/io.h>
void timer();
int i;
int main(void)
{
	
DDRC=0XFF;
while(1)
{
PORTC=0XFF;
timer();
PORTC=0X00;
timer();
}

}
void timer()
{
	for(i=0;i<100;i++)
	{
	TCCR0=0X05;
	TCNT0=0XB2;
	while((TIFR&0X01)==0);
	TIFR=0x01;
	}
	
}
