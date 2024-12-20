/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:53:30 by imugica-          #+#    #+#             */
/*   Updated: 2024/12/20 13:33:22 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(const char *c)
{
	int	i;

	if (!c)
		return (0);
	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	int		i;
	char	*str;

	i = 0;
	if (!dest && !src)
		return (0);
	str = (char *)dest;
	while (i < (int)count)
	{
		str[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char **s1, char const *s2, int bytes)
{
	size_t	lens1;
	size_t	lens2;
	size_t	lensdst;
	char	*newstring;

	if (!s2)
		return (0);
	lens1 = ft_strlen(*s1);
	lens2 = ft_strlen(s2);
	lensdst = lens1 + lens2 + 1 ;
	newstring = malloc(lensdst);
	if (!newstring)
		return (0);
	ft_memcpy(newstring, *s1, lens1);
	ft_memcpy(newstring + lens1, s2, bytes);
	if (*s1)
	{
		if (!**s1)
			*s1 = 0;
		//free(*s1);
	}
	return (newstring);
}
