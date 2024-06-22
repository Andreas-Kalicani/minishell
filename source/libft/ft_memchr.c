/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:25:45 by tienshi           #+#    #+#             */
/*   Updated: 2023/10/11 12:52:21 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/// @brief Search for int c out of max n byes of memory from void* s
/// @param s 
/// @param c 
/// @param n 
/// @return Returns pointer to memory adress of int c : returns NULL on error
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;
	size_t			i;

	chr = c;
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == chr)
		{
			return ((void *)&s[i]);
		}
		else
		{
			i++;
		}
	}
	return (NULL);
}
