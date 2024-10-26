/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:38:04 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/26 16:44:19 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/* Checks if the borders are all covered by 1 */
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

/* Fills a surface from a position going up / down / right / left with V's */
void	aux_fill(char **map, t_point *size, t_point *begin, char objective)
{
	if (begin->y < 0 || begin->y >= size->y
		|| begin->x < 0 || begin->x >= size->x
		|| (map[begin->y][begin->x] != objective
		&& map[begin->y][begin->x] != 'C'
		&& map[begin->y][begin->x] != '0'
		&& map[begin->y][begin->x] != 'P'))
		return ;
	map[begin->y][begin->x] = 'V';
	aux_fill(map, size, &(t_point){begin->x - 1, begin->y}, objective);
	aux_fill(map, size, &(t_point){begin->x + 1, begin->y}, objective);
	aux_fill(map, size, &(t_point){begin->x, begin->y - 1}, objective);
	aux_fill(map, size, &(t_point){begin->x, begin->y + 1}, objective);
}

/* Returns the amount of collectibles and exit objects existing in the map */
int	aux_number_elts(char **map, t_point *size, char obj1, char obj2)
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

/* Recursive function that traverses the map (flood fill) */
int	aux_flood_fill(char **map, t_point *size, t_point *begin)
{
	int	remaining;

	aux_fill(map, size, begin, 'E');
	remaining = aux_number_elts(map, size, 'C', 'E');
	return (remaining == 0);
}

/* Checks if there is a possible path collecting the objects & getting exit */
void	check_correct_path(t_map *map_data)
{
	char	**map_aux;

	map_aux = ft_dup_matrix(map_data->map);
	if (!map_aux)
		ft_error("Error\nMemory allocation failed\n", 10);
	if (!(aux_flood_fill(map_aux, map_data->area, map_data->p_player)))
		ft_error("Error\nThere's no valid path\n", 11);
	ft_free_matrix(map_aux);
}
