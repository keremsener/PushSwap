/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:47:20 by ksener            #+#    #+#             */
/*   Updated: 2026/02/24 12:58:21 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
	t_list	*a_head;
	t_list	*b_head;
	int     i;
	int		j;
	int		cmcount;
	char	*operation;
	char	**commands = ft_calloc((argc - 1), sizeof(char *));

	operation = "pa pb ra rb rr rra rrb rrr sa sb ss";
	i = 1;
	j = 0;
	a_head = NULL;
	b_head = NULL;

	while (i < argc)
	{
		if ((swp_strnstr(operation, argv[i], ft_strlen(operation))) == 1)
		{
			commands[cmcount] = argv[i];
			cmcount++;
		}
		else
			ft_lstadd_back(&a_head, ft_lstnew(ft_strdup(argv[i])));
		i++;
	}
	j = 0;

	while (j < cmcount)
	{
		controls(commands[j], &a_head, &b_head);
		j++;
	}
	printf("a b\n___\n");

	// Yazmak İçin Test Amaçlı kısım
	while (a_head != NULL)
	{
		printf("%s", (char *)a_head->content);
		if (b_head != NULL)
		{
			printf(" %s", (char *)b_head->content);
			b_head = b_head->next;
		}
		a_head = a_head->next;
		printf("\n");
	}
	return (0);
}
