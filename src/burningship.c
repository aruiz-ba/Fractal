/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:26:53 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/07/15 19:26:42 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int		burningship(int bright, t_thr *thr)
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
	thr->ca = thr->a;
	thr->cb = thr->b;
	while (thr->n < thr->max_it)
	{
		thr->aa = thr->a * thr->a - thr->b * thr->b;
		thr->bb = 2 * thr->a * thr->b;
		thr->a = fabs(thr->aa + thr->ca);
		thr->b = fabs(thr->bb + thr->cb);
		if (fabs(thr->a + thr->b) > 16)
			break ;
		thr->n++;
	}
	bright = map1(thr->n, thr->max_it, thr->color, 0xDEFF00);
	if (thr->n == thr->max_it)
		bright = 0;
	return (bright);
}
