/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:19:52 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/07/15 18:15:21 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

void	put_text(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 10, 20,
	0xFFFFF, "'ARROWS' to move");
	mlx_string_put(mlx->mlx, mlx->win, 10, 40,
	0xFFFFF, "'I & O' for iterations");
	mlx_string_put(mlx->mlx, mlx->win, 10, 60,
	0xFFFFF, "'Mouse Wheel' for zoom");
	mlx_string_put(mlx->mlx, mlx->win, 10, 80,
	0xFFFFF, "'C' for color");
	mlx_string_put(mlx->mlx, mlx->win, 10, 100,
	0xFFFFF, "'1','2'&'3' for fractals");
}

int		mouse_move(int x, int y, t_mlx *mlx)
{
	mlx->a = x;
	mlx->b = y;
	setall(mlx);
	return (1);
}

void	mouse_hook_zoom_in(int x, int y, t_mlx *mlx, t_zoom *zoom)
{
	zoom->tmpx = mlx->zoma1;
	zoom->tmpy = mlx->zomb1;
	zoom->oldrange_x = mlx->zoma2 - mlx->zoma1;
	zoom->oldrange_y = mlx->zomb2 - mlx->zomb1;
	zoom->newrange_x = zoom->oldrange_x * (3. / 4.);
	zoom->newrange_y = zoom->oldrange_y * (3. / 4.);
	mlx->zoma1 = zoom->tmpx + ((double)x / (double)WIN_WIDTH)
	* (zoom->oldrange_x - zoom->newrange_x);
	mlx->zoma2 = mlx->zoma1 + zoom->newrange_x;
	mlx->zomb1 = zoom->tmpy + ((double)y / (double)WIN_HEIGHT)
	* (zoom->oldrange_y - zoom->newrange_y);
	mlx->zomb2 = mlx->zomb1 + zoom->newrange_y;
}

void	mouse_hook_zoom_out(int x, int y, t_mlx *mlx, t_zoom *zoom)
{
	zoom->tmpx = mlx->zoma1;
	zoom->tmpy = mlx->zomb1;
	zoom->oldrange_x = mlx->zoma2 - mlx->zoma1;
	zoom->oldrange_y = mlx->zomb2 - mlx->zomb1;
	zoom->newrange_x = zoom->oldrange_x / (3. / 4.);
	zoom->newrange_y = zoom->oldrange_y / (3. / 4.);
	mlx->zoma1 = zoom->tmpx + ((double)x / (double)WIN_WIDTH)
	* (zoom->oldrange_x - zoom->newrange_x);
	mlx->zoma2 = mlx->zoma1 + zoom->newrange_x;
	mlx->zomb1 = zoom->tmpy + ((double)y / (double)WIN_HEIGHT)
	* (zoom->oldrange_y - zoom->newrange_y);
	mlx->zomb2 = mlx->zomb1 + zoom->newrange_y;
}

int		mouse_hook(int code, int x, int y, t_mlx *mlx)
{
	t_zoom		zoom;

	mlx->a = x;
	mlx->b = y;
	if (code == 4 || code == 1)
	{
		mouse_hook_zoom_in(x, y, mlx, &zoom);
	}
	else if (code == 5 || code == 2)
	{
		mouse_hook_zoom_out(x, y, mlx, &zoom);
	}
	setall(mlx);
	return (1);
}
