/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:32:35 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/18 20:32:03 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_images(void)
{
	int	i;

	(game()->player[0]) = mlx_xpm_file_to_image(game()->mlx_ptr, \
	"./img/snoop.xpm", &i, &i);
	(game()->player[1]) = mlx_xpm_file_to_image(game()->mlx_ptr, \
	"./img/snoop2.xpm", &i, &i);
	(game()->floor) = mlx_xpm_file_to_image(game()->mlx_ptr, \
	"./img/floor.xpm", &i, &i);
	(game()->wall) = mlx_xpm_file_to_image(game()->mlx_ptr, \
	"./img/wall.xpm", &i, &i);
	(game()->coin) = mlx_xpm_file_to_image(game()->mlx_ptr, \
	"./img/joint.xpm", &i, &i);
	(game()->exit) = mlx_xpm_file_to_image(game()->mlx_ptr, \
	"./img/door.xpm", &i, &i);
}
