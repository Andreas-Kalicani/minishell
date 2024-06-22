/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:57:51 by tienshi           #+#    #+#             */
/*   Updated: 2023/09/21 16:34:58 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Takes a char and capitalizes it
/// @param c 
/// @return Capitalized int c ; returns c on error
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (c - 32);
	}
	else
	{
		return (c);
	}
}
