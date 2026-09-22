## Ejercicio 3 — Contador decimal de cuatro dígitos

### Objetivo

Mostrar un contador de `0000` a `9999` en cuatro displays de siete segmentos
utilizando multiplexación.

### Funcionamiento

El valor del contador se separa en unidades, decenas, centenas y miles. Cada
dígito se activa durante un periodo corto y, al repetir rápidamente el proceso,
el ojo humano percibe los cuatro displays encendidos al mismo tiempo.

El contador se incrementa después de refrescar la pantalla y vuelve a `0000`
cuando supera `9999`.

### Aspectos técnicos

- `PORTC` contiene el patrón de segmentos de cada número.
- `RD0-RD3` seleccionan individualmente los cuatro displays.
- Los patrones de segmentos están definidos en la tabla `tabla` y corresponden
  a displays de lógica activa en bajo.
- Cada dígito se muestra durante aproximadamente 2 ms.
- El programa está preparado para un cristal de 20 MHz.

La simulación de Proteus está en `proteus/ejercicio3.pdsprj` y el código en
`src/ejercicio3.c`.