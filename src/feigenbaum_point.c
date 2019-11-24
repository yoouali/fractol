/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feigenbaum_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 04:58:44 by yoouali           #+#    #+#             */
/*   Updated: 2019/11/24 02:13:35 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	set_feigenbaum_point(t_fr *fr, int *col)
{
	fr->rnr = -1.5;
	fr->rxr = 1.5;
	fr->inr = -1.5;
	fr->ixr = 1.5;
	fr->mr = 0;
	fr->mi = 0;
	fr->itr = MIN_ITR;
	fr->pow = 0;
	fr->col = 0;
	fr->xof = 0;
	fr->yof = 0;
	fr->ex = 1;
	fr->colt = col;
}

void	feigenbaum_point_draw(t_ge *ge, t_dr dr)
{
	t_fr	fr;

	fr = ge->feig;
	dr.zr = map(dr.x + fr.xof, IMG_WID, fr.rnr, fr.rxr);
	dr.zi = map(dr.y + fr.yof, IMG_HEI, fr.inr, fr.ixr);
	dr.cr = dr.zr * dr.zr * dr.zr - 3 * dr.zr * dr.zi * dr.zi - 1.401155;
	dr.ci = 3 * dr.zr * dr.zr * dr.zi - dr.zi * dr.zi * dr.zi;
	dr.zr = 0;
	dr.zi = 0;
	dr.n = 0;
	while (dr.n < fr.itr && dr.zr * dr.zr + dr.zi * dr.zi <= 4)
	{
		dr.tp = dr.zr * dr.zr - dr.zi * dr.zi + dr.cr;
		dr.zi = 2 * dr.zr * dr.zi + dr.ci;
		dr.zr = dr.tp;
		dr.n++;
	}
	if (dr.n != fr.itr)
		ge->data[dr.x + dr.y * IMG_WID] = fr.colt[(int)(map(dr.n,\
					fr.itr, 0, 50))];
}
