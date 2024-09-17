/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:33:56 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/17 23:14:17 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	aux_check_borders(char **map, int last_row, int last_col)
{
	int	i;

	i = 0;
	while (i <= last_col)
	{
		if (map[0][i] != '1' || map[last_row][i] != '1')
			ft_error("Error\nNot enough walls on the top or bottom\n", 9);
		i++;
	}
	i = 0;
	while (i <= last_row)
	{
		if (map[i][0] != '1' || map[i][last_col] != '1')
			ft_error("Error\nNot enough walls on the sides\n", 9);
		i++;
	}
}
/* Check if the borders are all covered by 1 */
void	check_borders(t_map *map_data)
{
	char	**map = map_data->map;
	int		last_row;
	int		last_col;

	last_row = 0;
	while (map[last_row])
		last_row++;
	map_data->rows = last_row; //METO FILAS MAPA
	last_col = 0;
	while (map[0][last_col])
		last_col++;
	map_data->cols = last_col - 1; //METO COLUMNAS MAPA
	aux_check_borders(map, map_data->rows-1, map_data->cols-1);
}

int	dfs(t_map *map_data, int x, int y) // Comprobar esto
{
	char	**map;
	int		rows;
	int		cols;

	map = map_data->map;
	rows = map_data->rows-1;
	cols = map_data->cols-1;

    if (x < 0 || x >= rows || y < 0 || y >= cols || map[x][y] == '1')
        return (0);
    if (map[x][y] == 'E')
        return (1);
    if (map[x][y] == 'V' || map[x][y] == 'P' || map[x][y] == '0' || map[x][y] == 'C')
        map[x][y] = 'V';
    if (dfs(map_data, x - 1, y))
		return (1); // Arriba
    if (dfs(map_data, x + 1, y))
		return (1); // Abajo
    if (dfs(map_data, x, y - 1))
		return (1); // Izquierda
    if (dfs(map_data, x, y + 1))
		return (1); // Derecha
    return (0); // No se encontró un camino
}

void 	player_position(t_map *map_data, int *player_x, int *player_y)
{
	char	**map;
	int		i;
	int		j;
	int		last_row;
	int		last_col;

	map = map_data->map;
	last_row = map_data->rows-1;
	last_col = map_data->cols-1;
	i = 0;
    while (i <= last_row)
    {
        j = 0;
        while (j <= last_col)
        {
            if (map[i][j] == 'P')
            {
                *player_x = i;
                *player_y = j;
                return;
            }
            j++;
        }
        i++;
    }
}

int	check_correct_path(t_map *map_data)
{
	int	player_x;
	int	player_y;

	player_x = 0;
	player_y = 0;
	player_position(map_data, &player_x, &player_y); //Ya existe jugador previamente
	return (dfs(map_data, player_x, player_y));
}
