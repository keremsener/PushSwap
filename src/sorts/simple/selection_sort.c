/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:27:06 by ksener            #+#    #+#             */
/*   Updated: 2026/03/09 03:36:50 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_list **a_head, t_list **b_head)
{
	int	min_val;

	min_val = 0;
	if (!a_head || !(*a_head))
		return ;
	while ((*a_head) != NULL)
	{
		min_val = get_min_value(*a_head);
		if (*(int *)(*a_head)->content == min_val)
			pb(b_head, a_head);
		else
			ra(a_head);	
	}
	while (*b_head)
		pa(a_head, b_head);
}
