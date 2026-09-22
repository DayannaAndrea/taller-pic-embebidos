## Ejercicio 1 — Secuencias de LEDs con pulsador

### Objetivo

Controlar ocho LEDs conectados al `PORTD` de un microcontrolador PIC y cambiar
la secuencia de encendido mediante un pulsador conectado a `RB0`.

### Funcionamiento

Cada pulsación cambia entre cuatro modos:

1. Desplazamiento de derecha a izquierda.
2. Desplazamiento de izquierda a derecha.
3. Encendido desde el centro hacia los extremos.
4. Encendido desde los extremos hacia el centro.

Después del cuarto modo, el programa vuelve al primero. El pulsador se
debouncea con una espera de 30 ms y el programa espera a que se suelte antes de
aceptar otra pulsación.

### Aspectos técnicos

- `PORTD` se configura como salida para manejar los LEDs.
- `RB0` se configura como entrada con las resistencias pull-up del puerto B.
- Cada paso de la secuencia permanece visible durante 500 ms.
- El cristal utilizado por el programa es de 20 MHz.

La simulación de Proteus se encuentra en `proteus/ejercicio1.pdsprj` y el
programa fuente en `src/ejercicio1.c`.

