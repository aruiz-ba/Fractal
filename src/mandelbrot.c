/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:58:03 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/07/11 20:25:10 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

float	map1(float a, float a0, float a1, float b0, float b1)
{
	return (b0 + (b1 - b0) * ((a - a0) / (a1 - a0)));
}

int		mandelbrot(int bright, t_thr *thr)
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

	a = map1(thr->x, 0, WIN_WIDTH, thr->zoma1, thr->zoma2);
	b = map1(thr->y, 0, WIN_HEIGHT, thr->zomb1, thr->zomb2);
	n = 0;
	max_it = 50;
	z = 0;
	ca = a;
	cb = b;
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
	bright = map1(n, 0, max_it, 0xFF0000, 0xDEFF00);
	if (n == max_it)
		bright = 0;
	return (bright);
}
