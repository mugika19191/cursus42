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
#include "libft.h"

void	*ft_calloc(size_t elems, size_t size)
{
	void	*ptr;

	ptr = malloc(elems * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * elems);
	return (ptr);
}
