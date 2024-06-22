/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:48:33 by tienshi           #+#    #+#             */
/*   Updated: 2023/10/10 15:03:10 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

/// @brief Trimms char* set from the start and end of char* s1
/// @param s1 
/// @param set 
/// @return Trimmed char* s1 ;
char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	while (ft_strchr(set, *s1) && *s1)
	{
		s1++;
	}
	i = ft_strlen(s1);
	if (i != 0)
	{
		while (ft_strchr(set, s1[i - 1]))
		{
			i--;
		}
	}
	return (ft_substr(s1, 0, i));
}
