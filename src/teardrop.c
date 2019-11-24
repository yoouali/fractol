/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teardrop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:06:10 by yoouali           #+#    #+#             */
/*   Updated: 2019/11/23 18:45:34 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	set_teardrop(t_fr *fr, int *col)
{
	fr->rnr = -2;
	fr->rxr = 2;
	fr->inr = -2;
	fr->ixr = 2;
	fr->mr = 0;
	fr->mi = 0;
	fr->itr = 50;
	fr->pow = 0;
	fr->col = 0;
	fr->xof = 0;
	fr->yof = 0;
	fr->ex = 1;
	fr->colt = col;
}

void	teardrop_draw(t_ge *ge, t_dr dr)
{
	t_fr	fr;

	fr = ge->tear;
	dr.zi = map(dr.x + fr.xof, IMG_WID, fr.rnr, fr.rxr);
	dr.zr = map(dr.y + fr.yof, IMG_HEI, fr.inr, fr.ixr);
	dr.cr = dr.zr / (dr.zr * dr.zr + dr.zi * dr.zi) * -1;
	dr.ci = dr.zi / (dr.zr * dr.zr + dr.zi * dr.zi) * -1;
	dr.zr = 0;
	dr.zi = 0;
	if (fr.pow == 0)
		mandelbrot1_pow(ge, fr, dr);
	else if (fr.pow == 1)
		mandelbrot2_pow(ge, fr, dr);
	else if (fr.pow == 2)
		mandelbrot3_pow(ge, fr, dr);
	else if (fr.pow == 3)
		mandelbrot4_pow(ge, fr, dr);
	else
		mandelbrot5_pow(ge, fr, dr);
}
