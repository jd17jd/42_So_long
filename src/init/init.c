/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:34:37 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/26 15:46:40 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/* Converts the textures to images and stores it in the data structures */
void	load_images_1(t_map *map_data)
{
	int				i;
	mlx_texture_t	*empty_texture;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*collect_texture;

	empty_texture = mlx_load_png(EMPTY);
	if (!(empty_texture))
		ft_error("Error\nImage couldn't be opened: EMPTY\n", 13);
	map_data->empty = mlx_texture_to_image(map_data->mlx, empty_texture);
	mlx_delete_texture(empty_texture);
	wall_texture = mlx_load_png(WALL);
	if (!wall_texture)
		ft_error("Error\nImage couldn't be opened: WALL\n", 13);
	map_data->wall = mlx_texture_to_image(map_data->mlx, wall_texture);
	mlx_delete_texture(wall_texture);
	collect_texture = mlx_load_png(COLLECT);
	if (!collect_texture)
		ft_error("Error\nImage couldn't be opened: COLLECT\n", 13);
	i = 0;
	while (i < map_data->total_collectibles)
		map_data->collect[i++].image
			= mlx_texture_to_image(map_data->mlx, collect_texture);
	mlx_delete_texture(collect_texture);
}

/* Continuation */
void	load_images_2(t_map *map_data)
{
	mlx_texture_t	*exit_texture;
	mlx_texture_t	*player_texture;

	exit_texture = mlx_load_png(EXIT);
	if (!exit_texture)
		ft_error("Error\nImage couldn't be opened: EXIT\n", 13);
	map_data->exit = mlx_texture_to_image(map_data->mlx, exit_texture);
	mlx_delete_texture(exit_texture);
	player_texture = mlx_load_png(PLAYER);
	if (!player_texture)
		ft_error("Error\nImage couldn't be opened: PLAYER\n", 13);
	map_data->player = mlx_texture_to_image(map_data->mlx, player_texture);
	mlx_delete_texture(player_texture);
}
