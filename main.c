/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:47:20 by ksener            #+#    #+#             */
/*   Updated: 2026/02/23 16:15:16 by ksener           ###   ########.fr       */
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

	while(i < argc - 2)
	{
		printf("girdim\n");
		ft_lstadd_back(&a_head, ft_lstnew(ft_strdup(argv[i + 2])));
		i++;
	}
	i = 0;
	while(i < argc - 2)
	{
		printf("girdim\n");
		ft_lstadd_back(&b_head, ft_lstnew(ft_strdup(argv[i + 2])));
		i++;
	}
	if (ft_strncmp(argv[1], "sa", 2) == 0)
	{
		sa(&a_head);
	}
	else if (ft_strncmp(argv[1], "sb", 2) == 0)
	{
		
		sb(&b_head);
	}
	else if (ft_strncmp(argv[1], "ss", 2) == 0)
	{
		ss(a_head, b_head);
	}
	else if (ft_strncmp(argv[1], "pb", 2) == 0)
	{
		pb(&b_head, a_head);
	}
	printf("a b\n___\n");

	while (a_head != NULL)
	{
		printf("%s %s\n", (char *)a_head->content, (char *)b_head->content);
		a_head = a_head->next;
		b_head = b_head->next;
	}
	return (0);
}
