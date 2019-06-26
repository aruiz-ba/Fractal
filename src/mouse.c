/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:19:52 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/06/24 18:57:58 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <frac.h>

int mouse_move(int x, int y, t_mlx *mlx)
{
	mlx->a = x;
	mlx->b = y;
	setall(mlx);
	return (1);
}

int mouse_hook(int code, int x, int y, t_mlx *mlx)
{
	mlx->a = x;
	mlx->b = y;
	if(code == 4|| code == 1)
	{
		mlx->zom1 += 0.1;
		mlx->zom2 -= 0.1;
	}
	else if(code == 5 || code == 2)
	{
		mlx->zom1 -= 0.1;
		mlx->zom2 += 0.1;
	}
	setall(mlx);
	return (1);
}

