#define F_CPU 8000000UL
#include<avr/io.h>
void trans(char a);
char rec();
int flag;
void main()
{
	
	char c;
	DDRD=0X02;
	UCSRA=0X00;
	UCSRB=0X18;
	UCSRC=0X86;
	UBRRL=51;
	while(1)
	{
		c=rec();
		if(c=='*')
		{
			flag=1;
		}
		if(c=='#')
		{
			flag=0;
		}
		if(flag==1)
		{
			trans(c);
		}
		
	}
}
void trans(char a)
{
	UDR=a;
	while((UCSRA&0x40)==0);
	UCSRA=0x40;
}
char rec()
{
	while((UCSRA&0x80)==0);
	return(UDR);
}
