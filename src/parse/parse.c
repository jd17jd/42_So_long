/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 04:06:49 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/28 18:00:42 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/* Opens the file, handles errors, and returns the file descriptor */
int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nNo such file or directory\n", 3);
	return (fd);
}

/* Returns the total number of lines of the file */
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
	return (line_count);
}

char	**ft_read_lines(int fd, int lines)
{
	int		i;
	char	**res;
	char	*line;

	res = ft_calloc((lines + 1), sizeof(char *));
	if (!res)
		ft_error("Error\nMemory allocation failed\n", 1);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		res[i++] = line;
		line = get_next_line(fd);
		if (!line && i < lines - 1)
		{
			while (i-- > 0)
				free(res[i]);
			free(res);
			ft_error("Error\nFile reading failed\n", 5);
		}
	}
	return (res);
}

/* Converts the info located in the file to a 2-dimension array */
char	**aux_file_to_array(char *complete_path, int fd)
{
	int		lines;
	char	**res;

	lines = aux_number_lines(fd);
	close(fd);
	fd = open_file(complete_path);
	res = ft_read_lines(fd, lines);
	close(fd);
	return (res);
}

/* Main function that calls all the others */
void	check_conditions_map(t_map *map_data)
{
	check_size(map_data);
	check_number_elts(map_data);
	check_borders(map_data, map_data->area->y - 1, map_data->area->x - 1);
	check_correct_path(map_data);
}
