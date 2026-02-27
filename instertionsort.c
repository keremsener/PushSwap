/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instertionsort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:53:57 by ksener            #+#    #+#             */
/*   Updated: 2026/02/28 02:55:14 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	insertion_sort(t_list **a_head, t_list **b_head)
{
	t_list	**temp;

	int	size;

	size = ft_lstsize(*a_head);
	temp = a_head;
	while (size > 4)
	{
		size = ft_lstsize(*a_head);
		pb(b_head, a_head);
		printf("\nB head: %d", *(int *)(*b_head)->content);
	}
	bublesort(a_head);
	while (*b_head != NULL)
	{
		while (*(int *)(*b_head)->content > *(int *)(*temp)->content)
		{
			printf("%d\n",*(int *)(*temp)->content);
			ra(temp);
		}
		pa(temp, b_head);
	}
}