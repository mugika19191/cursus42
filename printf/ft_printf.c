/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:07:50 by imugica-          #+#    #+#             */
/*   Updated: 2024/12/16 14:58:47 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_long_to_hex(unsigned long pos, int *len, int mode)
{
	char	*a;

	if (mode == 0)
		a = "0123456789abcdef";
	else
		a = "0123456789ABCDEF";
	if (pos >= 16)
	{
		ft_long_to_hex(pos / 16, len, mode);
		ft_print_char(a[pos % 16]);
		(*len)++;
		return ;
	}
	if (pos < 16)
	{
		ft_print_char(a[pos]);
		(*len)++;
	}
	return ;
}

int	ft_print_mem(unsigned long pos)
{
	int	i;

	i = 0;
	if (!pos)
	{
		i += ft_print_str("(nil)", 0);
		return (i);
	}
	i += ft_print_str("0x", 0);
	ft_long_to_hex(pos, &i, 0);
	return (i);
}

int	ft_format(char c, va_list args)
{
	int	size;

	size = 0;
	if (c == 'c')
		size += ft_print_char(va_arg(args, int));
	if (c == 's')
		size += ft_print_str(va_arg(args, char *), 0);
	if (c == 'p')
		size += ft_print_mem(va_arg(args, unsigned long));
	if (c == 'd' || c == 'i')
		size += ft_print_str(ft_itoa(va_arg(args, int)), 1);
	if (c == 'u')
		size += ft_print_str(ft_itoa_un(va_arg(args, unsigned int)), 1);
	if (c == 'x')
		ft_long_to_hex(va_arg(args, unsigned int), &size, 0);
	if (c == 'X')
		ft_long_to_hex(va_arg(args, unsigned int), &size, 1);
	if (c == '%')
		size += ft_print_char('%');
	return (size);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_format(str[++i], args);
		else
			len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
