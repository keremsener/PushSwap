/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:47:20 by ksener            #+#    #+#             */
/*   Updated: 2026/03/03 17:22:19 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	test_print(t_list *a_head, t_list *b_head)
{
	int wlcount = 8;

	printf("\n\na b\n___\n");
	while (wlcount--)
	{

		if (a_head != NULL)
		{
			printf("%d", *(int *)a_head->content);
			a_head = a_head->next;
		}
		else
			printf(" ");
		if (b_head != NULL)
		{
			printf(" %d", *(int *)b_head->content);
			b_head = b_head->next;
		}
		else
			printf(" ");
		printf("\n");
	}
}
int main(int argc, char *argv[])
{
	t_list	*a_head;
	t_list	*b_head;
	int     i;
	int		j;
	int		cmcount = 0;
	char	*operation;
	char	**commands = ft_calloc((argc - 1), sizeof(char *));
	int		pbatoi[argc - 1];


	operation = "pa pb ra rb rr rra rrb rrr sa sb ss";
	i = 1;
	j = 0;
	a_head = NULL;
	b_head = NULL;
	int wlcount;

	wlcount = 20;
	while (i < argc)
	{
		if ((swp_strnstr(operation, argv[i], ft_strlen(operation))) == 1)
		{
			commands[cmcount] = argv[i];
			cmcount++;
		}
		else
		{
			pbatoi[i] = ft_atoi(argv[i]);
			ft_lstadd_back(&a_head, ft_lstnew(&pbatoi[i]));
		}
		i++;
	}
	j = 0;

	while (j < cmcount)
	{
		//controls(commands[j], &a_head, &b_head);
		j++;
	}
	//bublesort(&a_head);
	insertion_sort(&a_head, &b_head);
	test_print(a_head, b_head);
	return (0);
}
