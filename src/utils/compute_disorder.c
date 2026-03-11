/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 04:19:02 by adede             #+#    #+#             */
/*   Updated: 2026/03/11 16:06:12 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_list *a_head)
{
	size_t	total_pairs;
	size_t	mistakes;
	t_list	*outer;
	t_list	*inner;

	total_pairs = 0;
	mistakes = 0;
	outer = a_head;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			total_pairs++;
			if (get_int(outer) > get_int(inner))
				mistakes++;
			inner = inner->next;
		}
		outer = outer->next;
	}
	if (total_pairs == 0)
		return (0);
	return (((double)mistakes / total_pairs) * 100);
}