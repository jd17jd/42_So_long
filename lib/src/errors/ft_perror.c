/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:31:54 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/07 18:42:25 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * Shows a system error message (from perror) followed by an exit code
 * @param str String with a custom message to prefix the system error
 * @param code Exit code
 */
void	ft_perror(char *str, int code)
{
	perror(str);
	exit(code);
}
