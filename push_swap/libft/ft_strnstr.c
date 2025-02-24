/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:04:48 by imugica-          #+#    #+#             */
/*   Updated: 2024/11/26 11:39:42 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (j < (int)len && big[j] && little[i])
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
	if (len > 0 && !little[i])
		return ((char *)(big + j - i));
	else
		return (NULL);
}
