/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:10:03 by ksener            #+#    #+#             */
/*   Updated: 2026/03/05 10:10:13 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printnode(t_list *list)
{
	while (list)
	{
		printf("%d", *(int *)list->content);
		list = list->next;
	}
}
