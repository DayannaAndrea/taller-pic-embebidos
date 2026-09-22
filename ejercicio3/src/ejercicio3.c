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

#define _XTAL_FREQ 20000000UL

const unsigned char tabla[10] =
    {
        0b11000000,
        0b11111001,
        0b10100100,
        0b10110000,
        0b10011001,
        0b10010010,
        0b10000010,
        0b11111000,
        0b10000000,
        0b10010000};

unsigned int contador = 0;

unsigned char unidades;
unsigned char decenas;
unsigned char centenas;
unsigned char miles;

void separar_numero(void)
{
    unidades = contador % 10;
    decenas = (contador / 10) % 10;
    centenas = (contador / 100) % 10;
    miles = (contador / 1000) % 10;
}

void apagar_displays(void)
{
    RD0 = 1;
    RD1 = 1;
    RD2 = 1;
    RD3 = 1;
}

void mostrar_digito(unsigned char numero, unsigned char posicion)
{
    apagar_displays();
    PORTC = tabla[numero];
    if (posicion == 0)
        RD0 = 0;
    else if (posicion == 1)
        RD1 = 0;
    else if (posicion == 2)
        RD2 = 0;
    else if (posicion == 3)
        RD3 = 0;
    __delay_ms(2);
    apagar_displays();
}

void refrescar_display(void)
{
    mostrar_digito(miles, 0);
    mostrar_digito(centenas, 1);
    mostrar_digito(decenas, 2);
    mostrar_digito(unidades, 3);
}

void configurar(void)
{
    ANSEL = 0x00;
    ANSELH = 0x00;
    TRISC = 0x00;
    TRISD = 0x00;
    PORTC = 0xFF;
    apagar_displays();
}

void main(void)
{
    configurar();
    contador = 0;
    while (1)
    {
        separar_numero();
        for (unsigned int i = 0; i < 120; i++)
        {
            refrescar_display();
        }
        contador++;
        if (contador > 9999)
        {
            contador = 0;
        }
    }
}