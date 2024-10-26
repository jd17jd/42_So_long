/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:51:29 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/26 16:43:12 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/* Checks if the measures of the map are correct */
void	check_size(t_map *map_data)
{
	int		i;
	char	**map;
	size_t	col_size;

	i = 0;
	map = map_data->map;
	col_size = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != col_size)
			ft_error("Error\nThe map is not rectangular\n", 7);
		i++;
	}
	map_data->area->y = i;
	map_data->area->x = (int) col_size - 1;
}

/* Goes through all the map looking for the elements */
void	aux_quan_elts(t_map *map_data, int *player, int *exit, int *collect)
{
	int		i;
	int		j;
	char	**map;

	map = map_data->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'P')
				update_player_pos(map_data, i, j, player);
			else if (map[i][j] == 'E')
				update_exit_pos(map_data, i, j, exit);
			else if (map[i][j] == 'C')
				(*collect)++;
			j++;
		}
		i++;
	}
	map_data->collectibles = *collect;
	map_data->total_collectibles = *collect;
	aux_collects_pos(map_data);
}

/* Checks the number of elements in the map */
void	check_number_elts(t_map *map_data)
{
	int	player;
	int	exit;
	int	collectibles;

	player = 0;
	exit = 0;
	collectibles = 0;
	aux_quan_elts(map_data, &player, &exit, &collectibles);
	if (player != 1)
		ft_error("Error\nThere must be exactly one player\n", 8);
	if (exit != 1)
		ft_error("Error\nThere must be exactly one exit\n", 8);
	if (collectibles == 0)
		ft_error("Error\nThere must be at least one collectible\n", 8);
}
