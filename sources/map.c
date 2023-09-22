/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:56:39 by feden-pe          #+#    #+#             */
/*   Updated: 2023/09/21 18:21:55 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>

void	argcheck(int ac, char **av)
{
	int	i;
	int	j;
	char	*ber;

	i = 0;
	j = 0;
	ber = ".ber";

	if (ac != 2)
	{
		ft_printf("Invalid number of arguments!\nUsage: ./so_long 'map.ber'\n");
		exit(EXIT_FAILURE);
	}
	i = ft_strlen(av[1]) - 4;
	while (av[1][i])
	{
		if (av[1][i++] != ber[j++])
		{
			ft_printf("Invalid map! Use a .ber file for the map\n");
			exit(0);
		}
	}
}

int	is_rectangule(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}

int	map_width(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (line[i - 1] == '\n')
		i--;
	return (i);
}

void	add_line(t_data *game, int fd, int height)
{
	char	*line;
	
	line = get_next_line(fd);
	if (line)
		add_line(game, fd, height + 1);
	else if (height > 0)
	{
		game->map = malloc(sizeof(char *) * (height + 1));
		game->map_var.height = height;
	}
	if (game->map)
		game->map[height] = line;
}

int	map_read(char *av, t_data *game)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (0);
	add_line(game, fd, 0);
	close(fd);
	if (game->map)
		game->map_var.width = map_width(game->map[0]);
	else
		exit_msg(game, "Map is empty!");
	return (1);
}

