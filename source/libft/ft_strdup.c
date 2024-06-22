/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:47:52 by tienshi           #+#    #+#             */
/*   Updated: 2023/09/21 16:30:29 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

/// @brief Duplicates char *s
/// @param s 
/// @return Duplicated char* ; returns NULL on error
char	*ft_strdup(const char *s)
{
	char	*buffer;
	size_t	length;
	size_t	i;

	length = ft_strlen(s);
	i = 0;
	buffer = (char *) malloc(sizeof(char) * (length + 1));
	if (!buffer)
	{
		return (NULL);
	}
	while (s[i])
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
