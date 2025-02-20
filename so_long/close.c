/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:52:18 by imugica-          #+#    #+#             */
/*   Updated: 2025/01/28 11:06:48 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clean_content(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->content[i])
	{
		free(game->map->content[i]);
		i++;
	}
	free(game->map->content);
	return (0);
}

int	close_window(t_game *game)
{
	clean_content(game);
	mlx_destroy_image(game->mlx, game->player->text.img);
	mlx_destroy_image(game->mlx, game->map->door.img);
	mlx_destroy_image(game->mlx, game->map->wall.img);
	mlx_destroy_image(game->mlx, game->map->empty.img);
	mlx_destroy_image(game->mlx, game->map->star.img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}
