/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagine_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 07:56:41 by yoouali           #+#    #+#             */
/*   Updated: 2019/11/24 02:14:01 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	set_imagine_point(t_fr *fr, int *col)
{
	fr->rnr = -1.5;
	fr->rxr = 1.5;
	fr->inr = -1.5;
	fr->ixr = 1.5;
	fr->mr = 0.705000;
	fr->mi = -0.330000;
	fr->itr = MIN_ITR;
	fr->pow = 0;
	fr->col = 0;
	fr->xof = 0;
	fr->yof = 0;
	fr->ex = 1;
	fr->colt = col;
}

void	imagine_point_draw(t_ge *ge, t_dr dr)
{
	t_fr	fr;

	fr = ge->imag;
	dr.zr = map(dr.x + fr.xof, IMG_WID, fr.rnr, fr.rxr);
	dr.zi = map(dr.y + fr.yof, IMG_HEI, fr.inr, fr.ixr);
	dr.cr = dr.zr * dr.zr * dr.zr - 3 * dr.zr * dr.zi * dr.zi - fr.mr;
	dr.ci = 3 * dr.zr * dr.zr * dr.zi - dr.zi * dr.zi * dr.zi + fr.mi;
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
