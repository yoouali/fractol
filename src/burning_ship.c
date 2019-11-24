/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 04:09:05 by yoouali           #+#    #+#             */
/*   Updated: 2019/11/23 18:45:36 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	set_burning_ship(t_fr *fr, int *col)
{
	fr->rnr = -2.5;
	fr->rxr = 2;
	fr->inr = -2;
	fr->ixr = 1;
	fr->mr = 0;
	fr->mi = 0;
	fr->itr = MIN_ITR;
	fr->pow = 5;
	fr->col = 0;
	fr->xof = 0;
	fr->yof = 0;
	fr->ex = 1;
	fr->colt = col;
}

void	burning_ship_draw(t_ge *ge, t_dr dr)
{
	t_fr	fr;

	fr = ge->burn;
	dr.zr = map(dr.x + fr.xof, IMG_WID, fr.rnr, fr.rxr);
	dr.zi = map(dr.y + fr.yof, IMG_HEI, fr.inr, fr.ixr);
	dr.cr = dr.zr;
	dr.ci = dr.zi;
	dr.n = 0;
	while (dr.n < fr.itr && dr.zr * dr.zr + dr.zi * dr.zi <= 4)
	{
		dr.tp = dr.zr * dr.zr - dr.zi * dr.zi + dr.cr;
		dr.zi = fabsl(2 * dr.zr * dr.zi) + dr.ci;
		dr.zr = dr.tp;
		dr.n++;
	}
	if (dr.n != fr.itr)
		ge->data[dr.x + dr.y * IMG_WID] = fr.colt[(int)(map(dr.n,\
					fr.itr, 0, 50))];
}
