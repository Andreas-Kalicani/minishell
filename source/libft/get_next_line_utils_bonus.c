/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:10:38 by tienshi           #+#    #+#             */
/*   Updated: 2023/11/14 08:39:02 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils copy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:11:35 by tienshi           #+#    #+#             */
/*   Updated: 2023/10/25 16:11:35 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*line_extract(char **str)
{
	int		i;
	char	*buffer;
	void	*temp;

	i = 0;
	if (!str || !*str)
		return (NULL);
	while ((*str)[i])
	{
		if ((*str)[i] == '\n')
		{
			buffer = ft_substr(*str, 0, i + 1);
			temp = (char *) *str;
			*str = ft_substr(*str, i + 1, ft_strlen(*str) - (i + 1));
			free(temp);
			return (buffer);
		}
		i++;
	}
	buffer = *str;
	*str = NULL;
	return (buffer);
}
