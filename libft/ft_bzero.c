/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielakucharova <danielakucharova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:50:52 by danielakuch       #+#    #+#             */
/*   Updated: 2025/11/24 22:30:51 by danielakuch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//sets a block of memory to zero
// memory s gets 0 in n bytes

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
