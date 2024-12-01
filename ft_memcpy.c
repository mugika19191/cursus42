/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:24:14 by imugica-          #+#    #+#             */
/*   Updated: 2024/11/25 11:36:22 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	int		i;
	char	*str;

	i = 0;
	str = (unsigned char *)dest;
	while (i < count)
	{
		str[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
