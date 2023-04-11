/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeanno <dojeanno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:23:49 by dojeanno          #+#    #+#             */
/*   Updated: 2023/04/11 18:14:11 by dojeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cleaner(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;
	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash)
		i++;
	if (stash[i] == '\n')
		i++;
	j = ft_strlen(stash) - i;
	new_stash = ft_calloc(sizeof(char), j + 1);
	if (!new_stash)
		return (NULL);
	j = 0;
	while (stash[i] != '\0')
	{
		new_stash[j] = stash[i];
		i++;
		j++;
	}
	free (stash);
	return (new_stash);
}

char	*builder(char *stash)
{
	int		i;
	int		j;
	char	*line;
	
	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		line[j] = stash[j];
		j++;	
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	static int		eof;
	char			buff[BUFFER_SIZE];
	char			*line;
	
	if (BUFFER_SIZE < 1 || (fd < 0 || fd > 1023))
		return (NULL);
	if (!stash)
	{
		stash = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!stash)
			return (NULL);
		eof = read(fd, stash, BUFFER_SIZE);
	}
	while (eof > 0 && ft_strrchr(stash, '\n'))
	{
		eof = read(fd, buff, BUFFER_SIZE);
		stash = ft_strjoin(stash, buff);
	}
	line = builder(stash);
	stash = cleaner(stash);
	return (line);
}
