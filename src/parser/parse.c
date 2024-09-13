/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 04:06:49 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/13 16:17:02 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/*
COMPROBACIONES:
    - 1 salida, >1 objeto, 1 jugador
    - == numero de columns
    - rodeado de muros
    - camino valido
*/
int	number_lines(int fd)
{
	char	*line;
	int		line_count;

	line = get_next_line(fd);
	line_count = 0;
	if (!line)
		ft_error("Error\nMap is empty\n", 4);
	while (line)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

char	**file_to_array(char *complete_path, int fd)
{
	int		i;
	char	**res;
	char	*line;
	int		lines;

	lines = number_lines(fd);
	fd = open(complete_path, O_RDONLY);
	// if (fd < 0)
	// 	ft_error("Error\nNo such file or directory\n", 3);
	res = ft_calloc((lines + 1), sizeof(char *));
	if (!res)
		ft_error("Error\nUnable to allocate memory\n", 5);
	line = get_next_line(fd);
	// if (!line)
	// 	ft_error("Error\nMap is empty\n", 4);
	i = 0;
	while (line)
	{
		res[i++] = line;
		line = get_next_line(fd);
	}
	res[i] = NULL;
	close(fd);
	return (res);
}

void	check_conditions_map(char *filename, int fd)
{
	char	**map;

	map = file_to_array(filename, fd);
	(void) map;
	// check_size(map);
	// check_number_objects(map);
	// check_borders(map);
	// check_correct_path(map);
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
