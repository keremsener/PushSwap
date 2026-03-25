/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 09:01:09 by adede             #+#    #+#             */
/*   Updated: 2026/03/25 12:00:51 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static bool	str_is_int(const char *argument)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*argument == '-')
		sign = -1;
	if (*argument == '-' || *argument == '+')
		argument++;
	if (!ft_isdigit(*argument))
		return (false);
	while (ft_isdigit(*argument))
	{
		result = result * 10 + (*argument - '0');
		if ((sign == 1 && result > INT_MAX))
			return (false);
		if ((sign == -1 && (-result < INT_MIN)))
			return (false);
		argument++;
	}
	if (*argument != '\0')
		return (false);
	return (true);
}

static bool	parse_number(const char *argument, t_list **list)
{
	char	**split_arg;
	int		*val;
	int		i;

	split_arg = ft_split(argument, ' ');
	if (!split_arg[0])
		return (false);
	i = 0;
	while (split_arg[i])
	{
		if (!str_is_int(split_arg[i]))
			return (free(split_arg[i]), free(split_arg), false);
		val = ft_calloc(1, sizeof(int));
		if (!val)
			return (free(split_arg[i]), free(split_arg), false);
		*val = ft_atoi(split_arg[i]);
		ft_lstadd_back(list, ft_lstnew(val));
		free(split_arg[i++]);
	}
	free(split_arg);
	return (true);
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

static bool	check_duplicate(t_list *list)
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
				return (true);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (false);
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
	{
		if (!parse_number(argv[argi++], &list))
		{
			ft_lstclear(&list, free);
			error();
		}
	}
	if (check_duplicate(list))
	{
		ft_lstclear(&list, free);
		error();
	}
	return (list);
}
