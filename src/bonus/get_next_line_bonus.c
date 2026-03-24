/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:27:27 by ksener            #+#    #+#             */
/*   Updated: 2026/03/24 15:24:49 by adede            ###   ########.fr       */
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

static void free_stash(char *stash, char *buff)
{
	free(buff);
	free(stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buff;
	int			counter;

	counter = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	while (!ft_strchr(stash, '\n') && counter != 0)
	{
		counter = read(fd, buff, BUFFER_SIZE);
		if (counter == -1)
		{
			free_stash(stash, buff);
			stash = NULL;
			return (NULL);
		}
		buff[counter] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	return (helper(&stash, buff));
}
