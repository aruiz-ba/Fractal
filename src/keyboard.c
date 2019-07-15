/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:12:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/07/15 17:44:09 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

void	sub_setall(t_mlx *mlx, int i)
{
	mlx->thr[i].image_string = &mlx->img->ptr;
	mlx->thr[i].tr1 = mlx->a;
	mlx->thr[i].tr2 = mlx->b;
	mlx->thr[i].zoma1 = mlx->zoma1;
	mlx->thr[i].zoma2 = mlx->zoma2;
	mlx->thr[i].zomb1 = mlx->zomb1;
	mlx->thr[i].zomb2 = mlx->zomb2;
	mlx->thr[i].x = mlx->x;
	mlx->thr[i].y = i + mlx->y;
	mlx->thr[i].color = mlx->color;
	mlx->thr[i].min_k = i * mlx->k_in;
	mlx->thr[i].end_k = (i * mlx->k_in) + mlx->k_in;
	mlx->thr[i].n = 0;
	mlx->thr[i].max_it = mlx->max_it;
	mlx->thr[i].f = mlx->f;
	pthread_create(&mlx->thr[i].tid, NULL, cast, &mlx->thr[i]);
}

void	setall(t_mlx *mlx)
{
	int	i;

	i = -1;
	freeimage(&mlx->img->ptr);
	mlx_clear_window(mlx->mlx, mlx->win);
	while (++i < THR_NUM)
	{
		sub_setall(mlx, i);
	}
	i = -1;
	while (++i < THR_NUM)
	{
		pthread_join(mlx->thr[i].tid, NULL);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->image, 0, 0);
	put_text(mlx);
}

int		sub_deal_key(int key, t_mlx *mlx)
{
	if (key == ESC)
		exit(0);
	if (key == C)
		mlx->color -= 100;
	if (key == U || key == I || key == T || key == Y || key == ESC
	|| key == UP || key == DOWN || key == LEFT || key == RIGHT
	|| key == T1 || key == T2 || key == T3 || key == I || key == O || key == C)
		setall(mlx);
	return (1);
}

int		deal_key(int key, t_mlx *mlx)
{
	if (key == T1)
		mlx->f = mandelbrot;
	if (key == T2)
	{
		mlx->a = -0.8;
		mlx->b = 0;
		mlx->f = julia_no_mouse;
	}
	if (key == T3)
		mlx->f = burningship;
	if (key == UP)
		mlx->y -= 50;
	if (key == I)
		mlx->max_it += 10;
	if (key == O)
		mlx->max_it -= 10;
	if (key == DOWN)
		mlx->y += 50;
	if (key == LEFT)
		mlx->x -= 50;
	if (key == RIGHT)
		mlx->x += 50;
	sub_deal_key(key, mlx);
	return (1);
}
