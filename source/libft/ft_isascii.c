/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:51:16 by tienshi           #+#    #+#             */
/*   Updated: 2023/09/21 16:18:34 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Checks if char c is on the ascii table or not
/// @param c 
/// @return 1 if char c is on the ascii table ; returns 0 on error
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
