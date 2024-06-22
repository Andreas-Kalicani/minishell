/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:36:13 by stripet           #+#    #+#             */
/*   Updated: 2024/04/10 13:50:52 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (str[0] == '-')
	{
		if ((ft_strncmp(str, "-2147483648", ft_strlen(str)) > 0
				&& ft_strlen(str) >= 11) || ft_strlen(str) > 11)
			return (0);
	}
	else
	{
		if ((ft_strncmp(str, "2147483647", ft_strlen(str)) > 0
				&& ft_strlen(str) >= 10) || ft_strlen(str) > 10)
			return (0);
	}
	return (1);
}
