/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 09:01:09 by adede             #+#    #+#             */
/*   Updated: 2026/03/17 17:17:13 by adede            ###   ########.fr       */
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

static t_list	*parse_number(const char *argument)
{
	t_list	*list;
	char	**split_arg;
	int		*val;
	int		i;

	list = NULL;
	split_arg = ft_split(argument, ' ');
	i = 0;
	while (split_arg[i])
	{
		if (!str_is_digits(split_arg[i]))
			error();
		val = ft_calloc(1, sizeof(int));
		if (!val)
			return (NULL);
		*val = ft_atoi(split_arg[i]);
		ft_lstadd_back(&list, ft_lstnew(val));
		free(split_arg[i++]);
	}
	free(split_arg);
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

static void	check_duplicate(t_list *list)
{
	t_list	*outer;
	t_list	*inner;

	outer = list;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (get_int(inner) == get_int(outer))
				error();
			inner = inner->next;
		}
		outer = outer->next;
	}
}

t_list	*parse(int argc, const char *argv[], t_config *config)
{
	t_list	*list;
	int		argi;

	list = NULL;
	argi = 1;
	while (argi < argc && !ft_strncmp(argv[argi], "--", 2))
		parse_option(argv[argi++], config);
	while (argi < argc)
		ft_lstadd_back(&list, parse_number(argv[argi++]));
	check_duplicate(list);
	return (list);
}
