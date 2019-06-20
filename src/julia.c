/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:50:33 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/06/20 17:18:06 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

int		julia(int bright, t_thr *thr)
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

	a = map1(thr->x , 0, WIN_WIDTH, thr->zom1 , thr->zom2);
	b = map1(thr->y , 0, WIN_HEIGHT, thr->zom1, thr->zom2);
	
	ca = map1(thr->tr1 , 0, WIN_WIDTH, -2, 2);
	cb = map1(thr->tr2 , 0, WIN_HEIGHT, -2, 2);
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
	bright = map1(n, 0, max_it, 0x0400FF, 0xFB300);
	if(n == max_it)
		bright = 0;
	return(bright);
}