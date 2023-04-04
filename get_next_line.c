/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeanno <dojeanno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:23:49 by dojeanno          #+#    #+#             */
/*   Updated: 2023/04/04 16:31:16 by dojeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*cleaner(char *stash)
{
	int		i;
	int		start;
	char	*new_stash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	i++;
	start = 0;
	while (stash[i + start] != '\0')
		start++;
	new_stash = ft_calloc(sizeof(char), ft_strlen(stash + 1 - start));
	if (!new_stash)
		return (NULL);
	start = 0;
	while (stash[i])
	{
		new_stash[start] = stash[i];
		start++;
		i++;
	}
	return (new_stash);
}

char	*builder(char *stash)
{
	char	*line;
	int		i;
	int		y;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	line = ft_calloc(sizeof(char), i + 1);
	if (!line)
		return (NULL);
	y = 0;
	while (y <= i)
	{
		line[y] = stash[y];
		y++;
	}
	return (line);
}

char	*readline(int fd, char *stash)
{
	char	*buf;
	size_t	bread;
	
	if (!stash)
		return (NULL);
	bread = 1;
	if (ft_strrchr(stash, '\n'))
		return (stash);
	while (bread && (!ft_strrchr(buf, '\n') || !ft_strrchr(buf, '\0')))
	{
		buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		bread = read(fd, buf, BUFFER_SIZE);
		stash = ft_strjoin(stash, buf);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static	char	*stash;
	char			*line;
	
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0 || (fd < 0 || fd > 1023))
		return (NULL);
	if (stash == NULL)
	{	
		stash = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		read(fd, stash, BUFFER_SIZE);
		stash[BUFFER_SIZE] = '\0';
	}
	stash = readline(fd, stash);
	line = builder(stash);
	stash = cleaner(stash);
	return (line);
}
