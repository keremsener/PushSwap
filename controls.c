/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:30:23 by ksener            #+#    #+#             */
/*   Updated: 2026/02/24 10:43:24 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    controls(int argc, char *argv[], t_list **a_head, t_list **b_head)
{
	if (ft_strncmp(argv[1], "sa", 2) == 0)
		sa(&*a_head);
	else if (ft_strncmp(argv[1], "sb", 2) == 0)
		sb(&*b_head);
	else if (ft_strncmp(argv[1], "ss", 2) == 0)
		ss(&*a_head, &*b_head);
	else if (ft_strncmp(argv[1], "pb", 2) == 0)
		pb(&*b_head, &*a_head);
	else if (ft_strncmp(argv[1], "pa", 2) == 0)
		pa(&*a_head, &*b_head);
	else if (ft_strncmp(argv[1], "ra", 2) == 0)
		ra(&*a_head);
	else if (ft_strncmp(argv[1], "rb", 2) == 0)
		rb(&*b_head);
	else if (ft_strncmp(argv[1], "rra", 3) == 0)
		rra(&*a_head);
	else if (ft_strncmp(argv[1], "rrb", 3) == 0)
		rrb(&*b_head);
	else if (ft_strncmp(argv[1], "rrr", 3) == 0)
		rrr(&*a_head, &*b_head);
}
