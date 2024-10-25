/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:57:02 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/18 02:46:32 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	move_up(t_map *map_data)
{
	char	**map;
	int		i;
	int		player_x;
	int		player_y;

	map = map_data->map;
	player_x = map_data->p_player->x;
	player_y = map_data->p_player->y;
if (map[player_y - 1][player_x] == 'C')
{
    map_data->collectibles--;
    i = 0;
    while (i < map_data->total_collectibles)
    {
        printf("Player pos: (%d, %d)\n", player_x * 64, (player_y - 1) * 64);
        printf("Collectible pos: (%d, %d)\n", map_data->collect[i]->instances->x, map_data->collect[i]->instances->y);
        if (map_data->collect[i]->instances->x == player_x * 64 && map_data->collect[i]->instances->y == (player_y - 1) * 64)
        {
            map_data->collect[i]->enabled = false;  // Desactiva el coleccionable
            break;
        }
        i++;
    }
}

	map[player_y][player_x] = '0';
	map[player_y - 1][player_x] = 'P'; // map_data->collect->instances[0].enabled = false;
	map_data->p_player->y = player_y - 1;
	map_data->player->instances->y -= 64;
	map_data->moves++;
	ft_printf("Movimientos: %d\n", map_data->moves);
}

void	move_down(t_map *map_data)
{
	char	**map;
	int		i;
	int		player_x;
	int		player_y;

	map = map_data->map;
	player_x = map_data->p_player->x;
	player_y = map_data->p_player->y;
	if (map[player_y + 1][player_x] == 'C')
	{
        map_data->collectibles--;
		i = 0;
		while (i < map_data->total_collectibles)
		{
			if (map_data->collect[i]->instances->x == player_x * 64 && map_data->collect[i]->instances->y == (player_y + 1) * 64)
			{
				map_data->collect[i]->enabled = false;  // Desactiva el coleccionable
				break;
			}
			i++;
		}
    }
	map[player_y][player_x] = '0';
	map[player_y + 1][player_x] = 'P'; // map_data->collect->instances[0].enabled = false;
	map_data->p_player->y = player_y + 1;
	map_data->player->instances->y += 64;
	map_data->moves++;
	ft_printf("Movimientos: %d\n", map_data->moves);
}

void	move_right(t_map *map_data)
{
	char	**map;
	int		i;
	int		player_x;
	int		player_y;

	map = map_data->map;
	player_x = map_data->p_player->x;
	player_y = map_data->p_player->y;
	if (map[player_y][player_x + 1] == 'C')
	{
        map_data->collectibles--;
		i = 0;
		while (i < map_data->total_collectibles)
		{
			if (map_data->collect[i]->instances->x == (player_x + 1) * 64 && map_data->collect[i]->instances->y == player_y * 64)
			{
				map_data->collect[i]->enabled = false;  // Desactiva el coleccionable
				break;
			}
			i++;
		}
    }
	map[player_y][player_x] = '0';
	map[player_y][player_x + 1] = 'P'; // map_data->collect->instances[0].enabled = false;
	map_data->p_player->x = player_x + 1;
	map_data->player->instances->x += 64;
	map_data->moves++;
	ft_printf("Movimientos: %d\n", map_data->moves);
}

void	move_left(t_map *map_data)
{
	char	**map;
	int		i;
	int		player_x;
	int		player_y;

	map = map_data->map;
	player_x = map_data->p_player->x;
	player_y = map_data->p_player->y;
	if (map[player_y][player_x - 1] == 'C')
	{
        map_data->collectibles--;
		i = 0;
		while (i < map_data->total_collectibles)
		{
			if (map_data->collect[i]->instances->x == (player_x - 1) * 64 && map_data->collect[i]->instances->y == player_y * 64)
			{
				map_data->collect[i]->enabled = false;  // Desactiva el coleccionable
				break;
			}
			i++;
		}
    }
	map[player_y][player_x] = '0';
	map[player_y][player_x - 1] = 'P'; // map_data->collect->instances[0].enabled = false;
	map_data->p_player->x = player_x - 1;
	map_data->player->instances->x -= 64;
	map_data->moves++;
	ft_printf("Movimientos: %d\n", map_data->moves);
}

/* Detects which key has been pressed */
void	detect_key(mlx_key_data_t keydata, void *param)
{
	t_map	*map_data;
	char	**map;
	int		player_x;
	int		player_y;

	map_data = (t_map *)param;
	map = map_data->map;
	player_x = map_data->p_player->x;
	player_y = map_data->p_player->y;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_W && map[player_y - 1][player_x] != '1')
		move_up(map_data);
	if (keydata.key == MLX_KEY_S && map[player_y + 1][player_x] != '1')
		move_down(map_data);
	if (keydata.key == MLX_KEY_D && map[player_y][player_x + 1] != '1')
		move_right(map_data);
	if (keydata.key == MLX_KEY_A && map[player_y][player_x - 1] != '1')
		move_left(map_data);
	aux_ending_situations(keydata, map_data);
}
