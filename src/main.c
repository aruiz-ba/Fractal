/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:44:35 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/06/18 17:13:05 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

int		main()
{
	t_m			*m;
	int			i;
	
	i = -1;
	m = NULL;
	if (!(m = (t_m*)malloc(sizeof(t_m))))
		return (-1);
	ft_bzero(m, sizeof(m));
	m->k_in = WIN_HEIGHT * 4;
	m->mlx.mlx = mlx_init();
	m->mlx.win = mlx_new_window(m->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "fract");
	new_image(m);

	while(++i < THR_NUM)
	{
		m->thr[i].image_string = &m->img.ptr;
		m->thr[i].zom1 = -1;
		m->thr[i].zom2 = 1;
		m->thr[i].tr1 = 1;
		m->thr[i].tr2 = 1;
		m->thr[i].x = 0;
		m->thr[i].y = i;
		m->thr[i].min_k = i * m->k_in;
		m->thr[i].end_k = (i * m->k_in) + m->k_in;
		pthread_create(&m->thr[i].tid, NULL, cast, &m->thr[i]);
	}
	i = -1;
	while(++i < THR_NUM)
		pthread_join(m->thr[i].tid, NULL);	
	mlx_put_image_to_window(m->mlx.mlx, m->mlx.win, m->img.image, 0, 0);
	m->mlx.a = -1;
	m->mlx.b = 1;
	m->mlx.img = &m->img;
	m->mlx.k_in = m->k_in;

	//mlx_hook(m->mlx.win, 2, 1L << 2, deal_key, &m->mlx);
	mlx_hook(m->mlx.win, 6, 1L << 2, mouse_move, &m->mlx);
	mlx_loop(m->mlx.mlx);
	return (0);
}
