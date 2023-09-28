/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:48:47 by feden-pe          #+#    #+#             */
/*   Updated: 2023/09/27 16:52:41 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	static t_data	game;
	argcheck(ac, av);
	map_read(av[1], &game);
	check_map(&game);
	printf("\nCoins in map: %d\nCoins in fill: %d\nExit: %d\n", game.map_var.coins, game.map_var.coins_fill, game.map_var.exit_count);
	game_init(&game);
	mlx_loop(game.mlx_ptr);
}

