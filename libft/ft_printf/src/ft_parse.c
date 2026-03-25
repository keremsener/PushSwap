/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 00:56:00 by adede             #+#    #+#             */
/*   Updated: 2026/03/05 10:06:19 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_parse_flag(t_options *options, const char flag)
{
	if (flag == '-')
	{
		options->flags.dash = true;
		options->flags.zero = false;
	}
	else if (flag == '0' && !options->flags.dash)
		options->flags.zero = true;
	else if (flag == '#')
		options->flags.hash = true;
	else if (flag == '+')
		options->flags.plus = true;
	else if (flag == ' ')
		options->flags.space = true;
}

int	ft_parse(const char *format, t_options *options)
{
	const char	*start;

	ft_bzero(options, sizeof(t_options));
	start = format;
	format++;
	while (ft_strchr("-0#+ ", *format))
		ft_parse_flag(options, *format++);
	if (ft_isdigit(*format))
	{
		options->width = ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
	}
	if (*format == '.')
	{
		format++;
		options->flags.dot = true;
		options->precision = ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
	}
	if (ft_strchr("cspdiuxX%", *format) == 0)
		options->error = true;
	options->specifier = *format++;
	return (format - start);
}
