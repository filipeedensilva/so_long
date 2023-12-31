/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:36:33 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/22 12:02:56 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	horizontal_outer_wall(void)
{
	int	i;
	int	j;

	i = game()->map_var.width - 1;
	j = 0;
	while (j < i)
	{
		if (game()->map[0][j] != '1' \
		|| game()->map[game()->map_var.height - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	vertical_outer_wall(void)
{
	int	i;
	int	j;

	i = map()->width - 1;
	j = 0;
	while (j < map()->height)
	{
		if (game()->map[j][0] != '1' || game()->map[j][i] != '1')
			return (0);
		j++;
	}
	return (1);
}

void	check_map(void)
{
	if (!is_rectangule(game()->map))
		exit_msg("Map isn't a rectangule!");
	else if (!vertical_outer_wall() || !horizontal_outer_wall())
		exit_msg("Map isn't surrounded by walls!");
	else
		search_for_items();
	if (map()->player_count != 1)
		exit_msg("0 or more than 1 player on the map!");
	if (map()->exit_count != 1)
		exit_msg("0 or more than 1 exit on the map!");
	map_copy();
	flood_fill(map()->x, map()->y, game()->map_copy);
	if (map()->coins != map()->coins_fill)
		exit_msg("1 or more coins are inaccessible!");
	else if (map()->exit_count != 0)
		exit_msg("Exit is inaccessible!");
}	

void	search_for_items(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < game()->map_var.height)
	{
		j = 0;
		while (j < game()->map_var.width)
		{
			if (game()->map[i][j] != '1' && game()->map[i][j] != '0' && \
			game()->map[i][j] != 'E' && game()->map[i][j] != 'P' && \
			game()->map[i][j] != 'C')
				exit_msg("Map has invalid characters!");
			else if (game()->map[i][j] == 'P')
			{
				game()->map_var.x = j;
				game()->map_var.y = i;
				game()->map_var.player_count += 1;
			}
			game()->map_var.coins += (game()->map[i][j] == 'C');
			game()->map_var.exit_count += (game()->map[i][j] == 'E');
			j++;
		}
		i++;
	}
}

void	flood_fill(int x, int y, char **map)
{
	if (x < 0 || y < 0 || x >= game()->map_var.width || \
	y >= game()->map_var.height || map[y][x] == '1')
		return ;
	game()->map_var.coins_fill += (map[y][x] == 'C');
	game()->map_var.exit_count -= (map[y][x] == 'E');
	map[y][x] = '1';
	flood_fill(x + 1, y, map);
	flood_fill(x - 1, y, map);
	flood_fill(x, y + 1, map);
	flood_fill(x, y - 1, map);
}
