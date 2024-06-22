/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:57:43 by tienshi           #+#    #+#             */
/*   Updated: 2023/10/10 11:49:13 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*buffer;
	size_t			len;

	i = 0;
	len = ft_strlen(s);
	buffer = (char *) malloc((len + 1) * sizeof(char));
	if (!buffer || !s)
	{
		return (NULL);
	}
	while (s[i])
	{
		buffer [i] = f(i, s[i]);
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
