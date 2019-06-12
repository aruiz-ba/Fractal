/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:44:35 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/06/12 20:11:03 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

int		main()
{
	t_mlx		mlx;
	t_image		*img;
	int			i;
	t_thr		thr;
	pthread_t	tid[2];

	i = -1;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "fract");
	img = new_image(&mlx);

	thr.image_string = &img->ptr;
	while(++i < 2)
	{
		thr.a = -1;
		thr.b = 1;
		thr.x = 0;
		thr.y = i * 350;
		thr.min_k = i * 980000;// i * 50;
		thr.end_k = (i * 980000) + 980000;//(i + i) * 50;
		pthread_create(&tid[i], NULL, cast, &thr);
	}
	i = -1;
	while(++i < 2)
	{
		pthread_join(tid[i], NULL);	
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, img->image, 0, 0);
	mlx.img = img;
	mlx.a = -5;
	mlx.b = 5;
	mlx_hook(mlx.win, 2, 1L << 2, deal_key, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
