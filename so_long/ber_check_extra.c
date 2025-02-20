/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_check_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:36:17 by imugica-          #+#    #+#             */
/*   Updated: 2025/01/28 13:24:01 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	contains_char(char a, char *string)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (string[i])
	{
		if (string[i] == a)
			count++;
		i++;
	}
	return (count);
}

int	contains_other_char(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] != 'P' && string[i] != 'E' && string[i] != 'C'
			&& string[i] != '0' && string[i] != '1' && string[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	count_player(char *string)
{
	int		p_count;
	int		fd;
	char	*str;

	p_count = 0;
	fd = open(string, O_RDONLY);
	if (fd == -1)
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		p_count += contains_char('P', str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (p_count);
}

int	count_doors(char *string)
{
	int		d_count;
	int		fd;
	char	*str;

	d_count = 0;
	fd = open(string, O_RDONLY);
	if (fd == -1)
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		d_count += contains_char('E', str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (d_count);
}

int	count_others(char *string)
{
	int		fd;
	char	*str;
	int		ans;

	ans = 0;
	fd = open(string, O_RDONLY);
	if (fd == -1)
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		if (contains_other_char(str))
			ans = 1;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (ans);
}
