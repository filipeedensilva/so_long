/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:48:24 by feden-pe          #+#    #+#             */
/*   Updated: 2023/09/22 14:30:41 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_data *game)
{
	if (keycode == ESC)
		exit_msg(game, 0);
	else if (game->end == 1)
		exit_msg(game, "You win!\n");
	else
	{
		movements(keycode, game);
		ft_printf("Moves: %d\n", GAME.moves);
	}
	return (0);
}

