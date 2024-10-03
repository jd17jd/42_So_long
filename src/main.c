/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:21:57 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/04 01:23:02 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_args(int argc, char *filename)
{
	int	len;

	if (argc != 2)
		ft_error("Error\nIncorrect number of arguments\n", 1);
	len = ft_strlen(filename);
	if (ft_strncmp(filename + (len - 4), ".ber", 4) != 0)
		ft_error("Error\nIncorrect file extension\n", 1);
}

int	main(int argc, char **argv)
{
	t_map	map_data;
	char	*map_name;

	if (argc < 2)
		return (0);
	map_name = argv[1];
	check_args(argc, map_name); //CHECKEO ARGUMENTOS
	parse(map_name, &map_data); //PARSEO ENTRADA
	init_image(&map_data); //INICIALIZACION DE GRAFICOS
	
	free(map_data.p_player); //LIBEROO POS.JUGADOR
	free(map_data.area); //LIBERO AREA
	
	free(map_data.empty);
	free(map_data.wall);
	free(map_data.collect);
	free(map_data.exit);
	free(map_data.player);
	free(map_data.mlx_win);
	free(map_data.mlx);
	
	free_array(map_data.map); //LIBERO MAP
	free(map_data.path_name); //LIBERO PATH
	return (0);
}
