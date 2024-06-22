/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:47:07 by tienshi           #+#    #+#             */
/*   Updated: 2023/10/13 15:45:52 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

static size_t	ft_countt(char *s, char c)
{
	int	count;
	int	trigger;

	count = 0;
	trigger = 0;
	while (s && *s)
	{
		if (*s != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (*s == c)
		{
			trigger = 0;
		}
		s++;
	}
	return (count);
}

static char	*ft_tokken_extract(char *s, size_t start, size_t end)
{
	char	*buffer;
	size_t	i;
	size_t	length;

	i = 0;
	length = end - start;
	buffer = (char *) malloc((length + 1) * sizeof(char));
	if (!s || !buffer)
	{
		return (NULL);
	}
	while (i < length)
	{
		buffer[i] = s[start];
		i++;
		start++;
	}
	buffer[i] = '\0';
	return (buffer);
}

/// @brief Splits char* s1 with char c as delimiters
/// @param s1 
/// @param c 
/// @return char** of the splited char* s1 : returns NULL on error
char	**ft_split(const char *s1, char c)
{
	char	**buffer;
	int		i1;
	size_t	i2;
	size_t	j;

	i1 = -1;
	i2 = 0;
	j = 0;
	buffer = (char **) malloc((ft_countt((char *) s1, c) + 1) * sizeof(char *));
	if (!buffer || !s1)
		return (NULL);
	while (i2 <= ft_strlen(s1))
	{
		if (s1[i2] != c && i1 < 0)
			i1 = i2;
		else if ((s1[i2] == c || i2 == ft_strlen(s1)) && i1 >= 0)
		{
			buffer[j++] = ft_tokken_extract((char *) s1, i1, i2);
			i1 = -1;
		}
		i2++;
	}
	buffer[j] = NULL;
	return (buffer);
}
