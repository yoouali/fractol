/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_pow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:48:15 by yoouali           #+#    #+#             */
/*   Updated: 2019/11/24 02:15:06 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	mandelbrot1_pow(t_ge *ge, t_fr fr, t_dr dr)
{
	dr.n = 0;
	while (dr.n < fr.itr && dr.zr * dr.zr + dr.zi * dr.zi <= 4)
	{
		dr.tp = dr.zr * dr.zr - dr.zi * dr.zi + dr.cr;
		dr.zi = dr.zr * dr.zi * 2 + dr.ci;
		dr.zr = dr.tp;
		dr.n++;
	}
	if (dr.n != fr.itr)
		ge->data[dr.x + dr.y * IMG_WID] = fr.colt[(int)map(dr.n, fr.itr,\
				0, 50)];
}

void	mandelbrot2_pow(t_ge *ge, t_fr fr, t_dr dr)
{
	dr.n = 0;
	while (dr.n < fr.itr && dr.zr * dr.zr + dr.zi * dr.zi <= 4)
	{
		dr.tp = dr.zr * dr.zr * dr.zr - 3 * dr.zr * dr.zi * dr.zi + dr.cr;
		dr.zi = 3 * dr.zr * dr.zr * dr.zi - dr.zi * dr.zi * dr.zi + dr.ci;
		dr.zr = dr.tp;
		dr.n++;
	}
	if (dr.n != fr.itr)
		ge->data[dr.x + dr.y * IMG_WID] = fr.colt[(int)map(dr.n, fr.itr,\
				0, 50)];
}

void	mandelbrot3_pow(t_ge *ge, t_fr fr, t_dr dr)
{
	dr.n = 0;
	while (dr.n < fr.itr && dr.zr * dr.zr + dr.zi * dr.zi <= 4)
	{
		dr.tp = dr.zr * dr.zr * dr.zr * dr.zr + dr.zi * dr.zi * dr.zi *\
				dr.zi - 6 * dr.zr * dr.zr * dr.zi * dr.zi + dr.cr;
		dr.zi = 4 * dr.zr * dr.zr * dr.zr * dr.zi - 4 * dr.zr * dr.zi *\
				dr.zi * dr.zi + dr.ci;
		dr.zr = dr.tp;
		dr.n++;
	}
	if (dr.n != fr.itr)
		ge->data[dr.x + dr.y * IMG_WID] = fr.colt[(int)map(dr.n, fr.itr,\
				0, 50)];
}

void	mandelbrot4_pow(t_ge *ge, t_fr fr, t_dr dr)
{
	dr.n = 0;
	while (dr.n < fr.itr && dr.zr * dr.zr + dr.zi * dr.zi <= 4)
	{
		dr.tp = dr.zr * dr.zr * dr.zr * dr.zr * dr.zr - 10 * dr.zr *\
				dr.zr * dr.zr * dr.zi * dr.zi + 5 * dr.zr * dr.zi *\
				dr.zi * dr.zi * dr.zi + dr.cr;
		dr.zi = 5 * dr.zr * dr.zr * dr.zr * dr.zr * dr.zi + dr.zi *\
				dr.zi * dr.zi * dr.zi * dr.zi - 10 * dr.zr * dr.zr *\
				dr.zi * dr.zi * dr.zi + dr.ci;
		dr.zr = dr.tp;
		dr.n++;
	}
	if (dr.n != fr.itr)
		ge->data[dr.x + dr.y * IMG_WID] = fr.colt[(int)map(dr.n, fr.itr,\
				0, 50)];
}

void	mandelbrot5_pow(t_ge *ge, t_fr fr, t_dr dr)
{
	dr.n = 0;
	while (dr.n < fr.itr && dr.zr * dr.zr + dr.zi * dr.zi <= 4)
	{
		dr.tp = dr.zr * dr.zr * dr.zr * dr.zr * dr.zr * dr.zr - 15 *\
				dr.zr * dr.zr * dr.zr * dr.zr * dr.zi * dr.zi + 15 *\
				dr.zr * dr.zr * dr.zi * dr.zi * dr.zi * dr.zi -\
				dr.zi * dr.zi * dr.zi * dr.zi * dr.zi * dr.zi + dr.cr;
		dr.zi = 6 * dr.zr * dr.zr * dr.zr * dr.zr * dr.zr * dr.zi +\
				6 * dr.zr * dr.zi * dr.zi * dr.zi * dr.zi * dr.zi -\
				20 * dr.zr * dr.zr * dr.zr * dr.zi * dr.zi * dr.zi\
				+ dr.ci;
		dr.zr = dr.tp;
		dr.n++;
	}
	if (dr.n != fr.itr)
		ge->data[dr.x + dr.y * IMG_WID] = fr.colt[(int)map(dr.n, fr.itr,\
				0, 50)];
}
