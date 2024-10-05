/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:57:02 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/05 02:56:44 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	move_up(t_map *map_data)
{
	char 	**map;
	int		player_x;
	int		player_y;

	map = map_data->map;
	player_x = map_data->p_player->x;
	player_y = map_data->p_player->y;
	if (map[player_y - 1][player_x] == 'C')
		map_data->collectibles--;
	map[player_y][player_x] = '0';
	map[player_y - 1][player_x] = 'P';
	map_data->p_player->y = player_y - 1;
	map_data->moves++;
	ft_printf("Movimientos: %d\n", map_data->moves);
	print_images(map_data);
}

void	move_down(t_map *map_data)
{
	char 	**map;
	int		player_x;
	int		player_y;

	map = map_data->map;
	player_x = map_data->p_player->x;
	player_y = map_data->p_player->y;
	if (map[player_y + 1][player_x] == 'C')
		map_data->collectibles--;
	map[player_y][player_x] = '0';
	map[player_y + 1][player_x] = 'P';
	map_data->p_player->y = player_y + 1;
	map_data->moves++;
	ft_printf("Movimientos: %d\n", map_data->moves);
	print_images(map_data);
}

void	move_right(t_map *map_data)
{
	char 	**map;
	int		player_x;
	int		player_y;

	map = map_data->map;
	player_x = map_data->p_player->x;
	player_y = map_data->p_player->y;
	if (map[player_y][player_x + 1] == 'C')
		map_data->collectibles--;
	map[player_y][player_x] = '0';
	map[player_y][player_x + 1] = 'P';
	map_data->p_player->x = player_x + 1;
	map_data->moves++;
	ft_printf("Movimientos: %d\n", map_data->moves);
	print_images(map_data);
}

void	move_left(t_map *map_data)
{
	char 	**map;
	int		player_x;
	int		player_y;

	map = map_data->map;
	player_x = map_data->p_player->x;
	player_y = map_data->p_player->y;
	if (map[player_y][player_x - 1] == 'C')
		map_data->collectibles--;
	map[player_y][player_x] = '0';
	map[player_y][player_x - 1] = 'P';
	map_data->p_player->x = player_x - 1;
	map_data->moves++;
	ft_printf("Movimientos: %d\n", map_data->moves);
	print_images(map_data);
}

int	end_game(void)
{
	exit (0);
	return (0);
}

/* Fills with empties */
/* When a key is pressed, the player is moved */
void aux_ending_situations(mlx_key_data_t keydata, t_map *map_data) {
    char **map;
    int player_x;
    int player_y;

    map = map_data->map;
    player_x = map_data->p_player->x;
    player_y = map_data->p_player->y;

    if (keydata.key == ESC)
        end_game();

    if (map_data->collectibles == 0 && 
        ((keydata.key == D && map[player_y][player_x + 1] == 'E') ||
         (keydata.key == S && map[player_y + 1][player_x] == 'E') ||
         (keydata.key == A && map[player_y][player_x - 1] == 'E') ||
         (keydata.key == W && map[player_y - 1][player_x] == 'E'))) {
        ft_printf("Congrats!! You won!\n");
        end_game();
    }
}

// Detectar la tecla presionada
void detect_key(mlx_key_data_t keydata, void *param)
{
	printf("Hola\n");
    t_map *map_data = (t_map *)param;

    aux_ending_situations(keydata, map_data);

    if (keydata.key == W && map_data->map[map_data->p_player->y - 1][map_data->p_player->x] != '1'
	&& map_data->map[map_data->p_player->y - 1][map_data->p_player->x] != 'E')
        move_up(map_data);

    if (keydata.key == S && map_data->map[map_data->p_player->y + 1][map_data->p_player->x] != '1'
	&& map_data->map[map_data->p_player->y + 1][map_data->p_player->x] != 'E')
        move_down(map_data);

    if (keydata.key == D && map_data->map[map_data->p_player->y][map_data->p_player->x + 1] != '1'
	&& map_data->map[map_data->p_player->y][map_data->p_player->x + 1] != 'E')
        move_right(map_data);

    if (keydata.key == A && map_data->map[map_data->p_player->y][map_data->p_player->x - 1] != '1'
	&& map_data->map[map_data->p_player->y][map_data->p_player->x - 1] != 'E')
        move_left(map_data);
}
