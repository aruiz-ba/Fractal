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
	pthread_t   tid[1];		

	i = -1;
	freeimage(&mlx->img->ptr);
	mlx_clear_window(mlx->mlx, mlx->win);
	while(++i <= 1)
	{
		mlx->thr->a = -1;
		mlx->thr->b = 1;
		mlx->thr->x = 0;
		mlx->thr->y = i * 350;
		mlx->thr->min_k = i * 980000;// i * 50;
		mlx->thr->end_k = (i * 980000) + 980000;//(i + i) * 50;
		pthread_create(&tid[i], NULL, cast, mlx->thr);
		ft_putnbr(mlx->thr->y);
		ft_putchar('\n');
	}
	i = -1;
	while(++i <= 1)
	{
		pthread_join(tid[i], NULL);
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
		mlx->a = mlx->a - 0.1;
		mlx->b = mlx->b + 0.1;
	}
	if(key == O || key == P)
		setall(mlx);
	return (1);
}
