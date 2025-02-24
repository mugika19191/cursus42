/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:57:06 by imugica-          #+#    #+#             */
/*   Updated: 2024/12/10 19:17:24 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	int				i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)buf1;
	b = (unsigned char *)buf2;
	if (count == 0)
		return (0);
	while (a[i] && b[i] && count--)
	{
		if (a[i] != b[i] || !count)
			return (a[i] - b[i]);
		i++;
	}
	return (a[i] - b[i]);
}
