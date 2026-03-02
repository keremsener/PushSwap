/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instertionsort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:53:57 by ksener            #+#    #+#             */
/*   Updated: 2026/03/02 14:48:45 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	insertion_sort(t_list **a_head, t_list **b_head)
{
	int	b_size = 0;
	
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
				pb(b_head, a_head);
				while (1 + b_size--)
					rb(b_head);
				break ;
			}
			else
			{
				rb(b_head);
				b_size--;
			}
		}
	}
	while (*b_head)
		pa(a_head, b_head);
}
