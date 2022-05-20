/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:35:42 by egoncalv          #+#    #+#             */
/*   Updated: 2022/05/20 17:48:04 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 255
# endif


char	*get_next_line(int fd);
char	*ft_trim(char *buffer)
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strldup(char *s1, int size);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
