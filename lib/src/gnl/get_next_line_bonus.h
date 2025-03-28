/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:06:50 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/10/07 20:06:34 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# include "../../inc/libft.h"

/* BUFFER_SIZE = Bytes to read/write in each iteration of get_next_line() */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_get_line(char *str);
char	*ft_append(int fd, char *stash);
char	*get_next_line(int fd);

#endif