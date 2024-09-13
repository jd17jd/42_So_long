/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 04:06:49 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/13 21:33:30 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	check_conditions_map(char *filename, int fd)
{
	char	**map;

	map = file_to_array(filename, fd);
	check_size(map);
	check_number_cells(map);
	check_borders(map);
	// check_correct_path(map);
	// free_array(map);
}

void	parse(char *filename)
{
	int		fd;
	char	*complete_path;

	complete_path = ft_strjoin(PATH_LEVELS, filename);
	fd = open(complete_path, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nNo such file or directory\n", 3);
	check_conditions_map(complete_path, fd);
	free(complete_path);
}
