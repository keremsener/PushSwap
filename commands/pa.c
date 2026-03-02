/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:44:18 by ksener            #+#    #+#             */
/*   Updated: 2026/03/02 14:42:16 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!b || !a)
		return ;
	temp = (*b)->next;
	ft_lstadd_front(a, *b);
	*b = temp;
	printf("\npa");
}
