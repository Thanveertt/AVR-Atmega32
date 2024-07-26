/*
 * main.c
 *
 * Created: 1/3/2022 3:39:21 PM
 *  Author: Thanveer
 */ 
#define F_CPU 8000000UL 
#include<util/delay.h>
#include<avr/io.h>
int main()
{
	DDRA=0XFF;
    while(1)
    {
        PORTA=0XFF;
		_delay_ms(1000);
		PORTA=0X00;
		_delay_ms(1000);
    }
}