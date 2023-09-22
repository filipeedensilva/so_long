/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long#2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:57:01 by feden-pe          #+#    #+#             */
/*   Updated: 2023/09/16 18:33:53 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "../includes/so_long.h"

int	mouse_hook(int button, int x, int y, t_var *vars)
{
	ft_printf("You can't use your mouse!\n");
	return (0);
}

int	key_hook(int keycode, t_var *vars)
{
	static int	moves;

	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		ft_printf("Movements: %d\n", moves++);
	else
		ft_printf("%d\n", keycode);
	return (0);
}

int	main(void)
{
	t_var	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 990, 540, "lol");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}*/
