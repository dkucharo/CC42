/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkucharo <dkucharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 20:16:47 by dkucharo          #+#    #+#             */
/*   Updated: 2026/03/23 18:22:04 by dkucharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_join_buffer(char *left_c, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!left_c)
		return (ft_strdup(buffer));
	res = malloc(sizeof(char) * (ft_strlen(left_c) + ft_strlen(buffer) + 1));
	if (!res)
	{
		free(left_c);
		return (NULL);
	}
	i = 0;
	while (left_c[i])
	{
		res[i] = left_c[i];
		i++;
	}
	j = 0;
	while (buffer[j])
		res[i++] = buffer[j++];
	res[i] = '\0';
	free(left_c);
	return (res);
}

static char	*fill_line_buffer(int fd, char *left_c, char *buffer)
{
	ssize_t	b_read;

	if (left_c && ft_strchr(left_c, '\n'))
		return (left_c);
	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(left_c);
			return (NULL);
		}
		if (b_read == 0)
			break ;
		buffer[b_read] = '\0';
		left_c = ft_join_buffer(left_c, buffer);
		if (!left_c)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

static char	*set_line(char *line_buffer)
{
	char	*rem;
	size_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\0')
		return (NULL);
	rem = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (!rem)
		return (NULL);
	if (*rem == '\0')
	{
		free(rem);
		rem = NULL;
	}
	line_buffer[i + 1] = '\0';
	return (rem);
}

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, left_c, buffer);
	free(buffer);
	if (!line || *line == '\0')
	{
		free(left_c);
		left_c = NULL;
		return (NULL);
	}
	left_c = set_line(line);
	return (line);
}