/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:45:37 by tienshi           #+#    #+#             */
/*   Updated: 2024/06/22 21:10:37 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/minishell.h"

#include "./pipex/header/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc > 1)
	{
		return (0);
	}
	return (msg(BAD_ARGS));
}
