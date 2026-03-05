/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bublesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:46:09 by ksener            #+#    #+#             */
/*   Updated: 2026/02/25 13:23:48 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	bublesort(t_list **a_head)
{
	int	size;
	int	i;
	int	j;

	if (!a_head || !*a_head || !(*a_head)->next)
		return ;
	size = ft_lstsize(*a_head);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (*(int *)(*a_head)->content > *(int *)(*a_head)->next->content)
				sa(a_head);
			ra(a_head);
			j++;
		}
		ra(a_head);
		i++;
	}
}
