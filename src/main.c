/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:47:20 by ksener            #+#    #+#             */
/*   Updated: 2026/03/06 15:38:36 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_print(t_list *a_head, t_list *b_head)
{
	int	wlcount;

	wlcount = 20;
	ft_printf("\n\na b\n___\n");
	while (wlcount--)
	{
		if (a_head != NULL)
		{
			ft_printf("%d", *(int *)a_head->content);
			a_head = a_head->next;
		}
		else
			ft_printf(" ");
		if (b_head != NULL)
		{
			ft_printf(" %d", *(int *)b_head->content);
			b_head = b_head->next;
		}
		else
			ft_printf(" ");
		ft_printf("\n");
	}
}

static void	split_args(int argc, char *argv[], t_list **a_head)
{
	int		i;
	int		j;
	int		*val;
	char	**split_args;

	i = 1;
	while (i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		j = 0;
		while (split_args[j])
		{
			val = (int *)malloc(sizeof(int));
			if (!val)
				return ;
			*val = ft_atoi(split_args[j]);
			ft_lstadd_back(&(*a_head), ft_lstnew(val));
			free(split_args[j]);
			j++;
		}
		free(split_args);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*a_head;
	t_list	*b_head;

	if (argc < 2)
		return (0);
	a_head = NULL;
	b_head = NULL;
	split_args(argc, argv, &a_head); 
//	insertion_sort(&a_head, &b_head); //100: 5176, 500: 125829:
	//bublesort(&a_head);  //100: 12625, 500: 313343:
//	selectionsort(&a_head, &b_head); //100: 2635, 500: 63366:
	chunksort(&a_head, &b_head);
	// test_print(a_head, b_head);
	return (0);
}
