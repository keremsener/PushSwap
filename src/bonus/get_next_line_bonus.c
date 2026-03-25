/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:27:27 by ksener            #+#    #+#             */
/*   Updated: 2026/03/25 10:32:19 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

static char	*helper(char **stash, char *buff)
{
	int		counter;
	char	*line;
	char	*temp;

	counter = 0;
	free (buff);
	if (!*stash || **stash == '\0')
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	while ((*stash)[counter] && (*stash)[counter] != '\n')
		counter++;
	if ((*stash)[counter] == '\n')
		counter++;
	line = ft_substr(*stash, 0, counter);
	temp = *stash;
	*stash = ft_substr(temp, counter, ft_strlen(temp) - counter);
	free (temp);
	return (line);
}

static int	read_into_stash(int fd, char **stash, char *buff)
{
	int		counter;
	char	*temp;

	counter = 1;
	while (!ft_strchr(*stash, '\n') && counter != 0)
	{
		counter = read(fd, buff, BUFFER_SIZE);
		if (counter == -1)
			return (-1);
		buff[counter] = '\0';
		temp = ft_strjoin(*stash, buff);
		free(*stash);
		*stash = temp;
		if (!*stash)
			return (-1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	if (read_into_stash(fd, &stash, buff) == -1)
	{
		free(buff);
		free(stash);
		stash = NULL;
		return (NULL);
	}
	return (helper(&stash, buff));
}
