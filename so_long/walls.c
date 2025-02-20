/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:16:11 by imugica-          #+#    #+#             */
/*   Updated: 2025/02/04 16:08:23 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (map->total_h / map->tile_h))
	{
		while (j < (map->total_w / map->tile_w))
		{
			if (i == 0 || i == ((map->total_h / map->tile_h) - 1))
			{
				if (map->content[i][j] != '1')
					return (!print_error(11));
			}
			if (j == 0 || j == ((map->total_w / map->tile_w) - 1))
			{
				if (map->content[i][j] != '1')
					return (!print_error(11));
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	doors_left(t_map map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (map.total_h / map.tile_h))
	{
		while (j < (map.total_w / map.tile_w))
		{
			if (map.content[i][j] == 'E')
			{
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
