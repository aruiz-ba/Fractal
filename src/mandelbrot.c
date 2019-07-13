/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:58:03 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/07/13 18:18:17 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

double	map1(double a, double a0, double a1, double b0, double b1)
{
	return (b0 + (b1 - b0) * ((a - a0) / (a1 - a0)));
}

int		mandelbrot(int bright, t_thr *thr)
{
	thr->a = map1(thr->x, 0, WIN_WIDTH, thr->zoma1, thr->zoma2);
	thr->b = map1(thr->y, 0, WIN_HEIGHT, thr->zomb1, thr->zomb2);
	thr->n = 0;
	thr->max_it = 100;
	thr->ca = thr->a;
	thr->cb = thr->b;
	while (thr->n < thr->max_it)
	{
		thr->aa = thr->a * thr->a - thr->b * thr->b;
		thr->bb = 2 * thr->a * thr->b;
		thr->a = thr->aa + thr->ca;
		thr->b = thr->bb + thr->cb;
		if (fabs(thr->a + thr->b) > 16)
			break ;
		thr->n++;
	}
	bright = map1(thr->n, 0, thr->max_it, 0xFF0000, 0xDEFF00);
	if (thr->n == thr->max_it)
		bright = 0;
	return (bright);
}
