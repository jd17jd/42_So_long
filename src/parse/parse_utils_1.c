/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:51:29 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/25 18:28:13 by jvivas-g         ###   ########.fr       */
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
	// Almacena la posición del coleccionable
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