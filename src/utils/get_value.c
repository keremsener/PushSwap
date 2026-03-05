/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:41:23 by ksener            #+#    #+#             */
/*   Updated: 2026/03/05 13:57:00 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_value(t_list *list)
{
	int	result;

	if (!list)
		return (0);
	result = *(int *)list->content;
	while (list != NULL)
	{
		if (*(int *)list->content > result)
			result = *(int *)list->content;
		list = list->next;
	}
	return (result);
}

int	get_min_value(t_list *list)
{
	int	result;

	if (!list)
		return (0);
	result = *(int *)list->content;
	while (list != NULL)
	{
		if (*(int *)list->content < result)
			result = *(int *)list->content;
		list = list->next;
	}
	return (result);
}
