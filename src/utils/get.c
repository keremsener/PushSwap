/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:41:23 by ksener            #+#    #+#             */
/*   Updated: 2026/03/23 11:39:40 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_max_node(t_list *list)
{
	t_list	*result;

	if (!list)
		return (0);
	result = list;
	while (list != NULL)
	{
		if (get_int(list) > get_int(result))
			result = list;
		list = list->next;
	}
	return (result);
}

t_list	*get_min_node(t_list *list)
{
	t_list	*result;

	if (!list)
		return (0);
	result = list;
	while (list != NULL)
	{
		if (get_int(list) < get_int(result))
			result = list;
		list = list->next;
	}
	return (result);
}

int	get_int(t_list *node)
{
	return (*(int *)node->content);
}
