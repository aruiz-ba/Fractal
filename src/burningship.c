/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:26:53 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/07/03 19:33:20 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int		burningship(int bright, t_thr *thr)
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

	a = map1(thr->x , 0, WIN_WIDTH, thr->zoma1 , thr->zoma2);
	b = map1(thr->y , 0, WIN_HEIGHT, thr->zoma1, thr->zoma2);

	if(!thr->tr1 || !thr->tr2)
		ca = 0;
	else
	{
		ca = map1(thr->tr1, 0, WIN_WIDTH, -2, 2);
		cb = map1(thr->tr2, 0, WIN_HEIGHT, -2, 2);
	}
	n = 0;
	max_it = 500;
	z = 0;
	ca = a;
	cb = b;
	while (n < max_it)
	{
		aa = a * a - b * b;
		bb = 2 * a * b;
		a = fabs(aa + ca);
		b = fabs(bb + cb);
		if (fabsf(a + b) > 16)
			break ;
		n++;
	}
	bright = map1(n, 0, max_it, 0xFF0000, 0xDEFF00);
	if(n == max_it)
		bright = 0;
	return(bright);
}
