/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:51:13 by adede             #+#    #+#             */
/*   Updated: 2026/03/18 18:39:31 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	rotate_reverse(t_list **stack)
{
	t_list	*before_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return (false);
	before_last = *stack;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	ft_lstadd_front(stack, before_last->next);
	before_last->next = NULL;
	return (true);
}

void	rra(t_list **a, t_op_count *ops)
{
	if (rotate_reverse(a))
	{
		ops->rra++;
		ft_printf("rra\n");
	}
}

void	rrb(t_list **b, t_op_count *ops)
{
	if (rotate_reverse(b))
	{
		ops->rrb++;
		ft_printf("rrb\n");
	}
}

void	rrr(t_list **a, t_list **b, t_op_count *ops)
{
	if (rotate_reverse(a) && rotate_reverse(b))
	{
		ops->rrr++;
		ft_printf("rrr\n");
	}
}