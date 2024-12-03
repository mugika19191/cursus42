/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:31:37 by imugica-          #+#    #+#             */
/*   Updated: 2024/11/27 13:40:48 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	len_checks(char const *s1, char const *s2, int *i, int *j)
{
	if (!s1 || !s2)
		return (0);
	*i = ft_strlen(s1);
	*j = ft_strlen(s2);
	return (1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (!len_checks(s1, s2, &i, &j))
		return (NULL);
	k = 0;
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	while (k < i)
	{
		str[k] = s1[k];
		k++;
	}
	k = 0;
	while (k < j)
	{
		str[k + i] = s2[k];
		k++;
	}
	str[i + j] = '\0';
	return (str);
}
