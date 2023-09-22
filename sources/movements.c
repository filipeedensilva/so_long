/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:05:41 by feden-pe          #+#    #+#             */
/*   Updated: 2023/09/22 14:35:09 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_data *game);
void	move_right(t_data *game);
void	move_left(t_data *game);
void	move_down(t_data *game);

void	movements(int keycode, t_data *game)
{
	if (keycode == UP || keycode == UP2)
		move_up(game);
	else if (keycode == RIGHT || keycode == RIGHT2)
		move_right(game);
	else if (keycode == LEFT || keycode == LEFT2)
		move_left(game);
	else if (keycode == DOWN || keycode == DOWN2)
		move_down(game);
}

void	move_up(t_data *game)
{
	GAME.y -= 1;
	if (game->map[GAME.y][GAME.x] == 'E' && GAME.coins == 0)
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		game->map[GAME.y + 1][GAME.x] = '0';
		GAME.moves++;
		game->end++;
		load_map(game);
	}
	else if (game->map[GAME.y][GAME.x] == '0' || game->map[GAME.y][GAME.x] == 'C')
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		if (game->map[GAME.y][GAME.x] == 'C')
			GAME.coins--;
		game->map[GAME.y][GAME.x] = 'P';
		game->map[GAME.y + 1][GAME.x] = '0';
		GAME.moves++;
		load_map(game);
	}
	else
		GAME.y += 1;
}

void	move_right(t_data *game)
{
	GAME.x += 1;
	if (game->map[GAME.y][GAME.x] == 'E' && GAME.coins == 0)
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		game->map[GAME.y][GAME.x - 1] = '0';
		GAME.moves++;
		game->end++;
		load_map(game);
	}
	else if (game->map[GAME.y][GAME.x] == '1' || game->map[GAME.y][GAME.x] == 'E')
		GAME.x -= 1;
	else
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		if (game->map[GAME.y][GAME.x] == 'C')
			GAME.coins--;
		game->map[GAME.y][GAME.x] = 'P';
		game->map[GAME.y][GAME.x - 1] = '0';
		GAME.moves++;
		load_map(game);
	}
}

void	move_left(t_data *game)
{
	GAME.x -= 1;
	if (game->map[GAME.y][GAME.x] == 'E' && GAME.coins == 0)
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		game->map[GAME.y][GAME.x + 1] = '0';
		GAME.moves++;
		game->end++;
		load_map(game);
	}
	else if (game->map[GAME.y][GAME.x] == '1' || game->map[GAME.y][GAME.x] == 'E')
		GAME.x += 1;
	else
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		if (game->map[GAME.y][GAME.x] == 'C')
			GAME.coins--;
		game->map[GAME.y][GAME.x] = 'P';
		game->map[GAME.y][GAME.x + 1] = '0';
		GAME.moves++;
		load_map(game);
	}
}

void	move_down(t_data *game)
{
	GAME.y += 1;
	if (game->map[GAME.y][GAME.x] == 'E' && GAME.coins == 0)
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		game->map[GAME.y - 1][GAME.x] = '0';
		GAME.moves++;
		game->end++;
		load_map(game);
	}
	else if (game->map[GAME.y][GAME.x] == '1' || game->map[GAME.y][GAME.x] == 'E')
		GAME.y -= 1;
	else
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		if (game->map[GAME.y][GAME.x] == 'C')
			GAME.coins--;
		game->map[GAME.y][GAME.x] = 'P';
		game->map[GAME.y - 1][GAME.x] = '0';
		GAME.moves++;
		load_map(game);
	}
}
