/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:00:17 by imugica-          #+#    #+#             */
/*   Updated: 2024/11/27 13:41:56 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putnbr(long nb, char *str, int *i)
{
	if (nb < 0)
	{
		nb *= -1;
		str[*i] = '-';
		(*i)++;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, str, i);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		str[*i] = (char)nb + '0';
		(*i)++;
	}
}

int	len(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(sizeof(char) * (len(n) + 1));
	if (!res)
		return (NULL);
	ft_putnbr((long)n, res, &i);
	res[i] = '\0';
	return (res);
}
