/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:47:20 by ksener            #+#    #+#             */
/*   Updated: 2026/03/09 05:55:34 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*split_args(int argc, const char *argv[])
{
	t_list	*list;
	int		i;
	int		j;
	int		*val;
	char	**split_args;

	list = NULL;
	i = 0;
	while (i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		j = 0;
		while (split_args[j])
		{
			val = (int *)malloc(sizeof(int));
			if (!val)
				return (NULL);
			*val = ft_atoi(split_args[j]);
			ft_lstadd_back(&list, ft_lstnew(val));
			free(split_args[j]);
			j++;
		}
		free(split_args);
		i++;
	}
	return (list);
}

static t_config	parse_option(const char *argument)
{
	t_config	config;
	size_t		length;
	
	ft_bzero(&config, sizeof(t_config));
	length = ft_strlen(argument);
	if (!ft_strncmp(argument, "--simple", length))
		config.strategy = SIMPLE;
	else if (!ft_strncmp(argument, "--medium", length))
		config.strategy = MEDIUM;
	else if (!ft_strncmp(argument, "--complex", length))
		config.strategy = COMPLEX;
	else if (!ft_strncmp(argument, "--adaptive", length))
		config.strategy = ADAPTIVE;
	else if (!ft_strncmp(argument, "--bench", length))
		config.bench_mode = true;
	// else
	// 	error();
	return (config);
}

static void	sort(t_list **a_head, t_list **b_head, t_metrics metrics)
{
	if (metrics.config.strategy == ADAPTIVE)
	{
		if (metrics.disorder < 20)
			selection_sort(a_head, b_head);
		else if (metrics.disorder < 50)
			chunk_sort(a_head, b_head);
		else
			ft_printf("complex-adaptive\n");
	}
	if (metrics.config.strategy == SIMPLE)
	{
		// insertion_sort(a_head, b_head); // 100: 5176, 500: 125829
		// buble_sort(a_head); // 100: 12625, 500: 313343
		selection_sort(a_head, b_head); // 100: 2635, 500: 63366
	}
	if (metrics.config.strategy == MEDIUM)
		chunk_sort(a_head, b_head);
	if (metrics.config.strategy == COMPLEX)
		ft_printf("complex\n");
	if (metrics.config.bench_mode)
		ft_printf("bench\n");
}

int	main(int argc, const char *argv[])
{
	t_list		*a_head;
	t_list		*b_head;
	t_metrics	metrics;
	int			argi;

	if (argc < 2)
		return (0);
	a_head = NULL;
	b_head = NULL;
	ft_bzero(&metrics, sizeof(t_metrics));
	argi = 1;
	while (argi < argc && !ft_strncmp(argv[argi], "--", 2))
		metrics.config = parse_option(argv[argi++]);
	a_head = split_args(argc - argi, argv + argi);
	metrics.disorder = compute_disorder(a_head);
	sort(&a_head, &b_head, metrics);
	// print_stack(a_head, b_head);
	return (0);
}
