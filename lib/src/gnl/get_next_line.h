/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:18:24 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/13 04:57:48 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

/* BUFFER_SIZE = Bytes to read/write in each iteration of get_next_line() */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_get_line(char *str);
char	*ft_append(int fd, char *stash);
char	*ft_move_start(char *stash);
char	*get_next_line(int fd);

/* AUX FUNCTIONS */
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
#endif