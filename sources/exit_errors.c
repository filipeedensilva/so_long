/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:02:19 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/03 19:28:02 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	if (map)
		free(map);
}

void	exit_msg(t_data *game, char *msg)
{
	if (ft_strncmp(msg, "You win!", ft_strlen(msg)))
		ft_printf("\n%s\n", msg);
	else if (msg)
		ft_printf("\nError: %s\n", msg);
	free_map(game->map);
	if (game->map_copy)
		free_map(game->map_copy);
	if (game->mlx_ptr)
	{
		mlx_destroy_image(game->mlx_ptr, game->player);
		mlx_destroy_image(game->mlx_ptr, game->exit);
		mlx_destroy_image(game->mlx_ptr, game->coin);
		mlx_destroy_image(game->mlx_ptr, game->floor);
		mlx_destroy_image(game->mlx_ptr, game->wall);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(0);
}

int	close_win(t_data *game)
{
	free_map(game->map);
	free_map(game->map_copy);
	mlx_destroy_image(game->mlx_ptr, game->player);
	mlx_destroy_image(game->mlx_ptr, game->exit);
	mlx_destroy_image(game->mlx_ptr, game->coin);
	mlx_destroy_image(game->mlx_ptr, game->floor);
	mlx_destroy_image(game->mlx_ptr, game->wall);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}
