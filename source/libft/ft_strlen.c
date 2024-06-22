/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:48:46 by tienshi           #+#    #+#             */
/*   Updated: 2023/11/14 08:38:34 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/// @brief Calculates the size of char* s
/// @param s 
/// @return int equal to the length of s terminating \0 not included ;
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}
