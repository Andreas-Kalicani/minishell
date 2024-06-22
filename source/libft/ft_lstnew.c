/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:25:16 by stripet           #+#    #+#             */
/*   Updated: 2023/10/11 16:21:48 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*buffer;

	buffer = (t_list *) malloc(sizeof(t_list));
	if (!buffer)
		return (NULL);
	buffer->content = content;
	buffer->next = NULL;
	return (buffer);
}
