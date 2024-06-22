/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:44:07 by tienshi           #+#    #+#             */
/*   Updated: 2023/09/21 16:27:11 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/// @brief Fills char* s with int c of length n
/// @param s 
/// @param c 
/// @param n 
/// @return char* s after filling ;
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*cursor;

	i = 0;
	cursor = s;
	while (i < n)
	{
		cursor[i] = c;
		i++;
	}
	return (s);
}
