/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:49:19 by stripet           #+#    #+#             */
/*   Updated: 2024/06/22 03:20:28 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/errors_bonus.h"
#include <stdlib.h>

int	msg(t_data data, int err)
{
	if (err == badargs_err)
		ft_printf("Bad number of arguments expected 4+\n");
	else if (err == path_err)
		ft_printf("Couldn't find valid path\n");
	else if (err == open_err)
		perror("Issue opening the input file : ");
	else if (err == open_create_err)
		perror("Issues opening or creating the output file :");
	else if (err == dup_err)
		perror("Problem dupping fds :");
	else if (err == pipe_err)
		perror("Problem creating a pipe :");
	else if (err == cmd_err)
		ft_printf("Couldnt find path for commamd\n");
	else if (err == fork_err)
		perror("Error forking :");
	if (data.paths)
		free(data.paths);
	exit (err);
}
