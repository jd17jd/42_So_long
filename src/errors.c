/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 03:20:33 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/06 20:27:29 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Shows error message when required followed by an specific exit code */
void	ft_error(char *str, int code)
{
	ft_putstr_fd(str, 2);
	exit(code);
}
