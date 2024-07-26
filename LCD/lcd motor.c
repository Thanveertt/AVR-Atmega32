#define F_CPU 8000000UL
#include<util/delay.h>
#include<avr/io.h>
void display(const char *p);
void cmd(char a);
void data(char b);
void main()
{
	DDRA=0X00;
	DDRB=0XFF;
	DDRC=0XFF;
	DDRD=0XFF;
	cmd(0x38);
	cmd(0x01);
	cmd(0x06);
	cmd(0x0E);
	cmd(0x80);
	while(1)
	{
		if((PINA&0X01)==0)
		{
			PORTB=0X1D;
			_delay_ms(100);
			display("Forward");
			cmd(0x01);
		}
		if((PINA&2)==0)
		{
				PORTB=0X2E;
				_delay_ms(100);
				display("Reverse");
				cmd(0x01);
		}
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
void display(const char *p)
{
	while(*p!='\0')
	{
		data(*p);
		p++;
	}
}

