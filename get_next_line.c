/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:33:52 by egoncalv          #+#    #+#             */
/*   Updated: 2022/01/22 03:15:10 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *state)
{
	char		*buffer;
	int			read_return;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_return = 1;
	while (read_return != 0 && !ft_strchr(state, '\n'))
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_return] = 0;
		state = ft_strjoin(state, buffer);
	}
	free(buffer);
	return (state);
}

char	*ft_line(char *state)
{
	int		line_size;
	char	*line;

	line_size = 0;
	if (!state)
		return (NULL);
	while (state[line_size] && state[line_size] != '\n')
		line_size++;
	line = ft_strldup(state, line_size);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*state;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	state = ft_read_line(fd, state);
	if (!state)
		return (NULL);
	line = ft_line(state);
	i = 0;
	while (state[i] && state[i] != '\n')
		i++;
	if (!state[i])
	{
		free(state);
		return (NULL);
	}
	ft_bzero(state, i + 1);
	return (line);
}
