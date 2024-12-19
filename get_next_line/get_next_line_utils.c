/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:53:30 by imugica-          #+#    #+#             */
/*   Updated: 2024/12/19 14:01:49 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stddef.h>
#include <stdlib.h>

int	ft_strlen(const char *c)
{
	int	i;

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

char	*ft_strjoin(char const *s1, char const *s2, int bytes)
{
	size_t	lens1;
	size_t	lens2;
	size_t	lensdst;
	char	*newstring;

	if (!s2)
		return (0);
	if (!s1)
		lens1 = 0;
	else
		lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	lensdst = lens1 + lens2 + 1 ;
	newstring = malloc(lensdst);
	if (!newstring)
		return (0);
	ft_memcpy(newstring, s1, lens1);
	ft_memcpy(newstring + lens1, s2, bytes);
	return (newstring);
}