/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:44:35 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/07/13 12:54:04 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

int		error(int i)
{
	if (i == 1)
	{
		ft_putendl("-usage: ./fractol name_of_fractol");
		ft_putendl("-Avaliable fractols:\n *julia\n *mandelbrot\n*burningship");
	}
	exit(0);
	return (0);
}

void	set_julia(t_m *m)
{
	m->mlx.a = -0.8;
	m->mlx.b = 0;
	m->mlx.img = &m->img;
	m->mlx.k_in = m->k_in;
	m->mlx.zoma1 = -2;
	m->mlx.zoma2 = 2;
	m->mlx.zomb1 = -2;
	m->mlx.zomb2 = 2;
	m->mlx.x = 1;
	m->mlx.y = 0;
	m->mlx.f = julia;
	setall(&m->mlx);
	mlx_mouse_hook(m->mlx.win, mouse_hook, &m->mlx);
	mlx_hook(m->mlx.win, 2, 1L << 2, deal_key, &m->mlx);
	mlx_hook(m->mlx.win, 6, 1L << 2, mouse_move, &m->mlx);
}

void	set_mandel(t_m *m)
{
	m->mlx.a = 2;
	m->mlx.b = 2;
	m->mlx.img = &m->img;
	m->mlx.k_in = m->k_in;
	m->mlx.zoma1 = -2;
	m->mlx.zoma2 = 2;
	m->mlx.zomb1 = -2;
	m->mlx.zomb2 = 2;
	m->mlx.x = 0;
	m->mlx.y = 0;
	m->mlx.f = mandelbrot;
	setall(&m->mlx);
	mlx_hook(m->mlx.win, 2, 1L << 2, deal_key, &m->mlx);
	mlx_mouse_hook(m->mlx.win, mouse_hook, &m->mlx);
}

void	set_burningship(t_m *m)
{
	m->mlx.a = 2;
	m->mlx.b = 2;
	m->mlx.img = &m->img;
	m->mlx.k_in = m->k_in;
	m->mlx.zoma1 = -2;
	m->mlx.zoma2 = 2;
	m->mlx.zomb1 = -2;
	m->mlx.zomb2 = 2;
	m->mlx.x = 0;
	m->mlx.y = 0;
	m->mlx.f = burningship;
	setall(&m->mlx);
	mlx_hook(m->mlx.win, 2, 1L << 2, deal_key, &m->mlx);
	mlx_mouse_hook(m->mlx.win, mouse_hook, &m->mlx);
}

int		main(int argc, char **argv)
{
	t_m			*m;
	int			i;

	if (argc != 2)
		error(1);
	i = -1;
	m = NULL;
	if (!(m = (t_m*)malloc(sizeof(t_m))))
		return (-1);
	ft_bzero(m, sizeof(m));
	m->k_in = WIN_HEIGHT * 4;
	m->mlx.mlx = mlx_init();
	m->mlx.win = mlx_new_window(m->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "fract");
	new_image(m);
	if (ft_strcmp(argv[1], "julia") == 0)
		set_julia(m);
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		set_mandel(m);
	else if (ft_strcmp(argv[1], "burningship") == 0)
		set_burningship(m);
	else
		error(1);
	mlx_loop(m->mlx.mlx);
	return (0);
}
