/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:23:54 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/06 20:26:56 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

/* Frees map_data objects */
void	free_all(t_map *map_data)
{
	free(map_data->path_name);
	free_array(map_data->map);
	free(map_data->p_player);
	free(map_data->p_exit);
	free(map_data->area);
}
