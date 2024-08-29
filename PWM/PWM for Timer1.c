#define F_CPU 8000000UL
#include<avr/io.h>
void main()
{
	DDRD=0XFF;
	TCCR1A=0X23;
	TCCR1B=0X1D;
	//70%
	OCR1AH=0X1E;
	OCR1AL=0X83;
	OCR1BH=0X15;
	OCR1BL=0X5B;
	while(1);
}
