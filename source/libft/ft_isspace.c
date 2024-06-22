/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:58:15 by tienshi           #+#    #+#             */
/*   Updated: 2023/09/21 16:18:21 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Checks if the character is a whitespace
/// @param c 
/// @return 1 on success 0 on error
int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r'
		|| c == '\n' || c == '\v' || c == '\f')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
