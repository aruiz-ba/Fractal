/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:12:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/06/24 21:08:47 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

void	setall(t_mlx *mlx)
{
	int	i;
	t_cast cst;

	i = -1;
	freeimage(&mlx->img->ptr);
	mlx_clear_window(mlx->mlx, mlx->win);
	while(++i < THR_NUM)
	{
		mlx->thr[i].image_string = &mlx->img->ptr;
		mlx->thr[i].tr1 = mlx->a;
		mlx->thr[i].tr2 = mlx->b;
		mlx->thr[i].zom1 = mlx->zom1;
		mlx->thr[i].zom2 = mlx->zom2;
		mlx->thr[i].x = 0;
		mlx->thr[i].y = i;
		mlx->thr[i].min_k = i * mlx->k_in;
		mlx->thr[i].end_k = (i * mlx->k_in) + mlx->k_in;
		cst.f = mlx->f;
		cst.th[i] = &mlx->thr[i];
		cst.thr = &mlx->thr[i];
		pthread_create(&mlx->thr[i].tid, NULL, cast, &cst);
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
		mlx->zom1 +=  0.01;
		mlx->zom2 -=  0.01;
	}
	if (key == P)
	{
		mlx->zom1 -=  0.01;
		mlx->zom2 +=  0.01;
	}
	if(key == O || key == P || key == 13 || key == 7 || key == 6)
		setall(mlx);
	return (1);
}
