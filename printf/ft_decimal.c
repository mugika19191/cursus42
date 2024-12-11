/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:45:02 by imugica-          #+#    #+#             */
/*   Updated: 2024/12/11 16:51:52 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putnbr(long nb, char *str, unsigned int *i)
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
	char			*res;
	unsigned int	i;

	i = 0;
	res = (char *)malloc(sizeof(char) * (len(n) + 1));
	if (!res)
		return (0);
	ft_putnbr((long)n, res, &i);
	res[i] = '\0';
	return (res);
}

char	*ft_itoa_un(unsigned int n)
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = (char *)malloc(sizeof(char) * (len(n) + 1));
	if (!res)
		return (0);
	ft_putnbr((long)n, res, &i);
	res[i] = '\0';
	return (res);
}
