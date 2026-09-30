## Ejercicio 2 — Contador en código Gray

### Objetivo

Generar la secuencia de números de 0 a 15 en código Gray y mostrarla mediante
los cuatro bits inferiores del `PORTC`.

### Funcionamiento

El programa recorre continuamente los valores binarios de 0 a 15. Para cada
valor calcula su equivalente Gray con la expresión:

```c
gray = n ^ (n >> 1);
```

El resultado se escribe en `RC0-RC3`, manteniendo cada valor durante un segundo.
Al llegar a 15, la secuencia vuelve a comenzar en 0.

### Aspectos técnicos

- `PORTC` se configura completamente como salida digital.
- Solo se utilizan los cuatro bits menos significativos del puerto.
- El código Gray cambia un solo bit entre valores consecutivos, lo que resulta
	útil para evitar transiciones ambiguas en ciertos sistemas digitales.
- El cristal utilizado por el programa es de 20 MHz.

La simulación se encuentra en `proteus/ejercicio2.pdsprj` y el código en
`src/ejercicio2.c`.

### Videos

- Protoboard: **https://drive.google.com/file/d/1J1H6bOISUHp3vsO0kwO3aWmxxLD8vZ2L/view?usp=sharing**
- Simulador: **https://drive.google.com/file/d/1K5uJyFmvCx1Cj9q1m0at2Ix_7er_9Lav/view?usp=sharing**
