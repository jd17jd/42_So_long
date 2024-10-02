/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:51:29 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/02 12:27:09 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	number_lines(int fd)
{
	char	*line;
	int		line_count;

	line = get_next_line(fd);
	line_count = 0;
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

char	**file_to_array(t_map *map_data, int fd)
{
	int		i;
	char	**res;
	char	*line;
	int		lines;

	lines = number_lines(fd);
	fd = open(map_data->path_name, O_RDONLY);
	res = ft_calloc((lines + 1), sizeof(char *));
	if (!res)
		ft_error("Error\nUnable to allocate memory\n", 5);
	line = get_next_line(fd);
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

void	check_size(char **map)
{
	int		i;
	size_t	col_size;

	col_size = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != col_size)
			ft_error("Error\nThe map is not rectangular\n", 7);
		i++;
	}
}

void	aux_check_number(char **map, int player, int exit, int objects)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] == 'P')
				player++;
			else if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'C')
				objects++;
			j++;
		}
		i++;
	}
	if (player != 1)
		ft_error("Error\nThere must be exactly one player\n", 8);
	if (exit != 1)
		ft_error("Error\nThere must be exactly one exit\n", 8);
	if (objects == 0)
		ft_error("Error\nThere must be at least one collectible\n", 8);
}

void	check_number_cells(char **map)
{
	int	player;
	int	exit;
	int	objects;

	player = 0;
	exit = 0;
	objects = 0;
	aux_check_number(map, player, exit, objects);
}
