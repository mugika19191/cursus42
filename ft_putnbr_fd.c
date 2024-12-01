/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:32:36 by imugica-          #+#    #+#             */
/*   Updated: 2024/11/28 15:32:36 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_putnbr_fd(int n, int fd)
{
    char    *str;
    str = ft_itoa(n);
    ft_putstr_fd(str, fd);
}