/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:32:35 by feden-pe          #+#    #+#             */
/*   Updated: 2023/09/19 20:08:35 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_images(t_data *game)
{
	int	i;

	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "./img/test.xpm", &i, &i);
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr, "./img/floor.xpm", &i, &i);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "./img/wall.xpm", &i, &i);
	game->coin = mlx_xpm_file_to_image(game->mlx_ptr, "./img/coin.xpm", &i, &i);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "./img/exit.xpm", &i, &i);
}
