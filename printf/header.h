/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:56:08 by imugica-          #+#    #+#             */
/*   Updated: 2024/12/11 16:56:14 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);
int		ft_format(char c, va_list args);
int		ft_print_mem(long long pos);
void	ft_long_to_hex(long long pos, int *len, int mode);
int		ft_print_str(char *str);
int		ft_print_char(char c);
void	ft_putnbr(long nb, char *str, unsigned int *i);
int		len(int nb);
char	*ft_itoa(int n);
char	*ft_itoa_un(unsigned int n);

#endif