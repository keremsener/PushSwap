/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:10:03 by ksener            #+#    #+#             */
/*   Updated: 2026/03/09 04:13:07 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *a_head, t_list *b_head)
{
	ft_printf("\n");
	ft_printf("+-------------+-------------+\n");
	ft_printf("| % 11s | % 11s |\n", "Stack A", "Stack B");
	ft_printf("+-------------+-------------+\n");
	while (a_head || b_head)
	{
		if (a_head)
		{
			ft_printf("| % 11d", *(int *)a_head->content);
			a_head = a_head->next;
		}
		else
			ft_printf("| % 11s", "");
		ft_printf(" | ");
		if (b_head)
		{
			ft_printf("% 11d |", *(int *)b_head->content);
			b_head = b_head->next;
		}
		else
			ft_printf("% 11s |", "");
		ft_printf("\n");
	}
	ft_printf("+-------------+-------------+\n");
	ft_printf("\n");
}
