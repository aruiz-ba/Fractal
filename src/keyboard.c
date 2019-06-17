/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:12:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/06/14 15:07:07 by aruiz-ba         ###   ########.fr       */
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
		mlx->thr[i].a = mlx->a;
		mlx->thr[i].b = mlx->b;
		mlx->thr[i].x = 0;
		mlx->thr[i].y = i;
		mlx->thr[i].min_k = i * 2800;
		mlx->thr[i].end_k = (i * 2800) + 2800;
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
		mlx->a = mlx->a + 0.1;
		mlx->b = mlx->b - 0.1;
	}
	if (key == P)
	{
		mlx->a = mlx->a - 0.001;
		mlx->b = mlx->b + 0.001;
	}
	if(key == 13)
	{
		mlx->a = mlx->a - 0.1;
	}
	if(key == O || key == P || key == 13)
		setall(mlx);
	return (1);
}
