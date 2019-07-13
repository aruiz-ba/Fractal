/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:26:13 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/07/13 18:18:15 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "mlx.h"
#include "math.h"
#include "pthread.h"

# define WIN_WIDTH	700	
# define WIN_HEIGHT	700
# define THR_NUM 	700
# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124


# define U			32	
# define I			34
# define T			17	
# define Y			16
# define T1			18
# define T2			19
# define T3			20
# define ESC		53

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
	double			tr1;
	double			tr2;
	double			zoma1;
	double			zoma2;
	double			zomb1;
	double			zomb2;
	int				x;
	int				y;
	int				min_k;
	int				end_k;
	void			*f;
	int				n;
	int				max_it;
	double			a;
	double			b;
	double			aa;
	double			bb;
	double			ca;
	double			cb;
}					t_thr;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	double			a;
	double			b;
	t_image			*img;
	t_thr			thr[THR_NUM];
	int				k_in;
	double			zoma1;
	double			zoma2;
	double			zomb1;
	double			zomb2;
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
int	julia_no_mouse(int bright, t_thr *thr);
int	deal_key(int key, t_mlx *m);
int 	mouse_move(int x, int y, t_mlx *mlx);
void	setall(t_mlx *mlx);
double 	map1(double a, double a0, double a1, double b0, double b1);
int	error(int i);
int	mouse_hook(int code, int x, int y, t_mlx *mlx);
int	burningship(int bright, t_thr *thr);

