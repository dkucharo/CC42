/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkucharo <dkucharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 20:16:47 by dkucharo          #+#    #+#             */
/*   Updated: 2026/03/24 22:32:27 by dkucharo         ###   ########.fr       */
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
	i = -1;
	while (left_c[++i])
		res[i] = left_c[i];
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
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	if (!line_buffer[i] || !line_buffer[i + 1])
		return (NULL);
	rem = ft_strdup(line_buffer + i + 1);
	if (!rem)
		return (NULL);
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
	if (!line)
	{
		left_c = NULL;
		return (NULL);
	}
	left_c = set_line(line);
	return (line);
}

// main.c
// #include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Cannot open the file!\n");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("Line: %s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return 0;
// }

// test.txt
// Hi this is the first line of this file.
// This is the second line.
// And this is the last line of this file, it has only three lines.
// HAHAHA just kidding, it has four lines.