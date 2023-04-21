/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeanno <dojeanno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:23:49 by dojeanno          #+#    #+#             */
/*   Updated: 2023/04/21 13:15:19 by dojeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cleaner(char *stash)
{
	t_vars	vars;
	char	*new_stash;

	if (!stash)
		return (NULL);
	vars.i = 0;
	while (stash[vars.i] && stash[vars.i] != '\n')
		vars.i++;
	if (stash[vars.i] == '\n')
		vars.i++;
	vars.j = ft_strlen(stash) - vars.i;
	new_stash = ft_calloc(sizeof(char), vars.j + 1);
	if (!new_stash)
		return (NULL);
	vars.j = 0;
	while (stash[vars.i] != '\0')
	{
		new_stash[vars.j] = stash[vars.i];
		vars.i++;
		vars.j++;
	}
	return (new_stash);
}

char	*builder(char *stash)
{
	t_vars	vars;

	if (!stash)
		return (NULL);
	vars.i = 0;
	while (stash[vars.i] && stash[vars.i] != '\n')
		vars.i++;
	if (stash[vars.i] == '\n')
		vars.i++;
	vars.line = ft_calloc(sizeof(t_vars), vars.i + 1);
	if (!vars.line)
		return (NULL);
	vars.j = 0;
	while (vars.j < vars.i)
	{
		vars.line[vars.j] = stash[vars.j];
		vars.j++;
	}
	return (vars.line);
}

char	*get_next_line(int fd)
{
	t_vars			vars;
	static char		*stash;

	if (BUFFER_SIZE < 1 || (fd < 0 || fd > 1023))
		return (NULL);
	if (!stash)
	{
		stash = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!stash)
			return (NULL);
	}
	vars.eof = 1;
	while (vars.eof > 0 && ft_strrchr(stash))
	{
		ft_bzero(vars.buff, BUFFER_SIZE + 1);
		vars.eof = read(fd, vars.buff, BUFFER_SIZE);
		stash = ft_strjoin(stash, vars.buff);
	}
	vars.line = builder(stash);
	stash = cleaner(stash);
	if (vars.line[0] == 0)
	{	
		free (vars.line);
		return (NULL);
	}
	return (vars.line);
}
