/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielakucharova <danielakucharova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:36:06 by danielakuch       #+#    #+#             */
/*   Updated: 2025/12/04 19:59:03 by danielakuch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_string(char *s)
{
	int	res;

	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	res = ft_strlen(s);
	write (1, s, res);
	return (res);
}

int	ft_print_char(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_print_integer(int i)
{
	char	*str_i;
	int		len;

	str_i = ft_itoa(i);
	if (!str_i)
		return (0);
	len = ft_strlen(str_i);
	write (1, str_i, len);
	free (str_i);
	return (len);
}

int	ft_print_unsigned(unsigned int i)
{
	char	*str_i;
	int		len;

	str_i = ft_utoa(i);
	if (!str_i)
		return (0);
	len = ft_strlen(str_i);
	write (1, str_i, len);
	free (str_i);
	return (len);
}
