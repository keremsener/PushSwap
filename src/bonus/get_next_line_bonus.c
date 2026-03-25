/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:27:27 by ksener            #+#    #+#             */
/*   Updated: 2026/03/25 15:05:55 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

static void	*free_stash(char **stash)
{
	free(*stash);
	*stash = NULL;
	return (NULL);
}

static char	*helper(char **stash)
{
	int		counter;
	char	*line;
	char	*temp;

	counter = 0;
	if (!*stash || **stash == '\0')
		return (free_stash(stash));
	while ((*stash)[counter] && (*stash)[counter] != '\n')
		counter++;
	if ((*stash)[counter] == '\n')
		counter++;
	line = ft_substr(*stash, 0, counter);
	if ((*stash)[counter] == '\0')
	{
		free_stash(stash);
		return (line);
	}
	temp = *stash;
	*stash = ft_substr(temp, counter, ft_strlen(temp) - counter);
	free(temp);
	return (line);
}

static int	read_into_stash(int fd, char **stash, char *buff)
{
	int		bytes;
	char	*temp;

	bytes = 1;
	while (!ft_strchr(*stash, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
			return (bytes);
		buff[bytes] = '\0';
		temp = ft_strjoin(*stash, buff);
		free(*stash);
		*stash = temp;
		if (!*stash)
			return (-1);
	}
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buff;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (NULL);
	}
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes = read_into_stash(fd, &stash, buff);
	free(buff);
	if (bytes < 0 || !stash || *stash == '\0')
		return (free_stash(&stash));
	return (helper(&stash));
}
