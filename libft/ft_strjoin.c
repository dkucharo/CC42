/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielakucharova <danielakucharova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:52:36 by danielakuch       #+#    #+#             */
/*   Updated: 2025/11/26 22:23:04 by danielakuch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates memory (using malloc(3)) and returns a
// new string, which is the result of concatenating
// ’s1’ and ’s2’.

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	len1;
// 	size_t	len2;
// 	char	*result;
// 	size_t	i;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
// 	if (!result)
// 		return (NULL);
// 	i = 0;
// 	while (i < len1)
// 	{
// 		result[i] = s1[i];
// 		i++;
// 	}
// 	i = 0;
// 	while (i < len2)
// 	{
// 		result[len1 + i] = s2[i];
// 		i++;
// 	}
// 	result[len1 + len2] = '\0';
// 	return (result);
// }

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[i - len1])
	{
		result[i] = s2[i - len1];
		i++;
	}
	result[i] = '\0';
	return (result);
}
