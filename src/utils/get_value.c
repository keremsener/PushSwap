/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:41:23 by ksener            #+#    #+#             */
/*   Updated: 2026/03/11 16:07:08 by adede            ###   ########.fr       */
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
