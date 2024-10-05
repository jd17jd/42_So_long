/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:33:56 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/05 15:18:59 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/* Check if the borders are all covered by 1 */
void	check_borders(t_map *map_data, int last_row, int last_col)
{
	int		i;
	char	**map;

	map = map_data->map;
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

char	**aux_duplicate_map(char **map)
{
	char	**res;
	int		i;

	i = 0;
	while (map[i])
		i++;
	res = (char **)ft_calloc(i + 1, sizeof(char *));
	if (!res)
		ft_error("Error\nMemory allocation failed\n", 10);
	i = 0;
	while (map[i])
	{
		res[i] = ft_strdup(map[i]);
		i++;
	}
	return (res);
}

void	aux_fill(char **map, t_point *size, t_point *begin, char objective)
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
	aux_fill(map, size, &(t_point){begin->x - 1, begin->y}, objective);
	// derecha
	aux_fill(map, size, &(t_point){begin->x + 1, begin->y}, objective);
	// arriba
	aux_fill(map, size, &(t_point){begin->x, begin->y - 1}, objective);
	// abajo
	aux_fill(map, size, &(t_point){begin->x, begin->y + 1}, objective);
}

int		aux_number_elts(char **map, t_point *size, char obj1, char obj2)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < size->y)
	{
		j = 0;
		while (j < size->x)
		{
			if (map[i][j] == obj1 || map[i][j] == obj2)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

// Función recursiva que recorre el mapa (flood fill)
int	aux_flood_fill(char **map, t_point *size, t_point *begin)
{
	int	remaining;

	aux_fill(map, size, begin, 'E');
	remaining = aux_number_elts(map, size, 'C', 'E');
	return (remaining == 0);
}

void	check_correct_path(t_map *map_data)
{
	char	**map_aux;

	map_aux = aux_duplicate_map(map_data->map); //RESERVO PARA MAPA AUX
	if (!(aux_flood_fill(map_aux, map_data->area, map_data->p_player)))
		ft_error("Error\nThere's no valid path\n", 11);
	free_array(map_aux); //LIBERO MAPA_AUX
}
