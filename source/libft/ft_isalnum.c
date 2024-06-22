/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:36:09 by tienshi           #+#    #+#             */
/*   Updated: 2023/09/21 16:36:58 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Checks if char c is a number or a letter or not
/// @param c 
/// @return 1 if char c is a number or a letter ; returns 0 on error
int	ft_isalnum(int c)
{
	if ((c <= 90 && c >= 65)
		|| (c <= 122 && c >= 97)
		|| (c >= 48 && c <= 57))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
