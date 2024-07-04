/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:28:26 by tienshi           #+#    #+#             */
/*   Updated: 2024/07/01 16:04:30 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/utils.h"

char	*redirect_extract(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if ((string[i] != '<' && string[i] != '>') && !ft_isspace(string[i]))
			break ;
		i++;
	}
	return (&(string[i]));
}
