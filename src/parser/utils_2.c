/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:33:56 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/30 23:01:36 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	aux_check_borders(char **map, int last_row, int last_col)
{
	int	i;

	i = 0;
	while (i <= last_col)
	{
		if (map[0][i] != '1' || map[last_row][i] != '1')
			ft_error("Error\nNot enough walls on the top or bottom\n", 9);
		i++;
	}
	i = 0;
	while (i <= last_row)
	{
		if (map[i][0] != '1' || map[i][last_col] != '1')
			ft_error("Error\nNot enough walls on the sides\n", 9);
		i++;
	}
}
/* Check if the borders are all covered by 1 */
void	check_borders(t_map *map_data)
{
	char	**map = map_data->map;
	int		last_row;
	int		last_col;

	map_data->size_area = (t_point *)malloc(sizeof(t_point));
	last_row = 0;
	while (map[last_row])
		last_row++;
	map_data->size_area->y = last_row; //METO FILAS MAPA *OJO*
	last_col = 0;
	while (map[0][last_col])
		last_col++;
	map_data->size_area->x = last_col - 1; //METO COLUMNAS MAPA *OJO*
	aux_check_borders(map, map_data->size_area->y-1, map_data->size_area->x-1);
}

/* A PARTIR DE AQUI CHECK CORRECT PATH */

int contar_elementos(char **map, t_point *size, char objetivo1, char objetivo2)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	while (i < size->y)
	{
		j = 0;
		while (j < size->x)
		{
			if (map[i][j] == objetivo1 || map[i][j] == objetivo2)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
void fill(char **map, t_point *size, t_point *begin, char objective)
{
    // Verificar los límites del mapa y si la celda actual es válida para moverse
    if (begin->y < 0 || begin->y >= size->y || begin->x < 0 || begin->x >= size->x
        || (map[begin->y][begin->x] != objective && map[begin->y][begin->x] != 'C'
        && map[begin->y][begin->x] != '0'))  // Solo moverse sobre '0' o 'C'
        return;

    // Marcar la celda como visitada (evitar volver a pasar)
    map[begin->y][begin->x] = 'V';  // 'V' de visitado

    // Crear variables temporales para las nuevas posiciones
    t_point izquierda = {begin->x - 1, begin->y};
    t_point derecha = {begin->x + 1, begin->y};
    t_point arriba = {begin->x, begin->y - 1};
    t_point abajo = {begin->x, begin->y + 1};

    // Llamadas recursivas para las cuatro direcciones
    fill(map, size, &izquierda, objective);  // izquierda
    fill(map, size, &derecha, objective);    // derecha
    fill(map, size, &arriba, objective);     // arriba
    fill(map, size, &abajo, objective);      // abajo
}

// Función recursiva que recorre el mapa (flood fill)
int flood_fill(char **map, t_point *size, t_point *begin)
{
	int restantes;

	fill(map, size, begin, '0');  // Comenzar desde 'P' y llenar celdas '0'
	restantes = contar_elementos(map, size, 'C', 'E');
	return (restantes == 0);  // Si no quedan 'C' o 'E' sin visitar, hay un camino posible
}



void 	player_position(t_map *map_data, int *player_x, int *player_y)
{
	char	**map;
	int		i;
	int		j;
	int		last_row;
	int		last_col;

	map = map_data->map;
	last_row = map_data->size_area->y-1;
	last_col = map_data->size_area->x-1;
	i = 0;
    while (i <= last_row)
    {
        j = 0;
        while (j <= last_col)
        {
            if (map[i][j] == 'P')
            {
                *player_x = i;
                *player_y = j;
                return;
            }
            j++;
        }
        i++;
    }
}

// Función para imprimir el mapa
void imprimir_mapa(char **map, t_point *size) {
    for (int i = 0; i < size->y; i++) {
        for (int j = 0; j < size->x; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void	check_correct_path(t_map *map_data)
{
	
	imprimir_mapa(map_data->map, map_data->size_area);

	int	player_x;
	int	player_y;

	player_x = 0;
	player_y = 0;
	map_data->p_player = (t_point *)malloc(sizeof(t_point));
	player_position(map_data, &player_x, &player_y); //Ya existe jugador previamente
	map_data->p_player->x = player_x;
	map_data->p_player->y = player_y;
	
	// Verificar si existe un camino
    if (flood_fill(map_data->map, map_data->size_area, map_data->p_player)) {
        printf("Existe un camino posible.\n");
    } else {
        printf("No existe un camino posible.\n");
    }

    // Imprimir el mapa final (para ver cómo quedó tras el fill)
    imprimir_mapa(map_data->map, map_data->size_area);

}
