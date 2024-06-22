/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:07:14 by tienshi           #+#    #+#             */
/*   Updated: 2024/01/16 12:05:35 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "./libft/libft.h"

typedef struct threebyonematrix
{
	float	matrix[3][1];
}	t_tbom;

typedef struct threebythreematrix
{
	float	matrix[3][3];
}	t_tbtm;

typedef struct plane_coords{
	int	x;
	int	y;
}	t_plane_coords;

typedef struct coords{
	t_tbom			coords;
	t_plane_coords	*translate;
}	t_coords;

typedef struct img{
	void		*img_id;
	char		*addr;
	int			bpp;
	int			row_len;
	int			endian;
}	t_img;

typedef struct data{
	void		*w_id;
	void		*tun_id;
	t_img		img;
	t_list		*list;
	float		alpha;
	float		beta;
	t_tbtm		rotation1;
	t_tbtm		rotation2;
	t_tbtm		rotation3;
}	t_data;

#endif
