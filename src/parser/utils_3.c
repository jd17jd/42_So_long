/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:27:32 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/02 12:35:44 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

char	**duplicate_map(char **map)
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

void	player_position(t_map *map_data, int *player_x, int *player_y)
{
	char	**map;
	int		i;
	int		j;
	int		last_row;
	int		last_col;

	map = map_data->map;
	last_row = map_data->area->y - 1;
	last_col = map_data->area->x - 1;
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
				return ;
			}
			j++;
		}
		i++;
	}
}

int	contar_elementos(char **map, t_point *size, char objetivo1, char objetivo2)
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
			if (map[i][j] == objetivo1 || map[i][j] == objetivo2)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
