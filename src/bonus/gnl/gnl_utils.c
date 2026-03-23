/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:34:24 by ksener            #+#    #+#             */
/*   Updated: 2026/03/23 14:34:25 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"
#include <stdlib.h>

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	c2;

	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	c2 = (unsigned char)c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c2)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (c2 == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

static char	*gnl_cpy(char *s1, char *s2)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	str = malloc (1 * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!str)
	{
		free (s1);
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free (s1);
	return (str);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc (1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	return (gnl_cpy(s1, s2));
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t					i;
	char					*str;

	if (!s)
		return (NULL);
	if (start >= gnl_strlen(s))
	{
		str = malloc (sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > gnl_strlen(s + start))
		len = gnl_strlen(s + start);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}