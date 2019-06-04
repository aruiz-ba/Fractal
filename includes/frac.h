/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:26:13 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/06/04 18:32:08 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Libft/libft.h"
# include "mlx.h"
# include "math.h"
# include "pthread.h"

# define WIN_WIDTH	700	
# define WIN_HEIGHT	700
# define O			31	
# define P			35

typedef struct		s_image
{
	void			*image;
	char			*ptr;
	int				bpp;
	int				stride;
	int				endian;
}					t_image;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_image			*img;
	float			a;
	float			b;
}					t_mlx;

typedef struct		s_thr
{
	char			**image_string;
	float			a;
	float			b;
	int				k;
	int				end_k;
}					t_thr;

t_image *new_image(t_mlx *mlx);
void	fill_image(t_thr *thr);
void	freeimage(char **image_string);
int		mandelbrot(int bright, int x, int y, float c, float d);
int		deal_key(int key, t_mlx *mlx);
