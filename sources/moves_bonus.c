/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:19:32 by feden-pe          #+#    #+#             */
/*   Updated: 2023/09/28 16:33:36 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_moves(t_data *game)
{
	char	*moves;

	moves = ft_itoa(GAME.moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 20, 35, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 65, 35, 0xFFFFFF, moves);
	free(moves);
}
