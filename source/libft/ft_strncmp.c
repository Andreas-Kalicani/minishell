/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:21:46 by tienshi           #+#    #+#             */
/*   Updated: 2023/10/09 11:48:06 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/// @brief Compares the ascii value of char* s1 with char* s2
/// @param s1 
/// @param s2 
/// @param n 
/// @return int greater, equal to or smaller than 0 ;
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (!s1[i] || !s2[i])
		{
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		}
		if ((unsigned char) s1[i] > (unsigned char) s2[i])
		{
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		}
		else if ((unsigned char) s1[i] < (unsigned char) s2[i])
		{
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		}
		else
		{
			i++;
		}
	}
	return (0);
}
