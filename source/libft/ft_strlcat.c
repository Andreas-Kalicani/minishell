/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 01:59:17 by tienshi           #+#    #+#             */
/*   Updated: 2023/10/11 11:55:23 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/// @brief Adds char* src at the end of char* dst with
/// siz as the total size of char* dst
/// @param dst 
/// @param src 
/// @param siz 
/// @return int eyqal to the length of the string it tried to create ;
size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i[4];

	i[0] = ft_strlen(dst);
	i[1] = ft_strlen(src);
	i[2] = 0;
	i[3] = 0;
	if (siz > i[0])
		i[2] = i[1] + i[0];
	else
		i[2] = i[1] + siz;
	while (src[i[3]] && (i[0] + 1) < siz)
	{
		dst[i[0]] = src[i[3]];
		i[0]++;
		i[3]++;
	}
	dst[i[0]] = '\0';
	return (i[2]);
}
