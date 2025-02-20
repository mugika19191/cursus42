/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:53:43 by imugica-          #+#    #+#             */
/*   Updated: 2025/01/28 11:54:03 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rect(const char *string)
{
	int		i;
	int		fd;
	char	*str;
	int		len;

	i = 1;
	len = 0;
	fd = open(string, O_RDONLY);
	if (fd == -1)
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		if (len == 0)
			len = ft_strlen(str);
		if (len != ft_strlen(str) || len == 0)
			i = 0;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	get_nlines(const char *string)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(string, O_RDONLY);
	if (fd == -1)
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		i++;
		free(str);
		str = get_next_line(fd);
	}
	return (i);
}

int	read_file(const char *string)
{
	int	fd;

	fd = open(string, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	check_extension(const char *string)
{
	int	len;

	len = ft_strlen(string);
	if (len < 5)
		return (0);
	if (!ft_strncmp(&string[len - 4], ".ber", len))
		return (1);
	else
		return (0);
}

int	all_checks(char *string)
{
	if (!check_extension(string))
		return (print_error(1));
	if (!read_file(string))
		return (print_error(2));
	if (!get_nlines(string))
		return (print_error(3));
	if (get_nlines(string) < 3)
		return (print_error(4));
	if (!is_rect(string))
		return (print_error(5));
	if (count_doors(string) != 1)
		return (print_error(6));
	if (count_player(string) != 1)
		return (print_error(7));
	if (count_others(string))
		return (print_error(8));
	if (count_objects(string) <= 0)
		return (print_error(9));
	return (1);
}
