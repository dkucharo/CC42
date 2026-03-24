/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkucharo <dkucharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 20:33:57 by dkucharo          #+#    #+#             */
/*   Updated: 2026/03/24 22:31:10 by dkucharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Cannot open the file!\n");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line: %s", line);
		free(line);
	}
	close(fd);
	return 0;
}