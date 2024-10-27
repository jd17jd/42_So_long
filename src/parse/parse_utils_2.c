/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:33:56 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/27 17:26:00 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/* Increments the amount of players and save its coordenates */
void	update_player_pos(t_map *map_data, int i, int j, int *player)
{
	map_data->p_player->x = j;
	map_data->p_player->y = i;
	(*player)++;
}

/* Increments the amount of exits and save its coordenates */
void	update_exit_pos(t_map *map_data, int i, int j, int *exit)
{
	map_data->p_exit->x = j;
	map_data->p_exit->y = i;
	(*exit)++;
}

void	update_collectibles_pos(t_map *map_data, int i, int j, int collectible)
{
	map_data->collect[collectible].position = ft_calloc(1, sizeof(t_point));
	if (!map_data->collect[collectible].position)
		ft_error("Error\nMemory allocation failed\n", 1);
	map_data->collect[collectible].position->x = j;
	map_data->collect[collectible].position->y = i;
}

/* Increments the amount of collectibles and saves its coordinates */
void	aux_collects_pos(t_map *map_data)
{
	int		i;
	int		j;
	int		collectible;
	char	**map;

	map_data->collect = ft_calloc(map_data->collectibles, sizeof(collect_info));
	if (!map_data->collect)
		ft_error("Error\nMemory allocation failed\n", 1);
	map = map_data->map;
	i = 0;
	collectible = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'C')
			{
				update_collectibles_pos(map_data, i, j, collectible);
				collectible++;
			}
			j++;
		}
		i++;
	}
}
