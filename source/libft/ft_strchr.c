/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:15:06 by tienshi           #+#    #+#             */
/*   Updated: 2023/10/03 01:53:34 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

/// @brief Finds the first occurence of char c in char* s
/// @param s 
/// @param c 
/// @return char* to the first char c included ; returns NULL on error
char	*ft_strchr(const char *s, int c)
{
	char	*cursor;

	cursor = (char *) s;
	while (*cursor)
	{
		if (*cursor == (char) c)
		{
			return (cursor);
		}
		else
		{
			cursor++;
		}
	}
	if ((char) c == '\0')
		return (cursor);
	return (NULL);
}
