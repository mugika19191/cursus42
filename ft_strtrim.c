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

int	get_pos(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (len == 0)
		return (-1);
	if (little[0] == '\0')
		return (0);
	while (len-- && big[j] && little[i])
	{
		if (big[j] == little[i])
			i++;
		else
		{
			j = j - i;
			i = 0;
		}
		j++;
	}
	if (len >= 0 && !little[i])
		return (j - i);
	else
		return (-1);
}

int	find_amount(char const *s1, char const *set, int s)
{
	int	i;
	char	*copy;

	i = 0;
	copy = (char *)s1;
	while (ft_strnstr(copy, set, s))
	{
		copy = ft_strnstr(copy, set, s);
		copy += ft_strlen(set);
		i++;
	}
	return (i * ft_strlen(set));
}

char *ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	trims;
	char	*res;

	i = ft_strlen(s1);
	trims = find_amount(s1, set, i);
	res = (char *)malloc(sizeof(char) * (i - trims + 1));
	j = get_pos(s1, set, i);
	while (k < (i - trims + 1))
	{
		l = 0;
		while (l < strlen(set))
		{
			res[k] = (s1 + j)[k];
			k++;
			l++;
		}
	}
	return (res);
}
