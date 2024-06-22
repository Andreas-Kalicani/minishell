/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:20:11 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/12 11:26:38 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_argv_to_str(int argc, char **argv)
{
	int		i;
	char	*result;
	char	*temp;

	i = 1;
	result = NULL;
	while (argv[i])
	{
		temp = result;
		result = ft_strjoin(result, argv[i]);
		if (temp)
			free(temp);
		if (i < argc && argv[i + 1])
		{
			temp = result;
			result = ft_strjoin(result, " ");
			free(temp);
		}
		i++;
	}
	return (result);
}
