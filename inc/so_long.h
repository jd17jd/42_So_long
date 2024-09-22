/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:33:48 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/22 02:14:36 by jvivas-g         ###   ########.fr       */
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
# include "../MLX42/include/MLX42/MLX42.h"

# define ESC 53
# define A 0
# define S 1
# define D 2
# define W 13

# define EMPTY "resources/sprites/Mandatory/0-Empty/empty.png"
# define WALL "resources/sprites/Mandatory/1-Walls/wall.png"
# define COLLECT "resources/sprites/Mandatory/C-Collect/collect.png"
# define EXIT "resources/sprites/Mandatory/E-Exit-portal/portal.png"
# define PLAYER "resources/sprites/Mandatory/P-Player-pac-man/Moving.png"


# define PATH_LEVELS "resources/maps/valid/"

/* Structure for the state of the map */
typedef struct s_map
{
	void	*mlx; /* Conexion con la minilibx */
	void	*mlx_win; /* Pointer to the window where the game is renderized */
	char	*path_name;
	char	**map;
	int		rows;
	int		cols;
	void	*empty;
	void	*wall;
	void	*collect;
	void	*exit;
	void	*player;
}	t_map;

/* Errors */
void	ft_perror(char *str, int code);
void	ft_error(char *str, int code);

/* Free */
void	free_array(char **array);

/* Init */
void	init_image(t_map *map_data);

/* Parse */
void	check_conditions_map(t_map *map_data, int fd);
void	parse(char *filename, t_map *map_data);

/* Utils_2 */
void	aux_check_borders(char **map, int last_row, int last_col);
void	check_borders(t_map *map_data);
int		dfs(t_map *map_data, int x, int y);
void 	player_position(t_map *map_data, int *player_x, int *player_y);
void	check_correct_path(t_map *map_data);

/* Utils */
int		number_lines(int fd);
char	**file_to_array(t_map *map_data, int fd);
void    check_size(char **map);
void	aux_check_number(char **map, int player, int exit, int objects);
void	check_number_cells(char **map);

#endif