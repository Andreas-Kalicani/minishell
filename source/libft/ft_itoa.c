/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:03:40 by tienshi           #+#    #+#             */
/*   Updated: 2023/10/13 13:15:02 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/// @brief Converts int n into char*
/// @param n 
/// @return char* from the conversion of int n ; returns NULL on error
char	*ft_itoa(int n)
{
	char	*buffer;
	int		len;

	len = ft_intlen(n);
	if (n < 0)
		len++;
	buffer = (char *) malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (n == 0)
	{
		*buffer = 48;
		buffer[1] = '\0';
		return (buffer);
	}
	buffer[len--] = '\0';
	while (len >= 0 && n != 0)
	{
		if (n < 0)
			buffer[0] = '-';
		buffer[len] = ft_abs(n % 10) + '0';
		n /= 10;
		len--;
	}
	return (buffer);
}
