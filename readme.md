# EXPLICACION DEL PROYECTO 
## Juego
- El objetivo del jugador es recolectar todos los objetos presentes en el mapa y salir eligiendo la ruta más corta posible.
- Las teclas W, A, S y D se utilizarán para mover al personaje principal.
- El jugador debe poder moverse en 4 direcciones: subir, bajar, ir a la izquierda o ir a la derecha.
- El jugador no puede entrar dentro de las paredes.
- Tras cada movimiento, el número real de movimientosdebe mostrarse en un terminal.
- Utilizarás una perspectiva 2D (vista de pájaro o lateral).
- El juego no necesita ser en tiempo real.
- Aunque los ejemplos dados se refieren a una temática de delfín, puedes crear el mundo que quieras.

## Gestión de gráficos
- El programa mostrará la imagen en una ventana.
- La gestión de tu ventana debe ser limpia (cambiar de ventana, minimizar, etc)
- Pulsar la tecla ESC debe cerrar la ventana y cerrar el programa limpiamente.
- Hacer clic en la cruz roja de la ventana debe cerrar la ventana y terminar el programa limpiamente.
- El uso de images de la miniLibX es obligatorio

## Mapa
- El mapa estará construido de 3 componentes: paredes, objetos y espacio abierto.
- El mapa estará compuesto de solo 5 caracteres:
    - 0 para un espacio vacío
    - 1 para u muro
    - C para un coleccionable
    - E para salir del mapa
    - P para la posición inicial del jugador.

- Este es un ejemplo simple de un mapa válido:

1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111

- El mapa debe tener una salida, al menos un objeto y una posición inicial.
- Si el mapa contiene caractéres duplicados (salida o posición inicial), deberás mostrar un mensaje de error.
- El mapa debe ser rectangular.
- El mapa deberá estar cerrado/rodeado de muros, en caso contrario el programa deberá devolver un error.
- Tienes que comprobar si hay un camino válido en el mapa.
- Debes poder procesar cualquier tipo de mapa, siempre y cuando respete las anteriores normas.
- Otro ejemplo minimalista de un mapa .ber:

1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111

- En caso de fallos de configuración de cualquier tipo encontrados en el archivo, el programa debe terminar correctamente y devolver “Error\n” seguido de un mensaje explícito de tu elección.

Pasos:
1. Checkeo de argumentos. Hecho
2. Parseo mapa
