/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:50:29 by imugica-          #+#    #+#             */
/*   Updated: 2025/02/04 16:05:24 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define UARROW 65362
# define LARROW 65361
# define DARROW 65364
# define RARROW 65363
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

typedef struct s_texture
{
	char		*path;
	void		*img;
	int			w;
	int			h;
}				t_texture;

typedef struct s_map
{
	char		**content;
	int			tile_w;
	int			tile_h;
	int			total_h;
	int			total_w;
	t_texture	wall;
	t_texture	empty;
	t_texture	star;
	t_texture	door;
}				t_map;

typedef struct s_player
{
	int			pos_x;
	int			pos_y;
	int			moves;
	t_texture	text;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_map		*map;
	t_player	*player;
}				t_game;

int				check_extension(const char *string);
int				read_file(const char *string);
void			load_text(t_texture *text, char *path, void *mlx);
int				get_nlines(const char *string);
int				all_checks(char *string);
int				is_rect(const char *string);
void			load_all_text(t_map *map, t_player *player, void *mlx);
void			load_content(t_map *map, int length, char *path,
					t_player *player);
int				get_nlines(const char *string);
int				close_window(t_game *game);
int				contains_char(char a, char *string);
int				count_player(char *string);
int				count_doors(char *string);
int				contains_other_char(char *string);
int				count_others(char *string);
int				solve_maze(char **content, int x, int y);
int				collect_left(t_map map, int error);
void			print_moves(int moves);
int				clean_content(t_game *game);
int				print_error(int error);
int				count_objects(char *string);
int				check_walls(t_map *map);
int				doors_left(t_map map);

#endif