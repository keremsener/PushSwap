/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:27:07 by adede             #+#    #+#             */
/*   Updated: 2026/03/23 19:09:25 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	push(t_list **from, t_list **to)
{
	t_list	*temp;

	if (!from || !*from)
		return (false);
	temp = (*from)->next;
	ft_lstadd_front(to, *from);
	*from = temp;
	return (true);
}

void	pa(t_list **a, t_list **b, t_op_count *ops)
{
	if (push(b, a))
	{
		ops->pa++;
		ft_printf("pa\n");
	}
}

void	pb(t_list **b, t_list **a, t_op_count *ops)
{
	if (push(a, b))
	{
		ops->pb++;
		ft_printf("pb\n");
	}
}
