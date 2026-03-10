/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:13:30 by ksener            #+#    #+#             */
/*   Updated: 2026/03/10 17:05:05 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_chunk_size(int total_numbers)
{
	int	i;

	i = 2;
	while (i < total_numbers)
	{
		if (i * i <= total_numbers && total_numbers < (i + 1) * (i + 1))
			return (i);
		else
			i++;
	}
	return (i);
}


void	chunk_sort(t_list  **a_head, t_list **b_head)
{
	int	chunk_size;
	int	i;
	int	j;
	// t_list	*temp = NULL;

	i = 0;
	j = 0;
	if (!a_head || !(*a_head))
		return ;
	chunk_size = calc_chunk_size(ft_lstsize(*a_head));
	while (*a_head != NULL)
	{
		i = 0;
		while (i < chunk_size)
		{
			pb(b_head, a_head);
			i++;
			j = 0;
			while (j < i - 1 && (*b_head)->next != NULL)
			{
				if (get_int(b_head) > *(int *)(*b_head)->next->content)
					sb(b_head);
				rb(b_head);
				j++;
			}
			while (j--)
				rrb(b_head);
		}
	}
	int	size;
	pa(a_head, b_head);
	while (*b_head)
	{
		size = ft_lstsize(*a_head);
		while (size && get_int(b_head) > get_int(a_head))
		{
			ra(a_head);
			size--;
		}
		pa(a_head, b_head);
	}
}