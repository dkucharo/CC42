/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielakucharova <danielakucharova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:28:59 by danielakuch       #+#    #+#             */
/*   Updated: 2025/11/26 22:34:50 by danielakuch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The calloc() function contiguously allocates/
// enough space for count objects that are size bytes of memory each and
// returns a pointer to the allocated memory.  
// The allocated memory is filled with bytes of value zero.

// allocates memory and initializes it to zero.

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	if (count == 0 || size == 0)
		return (malloc(1));
	if (size > ((size_t)-1) / count)
		return (NULL);
	total = count * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*ptr;

// 	if (count != 0 && size > SIZE_MAX / count)
//     return (NULL);

// 	ptr = malloc(count * size);
// 	if (!ptr)
// 		return (NULL);
// 	ft_bzero(ptr, count * size);
// 	return (ptr);
// }
