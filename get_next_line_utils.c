/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeanno <dojeanno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:24:32 by dojeanno          #+#    #+#             */
/*   Updated: 2023/03/21 13:35:00 by dojeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n-- > 0)
		*p++ = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = malloc(size * count);
	if (ptr == NULL)
		return (0);
	ft_bzero(ptr, (count * size));
	return ((void *)ptr);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	max;
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	max = ft_strlen(s);
	if (len > max)
		len = max;
	str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (NULL);
	while (start < max && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	return (str);
}

// Will need protections!