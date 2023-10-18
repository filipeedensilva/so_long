/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:05:41 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/18 20:24:48 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	moves(int x, int y);

int	movements(int keycode)
{
	if (keycode == XK_Up || keycode == XK_w)
		moves(0, -1);
	else if (keycode == XK_Right || keycode == XK_d)
		moves(1, 0);
	else if (keycode == XK_Left || keycode == XK_a)
		moves(-1, 0);
	else if (keycode == XK_Down || keycode == XK_s)
		moves(0, 1);
	display_moves();
	return (0);
}

void	moves(int x, int y)
{
	if (x == 1)
		map()->dir = 0;
	else if (x == -1)
		map()->dir = 1;
	x += map()->x;
	y += map()->y;
	if (game()->map[y][x] == 'E' && map()->coins == 0)
	{
		mlx_clear_window(game()->mlx_ptr, game()->win_ptr);
		game()->map[map()->y][map()->x] = '0';
		map()->moves++;
		game()->end++;
		exit_msg("You win!");
	}
	else if (game()->map[y][x] == '1' || game()->map[y][x] == 'E')
		return ;
	if (game()->map[y][x] == 'C')
		map()->coins--;
	mlx_clear_window(game()->mlx_ptr, game()->win_ptr);
	game()->map[y][x] = 'P';
	game()->map[map()->y][map()->x] = '0';
	map()->moves++;
	load_map();
	map()->x = x;
	map()->y = y;
}
