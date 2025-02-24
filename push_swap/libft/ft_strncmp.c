/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:00:59 by imugica-          #+#    #+#             */
/*   Updated: 2024/11/26 10:10:24 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count && (string1[i] || string2[i]))
	{
		if (string1[i] - string2[i])
			return (string1[i] - string2[i]);
		i++;
	}
	return (0);
}
