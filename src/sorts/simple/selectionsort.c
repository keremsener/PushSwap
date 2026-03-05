/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selectionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:27:06 by ksener            #+#    #+#             */
/*   Updated: 2026/03/05 13:56:35 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selectionsort(t_list **a_head, t_list **b_head)
{
	int	min_val;

	min_val = 0;
	if (!a_head || !(*a_head))
		return ;
	while ((*a_head) != NULL)
	{
		if ((*a_head)->next == NULL)
		{
			pb(b_head, a_head);
			break ;
		}
		min_val = get_min_value(*a_head);
		if (*(int *)(*a_head)->next->content == min_val)
			pb(b_head, &(*a_head)->next);
		else
		{
			ra(a_head);
		}	
	}
	while (*b_head)
		pa(a_head, b_head);
}
