/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:57:32 by tienshi           #+#    #+#             */
/*   Updated: 2023/10/13 13:22:00 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static void	ft_fmemmove(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

static void	ft_rmemmove(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = n;
	while (i > 0)
	{
		i--;
		dest[i] = src[i];
	}
}

/// @brief Moves n bytes of the memory of void* src to void* dest
/// disregarding overllap
/// @param dest 
/// @param src 
/// @param n 
/// @return void* dest with the memory from src ; returns NULL on error
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src)
		return (dest);
	if (dest < src)
	{
		ft_fmemmove((char *) dest, (const char *) src, n);
	}
	else if (dest > src)
	{
		ft_rmemmove((char *) dest, (const char *) src, n);
	}
	return (dest);
}
