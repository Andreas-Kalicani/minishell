/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunsigneddecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:36:35 by stripet           #+#    #+#             */
/*   Updated: 2023/11/14 09:03:30 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	nb_len(unsigned int c)
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

int	printunsigneddecimal(unsigned int c)
{
	unsigned int	temp;

	temp = 0;
	if (c >= 10)
	{
		printunsigneddecimal(c / 10);
		printunsigneddecimal(c % 10);
	}
	else
	{
		temp = '0' + (c % 10);
		write(1, &temp, 1);
	}
	return (nb_len(c));
}
