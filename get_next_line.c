/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:33:52 by egoncalv          #+#    #+#             */
/*   Updated: 2022/05/20 17:47:42 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;
	int			read_return;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
	buffer[fd] = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer[fd])
		return (NULL);
	read_return = 1;
	while (read_return != 0 && ft_strchr(buffer[fd], '\n'))
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
	}
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_trim(buffer[fd]);
	return (line);
}

char	*ft_line(char	*buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] != 0 && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

char	*ft_trim(char *buffer)
{
	char	*new;
	int		i;
	int		j

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * BUFFER_SIZE);
	if (!new)
 		return (NULL);
	while (buffer[i] != 0 && buffer[i] != '\n')
		i++;
	while (buffer[i])
	{
		new[j] = buffer[i];
		i++;
		j++;
	}
	free (buffer);
	return (new);
}
