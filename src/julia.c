/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 02:55:46 by yoouali           #+#    #+#             */
/*   Updated: 2019/11/23 22:09:23 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	set_julia(t_fr *fr, int *col)
{
	fr->rnr = -2;
	fr->rxr = 2;
	fr->inr = -2;
	fr->ixr = 2;
	fr->mr = -0.510000;
	fr->mi = -0.520000;
	fr->itr = MIN_ITR;
	fr->pow = 0;
	fr->col = 0;
	fr->xof = 0;
	fr->yof = 0;
	fr->ex = 1;
	fr->colt = col;
}

void	julia_draw(t_ge *ge, t_dr dr)
{
	t_fr	fr;

	fr = ge->juli;
	dr.zr = map(dr.x + fr.xof, IMG_WID, fr.rnr, fr.rxr);
	dr.zi = map(dr.y + fr.yof, IMG_HEI, fr.inr, fr.ixr);
	dr.cr = fr.mr;
	dr.ci = fr.mi;
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
