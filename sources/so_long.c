/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:48:47 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/18 19:16:59 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_data	*game(void)
{
	static t_data	game;

	return (&game);
}

t_map	*map(void)
{
	return (&game()->map_var);
}

int	main(int ac, char **av)
{
	argcheck(ac, av);
	map_read(av[1]);
	check_map();
	game_init();
	mlx_loop(game()->mlx_ptr);
}
