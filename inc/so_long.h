/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:33:48 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/13 05:10:16 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/fcntl.h>
# include <sys/wait.h>
# include "../lib/inc/libft.h"
# include "../minilibx-linux/mlx.h"

# define ESC 53
# define A 0
# define S 1
# define D 2
# define W 13
# define PATH_LEVELS "resources/maps/valid/"

typedef struct s_map
{
	void	*mlx;
    char    *path;
	char	**map;
	int		rows;
	int		cols;
	int		width;
	int		height;
}	t_map;

/* Parse */
void	parse(char *filename, t_map *map);

/* Errors */
void	ft_perror(char *str, int code);
void	ft_error(char *str, int code);

#endif