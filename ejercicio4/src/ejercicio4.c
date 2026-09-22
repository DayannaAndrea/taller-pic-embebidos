#include <xc.h>

#pragma config FOSC = HS
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config MCLRE = ON
#pragma config CP = OFF
#pragma config CPD = OFF
#pragma config BOREN = OFF
#pragma config IESO = OFF
#pragma config FCMEN = OFF
#pragma config LVP = OFF
#pragma config DEBUG = OFF

#define _XTAL_FREQ 20000000

const unsigned char DIGITOS[10] = {
    0x7E,
    0x42,
    0x6D,
    0x67,
    0x53,
    0x37,
    0x3F,
    0x62,
    0x7F,
    0x77
};

unsigned char segundos = 0;
unsigned char funcionando = 0;

void mostrarDisplay(void)
{
    unsigned char decenas;
    unsigned char unidades;

    decenas = segundos / 10;
    unidades = segundos % 10;

    RD6 = 0;
    RD7 = 0;

    PORTC = DIGITOS[decenas];
    RD6 = 1;
    __delay_ms(2);
    RD6 = 0;

    PORTC = DIGITOS[unidades];
    RD7 = 1;
    __delay_ms(2);
    RD7 = 0;
}

void revisarBotones(void)
{
    if(RA0 == 0)
    {
        __delay_ms(30);

        if(RA0 == 0)
        {
            funcionando = 1;

            while(RA0 == 0)
            {
                mostrarDisplay();
            }
        }
    }

    if(RA1 == 0)
    {
        __delay_ms(30);

        if(RA1 == 0)
        {
            funcionando = 0;

            while(RA1 == 0)
            {
                mostrarDisplay();
            }
        }
    }

    if(RA2 == 0)
    {
        __delay_ms(30);

        if(RA2 == 0)
        {
            funcionando = 1;

            while(RA2 == 0)
            {
                mostrarDisplay();
            }
        }
    }
}

void main(void)
{
    unsigned int contadorTiempo = 0;

    ANSEL = 0x00;
    ANSELH = 0x00;

    TRISC = 0x00;

    TRISD6 = 0;
    TRISD7 = 0;

    TRISA0 = 1;
    TRISA1 = 1;
    TRISA2 = 1;

    PORTC = 0x00;
    PORTD = 0x00;

    RD6 = 0;
    RD7 = 0;

    segundos = 0;
    funcionando = 0;

    while(1)
    {
        mostrarDisplay();
        revisarBotones();

        if(funcionando == 1)
        {
            contadorTiempo++;

            if(contadorTiempo >= 250)
            {
                contadorTiempo = 0;

                segundos++;

                if(segundos > 59)
                {
                    segundos = 0;
                }
            }
        }
        else
        {
            contadorTiempo = 0;
        }
    }
}   