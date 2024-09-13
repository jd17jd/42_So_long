/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 04:06:49 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/13 05:10:55 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/so_long.h"

/*
COMPROBACIONES:
    - 1 salida, >1 objeto, 1 jugador
    - == numero de columns
    - rodeado de muros
    - camino valido
*/
void	check_objects_and_size(char *path)
{
	(void) path;
}

void	check_valid_path(char *path)
{
	(void) path;
}

void	parse(char *filename, t_map *map)
{
	int	fd;
	char *complete_path;

	complete_path = ft_strjoin(PATH_LEVELS, filename);
	map->path = complete_path;
	fd = open(complete_path, O_RDONLY, 0644);
	if (fd < 0)
		ft_error("No such file or directory\n", 3);
	free(complete_path);
	check_objects_and_size(map->path);
	check_valid_path(map->path);
}