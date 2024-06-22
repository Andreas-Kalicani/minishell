/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:49:04 by tienshi           #+#    #+#             */
/*   Updated: 2023/10/11 14:19:01 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/// @brief Fills void *dest with void* src of size n
/// @param dest 
/// @param src 
/// @param n 
/// @return void* dest filled with void* src ;
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	if (!s && !d)
		return (NULL);
	while (i != n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
