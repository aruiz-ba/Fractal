/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:02:24 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/06/14 16:52:16 by aruiz-ba         ###   ########.fr       */
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
	int		bright;
	int		init_x;
////ft_putstr("\nESTO ES Y :");
////ft_putnbr(th.y);
////ft_putstr("\nESTO ES X :");
////ft_putnbr(thr->x);
	init_x = thr->x;
	while (thr->y < WIN_WIDTH && thr->min_k <= thr->end_k)
	{
		thr->x = init_x;
		while (thr->x < WIN_HEIGHT && thr->min_k <= thr->end_k)
		{
			bright = mandelbrot(bright, thr->x, thr->y, thr->a, thr->b);
			(*thr->image_string)[thr->min_k + 0] = bright;
			(*thr->image_string)[thr->min_k + 1] = bright;
			(*thr->image_string)[thr->min_k + 2] = bright;
			(*thr->image_string)[thr->min_k + 3] = 0;
			thr->min_k += 4;
			thr->x++;
		}
		thr->y++;
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

void *cast(void *thr)
{
	fill_image(thr);
	return(NULL);
}
