/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:57:13 by tienshi           #+#    #+#             */
/*   Updated: 2023/10/10 17:06:33 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/// @brief Finds the last occurence of char c in char* s
/// @param s 
/// @param c 
/// @return char* to the last occurence of char c in char* s included 
///; returns NULL on error
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*cursor;

	i = ft_strlen(s);
	cursor = (char *) s;
	while (i >= 0)
	{
		if (cursor[i] == (char) c)
		{
			return (cursor + i);
		}
		i--;
	}
	return (NULL);
}
