/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielakucharova <danielakucharova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:28:41 by danielakuch       #+#    #+#             */
/*   Updated: 2025/11/23 16:28:43 by danielakuch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if (!(char)c)
		return ((char *)s);
	return ((char *)last);
}

// int main(void)
// {
//     char *result = ft_strrchr("abc0deaf0", 'a');
//     if (result)
//         printf("%s\n", result);
//     return 0;
// }
