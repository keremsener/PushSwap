/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:41:23 by ksener            #+#    #+#             */
/*   Updated: 2026/03/12 14:04:08 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_value(t_list *list)
{
	int	result;

	if (!list)
		return (0);
	result = get_int(list);
	while (list != NULL)
	{
		if (get_int(list) > result)
			result = get_int(list);
		list = list->next;
	}
	return (result);
}

int	get_min_value(t_list *list)
{
	int	result;

	if (!list)
		return (0);
	result = get_int(list);
	while (list != NULL)
	{
		if (get_int(list) < result)
			result = get_int(list);
		list = list->next;
	}
	return (result);
}
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
