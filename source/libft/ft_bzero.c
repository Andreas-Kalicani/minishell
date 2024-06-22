/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:28:16 by tienshi           #+#    #+#             */
/*   Updated: 2023/09/21 16:18:43 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/// @brief Fills void* s with '\0' of size n 
/// @param s 
/// @param n 
/// @return void* s filled with '\0' ;
void	*ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*cursor;

	i = 0;
	cursor = s;
	while (i < n)
	{
		cursor[i] = '\0';
		i++;
	}
	return (s);
}
