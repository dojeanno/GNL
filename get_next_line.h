/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeanno <dojeanno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:24:34 by dojeanno          #+#    #+#             */
/*   Updated: 2023/04/21 13:09:45 by dojeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // REMOVE !!!!!
# include <fcntl.h> // Remove
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_vars
{
	int		eof;
	char	*line;
	int		i;
	int		j;
	char	buff[BUFFER_SIZE + 1];
}				t_vars;

char	*get_next_line(int fd);
int		ft_strlen(char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strrchr(char *s);
void	ft_bzero(void *s, size_t n);
void	free_space(char *stash, char *line);

#endif