/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:57:02 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/05 19:53:58 by jvivas-g         ###   ########.fr       */
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

/* When a key is pressed, the player is moved */
void	aux_ending_situations(mlx_key_data_t keydata, t_map *map_data)
{
    int		player_x;
    int		player_y;
    int		exit_x;
    int		exit_y;

    player_x = map_data->p_player->x;
    player_y = map_data->p_player->y;
	exit_x = map_data->p_exit->x;
    exit_y = map_data->p_exit->y;

    // Este bloque es independiente
    if (keydata.key == MLX_KEY_ESCAPE) {
        end_game();
    }

	if (map_data->collectibles == 0) {
        if (mlx_image_to_window(map_data->mlx, map_data->exit, exit_x * 64, exit_y * 64) < 0)
		{
            ft_error("Error\nImage couldn't be printed: EXIT\n", 14);
        }
    }
    if (map_data->collectibles == 0 && player_x == exit_x && player_y == exit_y) {
        ft_printf("Congrats!! You won!\n");
        end_game();
    }
}

// Detectar la tecla presionada
void detect_key(mlx_key_data_t keydata, void *param)
{
    t_map *map_data = (t_map *)param;
    if (keydata.action != MLX_PRESS)
        return;

    if (keydata.key == MLX_KEY_W
    && map_data->map[map_data->p_player->y - 1][map_data->p_player->x] != '1') {
        move_up(map_data);
    }

    if (keydata.key == MLX_KEY_S
    && map_data->map[map_data->p_player->y + 1][map_data->p_player->x] != '1') {
        move_down(map_data);
    }

    if (keydata.key == MLX_KEY_D
    && map_data->map[map_data->p_player->y][map_data->p_player->x + 1] != '1') {
        move_right(map_data);
    }

    if (keydata.key == MLX_KEY_A
    && map_data->map[map_data->p_player->y][map_data->p_player->x - 1] != '1') {
        move_left(map_data);
    }

    aux_ending_situations(keydata, map_data);
}



