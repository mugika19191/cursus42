/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:31:15 by imugica-          #+#    #+#             */
/*   Updated: 2025/01/29 17:54:49 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player(t_player *player, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	player->moves = 0;
	while (x < (map->total_h / map->tile_h))
	{
		while (y < (map->total_w / map->tile_w))
		{
			if (map->content[x][y] == 'P')
			{
				player->pos_x = x;
				player->pos_y = y;
				return ;
			}
			y++;
		}
		y = 0;
		x++;
	}
	return ;
}

void	fill_map(t_map *map, int fd)
{
	char	*str;
	int		i;

	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		(map->content)[i++] = ft_strdup(str);
		free(str);
		str = get_next_line(fd);
	}
	return ;
}

void	load_content(t_map *map, int length, char *path, t_player *player)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ;
	map->content = malloc(sizeof(char *) * (length + 1));
	if (map->content == NULL)
	{
		close(fd);
		return ;
	}
	fill_map(map, fd);
	(map->content)[length] = NULL;
	map->total_h = length * map->tile_h;
	map->total_w = (ft_strlen((map->content)[0]) - 1) * map->tile_w;
	set_player(player, map);
	close(fd);
	return ;
}

void	load_text(t_texture *text, char *path, void *mlx)
{
	(*text).img = mlx_xpm_file_to_image(mlx, path, &(*text).w, &(*text).h);
	return ;
}

void	load_all_text(t_map *map, t_player *player, void *mlx)
{
	load_text(&(*player).text, "textures/player.xpm", mlx);
	load_text(&(*map).empty, "textures/empty.xpm", mlx);
	load_text(&(*map).wall, "textures/wall.xpm", mlx);
	load_text(&(*map).star, "textures/Estrellita.xpm", mlx);
	load_text(&(*map).door, "textures/door.xpm", mlx);
	(*map).tile_h = (*map).empty.h;
	(*map).tile_w = (*map).empty.w;
	return ;
}
