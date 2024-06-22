/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:29:41 by tienshi           #+#    #+#             */
/*   Updated: 2023/10/04 19:07:46 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

/// @brief Allocates memory of size_t nmemb numbers of rows of size size_t size
/// @param nmemb 
/// @param size 
/// @return void* pointer with memory allocated and set to 0 ;
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*buffer;
	size_t	s;

	s = nmemb * size;
	buffer = (char *) malloc(s);
	if (!buffer)
		return (NULL);
	else
	{
		ft_bzero(buffer, s);
		return (buffer);
	}
}
