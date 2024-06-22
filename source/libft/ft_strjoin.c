/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:44:08 by tienshi           #+#    #+#             */
/*   Updated: 2023/09/24 16:29:15 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

/// @brief Joins char* s1 and char* s2 into a new string
/// @param s1 
/// @param s2 
/// @return char* of char* s1 + char# s2 ; returns NULL on error
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	int		i;
	size_t	lens1;
	size_t	lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	buffer = (char *) malloc(sizeof(char) * (lens1 + lens2 + 1));
	i = 0;
	if (!buffer)
		return (NULL);
	while (s1 && *s1)
	{
		buffer[i] = *s1;
		s1++;
		i++;
	}
	while (s2 && *s2)
	{
		buffer[i] = *s2;
		s2++;
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
