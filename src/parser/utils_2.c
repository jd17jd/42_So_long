/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:33:56 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/04 00:16:48 by jvivas-g         ###   ########.fr       */
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
	char	**map;
	int		last_row;
	int		last_col;

	map = map_data->map;
	//RESERVO PARA AREA
	map_data->area = (t_point *)ft_calloc(1, sizeof(t_point));
	last_row = 0;
	while (map[last_row])
		last_row++;
	map_data->area->y = last_row;
	last_col = 0;
	while (map[0][last_col])
		last_col++;
	map_data->area->x = last_col - 1;
	aux_check_borders(map, map_data->area->y - 1, map_data->area->x - 1);
}

/* A PARTIR DE AQUI CHECK CORRECT PATH */
void	fill(char **map, t_point *size, t_point *begin, char objective)
{
	if (begin->y < 0 || begin->y >= size->y
		|| begin->x < 0 || begin->x >= size->x
		|| (map[begin->y][begin->x] != objective
		&& map[begin->y][begin->x] != 'C'
		&& map[begin->y][begin->x] != '0'
		&& map[begin->y][begin->x] != 'P'))
		return ;
	// Solo moverse sobre '0', 'C' o 'E'
	map[begin->y][begin->x] = 'V'; // 'V' de visitado	
	// Llamadas recursivas para las cuatro direcciones
	// izquierda
	fill(map, size, &(t_point){begin->x - 1, begin->y}, objective);
	// derecha
	fill(map, size, &(t_point){begin->x + 1, begin->y}, objective);
	// arriba
	fill(map, size, &(t_point){begin->x, begin->y - 1}, objective);
	// abajo
	fill(map, size, &(t_point){begin->x, begin->y + 1}, objective);
}

// Función recursiva que recorre el mapa (flood fill)
int	flood_fill(char **map, t_point *size, t_point *begin)
{
	int	restantes;

	fill(map, size, begin, 'E');
	restantes = contar_elementos(map, size, 'C', 'E');
	// Si no quedan 'C' o 'E' sin visitar, hay un camino posible
	return (restantes == 0);
}

void	check_correct_path(t_map *map_data)
{
	char	**map_aux;
	int		player_x;
	int		player_y;

	player_x = 0;
	player_y = 0;
	map_aux = duplicate_map(map_data->map); // RESERVO PARA MAPA AUX
	//RESERVO PARA POS.JUGADOR
	map_data->p_player = (t_point *)ft_calloc(1, sizeof(t_point));
	player_position(map_data, &player_x, &player_y);
	map_data->p_player->x = player_x;
	map_data->p_player->y = player_y;
	if (!(flood_fill(map_aux, map_data->area, map_data->p_player)))
		ft_error("Error\nThere's no valid path\n", 11);
	free_array(map_aux); //LIBERO MAPA_AUX
}
