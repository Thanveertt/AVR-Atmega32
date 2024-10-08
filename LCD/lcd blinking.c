#define F_CPU 8000000UL
#include<util/delay.h>
#include<avr/io.h>
void display(const char *p);
void cmd(char a);
void data(char b);            
void main()
{
	DDRB=0X00;
	DDRC=0XFF;
	DDRD=0XFF;
	cmd(0x38);
	cmd(0x01);
	cmd(0x06);
	cmd(0x0E);
	cmd(0x80);
	while(1)
	{
			PORTB=0XFF;
			_delay_ms(100);
			PORTB=0X00;
			display("Blinking");
			cmd(0x01);
			
	}
}
void cmd(char a)
{
	PORTD=a;
	PORTC=0X02;
	_delay_ms(30);
	PORTC=0X00;
}
void data(char b)
{
	PORTD=b;
	PORTC=0X03;
	_delay_ms(30);
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

