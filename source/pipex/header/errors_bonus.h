/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:49:41 by stripet           #+#    #+#             */
/*   Updated: 2024/06/22 03:19:00 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_BONUS_H
# define ERRORS_BONUS_H

# include "structures_bonus.h"

enum	e_errors{
	badargs_err = -1,
	path_err = -2,
	open_err = -3,
	open_create_err = -4,
	dup_err = -5,
	pipe_err = -6,
	cmd_err = -7,
	fork_err = -8
};

int	msg(t_data data, int err);

#endif