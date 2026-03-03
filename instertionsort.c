/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instertionsort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:53:57 by ksener            #+#    #+#             */
/*   Updated: 2026/03/03 16:08:29 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	get_max_value(t_list *list)
{
	int		result;

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
void	insertion_sort(t_list **a_head, t_list **b_head)
{
	int	b_size = 0;
	int	max_val;

	if (*(int *)(*a_head)->content < *(int *)(*a_head)->next->content)
		sa(a_head);
	pb(b_head, a_head);	
	while (*a_head)
	{
		b_size = ft_lstsize(*b_head);
		while (*b_head)
		{
			if ((*(int *)(*a_head)->content > *(int *)(*b_head)->content) ||
				b_size <= 0)
			{
				if (b_size <= 0)
                {
                    max_val = get_max_value(*b_head);
                    while (max_val != *(int *)(*b_head)->content)
                        rb(b_head);
                }
				pb(b_head, a_head);
					break ;
			}
			else
			{
				rb(b_head);
				b_size--;
			}
		}
	}
	max_val = get_max_value(*b_head);
	while (max_val != *(int *)(*b_head)->content)
	{
		rb(b_head);
	}
	while (*b_head)
		pa(a_head, b_head);
}
