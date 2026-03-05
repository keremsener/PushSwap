/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:30:23 by ksener            #+#    #+#             */
/*   Updated: 2026/03/05 11:02:37 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	controls(char *operation, t_list **a_head, t_list **b_head)
{
	static int	counter;

	if (ft_strncmp(operation, "sa", 2) == 0)
		sa(a_head);
	else if (ft_strncmp(operation, "sb", 2) == 0)
		sb(b_head);
	else if (ft_strncmp(operation, "ss", 2) == 0)
		ss(a_head, b_head);
	else if (ft_strncmp(operation, "pb", 2) == 0)
		pb(b_head, a_head);
	else if (ft_strncmp(operation, "pa", 2) == 0)
		pa(a_head, b_head);
	else if (ft_strncmp(operation, "ra", 2) == 0)
		ra(a_head);
	else if (ft_strncmp(operation, "rb", 2) == 0)
		rb(b_head);
	else if (ft_strncmp(operation, "rra", 3) == 0)
		rra(a_head);
	else if (ft_strncmp(operation, "rrb", 3) == 0)
		rrb(b_head);
	else if (ft_strncmp(operation, "rrr", 3) == 0)
		rrr(a_head, b_head);
	else
		return ;
	++counter;
}
