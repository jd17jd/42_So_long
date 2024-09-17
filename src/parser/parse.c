/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 04:06:49 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/17 23:10:35 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	check_conditions_map(t_map *map_data, int fd)
{
	char	**map;

	map = file_to_array(map_data, fd);
	map_data->map = map; //METO MAP
	check_size(map_data->map);
	check_number_cells(map_data->map);
	check_borders(map_data);
	
	// Verificar si existe un camino
    if (!check_correct_path(map_data))
        ft_error("Error\nThere's no vallid path from P to E\n", 10);
	// free_array(map);
}

void	parse(char *filename, t_map *map_data)
{
	int		fd;
	char	*complete_path;

	complete_path = ft_strjoin(PATH_LEVELS, filename);
	map_data->path_name = complete_path; //METO PATH
	fd = open(map_data->path_name, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nNo such file or directory\n", 3);
	check_conditions_map(map_data, fd);
	free(complete_path);
}
