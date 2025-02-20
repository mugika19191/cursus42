/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:45:38 by imugica-          #+#    #+#             */
/*   Updated: 2025/01/28 13:12:21 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collect_left(t_map map, int error)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (map.total_h / map.tile_h))
	{
		while (j < (map.total_w / map.tile_w))
		{
			if (map.content[i][j] == 'C')
			{
				if (error)
					print_error(10);
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	solve_maze(char **content, int x, int y)
{
	content[x][y] = 'X';
	if (content[x][y - 1] != '1' && content[x][y - 1] != 'X')
		solve_maze(content, x, y - 1);
	if (content[x + 1][y] != '1' && content[x + 1][y] != 'X')
		solve_maze(content, x + 1, y);
	if (content[x][y + 1] != '1' && content[x][y + 1] != 'X')
		solve_maze(content, x, y + 1);
	if (content[x - 1][y] != '1' && content[x - 1][y] != 'X')
		solve_maze(content, x - 1, y);
	return (1);
}

void	print_moves(int moves)
{
	char	*str;

	str = ft_itoa(moves);
	write(1, "Moves: ", 7);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
	return ;
}

int	print_error(int error)
{
	write(1, "Error: ", 7);
	if (error == 1)
		write(1, "wrong extension.", 16);
	else if (error == 2)
		write(1, "can not read.", 13);
	else if (error == 3 || error == 4)
		write(1, "Not enough lines.", 17);
	else if (error == 5)
		write(1, "Not a rect.", 11);
	else if (error == 6)
		write(1, "Only one door pls.", 18);
	else if (error == 7)
		write(1, "Only one player pls.", 20);
	else if (error == 8)
		write(1, "Weird char insde map.", 21);
	else if (error == 9)
		write(1, "at least one object pls.", 24);
	else if (error == 10)
		write(1, "can not solve.", 14);
	else if (error == 11)
		write(1, "no walls.", 9);
	write(1, "\n", 1);
	return (0);
}

int	count_objects(char *string)
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
		d_count += contains_char('C', str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (d_count);
}
