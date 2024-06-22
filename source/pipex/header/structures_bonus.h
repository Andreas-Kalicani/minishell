/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:26:57 by stripet           #+#    #+#             */
/*   Updated: 2024/06/22 03:23:59 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_BONUS_H
# define STRUCTURES_BONUS_H

# include "stdio.h"
# include "fcntl.h"
# include "unistd.h"
# include "../../libft/libft.h"

typedef struct s_data{
	int		input;
	int		output;
	char	*paths;
	char	*path;
	char	**args;
	int		pid;
}	t_data;

#endif