/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:26:13 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/07/03 18:50:27 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Libft/libft.h"
# include "mlx.h"
# include "math.h"
# include "pthread.h"
# include "stdio.h" //BORRAME

# define WIN_WIDTH	700	
# define WIN_HEIGHT	700
# define THR_NUM 	700
# define O			31	
# define P			35
# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124


# define U			32	
# define I			34
# define T			17	
# define Y			16
# define ESC			53

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
	float			zoma1;
	float			zoma2;
	float			zomb1;
	float			zomb2;
	int				x;
	int				y;
	int				min_k;
	int				end_k;
	void			*f;
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
	float			zoma1;
	float			zoma2;
	int				x;
	int				y;
	int				(*f)(int ,t_thr *);
}					t_mlx;

typedef struct		s_m
{
	t_mlx			mlx;
	t_thr			thr[THR_NUM];
	t_image			img;
	int				k_in;
}					t_m;

void 	new_image(t_m *m);
void	fill_image(t_thr *thr, int (*f)(int , t_thr *));
void	*cast(void *cast);
void	freeimage(char **image_string);
int	mandelbrot(int bright, t_thr *thr);
int	julia(int bright, t_thr *thr);
int	deal_key(int key, t_mlx *m);
int 	mouse_move(int x, int y, t_mlx *mlx);
void	setall(t_mlx *mlx);
float 	map1(float a, float a0, float a1, float b0, float b1);
int	error(int i);
int	mouse_hook(int code, int x, int y, t_mlx *mlx);
int	burningship(int bright, t_thr *thr);

