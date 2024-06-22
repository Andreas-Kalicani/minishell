/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexadecimalu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:38:28 by stripet           #+#    #+#             */
/*   Updated: 2023/10/30 15:21:57 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hex_len(unsigned long long c)
{
	int	len;

	len = 0;
	if (c == 0)
		return (1);
	while (c != 0)
	{
		len++;
		c = c / 16;
	}
	return (len);
}

static void	printhex(unsigned long long c)
{
	unsigned long long	temp;

	temp = 0;
	if (c == 0)
		write(1, "0", 1);
	else if (c >= 16)
	{
		printhex(c / 16);
		printhex(c % 16);
	}
	else
	{
		if (c <= 9)
		{
			temp = c + '0';
			write (1, &temp, 1);
		}
		else
		{
			temp = c + 'A' - 10;
			write(1, &temp, 1);
		}
	}
}

int	printhexadecimalu(unsigned int c)
{
	int	returnvalue;

	returnvalue = hex_len(c);
	printhex(c);
	return (returnvalue);
}
