/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:19:52 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/07/03 16:44:49 by aruiz-ba         ###   ########.fr       */
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
		mlx->zoma1 /= 1.1;
		mlx->zoma2 /= 1.1;
		printf("ZOOM1:%f\n", mlx->zoma1);	
		printf("ZOOM2:%f\n", mlx->zoma2);	
	}
	else if(code == 5 || code == 2)
	{
		mlx->zoma1 *= 1.1;
		mlx->zoma2 *= 1.1;
		printf("ZOOM1:%f\n", mlx->zoma1);	
		printf("ZOOM2:%f\n", mlx->zoma2);	
	}
	setall(mlx);
	return (1);
}

