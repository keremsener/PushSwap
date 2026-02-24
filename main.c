/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:47:20 by ksener            #+#    #+#             */
/*   Updated: 2026/02/24 10:42:47 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_list	*a_head;
	t_list	*b_head;
	int     i;
	int		j;

	i = 0;
	j = 0;
	a_head = NULL;
	b_head = NULL;

	while (i < argc - 2)
	{
		ft_lstadd_back(&a_head, ft_lstnew(ft_strdup(argv[i + 2])));
		i++;
	}
	i = 0;
	while (i < argc - 2)
	{
		ft_lstadd_back(&b_head, ft_lstnew(ft_strdup(argv[i + 2])));
		i++;
	}
	controls(argc, argv, &a_head, &b_head);
	printf("a b\n___\n");

	while (a_head != NULL)
	{
		printf("%s %s\n", (char *)a_head->content, (char *)b_head->content);
		a_head = a_head->next;
		b_head = b_head->next;
	}
	return (0);
}
