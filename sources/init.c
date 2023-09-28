/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:49:24 by feden-pe          #+#    #+#             */
/*   Updated: 2023/09/28 16:31:51 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_map(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_var.height)
	{
		j = 0;
		while (j < game->map_var.width)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall, j * 64, i * 64);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor, j * 64, i * 64);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->coin, j * 64, i * 64);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player, j * 64, i * 64);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	game_init(t_data *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map_var.width * 64, game->map_var.height * 64, "so_long");
	load_images(game);
	load_map(game);
	display_moves(game);
	mlx_key_hook(game->win_ptr, key_hook, game);
}

