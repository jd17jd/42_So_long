/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:23:54 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/25 18:32:03 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/* Frees map_data objects */
void	free_all(t_map *map_data)
{
	int	i;

	i = 0;
	free(map_data->path_name);
	ft_free_matrix(map_data->map);
	free(map_data->p_player);
	free(map_data->p_exit);
	free(map_data->area);
	while (i < map_data->collectibles)
	{
		free(map_data->collect[i].position);
		i++;
	}
	free(map_data->collect);
}
