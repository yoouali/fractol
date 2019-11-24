/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 03:12:46 by yoouali           #+#    #+#             */
/*   Updated: 2019/11/24 02:12:51 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	set_tricorn(t_fr *fr, int *col)
{
	fr->rnr = -2;
	fr->rxr = 1.5;
	fr->inr = -2;
	fr->ixr = 2;
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

void	tricorn_draw(t_ge *ge, t_dr dr)
{
	t_fr	fr;

	fr = ge->tric;
	dr.zr = map(dr.x + fr.xof, IMG_WID, fr.rnr, fr.rxr);
	dr.zi = map(dr.y + fr.yof, IMG_HEI, fr.inr, fr.ixr);
	dr.cr = dr.zr;
	dr.ci = dr.zi;
	if (fr.pow == 0)
		tricorn1_pow(ge, fr, dr);
	else if (fr.pow == 1)
		tricorn2_pow(ge, fr, dr);
	else if (fr.pow == 2)
		tricorn3_pow(ge, fr, dr);
	else if (fr.pow == 3)
		tricorn4_pow(ge, fr, dr);
	else
		tricorn5_pow(ge, fr, dr);
}
