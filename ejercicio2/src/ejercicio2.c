#include <xc.h>

#pragma config FOSC = HS
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config MCLRE = ON
#pragma config CP = OFF
#pragma config CPD = OFF
#pragma config BOREN = OFF
#pragma config IESO = OFF
#pragma config FCMEN = OFF
#pragma config LVP = OFF
#pragma config DEBUG = OFF
#define _XTAL_FREQ 20000000

void ConfigurarPIC(void)
{
    ANSEL = 0x00;
    ANSELH = 0x00;
    TRISC = 0x00;
    PORTC = 0x00;
}

void main(void)
{
    unsigned char n;
    unsigned char gray;
    ConfigurarPIC();
    while (1)
    {
        for (n = 0; n < 16; n++)
        {
            gray = n ^ (n >> 1);
            PORTC = gray & 0x0F;
            __delay_ms(1000);
        }
    }
}