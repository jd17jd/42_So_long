/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:23:54 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/05 21:09:10 by jvivas-g         ###   ########.fr       */
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
	free(map_data->path_name); //LIBERO PATH
	free_array(map_data->map); //LIBERO MAP
	
	free(map_data->p_player); //LIBERO
	free(map_data->p_exit); //LIBERO
	free(map_data->area); //LIBERO
}
