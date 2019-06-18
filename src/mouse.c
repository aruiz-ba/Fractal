/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:19:52 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/06/18 17:27:07 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

int mouse_move(int x, int y, t_mlx *mlx)
{
	/*ft_putstr("\nX value:");
	ft_putnbr(x);
	ft_putstr("\nY value:");*/
	ft_putnbr(y);
	mlx->a = x;
	mlx->b = y;
	setall(mlx);
	return (1);
}
