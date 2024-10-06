/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:33:56 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/06 20:21:25 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Duplicates a char** object */
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

	map_aux = aux_duplicate_map(map_data->map);
	if (!(aux_flood_fill(map_aux, map_data->area, map_data->p_player)))
		ft_error("Error\nThere's no valid path\n", 11);
	free_array(map_aux);
}
