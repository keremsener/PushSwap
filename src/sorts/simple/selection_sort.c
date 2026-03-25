/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:27:06 by ksener            #+#    #+#             */
/*   Updated: 2026/03/25 09:49:59 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_list **a_head, t_list **b_head, t_op_count *ops)
{
	int		min_val;
	int		a_size;

	if (!a_head || !(*a_head))
		return ;
	a_size = ft_lstsize(*a_head);
	while (a_size > 0)
	{
		min_val = get_int(get_min_node(*a_head));
		if (get_int(*a_head) == min_val)
		{
			pb(b_head, a_head, ops);
			a_size--;
		}
		else
			ra(a_head, ops);
	}
	while (*b_head)
		pa(a_head, b_head, ops);
}
