/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:03:40 by imugica-          #+#    #+#             */
/*   Updated: 2024/11/26 12:15:44 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t elems, size_t size)
{
	char	*ptr;
	size_t	size2;

	ptr = malloc(elems * size);
	if (!ptr)
		return (NULL);
	size2 = 0;
	while (size2 < elems)
		ptr[size2++] = 0;
	return ((void *)ptr);
}
