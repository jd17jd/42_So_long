/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:33:48 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/26 16:55:16 by jvivas-g         ###   ########.fr       */
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

# define EMPTY "resources/sprites/Mandatory/0-Empty/empty.png"
# define WALL "resources/sprites/Mandatory/1-Walls/wall.png"
# define COLLECT "resources/sprites/Mandatory/C-Collect/collect.png"
# define EXIT "resources/sprites/Mandatory/E-Exit-portal/portal.png"
# define PLAYER "resources/sprites/Mandatory/P-Player-pac-man/Moving.png"

# define SIZE 64

# define PATH_LEVELS "resources/maps/valid/"

/* Structure for the representation of a coordenate */
typedef struct	s_point
{
	int x;
	int y;
} t_point;

typedef struct	collect
{
	mlx_image_t	*image;
	t_point 	*position;
} collect_info;


/* Structure for the state of the map */
typedef struct s_map
{
	void	*mlx; /* Conexion con la minilibx */
	void	*mlx_win; /* Pointer to the window where the game is renderized */
	char	*path_name; /* Ya inicializado */
	char	**map; /* Ya inicializado */
	t_point	*p_player; /* Ya inicializado */
	t_point	*p_exit; /* Ya inicializado */
	t_point	*area; /* Ya inicializado */
	mlx_image_t 	*empty;
	mlx_image_t 	*wall;
	collect_info	*collect;
	mlx_image_t 	*exit;
	mlx_image_t 	*player;
	int		moves;
	int		collectibles;
	int 	total_collectibles;
}	t_map;

/* free */
void	free_all(t_map *map_data);

/* init_utils */
void	all_empty(t_map *map_data, int rows, int cols);
void	window_collectible(t_map *map_data, int col, int row);
void	select_image(int col, int row, t_map *map_data);
void	print_images(t_map *map_data);

/* init */
void	load_images_1(t_map *map_data);
void	load_images_2(t_map *map_data);

/* keys */
void	move_up(t_map *map_data);
void	move_down(t_map *map_data);
void	move_right(t_map *map_data);
void	move_left(t_map *map_data);
void	detect_key(mlx_key_data_t keydata, void *param);

/* keys_utils */
void	disable_images(t_map *map_data, int x, int y);
int		end_game(void);
void	aux_ending_situations(mlx_key_data_t keydata, t_map *map_data);

/* parse */
int		open_file(char *path);
int		aux_number_lines(int fd);
char	**ft_read_lines(int fd, int lines);
char	**aux_file_to_array(char *complete_path, int fd);
void	check_conditions_map(t_map *map_data);

/* parse_utils_1 */
void	check_size(t_map *map_data);
void	aux_quan_elts(t_map *map_data, int *player, int *exit, int *collect);
void	check_number_elts(t_map *map_data);

/* parse_utils_2 */
void	update_player_pos(t_map *map_data, int i, int j, int *player);
void	update_exit_pos(t_map *map_data, int i, int j, int *exit);
void	update_collectibles_pos(t_map *map_data, int i, int j, int collectible);
void	aux_collects_pos(t_map *map_data);

/* parse_utils_3 */
void	check_borders(t_map *map_data, int last_row, int last_col);
void	aux_fill(char **map, t_point *size, t_point *begin, char objective);
int		aux_number_elts(char **map, t_point *size, char obj1, char obj2);
int		aux_flood_fill(char **map, t_point *size, t_point *begin);
void	check_correct_path(t_map *map_data);

/* main */
void	allocate_mem(t_map *map_data);
void	check_args(int argc, char *filename);
void	parse(char *filename, t_map *map_data);
void	init_image(t_map *map_data);

#endif