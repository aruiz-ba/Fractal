/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:50:33 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/07/15 19:26:40 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

int		julia(int bright, t_thr *thr)
{
	thr->a = map1(thr->x, WIN_WIDTH, thr->zoma1, thr->zoma2);
	thr->b = map1(thr->y, WIN_HEIGHT, thr->zomb1, thr->zomb2);
	if (!thr->tr1 || !thr->tr2)
		thr->ca = 0;
	else
	{
		thr->ca = map1(thr->tr1, WIN_WIDTH, -2, 2);
		thr->cb = map1(thr->tr2, WIN_HEIGHT, -2, 2);
	}
	while (thr->n < thr->max_it)
	{
		thr->aa = thr->a * thr->a - thr->b * thr->b;
		thr->bb = 2 * thr->a * thr->b;
		thr->a = thr->aa + thr->ca - 0.8;
		thr->b = thr->bb + thr->cb;
		if (fabs(thr->a + thr->b) > 16)
			break ;
		thr->n++;
	}
	bright = map1(thr->n, thr->max_it, thr->color, 0xDEFF00);
	if (thr->n == thr->max_it)
		bright = 0;
	return (bright);
}

int		julia_no_mouse(int bright, t_thr *thr)
{
	thr->a = map1(thr->x, WIN_WIDTH, thr->zoma1, thr->zoma2);
	thr->b = map1(thr->y, WIN_HEIGHT, thr->zomb1, thr->zomb2);
	while (thr->n < thr->max_it)
	{
		thr->aa = thr->a * thr->a - thr->b * thr->b;
		thr->bb = 2 * thr->a * thr->b;
		thr->a = thr->aa - 0.8;
		thr->b = thr->bb;
		if (fabs(thr->a + thr->b) > 16)
			break ;
		thr->n++;
	}
	bright = map1(thr->n, thr->max_it, thr->color, 0xDEFF00);
	if (thr->n == thr->max_it)
		bright = 0;
	return (bright);
}
