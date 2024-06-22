/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:53:53 by tienshi           #+#    #+#             */
/*   Updated: 2023/09/29 21:21:22 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/// @brief Compares memory void* s1 with void* s2 of size n max
/// @param s1 
/// @param s2 
/// @param n 
/// @return int greater, equal, or smaller to 0 ;
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cursors1;
	unsigned char	*cursors2;

	i = 0;
	cursors1 = (unsigned char *) s1;
	cursors2 = (unsigned char *) s2;
	while (i < n)
	{
		if (cursors1[i] > cursors2[i] || cursors1[i] < cursors2[i])
		{
			return (cursors1[i] - cursors2[i]);
		}
		i++;
	}
	return (0);
}
