/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:35:48 by imugica-          #+#    #+#             */
/*   Updated: 2025/02/04 16:08:04 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_back(void *mlx, void *mlx_win, t_map map)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (h < (map.total_h / map.tile_h))
	{
		while (w < (map.total_w / map.tile_w))
		{
			if (map.content[h][w] == '1')
				mlx_put_image_to_window(mlx, mlx_win, map.wall.img, w
					* map.tile_w, map.tile_h * h);
			else
				mlx_put_image_to_window(mlx, mlx_win, map.empty.img, w
					* map.tile_w, map.tile_h * h);
			w++;
		}
		w = 0;
		h++;
	}
	return ;
}

void	draw_empty(void *mlx, void *mlx_win, t_map map, t_player player)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (h < (map.total_h / map.tile_h))
	{
		while (w < (map.total_w / map.tile_w))
		{
			if (map.content[h][w] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, map.star.img, w
					* map.tile_w, map.tile_h * h);
			else if (map.content[h][w] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, map.door.img, w
					* map.tile_w, map.tile_h * h);
			else if (map.content[h][w] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, player.text.img, w
					* map.tile_w, map.tile_h * h);
			w++;
		}
		w = 0;
		h++;
	}
	return ;
}

void	move_player(int x, int y, t_game *game)
{
	int	player_x;
	int	player_y;

	player_x = game->player->pos_x;
	player_y = game->player->pos_y;
	if (x < 0 || y < 0)
		return ;
	if (game->map->content[x][y] == '1')
		return ;
	else
	{
		game->player->moves++;
		print_moves(game->player->moves);
		if (game->map->content[x][y] == 'E' && !collect_left(*game->map, 0))
			close_window(game);
		if (game->map->content[player_x][player_y] != 'E')
			game->map->content[player_x][player_y] = '0';
		game->player->pos_x = x;
		game->player->pos_y = y;
		if (game->map->content[x][y] != 'E')
			game->map->content[x][y] = 'P';
	}
	draw_back(game->mlx, game->mlx_win, *game->map);
	draw_empty(game->mlx, game->mlx_win, *game->map, *game->player);
	return ;
}

int	input(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_window(game);
	else if (keycode == KEY_W || keycode == UARROW)
		move_player(game->player->pos_x - 1, game->player->pos_y, game);
	else if (keycode == KEY_A || keycode == LARROW)
		move_player(game->player->pos_x, game->player->pos_y - 1, game);
	else if (keycode == KEY_S || keycode == DARROW)
		move_player(game->player->pos_x + 1, game->player->pos_y, game);
	else if (keycode == KEY_D || keycode == RARROW)
		move_player(game->player->pos_x, game->player->pos_y + 1, game);
	return (0);
}

int	main(int count, char **args)
{
	t_map		map;
	t_game		game;
	t_player	player;

	if (count != 2 || !all_checks(&args[1][0]))
		return (0);
	game.mlx = mlx_init();
	load_all_text(&map, &player, game.mlx);
	load_content(&map, get_nlines(args[1]), args[1], &player);
	game.mlx_win = mlx_new_window(game.mlx, map.total_w, map.total_h, "#1");
	game.map = &map;
	game.player = &player;
	if (check_walls(game.map))
		close_window(&game);
	solve_maze(game.map->content, player.pos_x, player.pos_y);
	if (collect_left(*game.map, 1) || doors_left(*game.map))
		close_window(&game);
	clean_content(&game);
	load_content(&map, get_nlines(args[1]), args[1], &player);
	draw_back(game.mlx, game.mlx_win, map);
	draw_empty(game.mlx, game.mlx_win, map, player);
	mlx_hook(game.mlx_win, 17, 0, close_window, &game);
	mlx_key_hook(game.mlx_win, input, &game);
	mlx_loop(game.mlx);
	return (0);
}
