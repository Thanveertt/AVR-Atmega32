#define F_CPU 8000000UL
#include<avr/io.h>
void trans(char a);
void main()
{
	
	DDRD=0X02;
	UCSRA=0X00;
	UCSRB=0X08;
	UCSRC=0X86;
	UBRRL=51;
		trans('b');
		while(1);
	
}
	void trans(char a)
	{
		UDR=a;
		while((UCSRA&0x40)==0);
		UCSRA=0x40;
	}
	
