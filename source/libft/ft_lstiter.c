/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:43:24 by stripet           #+#    #+#             */
/*   Updated: 2023/10/13 12:53:10 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*cursor;

	if (!lst || !f)
		return ;
	cursor = lst;
	while (cursor)
	{
		f(cursor->content);
		cursor = cursor->next;
	}
}
