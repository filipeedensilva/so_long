/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:38:59 by feden-pe          #+#    #+#             */
/*   Updated: 2023/09/21 18:22:05 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include"../mlx_linux/mlx.h"
# include"../mlx_linux/mlx_int.h"
# include"../libft/libft.h"
# include"../get_next_line/get_next_line.h"

# define ESC 65307
# define UP 65362
# define UP2 119
# define DOWN 65364
# define DOWN2 115
# define LEFT 65361
# define LEFT2 97
# define RIGHT 65363
# define RIGHT2 100
# define GAME game->map_var

typedef struct	s_map
{
	int	height;
	int	width;
	int	player_count;
	int	exit_count;
	int	x;
	int	y;
	int	moves;
	int	coins;
	int	coins_fill;
}		t_map;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	char	**map_copy;
	void	*floor;
	void	*wall;
	void	*player;
	void	*coin;
	void	*exit;
	int	end;
	t_map	map_var;
}		t_data;

void	argcheck(int ac, char **av);
int	map_read(char *av, t_data *game);
void	game_init(t_data *game);
void	check_map(t_data *game);
int	is_rectangule(char **map);
void	search_for_items(t_data *game);
void	flood_fill(t_data *game, int x, int y, char **map);
void	map_copy(t_data *game);
void	exit_msg(t_data *game, char *msg);
void	load_images(t_data *game);
int	key_hook(int keycode, t_data *game);
void	load_map(t_data *game);
void	movements(int keycode, t_data *game);

#endif