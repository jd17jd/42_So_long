/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:31:02 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/26 16:57:26 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	disable_images(t_map *map_data, int x, int y)
{
	int	i;

	i = 0;
	while (i < map_data->total_collectibles
		&& !(map_data->collect[i].position->x == x
			&& map_data->collect[i].position->y == y))
		i++;
	if (i < map_data->total_collectibles)
		map_data->collect[i].image->enabled = false;
	map_data->collectibles--;
}

int	end_game(void)
{
	exit (0);
	return (0);
}

/* Shows the exit image when required & enables the winning exit of the game */
void	aux_ending_situations(mlx_key_data_t keydata, t_map *map)
{
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	void	*exit;

	player_x = map->p_player->x;
	player_y = map->p_player->y;
	exit_x = map->p_exit->x;
	exit_y = map->p_exit->y;
	exit = map->exit;
	if (keydata.key == MLX_KEY_ESCAPE)
		end_game();
	if (map->collectibles == 0)
	{
		if (mlx_image_to_window(map->mlx, exit,
				exit_x * SIZE, exit_y * SIZE) < 0)
			ft_error("Error\nImage couldn't be printed: EXIT\n", 14);
	}
	if (map->collectibles == 0 && player_x == exit_x && player_y == exit_y)
	{
		ft_printf("Congrats!! You won!\n");
		end_game();
	}
}
