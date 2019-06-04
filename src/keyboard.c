/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:12:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/06/04 17:26:41 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

void	setall(t_mlx *mlx)
{
	freeimage(&mlx->img->ptr);
	mlx_clear_window(mlx->mlx, mlx->win);
	fill_image(&mlx->img->ptr, mlx->a, mlx->b);
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
