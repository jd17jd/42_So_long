/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:23:54 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/04 21:10:57 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_all(t_map *map_data)
{
	free(map_data->p_player); //LIBEROO POS.JUGADOR
	free(map_data->area); //LIBERO AREA
	
	//LIBERO CARGAS IMAGENES
	free(map_data->empty);
	free(map_data->wall);
	free(map_data->collect);
	free(map_data->exit);
	free(map_data->player);

	//LIBERO PUNTEROS A LIB
	free(map_data->mlx_win);
	free(map_data->mlx);
	
	free_array(map_data->map); //LIBERO MAP
	free(map_data->path_name); //LIBERO PATH
}
