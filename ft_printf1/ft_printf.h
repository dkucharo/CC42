/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielakucharova <danielakucharova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:45:27 by danielakuch       #+#    #+#             */
/*   Updated: 2025/12/04 20:56:09 by danielakuch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		ft_print_string(char *str);
int		ft_print_char(char c);
int		ft_print_integer(int i);
int		ft_print_unsigned(unsigned int i);
char		*ft_utoa(unsigned int n);
char		*ft_utoa_base(unsigned long h, char *base);
int		ft_print_hex(unsigned int hex, char *base);
int		ft_print_pointer(void *ptr);
int		ft_conversion_handle(char specifier, va_list *args);

#endif