/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:12:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/07/03 19:50:06 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

void	setall(t_mlx *mlx)
{
	int	i;

	i = -1;
	freeimage(&mlx->img->ptr);
	mlx_clear_window(mlx->mlx, mlx->win);
	while(++i < THR_NUM)
	{
		mlx->thr[i].image_string = &mlx->img->ptr;
		mlx->thr[i].tr1 = mlx->a;
		mlx->thr[i].tr2 = mlx->b;
		mlx->thr[i].zoma1 = mlx->zoma1;
		mlx->thr[i].zoma2 = mlx->zoma2;
		mlx->thr[i].x = mlx->x;
		mlx->thr[i].y = i + mlx->y;
		mlx->thr[i].min_k = i * mlx->k_in;
		mlx->thr[i].end_k = (i * mlx->k_in) + mlx->k_in;
		mlx->thr[i].f = mlx->f;
		pthread_create(&mlx->thr[i].tid, NULL, cast, &mlx->thr[i]);
	}
	i = -1;
	while(++i < THR_NUM)
	{
		pthread_join(mlx->thr[i].tid, NULL);
	}	
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->image, 0, 0);
}

int		deal_key(int key, t_mlx *mlx)
{
	if (key == O)
	{
		mlx->x += WIN_WIDTH;
		mlx->y += WIN_HEIGHT;
		mlx->x *= 1.2;
		mlx->y *= 1.2;
		//mlx->zoma1 /=  1.1;
		//mlx->zoma2 /=  1.1;
	}
	if (key == P)
	{
		mlx->zoma1 *=  1.1;
		mlx->zoma2 *=  1.1;
	}
	if (key == UP)
		mlx->y -=  50;
	if (key == DOWN)
		mlx->y +=  50;
	if (key == LEFT)
		mlx->x -=  50;
	if (key == RIGHT)
		mlx->x +=  50;
	if (key == ESC)
	{
		exit(0);
	}
	if(key == O || key == P || key == U || key == I || key == T || key == Y || key == ESC || key == UP || key == DOWN || key == LEFT || key == RIGHT)
		setall(mlx);
	printf("TECLA:%i\n", key);
	return (1);
}
