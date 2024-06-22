/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:55:38 by stripet           #+#    #+#             */
/*   Updated: 2023/10/13 15:38:24 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*retval;
	t_list	*buffer;

	retval = NULL;
	while (lst)
	{
		buffer = ft_lstnew(f(lst->content));
		if (!buffer)
		{
			ft_lstclear(&retval, (*del));
			return (0);
		}
		ft_lstadd_back(&retval, buffer);
		lst = lst->next;
	}
	return (retval);
}
