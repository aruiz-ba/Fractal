/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:44:35 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/06/14 16:52:18 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

int		main()
{
	t_mlx		mlx;
	t_image		*img;
	int			i;
	t_thr		thr[THR_NUM];
	
	i = -1;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "fract");
	img = new_image(&mlx);

	while(++i < THR_NUM)
	{
		thr[i].image_string = &img->ptr;
		thr[i].a = -1;
		thr[i].b = 1;
		thr[i].x = 0;
		thr[i].y = i * 350;
		thr[i].min_k = i * 980000;
		thr[i].end_k = (i * 980000) + 980000;
		pthread_create(&thr[i].tid, NULL, cast, &thr[i]);
	}
	i = -1;
	while(++i < THR_NUM)
	{
		pthread_join(thr[i].tid, NULL);	
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, img->image, 0, 0);
	mlx.img = img;
	mlx.a = -5;
	mlx.b = 5;
	mlx_hook(mlx.win, 2, 1L << 2, deal_key, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
