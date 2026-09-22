## Ejercicio 5 — Reloj en pantalla LCD

### Objetivo

Mostrar en un LCD el nombre de la ciudad de Santa Marta y un reloj digital en
formato de 12 horas.

### Funcionamiento

Al iniciar, el LCD muestra `Santa Marta` en la primera fila. En la segunda fila
se presenta la hora con el formato `Hora: HH:MM a.m.` o `Hora: HH:MM p.m.`.
El reloj comienza en `07:01 a.m.`, avanza un minuto cada segundo y cambia entre
`a.m.` y `p.m.` al pasar por las 12:00. Después de las 12:59, la hora vuelve a
la 1:00.

### Aspectos técnicos

- `PORTD` se utiliza para enviar los datos al LCD en modo de 4 bits.
- `RE0` funciona como señal `RS` y `RE1` como señal `EN`.
- Las funciones `Lcd_Cmd`, `Lcd_Chr` y `Lcd_Str` separan el envío de comandos,
  caracteres y cadenas.
- El programa utiliza un cristal de 20 MHz.
- El avance del reloj se basa en retardos de software de un segundo, por lo que
  no representa una hora real sin calibración o un temporizador externo.

La simulación de Proteus se encuentra en `proteus/EJE5.pdsprj` y el código
fuente en `src/ejercicio5.c`.