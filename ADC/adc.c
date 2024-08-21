#define F_CPU 8000000UL
#include<util/delay.h>
#include<avr/io.h>
void cmd(char a);
void data(char b);
int main(void)
{
	int i,a;
	int b[10];
	DDRA=0X00;
	DDRD=0XFF;
	DDRC=0XFF;
	ADMUX=0X40;
	ADCSRA=0X80;
	cmd(0x38);
	cmd(0x01);
	cmd(0x06);
	cmd(0x0E);
	cmd(0x80);
	while(1)
	{
		ADCSRA=0XC0;
		while((ADCSRA&0X40)==1);
		a=ADCL;
		a+=(ADCH<<8);
		for(i=0;i<4;i++)
		{
			b[3-i]=(a%10)+48;
			a=a/10;
		}
		for(i=0;i<4;i++)
		{
			data(b[i]);
		}
	//	_delay_ms(100);
		cmd(0x01);
	}
}
void cmd(char a)
{
	PORTD=a;
	PORTC=0X02;
	_delay_ms(100);
	PORTC=0X00;
}
void data(char b)
{
	PORTD=b;
	PORTC=0X03;
	_delay_ms(100);
	PORTC=0X01;
}

