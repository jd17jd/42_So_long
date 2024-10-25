/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:34:37 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/18 03:04:27 by jvivas-g         ###   ########.fr       */
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
	
	
	map_data->collect = ft_calloc(map_data->collectibles, sizeof(mlx_image_t*));
    if (!map_data->collect)
        ft_error("Error\nMemory allocation failed\n", 1);
	i = 0;
	while (i < map_data->collectibles)
	{
		collect_texture = mlx_load_png(COLLECT);
		if (!collect_texture)
       		ft_error("Error\nImage couldn't be opened: COLLECT\n", 13);
		
		map_data->collect[i] = mlx_texture_to_image(map_data->mlx, collect_texture);
		if (!map_data->collect[i])
			ft_error("Error\nImage couldn't be created: COLLECT\n", 14);
		i++;

		mlx_delete_texture(collect_texture);
	}
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

/* Fills all the window with empty cells for the background */
void	all_empty(t_map *map_data, int rows, int cols)
{
	int		i;
	int		j;
	void	*empty;
	void	*mlx;

	empty = map_data->empty;
	mlx = map_data->mlx;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (mlx_image_to_window(mlx, empty, i * 64, j * 64) < 0)
				ft_error("Error\nImage couldn't be printed: EMPTY\n", 14);
			j++;
		}
		i++;
	}
}

/* Selects an image and a position in order to print it there */
void	select_image(int col, int row, t_map *map_data)
{
	void	*wall;
	void	*player;
	void	*mlx;
	int		collect_index; 

	wall = map_data->wall;
	player = map_data->player;
	mlx = map_data->mlx;
	collect_index = 0;
	if (map_data->map[row][col] == '1')
	{
		if (mlx_image_to_window(mlx, wall, col * 64, row * 64) < 0)
			ft_error("Error\nImage couldn't be printed: WALL\n", 14);
	}
	if (map_data->map[row][col] == 'P')
	{
		if (mlx_image_to_window(mlx, player, col * 64, row * 64) < 0)
			ft_error("Error\nImage couldn't be printed: PLAYER\n", 14);
	}
	if (map_data->map[row][col] == 'C') {
        if (mlx_image_to_window(mlx, map_data->collect[collect_index], col * 64, row * 64) < 0)
            ft_error("Error\nImage couldn't be printed: COLLECT\n", 14);
        collect_index++;  // Incrementa el índice para la siguiente instancia
    }
}

/* Prints all the images loaded on the window */
void	print_images(t_map *map_data)
{
	int		i;
	int		j;
	int		rows;
	int		cols;

	rows = map_data->area->y;
	cols = map_data->area->x;
	i = 0;
	all_empty(map_data, cols, rows);
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			select_image(j, i, map_data);
			j++;
		}
		i++;
	}
}
