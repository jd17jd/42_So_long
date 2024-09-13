/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 03:20:33 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/13 03:40:19 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_perror(char *str, int code)
{
	perror(str);
	exit(code);
}

void	ft_error(char *str, int code)
{
	ft_putstr_fd(str, 2);
	exit(code);
}
