/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:39:08 by imugica-          #+#    #+#             */
/*   Updated: 2024/11/25 12:00:25 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)dest;
	if (src == dest)
		return (dest);
	if (dest < src)
	{
		while (i < (int)n)
		{
			str[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			str[n] = ((char *)src)[n];
	}
	return (dest);
}
