/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:21:57 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/05 21:09:14 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Allocates memory for the objects in the struct */
void	allocate_mem(t_map *map_data)
{
	map_data->p_player = (t_point *)ft_calloc(1, sizeof(t_point)); //RESERVO
	if (!map_data->p_player)
		ft_error("Error\nMemory allocation failed\n", 1);
	map_data->p_exit = (t_point *)ft_calloc(1, sizeof(t_point)); //RESERVO
	if (!map_data->p_exit)
		ft_error("Error\nMemory allocation failed\n", 1);
	map_data->area = (t_point *)ft_calloc(1, sizeof(t_point)); //RESERVO
	if (!map_data->area)
		ft_error("Error\nMemory allocation failed\n", 1);
}

void	check_args(int argc, char *filename)
{
	int	len;

	if (argc != 2)
		ft_error("Error\nIncorrect number of arguments\n", 2);
	len = ft_strlen(filename);
	if (ft_strncmp(filename + (len - 4), ".ber", 4) != 0)
		ft_error("Error\nIncorrect file extension\n", 2);
}

int	main(int argc, char **argv)
{
	t_map	map_data;
	char	*map_name;

	if (argc < 2)
		return (0);
	allocate_mem(&map_data);
	map_name = argv[1];
	check_args(argc, map_name);
	parse(map_name, &map_data);
	map_data.moves = 0;
	init_image(&map_data);
	mlx_key_hook(map_data.mlx, detect_key, &map_data);
	mlx_loop(map_data.mlx);
	mlx_terminate(map_data.mlx);
	free_all(&map_data);
	return (0);
}
