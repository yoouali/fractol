/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 23:44:34 by yoouali           #+#    #+#             */
/*   Updated: 2019/11/24 01:52:36 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>

# define WIN_WID 1093
# define WIN_HEI 1093
# define IMG_WID 800
# define IMG_HEI 720
# define IMG_X 277
# define IMG_Y 354
# define MIN_ITR 50
# define MAX_ITR 10000

typedef	struct		s_fr
{
	long double	rnr;
	long double	rxr;
	long double	inr;
	long double	ixr;
	long double	mr;
	long double	mi;
	int			itr;
	int			pow;
	int			col;
	int			xof;
	int			yof;
	int			ex;
	int			*colt;
}					t_fr;

typedef	struct		s_ge
{
	void		*ptr;
	void		*win;
	void		*png;
	void		*img;
	int			*data;
	t_fr		mand;
	t_fr		juli;
	t_fr		tric;
	t_fr		burn;
	t_fr		burn_j;
	t_fr		feig;
	t_fr		real;
	t_fr		imag;
	t_fr		tear;
	int			col1[50];
	int			col2[50];
	int			col3[50];
	int			col4[50];
	int			col5[50];
	int			col6[50];
	int			col7[50];
	int			col8[50];
	int			col9[50];
	int			col10[50];
	int			frez;
	int			sonic;
	int			fracn;
	pthread_t	thread[4];
}					t_ge;

typedef	struct		s_dr
{
	long double	cr;
	long double	ci;
	long double	zr;
	long double	zi;
	long double	tp;
	int			n;
	int			x;
	int			y;
}					t_dr;

int					fractal_checker(char *name);
int					is_equal(char *s1, char *s2);
void				ft_putendl(char *str);
void				fractal_usage(void);
void				environment_set_error(t_ge *ge);
void				set_up_environment(t_ge *ge);
void				set_zero(t_ge *ge);
void				run_graphic_environment(t_ge *ge);
void				reset_graphic_environment(t_ge *ge);
void				draw_fractal(t_ge *ge);
void				find_fractal(t_ge *ge, t_dr dr);
void				set_fractal(t_ge *ge);
t_fr				*detect_fractal(t_ge *ge);
long double			map(long double v, long double ox, long double nn,\
		long double nx);
void				set_mandelbrot(t_fr *fr, int *col);
void				mandelbrot_draw(t_ge *ge, t_dr dr);
void				mandelbrot1_pow(t_ge *ge, t_fr fr, t_dr dr);
void				mandelbrot2_pow(t_ge *ge, t_fr fr, t_dr dr);
void				mandelbrot3_pow(t_ge *ge, t_fr fr, t_dr dr);
void				mandelbrot4_pow(t_ge *ge, t_fr fr, t_dr dr);
void				mandelbrot5_pow(t_ge *ge, t_fr fr, t_dr dr);
void				set_julia(t_fr *fr, int *col);
void				julia_draw(t_ge *ge, t_dr dr);
void				set_tricorn(t_fr *fr, int *col);
void				tricorn_draw(t_ge *ge, t_dr dr);
void				tricorn1_pow(t_ge *ge, t_fr fr, t_dr dr);
void				tricorn2_pow(t_ge *ge, t_fr fr, t_dr dr);
void				tricorn3_pow(t_ge *ge, t_fr fr, t_dr dr);
void				tricorn4_pow(t_ge *ge, t_fr fr, t_dr dr);
void				tricorn5_pow(t_ge *ge, t_fr fr, t_dr dr);
void				set_burning_ship(t_fr *fr, int *col);
void				burning_ship_draw(t_ge *ge, t_dr dr);
void				set_burning_julia(t_fr *fr, int *col);
void				burning_julia_draw(t_ge *ge, t_dr dr);
void				set_feigenbaum_point(t_fr *fr, int *col);
void				feigenbaum_point_draw(t_ge *ge, t_dr dr);
void				set_reality_point(t_fr *fr, int *col);
void				reality_point_draw(t_ge *ge, t_dr dr);
void				set_imagine_point(t_fr *fr, int *col);
void				imagine_point_draw(t_ge *ge, t_dr dr);
void				set_teardrop(t_fr *fr, int *col);
void				teardrop_draw(t_ge *ge, t_dr dr);
int					get_gradian(int ind, int max, int col1, int col2);
void				create_gradian(int *tab, int col1, int col2, int col3);
void				set_color(t_ge *ge);
int					key_hold_event(int key, t_ge *ge);
int					key_event(int key, t_ge *ge);
void				fractal_exit(t_ge *ge);
void				move_fractal(int key, t_ge *ge);
void				change_itr(int key, t_ge *ge);
void				change_color_key(int key, t_ge *ge);
void				change_pow(int key, t_ge *ge);
int					moving_fractal(int x, int y, t_ge *ge);
int					mouse_event(int bot, int x, int y, t_ge *ge);
void				fractal_zoom(int bot, int x, int y, t_ge *ge);
char				*ft_itoa(int va, t_ge *ge);

#endif
