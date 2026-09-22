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
unsigned char modo = 0;

const unsigned char centroExtremos[4] = {
    0x18,
    0x24,
    0x42,
    0x81};

void ConfigurarPIC(void)
{
    ANSEL = 0x00;
    ANSELH = 0x00;
    TRISD = 0x00;
    TRISB0 = 1;
    PORTD = 0x00;
    OPTION_REGbits.nRBPU = 0;
}

void DerechaIzquierda(void)
{
    unsigned char i;
    for (i = 0; i < 8; i++)
    {
        PORTD = (1 << i);
        __delay_ms(500);
    }
}

void IzquierdaDerecha(void)
{
    signed char i;
    for (i = 7; i >= 0; i--)
    {
        PORTD = (1 << i);
        __delay_ms(500);
    }
}

void CentroExtremos(void)
{
    unsigned char i;
    for (i = 0; i < 4; i++)
    {
        PORTD = centroExtremos[i];
        __delay_ms(500);
    }
}

void ExtremosCentro(void)
{
    unsigned char i;
    for (i = 3; i < 4; i--)
    {
        PORTD = centroExtremos[i];
        __delay_ms(500);
        if (i == 0)
            break;
    }
}

void main(void)
{
    ConfigurarPIC();
    while (1)
    {
        if (RB0 == 0)
        {
            __delay_ms(30);
            if (RB0 == 0)
            {
                modo++;
                if (modo > 3)
                    modo = 0;
                while (RB0 == 0)
                    ;
                __delay_ms(30);
            }
        }
        if (modo == 0)
            DerechaIzquierda();
        else if (modo == 1)
            IzquierdaDerecha();
        else if (modo == 2)
            CentroExtremos();
        else
            ExtremosCentro();
    }
}