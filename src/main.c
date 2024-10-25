/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:21:57 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/14 22:57:00 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Allocates memory for the objects in the struct */
void	allocate_mem(t_map *map_data)
{
	map_data->p_player = (t_point *)ft_calloc(1, sizeof(t_point));
	if (!map_data->p_player)
		ft_error("Error\nMemory allocation failed\n", 1);
	map_data->p_exit = (t_point *)ft_calloc(1, sizeof(t_point));
	if (!map_data->p_exit)
		ft_error("Error\nMemory allocation failed\n", 1);
	map_data->area = (t_point *)ft_calloc(1, sizeof(t_point));
	if (!map_data->area)
		ft_error("Error\nMemory allocation failed\n", 1);
}

/* Checks the number and the extension of the arguments */
void	check_args(int argc, char *filename)
{
	int	len;

	if (argc != 2)
		ft_error("Error\nIncorrect number of arguments\n", 2);
	len = ft_strlen(filename);
	if (ft_strncmp(filename + (len - 4), ".ber", 4) != 0)
		ft_error("Error\nIncorrect file extension\n", 2);
}

/* Evaluates whether the entry map is correct or not */
void	parse(char *filename, t_map *map_data)
{
	int		fd;
	char	*complete_path;
	char	**map;

	complete_path = ft_strjoin(PATH_LEVELS, filename);
	map_data->path_name = complete_path;
	fd = open_file(complete_path);
	map = aux_file_to_array(complete_path, fd);
	map_data->map = map;
	check_conditions_map(map_data);
	close(fd);
}

/* Initiates the window game */
void	init_image(t_map *map_data)
{
	int	width;
	int	height;

	width = map_data->area->x * 64;
	height = map_data->area->y * 64;
	map_data->mlx = mlx_init(width, height, "PAC-MAN", true);
	if (!map_data->mlx)
		ft_error("Error\nImpossible to initiate the lib\n", 12);
	map_data->mlx_win = mlx_new_image(map_data->mlx, width, height);
	if (!map_data->mlx_win)
		ft_error("Error\nImpossible to initiate the window\n", 13);
	load_images_1(map_data);
	load_images_2(map_data);
	print_images(map_data);
}

int	main(int argc, char **argv)
{
	t_map	map_data;
	char	*map_name;

	if (argc < 2)
		return (0);
	map_data.moves = 0;
	allocate_mem(&map_data);
	map_name = argv[1];
	check_args(argc, map_name);
	parse(map_name, &map_data);
	init_image(&map_data);
	mlx_key_hook(map_data.mlx, detect_key, &map_data);
	mlx_loop(map_data.mlx);
	mlx_terminate(map_data.mlx);
	free_all(&map_data);
	
	return (0);
}
