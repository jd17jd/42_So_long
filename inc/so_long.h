/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:33:48 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/13 22:34:49 by jvivas-g         ###   ########.fr       */
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
# include "../lib/src/gnl/get_next_line_bonus.h"
# include "../lib/src/gnl/get_next_line.h"


# define ESC 53
# define A 0
# define S 1
# define D 2
# define W 13
# define PATH_LEVELS "resources/maps/valid/"

/* Structure for the state of the map */
typedef struct s_map
{
	void	*mlx; /* Conexion con la minilibx */
	void	*mlx_win; /* Pointer to the window where the game is renderized */
	char	**map;
	int		rows;
	int		cols;
}	t_map;

/* Errors */
void	ft_perror(char *str, int code);
void	ft_error(char *str, int code);

/* Free */
void	free_array(char **array);

/* Init */
void	init(t_map	*map);

/* Parse */
void	check_conditions_map(char *filename, int fd);
void	parse(char *filename);

/* Utils_2 */
void	aux_check_borders(char **map, int last_row, int last_col);
void	check_borders(char **map);

/* Utils */
int		number_lines(int fd);
char	**file_to_array(char *filename, int fd);
void    check_size(char **map);
void	aux_check_number(char **map, int player, int exit, int objects);
void	check_number_cells(char **map);

#endif