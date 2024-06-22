/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:18:15 by tienshi           #+#    #+#             */
/*   Updated: 2023/10/11 13:54:30 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

/// @brief Trimms the string s with start as a starting index
/// and len as a length
/// @param s 
/// @param start 
/// @param len 
/// @return Trimmed char* s of length len ; returns NULL on error
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;
	size_t	c[2];

	c[0] = 0;
	c[1] = ft_strlen(s);
	if (c[1] <= start || !s || len == 0)
		return (ft_calloc(1, 1));
	if (c[1] - start < len)
		buffer = (char *) malloc (sizeof(char) * (c[1] - start + 1));
	if (c[1] - start >= len)
		buffer = (char *) malloc (sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	if (start < c[1])
	{
		while (c[0] < len && s[c[0] + start])
		{
			buffer[c[0]] = s[start + c[0]];
			c[0]++;
		}
	}
	buffer[c[0]] = '\0';
	return (buffer);
}
