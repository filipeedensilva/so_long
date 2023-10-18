/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:38:59 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/18 19:42:00 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <X11/X.h>

# define ESC 65307

typedef struct s_map
{
	int	height;
	int	width;
	int	player_count;
	int	exit_count;
	int	x;
	int	y;
	int	moves;
	int	dir;
	int	coins;
	int	coins_fill;
}		t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	char	**map_copy;
	void	*floor;
	void	*wall;
	void	*player[2];
	void	*coin;
	void	*exit;
	int		end;
	t_map	map_var;
}		t_data;

void	argcheck(int ac, char **av);
int		map_read(char *av);
void	game_init(void);
void	check_map(void);
int		is_rectangule(char **map);
void	search_for_items(void);
void	flood_fill(int x, int y, char **map);
void	map_copy(void);
void	exit_msg(char *msg);
void	load_images(void);
int		key_hook(int keycode);
void	load_map(void);
int		movements(int keycode);
void	display_moves(void);
int		close_win(void);
void	free_map(char **map);
t_data	*game(void);
t_map	*map(void);

#endif
