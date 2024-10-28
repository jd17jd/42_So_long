# EXPLICACION DEL PROYECTO 
## Juego
- Objetivo: El jugador debe recolectar todos los objetos presentes en el mapa y salir situandose en el portal de salida
- Teclas a utilizar:
    - W = Arriba
    - S = Abajo
    - A = Izquierda
    - D = Derecha
- El jugador no podrá atravesar paredes
- Se debe poder visualizar la cantidad de movimientos realizados por salida estándar
- El juego tendrá una perspectiva 2D


## Gestión de gráficos
- El programa mostrará la imagen en una ventana.
- La gestión de tu ventana debe ser limpia (cambiar de ventana, minimizar, etc)
- Pulsar la tecla ESC debe cerrar la ventana y cerrar el programa limpiamente.
- Hacer clic en la cruz roja de la ventana debe cerrar la ventana y terminar el programa limpiamente.

## Mapa
- El mapa en el fichero de texto plano estará compuesto de 5 caracteres:
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


### Restricciones: 
- Debe haber solo 1 jugador, 1 salida y por lo menos un coleccionable
- El mapa debe ser rectangular.
- El mapa deberá estar cerrado/rodeado de muros.
- Deberá haber un camino válido en el mapa (Posible reocger todos los objetos y llegar a la salida)
- Debes poder procesar cualquier tipo de mapa, siempre y cuando respete las anteriores normas.
- El mapa deberá tener extensión .ber


- En caso de fallos de configuración de cualquier tipo encontrados en el archivo, el programa debe terminar correctamente y devolver “Error\n” seguido de un mensaje explícito de tu elección.


## Usuarios

### Prerrequisitos
1. Sistema operativo: Idealmente, un sistema tipo UNIX (Linux o macOS), ya que la biblioteca MLX42 generalmente es compatible con estos entornos.
2. Dependencias: 
    -  Compilador GCC: Versión moderna de GCC (idealmente GCC 8 o superior) para asegurar compatibilidad con las opciones de compilación (-Wall -Wextra -Werror).
    - CMake: Necesitarás CMake para construir la biblioteca MLX42.
    - Libc y GLFW: MLX42 usa OpenGL, por lo que es importante tener las librerías de libGL y glfw instaladas.
3. Obviamos demás especificaciones como CPU, RAM y Almacenamiento, pues el programa requiere de recursos muy básicos

### Cómo usar
1. Clonar el repositorio
2. Compilar con make
3. Ejecutar ./so_long + nombre_mapa_en_resources/maps/valid

### Nuevo mapa
Si se quiere crear un nuevo mapa hay que introducirlo en la ruta: resources/maps/valid y deberá cumplir con las Restricciones anteriormente mencionadas

## Desarrolladores

### Algoritmo
1. Checkeo de argumentos. (Debe haber exactarmente 2 y debe tener la extensión correcta)
    - Error 1. Errores en las reservas de memoria de estructuras.
    - Error 2. Error en el numero de argumentos / Extension de fichero incorrecta  
2. Parseo mapa. El mapa del fichero deberá cumplir todas las características antes de ser procesado
    - Error 3. Error en la apertura del fichero que le pasamos por parametro
    - Error 4. El mapa está vacío
    - Error 5. Error leyendo las líneas del fichero
    - Error 6. El mapa no es rectangular
    - Error 7. El caracter introducido no es valido
    - Error 8. Incorrecto numero de objetos
    - Error 9. Error en los bordes del juego
    - Error 10. No hay un camino válido  
3. Inicialización mapa. Una vez sabemos que el mapa es válido, pasamos a visualizarlo gráficamente.
    - Error 11. Imposible inicializar la librería gráfica
    - Error 12. Imposible inicializar la ventana
    - Error 13. Libreria no puede abrir imagenes
    - Error 14. Libreria no puede pintar imagenes
4. Deteccion de teclas. Permitirá que nuestro personaje se peuda desplazar por el mapa.
5. Implementar el bucle del juego
6. Establecer una correcta terminación del juego
7. Librar la memoria asignada de todos los recursos
