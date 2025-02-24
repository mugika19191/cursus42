/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:31:26 by imugica-          #+#    #+#             */
/*   Updated: 2024/11/27 12:59:25 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	in_set(char a, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (a == set[i++])
			return (1);
	}
	return (0);
}

int	chars_front(char const *s1, char const *set)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s1[i])
	{
		if (in_set(s1[i++], set))
			count++;
		else
			return (count);
	}
	return (count);
}

int	chars_back(char const *s1, char const *set)
{
	int		i;
	int		count;

	i = ft_strlen(s1);
	count = 0;
	while (--i)
	{
		if (in_set(s1[i], set))
			count++;
		else
			return (count);
	}
	return (count);
}

int	copyable(char const *s1, char const *set, int j)
{
	int		i;

	i = ft_strlen(s1);
	if (j < chars_front(s1, set) || j >= (i - chars_back(s1, set)))
		return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = ft_strlen(s1);
	len = chars_front(s1, set) + chars_back(s1, set);
	if (len > ft_strlen(s1))
		str = (char *)malloc(1);
	else
		str = (char *)malloc(sizeof(char) * (i - len + 1));
	if (!str)
		return (NULL);
	j = 0;
	i = 0;
	while (i < ft_strlen(s1))
	{
		if (copyable(s1, set, i))
			str[j++] = s1[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}
