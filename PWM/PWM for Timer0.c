#define F_CPU 8000000UL
#include<avr/io.h>
void main()
{
	DDRB=0XFF;
	TCCR0=0X6D;
	OCR0=229;
	while(1);
}
