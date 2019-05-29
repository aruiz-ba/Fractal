/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:02:24 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/05/29 18:40:34 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

int		math(int bright)
{
	int	a;
	int	b;
	int	n;
	int z;
	int aa;
	int bb;

	a = 0;	
	b = 0;
	n = 0;
	z = 0;
	while (n < 100)
	{
		aa = a * a - b * b;
		bb = 2 * a * b;
		a = aa;
		b = bb;
		if (abs(a + b) > 16)
			break ;
		n++;
	}
	bright = 0;
	if(n == 100)
		bright = 255;
	return(bright);
}

void	fill_image(char **image_string)
{
	int		x;
	int		y;
	int		k;
	int		bright;

	k = 0;
	x = 0;
	while (x < 500)
	{
		y = 0;
		while (y < 500)
		{
			bright = math(bright);
			(*image_string)[k + 0] = bright;
			(*image_string)[k + 1] = bright;
			(*image_string)[k + 2] = bright;
			(*image_string)[k + 3] = 100;
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
	m->image = mlx_new_image(mlx->mlx, 500, 500);
	m->ptr = mlx_get_data_addr(m->image, &m->bpp, &m->stride, &m->endian);
	return (m);
}
