/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkucharo <dkucharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 20:16:47 by dkucharo          #+#    #+#             */
/*   Updated: 2026/03/16 16:16:44 by dkucharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_join_buffer(char *left_c, char *buffer)
{
	char	*res;

	if (!left_c)
	{
		left_c = malloc(1 * sizeof(char));
		if (!left_c)
			return NULL;
		left_c[0] = '\0';
	}
	if (!buffer)
		return NULL;
	res = ft_strjoin(left_c, buffer);
	if (!res)
		return (NULL);
	free(left_c);
	return (res);
}
//fills the line buffer
// reads the BUFFER_SIZE chars in each iter till \n or \0 in the line buffer
// each time checks for data in the left_c buffer - if there is, it appends the
// new read chars to it; if not, it duplicates the content of the read buffer 
// into the left_c buffer. if \n is found, it breaks out of the loop and returns
// the left_c buffer after appending the read chars to it

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
			return (NULL);
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
// takes buffer as a parameter, reads it till \n or \0
// sets at the end of the line_buffer a \0 
// returns a substring(left c) from the end of the line to the end of the buffer

static char	*set_line(char *line_buffer)
{
	char	*left_c;
	size_t	i;
	size_t	buffer_len;

	i = 0;
	buffer_len = ft_strlen(line_buffer);
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\0')
		return (NULL);
	left_c = ft_substr(line_buffer, i + 1, buffer_len - (i + 1));
	if (!left_c)
		return (NULL);
	if (*left_c == 0)
	{
		free(left_c);
		left_c = NULL;
	}
	line_buffer[i + 1] = '\0';
	return (left_c);
}

//check for wrong malloc etc
// calls fill_line_buffer to read in the fd till \n or \0
// when variable is filled, free the buffer
// after we set_line and return the line, storing the return value of 
// set_line in a static variable - so next tume we call the get_next_line 
// we have access to the first char of the line that may have been read before

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left_c);
		free(buffer);
		left_c = NULL;
		return (NULL);
	}
	line = fill_line_buffer(fd, left_c, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		free(left_c);
		left_c = NULL;
		return (NULL);
	}
	left_c = set_line(line);
	return (line);
}
