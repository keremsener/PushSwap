/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:45:21 by ksener            #+#    #+#             */
/*   Updated: 2026/03/05 11:01:37 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **a)
{
	t_list	*three;
	t_list	*two;

	if (!a || !(*a) || !(*a)->next)
		return ;
	three = (*a)->next->next;
	(*a)->next->next = (*a);
	two = (*a)->next;
	(*a)->next = three;
	*a = two;
	ft_printf("\nsa");
}
