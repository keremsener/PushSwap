/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buble_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:46:09 by ksener            #+#    #+#             */
/*   Updated: 2026/03/09 03:34:41 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	buble_sort(t_list **a_head)
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
			if (get_int(a_head) > *(int *)(*a_head)->next->content)
				sa(a_head);
			ra(a_head);
			j++;
		}
		ra(a_head);
		i++;
	}
}
