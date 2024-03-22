# Problema de los Filósofos Comensales - Multithreading

Este proyecto implementa una solución al problema de los filósofos comensales utilizando hilos pthread en C.

## Descripción

El problema de los filósofos comensales es un clásico problema de sincronización de procesos y acceso a recursos compartidos en informática. Consiste en un grupo de filósofos que pasan su vida pensando y comiendo en una mesa redonda. Entre cada par de filósofos, hay un tenedor. El problema surge cuando todos los filósofos intentan comer al mismo tiempo, ya que pueden entrar en una situación de espera mutua (deadlock) si cada uno toma un tenedor y espera el otro.

Este programa implementa una solución al problema utilizando hilos pthread en C. Cada filósofo es representado por un hilo, y se sincroniza el acceso a los tenedores compartidos utilizando mutex y condiciones pthread.

## Requisitos

- Compilador de C compatible con pthreads (por ejemplo, GCC)
- Sistema operativo que soporte multithreading (por ejemplo, Linux)

## Instalación

1. Clona el repositorio:

    ```bash
    git clone https://github.com/AlexMtzGzn/Cena_De_Filosofos.git
    ```

2. Navega al directorio del proyecto:

    ```bash
    cd Cena_De_Filosofos/src
    ```

3. Compila el programa:

    ```bash
    gcc -o cena_filosofos main.c filosofos.c
    ```

## Uso

1. Ejecuta el programa:

    ```bash
    ./cena_filosofos
    ```

2. Observa la simulación del problema de los filósofos comensales en la salida.

## Contribución

Las contribuciones son bienvenidas y apreciadas. Si encuentras errores, tienes sugerencias de mejoras o quieres agregar nuevas características, por favor, siéntete libre de abrir un issue o enviar un pull request. Tu contribución ayudará a mejorar este proyecto para todos.

## Licencia

Este proyecto está bajo la Licencia MIT. Consulta el archivo `LICENSE` para más detalles.
