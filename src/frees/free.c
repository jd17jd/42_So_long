/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:23:54 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/07 19:56:09 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/* Frees map_data objects */
void	free_all(t_map *map_data)
{
	free(map_data->path_name);
	ft_free_matrix(map_data->map);
	free(map_data->p_player);
	free(map_data->p_exit);
	free(map_data->area);
}
