#define F_CPU 8000000UL
#include<avr/io.h>
char rec();
int main(void)
{
	char c;
	DDRB=0xFF;
	DDRD=0X02;
	UCSRA=0X00;
	UCSRB=0X10;
	UCSRC=0X86;
	UBRRL=51;
	while(1)
	{
	c=rec();
	if(c=='a')
	{
		PORTB=0x0F;
	}
	else if(c=='b')
	{
		PORTB=0XF0;
	}
	}
}
char rec()
{
	while((UCSRA&0x80)==0);
	return(UDR);
}
