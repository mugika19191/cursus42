/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:00:47 by imugica-          #+#    #+#             */
/*   Updated: 2024/11/26 13:38:28 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((int)size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	while (dest[i])
		i++;
	while ((i + j) < (int)(size - 1) && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	while (src[j])
		j++;
	return (i + j);
}
