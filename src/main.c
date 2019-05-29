/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:44:35 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/05/29 16:02:02 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

int		main()
{
	t_mlx	mlx;
	t_image *img;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 700, 700, "fract");
	img = new_image(&mlx);
	fill_image(&img->ptr);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img->image, 0, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
