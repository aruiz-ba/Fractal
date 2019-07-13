/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:19:52 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/07/13 13:44:32 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

int		mouse_move(int x, int y, t_mlx *mlx)
{
	mlx->a = x;
	mlx->b = y;
	setall(mlx);
	return (1);
}

int		mouse_hook(int code, int x, int y, t_mlx *mlx)
{
	double		tmpx;
	double		tmpy;
	double		oldrange_x;
	double		oldrange_y;
	double		newrange_x;
	double		newrange_y;

	mlx->a = x;
	mlx->b = y;
	if (code == 4 || code == 1)
	{
		tmpx = mlx->zoma1;
		tmpy = mlx->zomb1;
		oldrange_x = mlx->zoma2 - mlx->zoma1;
		oldrange_y = mlx->zomb2 - mlx->zomb1;
		newrange_x = oldrange_x * (3. / 4.);
		newrange_y = oldrange_y * (3. / 4.);
		mlx->zoma1 = tmpx + ((double)x / (double)WIN_WIDTH)
		* (oldrange_x - newrange_x);
		mlx->zoma2 = mlx->zoma1 + newrange_x;
		mlx->zomb1 = tmpy + ((double)y / (double)WIN_HEIGHT)
		* (oldrange_y - newrange_y);
		mlx->zomb2 = mlx->zomb1 + newrange_y;
	}
	else if (code == 5 || code == 2)
	{
		tmpx = mlx->zoma1;
		tmpy = mlx->zomb1;
		oldrange_x = mlx->zoma2 - mlx->zoma1;
		oldrange_y = mlx->zomb2 - mlx->zomb1;
		newrange_x = oldrange_x / (3. / 4.);
		newrange_y = oldrange_y / (3. / 4.);
		mlx->zoma1 = tmpx + ((double)x / (double)WIN_WIDTH)
		* (oldrange_x - newrange_x);
		mlx->zoma2 = mlx->zoma1 + newrange_x;
		mlx->zomb1 = tmpy + ((double)y / (double)WIN_HEIGHT)
		* (oldrange_y - newrange_y);
		mlx->zomb2 = mlx->zomb1 + newrange_y;
	}
	setall(mlx);
	return (1);
}
