/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:21:57 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/13 04:32:30 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/so_long.h"

void	check_args(int argc, char* filename)
{
	int len;

	if (argc != 2)
		ft_error("Error\nIncorrect number of arguments\n", 1);
	len = ft_strlen(filename);
	if (ft_strncmp(filename + (len - 4), ".ber", 4) != 0)
		ft_error("Error\nIncorrect file extension\n", 1);
}

int	main(int argc, char** argv)
{
	t_map	map;

    check_args(argc, argv[1]);
	parse(argv[1], &map);
	
    return (0);
}