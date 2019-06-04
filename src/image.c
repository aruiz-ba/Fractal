/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:02:24 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/06/04 18:32:22 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

void	freeimage(char **image_string)
{
	int		i;
	int		k;
	int		color;

	color = 0xFFFFFF;
	k = 0;
	i = 0;
	while (i < (WIN_HEIGHT * WIN_WIDTH))
	{
		(*image_string)[k + 0] = (char)(color % 256 % 256);
		(*image_string)[k + 1] = (char)(color / 256 % 256);
		(*image_string)[k + 2] = (char)(color / 256 / 256);
		(*image_string)[k + 3] = 0;
		k += 4;
		i++;
	}
}

void	fill_image(t_thr *thr)
{
	int		x;
	int		y;
	int		bright;

	thr->k = 0;
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT && thr->k != thr->end_k)
		{
			bright = mandelbrot(bright, y, x, thr->a, thr->b);
			(*thr->image_string)[thr->k + 0] = bright;
			(*thr->image_string)[thr->k + 1] = bright;
			(*thr->image_string)[thr->k + 2] = bright;
			(*thr->image_string)[thr->k + 3] = 0;
			thr->k += 4;
			y++;
		}
		x++;
	}
}

t_image	*new_image(t_mlx *mlx)
{
	t_image		*m;

	if ((m = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	m->image = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	m->ptr = mlx_get_data_addr(m->image, &m->bpp, &m->stride, &m->endian);
	return (m);
}
