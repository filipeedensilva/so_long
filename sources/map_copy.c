/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:19:27 by feden-pe          #+#    #+#             */
/*   Updated: 2023/09/28 16:55:37 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_copy(t_data *game)
{
	char	**temp;
	int	i;

	temp = malloc(sizeof(char *) * (game->map_var.height + 1));
	if (!temp)
		return ;
	i = 0;
	while (i < game->map_var.height)
	{
		temp[i] = ft_strdup(game->map[i]);
		i++;
	}
	game->map_copy = temp;
}
