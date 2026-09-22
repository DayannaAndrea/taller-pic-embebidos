#include <xc.h>
#include <stdio.h>
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

#define _XTAL_FREQ 20000000UL

#define RS RE0
#define EN RE1

void ConfigurarPIC(void)
{
    ANSEL = 0x00;
    ANSELH = 0x00;
    TRISD = 0x00;
    TRISE = 0x00;
    PORTD = 0x00;
    PORTE = 0x00;
}

void Lcd_Pulso(void)
{
    EN = 1;
    __delay_us(50);
    EN = 0;
    __delay_us(50);
}

void Lcd_Nibble(unsigned char dato)
{
    PORTD = (PORTD & 0x0F) | (dato & 0xF0);
    Lcd_Pulso();
}

void Lcd_Cmd(unsigned char cmd)
{
    RS = 0;
    Lcd_Nibble(cmd);
    Lcd_Nibble(cmd << 4);
    __delay_ms(2);
}

void Lcd_Chr(char dato)
{
    RS = 1;
    Lcd_Nibble(dato);
    Lcd_Nibble(dato << 4);
    __delay_us(100);
}

void Lcd_Str(const char *cadena)
{
    while (*cadena)
    {
        Lcd_Chr(*cadena++);
    }
}

void Lcd_Set_Cursor(unsigned char fila, unsigned char columna)
{
    if (fila == 1)
        Lcd_Cmd(0x80 + columna);
    else
        Lcd_Cmd(0xC0 + columna);
}

void Lcd_Init(void)
{
    __delay_ms(20);
    Lcd_Nibble(0x30);
    __delay_ms(5);
    Lcd_Nibble(0x30);
    __delay_us(150);
    Lcd_Nibble(0x30);
    Lcd_Nibble(0x20);
    Lcd_Cmd(0x28);
    Lcd_Cmd(0x0C);
    Lcd_Cmd(0x06);
    Lcd_Cmd(0x01);
    __delay_ms(2);
}

void main(void)
{
    unsigned char hora = 7;
    unsigned char minuto = 1;
    unsigned char esAM = 1;
    char buffer[17];
    ConfigurarPIC();
    Lcd_Init();
    Lcd_Set_Cursor(1, 0);
    Lcd_Str("Santa Marta");
    while (1)
    {
        Lcd_Set_Cursor(2, 0);
        sprintf(buffer, "Hora: %02d:%02d %s", hora, minuto, esAM ? "a.m." : "p.m.");
        Lcd_Str(buffer);
        __delay_ms(1000);
        minuto++;
        if (minuto > 59)
        {
            minuto = 0;
            hora++;
            if (hora > 12)
            {
                hora = 1;
            }
            if (hora == 12)
            {
                esAM = !esAM;
            }
        }
    }
}