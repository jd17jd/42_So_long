/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:33:48 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/05 02:53:30 by jvivas-g         ###   ########.fr       */
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

/* Structure for the representation of a coordenate */
typedef struct	s_point
{
	int x;
	int y;
} t_point;


/* Structure for the state of the map */
typedef struct s_map
{
	void	*mlx; /* Conexion con la minilibx */
	void	*mlx_win; /* Pointer to the window where the game is renderized */
	char	*path_name; /* Ya inicializado */
	char	**map; /* Ya inicializado */
	t_point	*p_player; /* Ya inicializado (NO liberado)*/
	t_point	*area; /* Ya inicializado (NO liberado)*/
	void	*empty;
	void	*wall;
	void	*collect;
	void	*exit;
	void	*player;
	int		moves;
	int		collectibles;
}	t_map;

/* Errors */
void	ft_perror(char *str, int code);
void	ft_error(char *str, int code);

/* Free */
void	free_array(char **array);
void	free_all(t_map *map_data);

/* Init */
void	load_images_1(t_map *map_data);
void	load_images_2(t_map *map_data);
void	all_empty(t_map *map_data);
void	select_image(int col, int row, t_map *map_data);
void	print_images(t_map *map_data);
void	init_image(t_map *map_data);

/* Keys */
void	move_up(t_map *map_data);
void	move_down(t_map *map_data);
void	move_right(t_map *map_data);
void	move_left(t_map *map_data);
void	aux_ending_situations(mlx_key_data_t keydata, t_map *map_data);
void	detect_key(mlx_key_data_t keydata, void *param);

/* Parse */
int		open_file(char *path);
int		aux_number_lines(int fd);
char	**aux_file_to_array(t_map *map_data, int fd);
void	check_conditions_map(t_map *map_data);
void	parse(char *filename, t_map *map_data);

/* Utils_1 */
void	check_size(t_map *map_data);
void	aux_quan_elts(t_map *map_data, int player, int exit, int collectibles);
void	aux_errors_elts(int player, int exit, int collectibles);
void	check_number_elts(t_map *map_data);

/* Utils_2 */
void	check_borders(t_map *map_data, int last_row, int last_col);
void	aux_fill(char **map, t_point *size, t_point *begin, char objective);
int		aux_flood_fill(char **map, t_point *size, t_point *begin);
void	check_correct_path(t_map *map_data);

/* Utils_3 */
char 	**aux_duplicate_map(char **map);
void	aux_player_position(t_map *map_data, int *player_x, int *player_y);
int		aux_number_elts(char **map, t_point *size, char obj1, char pbj2);

#endif