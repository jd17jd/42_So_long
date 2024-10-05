/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 04:06:49 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/05 15:19:02 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/* Opens the file, handles errors, and returns the file descriptor */
int		open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nNo such file or directory\n", 3);
	return (fd);
}

/* Aux function for file_to_array */
int	aux_number_lines(int fd)
{
	char	*line;
	int		line_count;

	line_count = 0;
	line = get_next_line(fd);
	if (!line)
		ft_error("Error\nMap is empty4\n", 4);
	while (line)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

/* Converts the info located in the file to a 2-dimension array */
char	**aux_file_to_array(t_map *map_data, int fd)
{
	int		i;
	char	**res;
	char	*line;
	int		lines;

	lines = aux_number_lines(fd);
	fd = open_file(map_data->path_name);
	res = ft_calloc((lines + 1), sizeof(char *));
	if (!res)
		ft_error("Error\nMemory allocation failed\n", 5);
	i = 0;
	while ((line = get_next_line(fd)))
	{
		res[i++] = line;
		if (!line && i < lines - 1)
		{
			while (i-- > 0)
				free(res[i]);
			free(res);
			ft_error("Error\nFile reading failed\n", 6);
		}
	}
	close(fd);
	return (res);
}

/* Main function that calls the others */
void	check_conditions_map(t_map *map_data)
{
	check_size(map_data);
	check_number_elts(map_data);
	check_borders(map_data, map_data->area->y - 1, map_data->area->x - 1);
    check_correct_path(map_data);
}

void	parse(char *filename, t_map *map_data)
{
	int		fd;
	char	*complete_path;
	char	**map;

	complete_path = ft_strjoin(PATH_LEVELS, filename);
	map_data->path_name = complete_path; //RESERVO EN ESRUCTURA
	fd = open_file(complete_path);
	map = aux_file_to_array(map_data, fd);
	map_data->map = map; //RESERVO EN ESTRUCTURA
	check_conditions_map(map_data);
	close(fd);
}
