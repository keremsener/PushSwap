/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:47:20 by ksener            #+#    #+#             */
/*   Updated: 2026/03/15 16:59:52 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static size_t	max_int_digits(void)
{
	int		max;
	size_t	digits;

	max = INT_MAX;
	digits = 0;
	while (max != 0)
	{
		max /= 10;
		digits++;
	}
	return (digits);
}

static int	str_is_digits(const char *argument)
{
	long		result;
	size_t		digits;
	int			sign;

	result = 0;
	digits = 0;
	sign = 1;
	if (*argument == '-')
		sign = -1;
	if (*argument == '-' || *argument == '+')
		argument++;
	while (ft_isdigit(argument[digits]) && digits < max_int_digits())
		result = result * 10 + argument[digits++] - '0';
	if (digits == 0 || argument[digits] != '\0')
		return (0);
	result *= sign;
	if (result < INT_MIN || INT_MAX < result)
			return (0);
	return (1);
}

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
			if (!str_is_digits(split_args[j]))
				error();
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

static void	parse_option(const char *argument, t_config *config)
{
		if (!ft_strncmp(argument, "--simple", 9))
		config->strategy = SIMPLE;
	else if (!ft_strncmp(argument, "--medium", 9))
		config->strategy = MEDIUM;
	else if (!ft_strncmp(argument, "--complex", 10))
		config->strategy = COMPLEX;
	else if (!ft_strncmp(argument, "--adaptive", 11))
		config->strategy = ADAPTIVE;
	else if (!ft_strncmp(argument, "--bench", 8))
		config->bench_mode = true;
	else
	error();
}

static void	sort(t_list **a_head, t_list **b_head, t_metrics *metrics)
{
	if (metrics->config.strategy == ADAPTIVE)
	{
		if (metrics->disorder < 20)
			selection_sort(a_head, b_head, &metrics->ops);
		else if (metrics->disorder < 50)
			chunk_sort(a_head, b_head, &metrics->ops);
		else
			ft_printf("complex-adaptive\n");
	}
	if (metrics->config.strategy == SIMPLE)
	{
		// buble_sort(a_head, &metrics->ops); // 100: 12625, 500: 313343
		// insertion_sort(a_head, b_head, &metrics->ops); // 100: 5176, 500: 125829
		selection_sort(a_head, b_head, &metrics->ops); // 100: 2635, 500: 63366
	}
	if (metrics->config.strategy == MEDIUM)
	{
		// chunk_sort(a_head, b_head, &metrics->ops);
		turk_sort(a_head, b_head, &metrics->ops);
	}
	if (metrics->config.strategy == COMPLEX)
	{
		up_turk_sort(a_head, b_head, &metrics->ops);		
	}
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
		parse_option(argv[argi++], &metrics.config);
	a_head = split_args(argc - argi, argv + argi);
	metrics.disorder = compute_disorder(a_head);
	sort(&a_head, &b_head, &metrics);
	if (metrics.config.bench_mode)
		print_bench(metrics);
	// print_stack(a_head, b_head);
	return (0);
}
