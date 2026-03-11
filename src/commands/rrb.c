/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:29:06 by ksener            #+#    #+#             */
/*   Updated: 2026/03/11 15:38:42 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_list **b, t_op_count *ops)
{
	t_list	*temp;
	t_list	*temp2;

	if (!b || !(*b) || !(*b)->next)
		return ;
	temp = *b;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	temp2 = temp->next;
	temp->next = NULL;
	ft_lstadd_front(b, temp2);
	ops->rrb++;
	ft_printf("rrb\n");
}
