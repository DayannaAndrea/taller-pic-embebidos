# Taller de Microcontroladores PIC

Repositorio con las prácticas de programación y simulación de sistemas embebidos utilizando microcontroladores PIC, lenguaje C, MPLAB XC8 y Proteus.

## Contenido

| Ejercicio | Tema principal |
| --- | --- |
| [Ejercicio 1](ejercicio1/README.md) | Secuencias de LEDs controladas con un pulsador |
| [Ejercicio 2](ejercicio2/README.md) | Generación y visualización de código Gray de 4 bits |
| [Ejercicio 3](ejercicio3/README.md) | Contador decimal de `0000` a `9999` con displays multiplexados |
| [Ejercicio 4](ejercicio4/README.md) | Temporizador de `00` a `59` con pulsadores de control |
| [Ejercicio 5](ejercicio5/README.md) | Simulación disponible; código fuente pendiente |

Cada ejercicio incluye, cuando corresponde, el código fuente, el proyecto de
Proteus, el archivo compilado, imágenes de la simulación y videos de prueba.

## Organización del repositorio

```text
.
├── ejercicio1/
├── ejercicio2/
├── ejercicio3/
├── ejercicio4/
├── ejercicio5/
└── informe/
```

Dentro de cada ejercicio:

- `src/`: código fuente en C.
- `proteus/`: esquemas, simulaciones, imágenes y archivos compilados.
- `media/`: videos de la implementación o simulación.
- `README.md`: explicación particular de la práctica.

## Requisitos

Para compilar y simular los ejercicios se recomienda disponer de:

- MPLAB X IDE.
- Compilador MPLAB XC8.
- Proteus Design Suite.
- Un programador o entorno compatible con el microcontrolador PIC utilizado.

Los programas están configurados para trabajar con un cristal de 20 MHz. La
configuración exacta de pines, displays, LEDs y pulsadores se puede consultar
en el código fuente y en el proyecto correspondiente de Proteus.

## Flujo de trabajo

1. Abrir el README del ejercicio que se desea realizar.
2. Revisar el código ubicado en `src/`.
3. Abrir el proyecto `.pdsprj` en Proteus para comprobar las conexiones.
4. Compilar el código con XC8 y cargar el archivo `.hex` en la simulación.
5. Ejecutar la simulación y comparar el comportamiento con la descripción del
   ejercicio.

## Estado del proyecto

Los ejercicios 1 a 4 cuentan con código fuente, simulación y documentación. En
el ejercicio 5 está disponible la simulación, pero `ejercicio5/src/ejercicio5.c`
se encuentra vacío, por lo que su comportamiento aún no puede documentarse con
precisión.
