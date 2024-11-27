/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:57:06 by imugica-          #+#    #+#             */
/*   Updated: 2024/11/26 11:03:04 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	int		i;
	char	*a;
	char	*b;

	i = 0;
	a = (char *)buf1;
	b = (char *)buf2;
	if (count == 0)
		return (0);
	while (a[i] && b[i] && count--)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (a[i] - b[i]);
}
