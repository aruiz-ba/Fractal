/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:02:24 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/05/30 19:06:53 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

float map1(float a, float a0, float a1, float b0, float b1)
{
	return (b0 + (b1 - b0) * ((a-a0)/(a1-a0)));
}

int		math(int bright, int x, int y, float c, float d)
{
	float	a;
	float	b;
	int		n;
	int		max_it;
	int		z;
	float	aa;
	float	bb;
	float	ca;
	float	cb;

	a = map1(x , 0, WIN_WIDTH, c, d);
	b = map1(y , 0, WIN_HEIGHT, c, d);
	ca = a;
	cb = b;
	n = 0;
	max_it = 100;
	z = 0;
	while (n < max_it)
	{
		aa = a * a - b * b;
		bb = 2 * a * b;
		a = aa + ca;
		b = bb + cb;
		if (fabsf(a + b) > 16)
			break ;
		n++;
	}
	bright = map1(n, 0, max_it, 0, 255);
	if(n == max_it)
		bright = 0;
	return(bright);
}

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

void	fill_image(char **image_string, float a, float b)
{
	int		x;
	int		y;
	int		k;
	int		bright;

	k = 0;
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			bright = math(bright, y, x, a, b);
			(*image_string)[k + 0] = bright;
			(*image_string)[k + 1] = bright;
			(*image_string)[k + 2] = bright;
			(*image_string)[k + 3] = 0;
			k += 4;
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
