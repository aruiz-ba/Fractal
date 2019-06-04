/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:44:35 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/06/04 18:36:06 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

int		main()
{
	t_mlx	mlx;
	t_image *img;
	int		i;
	t_thr	thr;

	i = -1;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "fract");
	img = new_image(&mlx);
/*
	while(++i < 2)
	{
		thr.image_string = &img->ptr;
		thr.a = -5;
		thr.b = 5;
		thr.k = i * 50;
		thr.end_k = (i + i) * 50;
		pthread_create(&tid, NULL, fill_image, &thr)
	}
*/
		thr.image_string = &img->ptr;
		thr.a = -1;
		thr.b = 1;
		thr.k = i * 50;
		thr.end_k = (i + i) * 50;
		fill_image(&thr);
	
	mlx_put_image_to_window(mlx.mlx, mlx.win, img->image, 0, 0);
	mlx.img = img;
	mlx.a = -5;
	mlx.b = 5;
	mlx_hook(mlx.win, 2, 1L << 2, deal_key, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
