/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:34:37 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/22 02:49:31 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	load_images_1(t_map *map_data)
{
	mlx_texture_t* empty_texture;
	mlx_texture_t *wall_texture;
	mlx_texture_t *collect_texture;
	
	if (!(empty_texture = mlx_load_png(EMPTY)))
		ft_error("\nImage couldn't be opened: EMPTY!", 13);
	map_data->empty = mlx_texture_to_image(map_data->mlx, empty_texture);
	mlx_delete_texture(empty_texture);

	if (!(wall_texture = mlx_load_png(WALL)))
		ft_error("\nImage couldn't be opened: WALL!", 13);
	map_data->wall = mlx_texture_to_image(map_data->mlx, wall_texture);
	mlx_delete_texture(wall_texture);

	if (!(collect_texture = mlx_load_png(COLLECT)))
		ft_error("\nImage couldn't be opened: COLLECT!", 13);
	map_data->collect = mlx_texture_to_image(map_data->mlx, collect_texture);
	mlx_delete_texture(collect_texture);
}

void	load_images_2(t_map *map_data) {
	mlx_texture_t *exit_texture;
	mlx_texture_t *player_texture;

	if (!(exit_texture = mlx_load_png(EXIT)))
		ft_error("\nImage couldn't be opened: EXIT!", 13);
	map_data->exit = mlx_texture_to_image(map_data->mlx, exit_texture);
	mlx_delete_texture(exit_texture);

	if (!(player_texture = mlx_load_png(PLAYER)))
		ft_error("\nImage couldn't be opened: PLAYER!", 13);
	map_data->player = mlx_texture_to_image(map_data->mlx, player_texture);
	mlx_delete_texture(player_texture);
}

// void	print_images(t_map *map_data)
// {
// 	int		i;
// 	int		j;
// 	char **map;

// 	map = map_data->map;
// 	/*
// 	ME QUEDA:
// 	- Printear todo por primera vez
// 	- Hacer los movimientos
// 	- Hacer el floodfill / dijikstra
// 	*/
// }

void	init_image(t_map *map_data)
{
	int	width;
	int	height;

	width = map_data->cols * 56;
	height = map_data->rows * 56;
	if (!(map_data->mlx = mlx_init(width, height, "PAC-MAN", true)))
		ft_error("Error\nImpossible to initiate the lib\n", 11);
	if (!(map_data->mlx_win = mlx_new_image(map_data->mlx, width, height)))
		ft_error("Error\nImpossible to initiate the window\n", 12);
	load_images_1(map_data);
	load_images_2(map_data);

	// print_images(map_data);
	
	if (mlx_image_to_window(map_data->mlx, map_data->player, 0, 0) < 0)
		ft_error("Error\n", 14);
	
	mlx_loop(map_data->mlx);
}
