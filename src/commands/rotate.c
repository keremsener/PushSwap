/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:51:13 by adede             #+#    #+#             */
/*   Updated: 2026/03/23 19:10:00 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	rotate(t_list **stack)
{
	t_list	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return (false);
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	ft_lstadd_back(stack, first);
	return (true);
}

void	ra(t_list **a, t_op_count *ops)
{
	if (rotate(a))
	{
		ops->ra++;
		ft_printf("ra\n");
	}
}

void	rb(t_list **b, t_op_count *ops)
{
	if (rotate(b))
	{
		ops->rb++;
		ft_printf("rb\n");
	}
}

void	rr(t_list **a, t_list **b, t_op_count *ops)
{
	if (rotate(a) && rotate(b))
	{
		ops->rr++;
		ft_printf("rr\n");
	}
}
