/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 04:06:49 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/18 15:44:15 by jvivas-g         ###   ########.fr       */
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
    check_correct_path(map_data);
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