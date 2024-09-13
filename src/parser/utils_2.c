/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:33:56 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/13 22:36:14 by jvivas-g         ###   ########.fr       */
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

void	check_borders(char **map)
{
	int	last_row;
	int	last_col;

	// Calcular la última fila
	last_row = 0;
	while (map[last_row])
		last_row++;
	last_row--;  // índice de la última fila (ajustar)

	// Calcular la última columna (restar 1 al valor de last_col)
	last_col = 0;
	while (map[0][last_col])
		last_col++;
	last_col--;  // índice de la última columna (ajustar)

	// Debug: imprimir el valor de last_row y last_col
	printf("last_row: %d, last_col: %d\n", last_row, last_col);

	// Llamar a la función para verificar los bordes
	aux_check_borders(map, last_row, last_col);
}
