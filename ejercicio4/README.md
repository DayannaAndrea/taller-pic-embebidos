## Ejercicio 4 — Temporizador de 00 a 59

### Objetivo

Implementar un temporizador de dos dígitos que muestra los segundos transcurridos
en dos displays de siete segmentos.

### Funcionamiento

El valor mostrado comienza en `00`. El conteo se puede iniciar con el pulsador
conectado a `RA0` y detener con el pulsador conectado a `RA1`. `RA2` también
establece el estado de funcionamiento, tal como está implementado en el código.
Al llegar a `59`, el siguiente valor vuelve a ser `00`.

Los displays se multiplexan: `RD6` selecciona las decenas y `RD7` las unidades,
mientras `PORTC` envía el patrón de segmentos correspondiente.

### Aspectos técnicos

- `RA0-RA2` son entradas digitales para los pulsadores.
- `PORTC` se utiliza como bus de segmentos.
- Cada display permanece activo aproximadamente 2 ms por ciclo de refresco.
- Se aplica una espera de 30 ms para reducir el efecto del rebote mecánico.
- El tiempo se aproxima mediante un contador de ciclos, no mediante una
  interrupción de temporizador; por ello su precisión depende del reloj y de la
  duración real del bucle.

El proyecto de Proteus está en `proteus/cuarto.pdsprj`. El código principal se
encuentra en `src/ejercicio4.c` y existe una variante para protoboard en
`src/ejercicio4_protoboard.c`.