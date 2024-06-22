/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:13:23 by tienshi           #+#    #+#             */
/*   Updated: 2023/10/11 15:10:47 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

/// @brief Finds char* s2 in char* s1 with no more than n char searched
/// @param s1 
/// @param s2 
/// @param n 
/// @return char* to the first char* s2 included ; returns NULL on error
char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (*s2 == '\0')
		return ((char *)s1);
	i = 0;
	while (i < n && s1[i])
	{
		j = 0;
		while (((s2[j] && s1[i]) && s2[j] == s1[i]) && i < n)
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)&s1[i - j]);
		i = i - j + 1;
	}
	return (NULL);
}
