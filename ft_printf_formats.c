/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielakucharova <danielakucharova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:24:51 by danielakuch       #+#    #+#             */
/*   Updated: 2025/12/04 21:08:32 by danielakuch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_hex(unsigned int hex, char *base)
{
	char	*str_h;
	int		len;

	str_h = ft_utoa_base(hex, base);
	if (!str_h)
		return (0);
	len = ft_strlen(str_h);
	write(1, str_h, len);
	free(str_h);
	return (len);
}

int	ft_print_pointer(void *ptr)
{
	unsigned long	addr;
	char			*str_p;
	int				len;

	addr = (unsigned long)ptr;
	if (ptr == NULL)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	str_p = ft_utoa_base(addr, "0123456789abcdef");
	if (!str_p)
		return (0);
	len = ft_strlen(str_p);
	write (1, "0x", 2);
	write (1, str_p, len);
	free(str_p);
	return (len + 2);
}

int	ft_conversion_handle(char specifier, va_list *args)
{
	if (specifier == 's')
		return (ft_print_string(va_arg(*args, char *)));
	else if (specifier == 'i' || specifier == 'd')
		return (ft_print_integer(va_arg(*args, int)));
	else if (specifier == 'c')
		return (ft_print_char(va_arg(*args, int)));
	else if (specifier == 'u')
		return (ft_print_unsigned(va_arg(*args, unsigned int)));
	else if (specifier == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (specifier == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (specifier == 'p')
		return (ft_print_pointer(va_arg(*args, void *)));
	else if (specifier == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}
