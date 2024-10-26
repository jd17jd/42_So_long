/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:45:45 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/26 16:56:14 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

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
			if (mlx_image_to_window(mlx, empty, i * SIZE, j * SIZE) < 0)
				ft_error("Error\nImage couldn't be printed: EMPTY\n", 14);
			j++;
		}
		i++;
	}
}

/* Prints the collectible image in the window */
void	window_collectible(t_map *map_data, int col, int row)
{
	int		i;
	int		found;

	i = 0;
	found = 0;
	while (i < map_data->total_collectibles && !found)
	{
		if (map_data->collect[i].position->x == col
			&& map_data->collect[i].position->y == row)
		{
			if (mlx_image_to_window(map_data->mlx,
					map_data->collect[i].image, col * SIZE, row * SIZE) < 0)
				ft_error("Error\nImage couldn't be printed: COLLECT\n", 14);
			found = 1;
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

	wall = map_data->wall;
	player = map_data->player;
	mlx = map_data->mlx;
	if (map_data->map[row][col] == '1')
	{
		if (mlx_image_to_window(mlx, wall, col * SIZE, row * SIZE) < 0)
			ft_error("Error\nImage couldn't be printed: WALL\n", 14);
	}
	if (map_data->map[row][col] == 'P')
	{
		if (mlx_image_to_window(mlx, player, col * SIZE, row * SIZE) < 0)
			ft_error("Error\nImage couldn't be printed: PLAYER\n", 14);
	}
	if (map_data->map[row][col] == 'C')
		window_collectible(map_data, col, row);
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
