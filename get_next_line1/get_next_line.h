/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielakucharova <danielakucharova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:21:45 by danielakuch       #+#    #+#             */
/*   Updated: 2025/12/05 16:50:58 by danielakuch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>

static char	*ft_join_buffer(char *left_c, char *buffer);
static char	*fill_line_buffer(int fd, char *left_c, char *buffer);
static char	*set_line(char *line_buffer);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

# endif