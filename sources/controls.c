/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:48:24 by feden-pe          #+#    #+#             */
/*   Updated: 2023/09/27 16:53:29 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_data *game)
{
	if (keycode == XK_Escape)
		exit_msg(game, "You have left the game.\n");
	else if (game->map[GAME.y][GAME.x] == 'E' && GAME.coins == 0)
		exit_msg(game, "You win!\n");
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, movements, game);
	mlx_hook(game->win_ptr, 17, 1L << 17, close_win, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}

