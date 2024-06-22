/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdecimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:33:04 by stripet           #+#    #+#             */
/*   Updated: 2023/10/30 13:50:50 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_len(int c)
{
	int	returnvalue;

	returnvalue = 0;
	if (c == 0)
		return (1);
	if (c < 0)
		returnvalue++;
	while (c != 0)
	{
		c /= 10;
		returnvalue++;
	}
	return (returnvalue);
}

int	printdecimal(int c)
{
	int	returnvalue;

	returnvalue = nb_len(c);
	ft_putnbr_fd(c, 1);
	return (returnvalue);
}
