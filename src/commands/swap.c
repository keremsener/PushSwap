/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:51:13 by adede             #+#    #+#             */
/*   Updated: 2026/03/23 19:09:22 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return (false);
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (true);
}

void	sa(t_list **a, t_op_count *ops)
{
	if (swap(a))
	{
		ops->sa++;
		ft_printf("sa\n");
	}
}

void	sb(t_list **b, t_op_count *ops)
{
	if (swap(b))
	{
		ops->sb++;
		ft_printf("sb\n");
	}
}

void	ss(t_list **a, t_list **b, t_op_count *ops)
{
	if (swap(a) && swap(b))
	{
		ops->ss++;
		ft_printf("ss\n");
	}
}
