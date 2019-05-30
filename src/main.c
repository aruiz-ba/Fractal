/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:44:35 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/05/30 19:14:01 by aruiz-ba         ###   ########.fr       */
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
		mlx->a = mlx->a + 0.1;
	if (key == P)
		mlx->b = mlx->b - 0.1;
	if(key == O || key == P)
		setall(mlx);
	return (1);
}

int		main()
{
	t_mlx	mlx;
	t_image *img;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "fract");
	img = new_image(&mlx);
	fill_image(&img->ptr, -5, 5);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img->image, 0, 0);
	mlx.img = img;
	mlx.a = -5;
	mlx.b = 5;
	mlx_hook(mlx.win, 2, 1L << 2, deal_key, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
