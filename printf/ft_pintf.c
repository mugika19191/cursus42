/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:07:50 by imugica-          #+#    #+#             */
/*   Updated: 2024/12/09 18:58:54 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_print_char(str[i++]);
	return (i);
}

void    ft_long_to_hex(long long pos, int *len)
{
    char    *a;
    
    a = "0123456789abcdef";
    if (pos >= 16)
    {
        ft_long_to_hex(pos / 16, len);
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

int	ft_print_mem(long long pos)
{
	int	i;

	i = 0;
	i += ft_print_str("0x");
    ft_long_to_hex(pos, &i);
	return (i);
}

int	ft_format(char c, va_list args)
{
	int	size;

	size = 0;
	if (c == 'c')
		size += ft_print_char(va_arg(args, int));
	if (c == 's')
		size += ft_print_str(va_arg(args, char *));
	if (c == 'p')
		size += ft_print_mem(va_arg(args,long long));
	if (c == 'd')
		printf("");
	if (c == 'i')
		printf("");
	if (c == 'u')
		printf("");
	if (c == 'x')
		printf("");
	if (c == 'X')
		printf("");
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

int	main()
{
	int i = ft_printf("re%s%%","tard");
	printf("\n%p\n",&i);
	ft_printf("\n%p",&i);
	return (0);	
}
