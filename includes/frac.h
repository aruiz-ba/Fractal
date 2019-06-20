/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:26:13 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/06/20 17:23:33 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Libft/libft.h"
# include "mlx.h"
# include "math.h"
# include "pthread.h"

# define WIN_WIDTH	700	
# define WIN_HEIGHT	700
# define THR_NUM 	700
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

typedef struct		s_thr
{
	pthread_t		tid;
	char			**image_string;
	float			tr1;
	float			tr2;
	float			zom1;
	float			zom2;
	int				x;
	int				y;
	int				min_k;
	int				end_k;
	int				(*f)(int bright, t_thr *thr);
}					t_thr;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	float			a;
	float			b;
	t_image			*img;
	t_thr			thr[THR_NUM];
	int				k_in;
	float			zom1;
	float			zom2;
	int				(*f)(int bright, t_thr *thr);
}					t_mlx;

typedef struct		s_m
{
	t_mlx			mlx;
	t_thr			thr[THR_NUM];
	t_image			img;
	int				k_in;
}					t_m;

void 	new_image(t_m *m);
void	fill_image(t_thr *thr);
void	*cast(void *thr);
void	freeimage(char **image_string);
int		mandelbrot(int bright, t_thr *thr);
int		julia(int bright, t_thr *thr);
int		deal_key(int key, t_mlx *m);
int 	mouse_move(int x, int y, t_mlx *mlx);
void	setall(t_mlx *mlx);
float map1(float a, float a0, float a1, float b0, float b1);
