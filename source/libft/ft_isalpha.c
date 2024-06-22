/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:27:22 by tienshi           #+#    #+#             */
/*   Updated: 2023/09/21 16:18:36 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Checks if char c is a letter or not
/// @param c 
/// @return 1 if char c is a letter ; returns 0 on error
int	ft_isalpha(int c)
{
	if ((c <= 90 && c >= 65)
		|| (c <= 122 && c >= 97))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
