/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeanno <dojeanno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:23:49 by dojeanno          #+#    #+#             */
/*   Updated: 2023/04/06 17:56:17 by dojeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
        char    *destination;
        size_t  i;

        if (dst == NULL && src == NULL)
                return (NULL);
        i = 0;
        destination = dst;
        while (i < n)
        {
                destination[i] = *(char *)src++;
                i++;
        }
        return (destination);
}

char	*cleaner(char *stash)
{
	char	*hold;
	int		i;
	int		j;

	if (!stash)
		return (NULL);
	i = 0;
	hold = stash;
	while (stash[i] && (stash[i] != '\n'))
		i++;
	if (stash[i] == '\n')
		i++;
	stash = ft_calloc(sizeof(char), ft_strlen(hold) - i + 1);
	if (!stash)
		return (NULL);
	j = 0;
	while (hold[i])
	{
		stash[j] = hold[i];
		j++;
		i++;
	}
	return (stash);
}

char	*builder(char *stash)
{
	char	*line;
	int		i;
	
	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_calloc(sizeof(char), i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, stash, i);
	return (line);
}

char	*readline(int fd, char *stash)
{
	char	buf[BUFFER_SIZE + 1];
	int		bread;
	
	bread = 1;
	if (!stash)
	{
		bread = read(fd, buf, BUFFER_SIZE);
		if (!bread)
			return (NULL);
		stash = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!stash)
			return (NULL);
		ft_memcpy(stash, buf, BUFFER_SIZE);
	}
	while (bread && ft_strrchr(buf, '\n'))
	{
		bread = read(fd, buf, BUFFER_SIZE);
		if (!bread)
			return (NULL);
		stash = ft_strjoin(stash, buf);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static	char	*stash;
	char			*line;
	
	if (BUFFER_SIZE < 1 || (fd < 0 || fd > 1023))
		return (NULL);
	stash = readline(fd, stash);
	line = builder(stash);
	stash = cleaner(stash);
	return (line);
}
